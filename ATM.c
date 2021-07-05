#include "ATM.h"


uint32_t Num_of_clients=10;
ST_accountBalance_t Bank_DataBase[]={{100.00,"123456789"},
                                     {6000.00,"234567891"},
                                     {3250.25,"567891234"},
                                     {1500.12,"456789123"},
                                     {500.00,"258649173"},
                                     {2100.00,"654823719"},
                                     {0.00,"971362485"},
                                     {1.00,"793148625"},
                                     {10.12,"123123456"},
                                     {0.55,"456789321"}};





ST_cardData_t *get_card_data(void)
{
    ST_cardData_t *card=(ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    printf("Please Enter the Card Holder Name: ");
    scan_string(card->cardHolderName,25);
    printf("Please Enter the Primary Account Number: ");
    scan_string(card->primaryAccountNumber,20);
    printf("Please Enter the Card Expiry Date(MM/YY): ");
    scan_string(card->cardExpirationDate,6);
    return card;
}

ST_cardData_t *get_terminal_data(void)
{
    ST_terminalData_t *terminal=(ST_terminalData_t *)malloc(sizeof(ST_terminalData_t));
    terminal->MaxTransAmount=MAX_TRANSACTION;
    printf("Please Enter the Transaction Amount: ");
    fflush(stdin);
    scanf("%f",&(terminal->transAmount));
    if (terminal->transAmount>MAX_TRANSACTION)      return terminal;
    printf("Please Enter the Transaction Date(DD/MM/YYYY): ");
    scan_string(terminal->transactionDate,11);

    return terminal;
}


uint8_t Terminal_check(ST_cardData_t *card, ST_terminalData_t *terminal)
{
    if ((terminal->transAmount)>(terminal->MaxTransAmount))
    {
        return 0;
    }
    sint8_t year_flag=strncmp(card->cardExpirationDate+3,terminal->transactionDate+8,2);
    sint8_t month_flag=strncmp(card->cardExpirationDate,terminal->transactionDate+3,2);
    if (year_flag>=0)
    {
        if (year_flag==0)
        {
            if (month_flag<0)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

uint8_t Server_check(ST_cardData_t *card, ST_terminalData_t *terminal)
{
    int i,client_found=0;
    for (i=0;i<Num_of_clients;i++)
    {
        if(strncmp(card->primaryAccountNumber,Bank_DataBase[i].primaryAccountNumber,10)==0)
        {
            client_found=1;
            break;
        }
    }

    if((client_found) && (terminal->transAmount<=Bank_DataBase[i].Balance))
    {
        return 1;
    }
    return 0;
}

uint8_t check_transaction(ST_cardData_t *card,ST_terminalData_t *terminal)
{
    uint8_t local_check=0,remote_check=0;
    local_check=Terminal_check(card,terminal);
    if (local_check==1)
    {
        remote_check=Server_check(card,terminal);
    }
    if(local_check && remote_check)
    {
        return 1;
    }
    return 0;
}




/*******************************************************************************/

void scan_string(uint8_t *buffer,uint32_t max_size)
{
    uint8_t x;
    uint32_t i;
    fflush(stdin);
    for(i=0;i<max_size-1;i++)
    {
        scanf("%c",&x);
        if (x=='\n' || x=='\0')
        {
            buffer[i]=0;
            return;
        }
        else
        {
            buffer[i]=x;
        }
    }
    buffer[i]=0;
}

