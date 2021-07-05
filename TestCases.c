#include "TestCases.h"


void Test_Enter_Data(void)
{
    printf("Enter Card Data:\n");
    ST_cardData_t *card=get_card_data();
    printf("\nEnter Terminal Data:\n");
    ST_terminalData_t *terminal=get_terminal_data();

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);
}

void testCase1(void)
{
    ST_cardData_t *card = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    ST_terminalData_t *terminal = (ST_terminalData_t *) malloc(sizeof(ST_terminalData_t));

    strncpy(card->cardHolderName,"Yehia Mohammed",25);
    strncpy(card->primaryAccountNumber,"456789123",20);
    strncpy(card->cardExpirationDate,"12/19",6);

    terminal->MaxTransAmount=MAX_TRANSACTION;
    terminal->transAmount=20.5;
    strncpy(terminal->transactionDate,"27/11/2019",11);

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);

    if(check_transaction(card,terminal))
    {
       printf("\nThe Transaction is Approved\n\n");
    }
    else
    {
       printf("\nThe Transaction is Declined\n\n");
    }
    free(card);
    free(terminal);
}

void testCase2(void)
{
    ST_cardData_t *card = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    ST_terminalData_t *terminal = (ST_terminalData_t *) malloc(sizeof(ST_terminalData_t));

    strncpy(card->cardHolderName,"Yehia Mohammed",25);
    strncpy(card->primaryAccountNumber,"456789123",20);
    strncpy(card->cardExpirationDate,"10/19",6);

    terminal->MaxTransAmount=MAX_TRANSACTION;
    terminal->transAmount=20.5;
    strncpy(terminal->transactionDate,"27/11/2019",11);

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);

    if(check_transaction(card,terminal))
    {
       printf("\nThe Transaction is Approved\n\n");
    }
    else
    {
       printf("\nThe Transaction is Declined\n\n");
    }
}

void testCase3(void)
{
    ST_cardData_t *card = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    ST_terminalData_t *terminal = (ST_terminalData_t *) malloc(sizeof(ST_terminalData_t));

    strncpy(card->cardHolderName,"Yehia Mohammed",25);
    strncpy(card->primaryAccountNumber,"456789123",20);
    strncpy(card->cardExpirationDate,"12/19",6);

    terminal->MaxTransAmount=MAX_TRANSACTION;
    terminal->transAmount=2000;
    strncpy(terminal->transactionDate,"27/11/2019",11);

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);

    if(check_transaction(card,terminal))
    {
       printf("\nThe Transaction is Approved\n\n");
    }
    else
    {
       printf("\nThe Transaction is Declined\n\n");
    }
}

void testCase4(void)
{
    ST_cardData_t *card = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    ST_terminalData_t *terminal = (ST_terminalData_t *) malloc(sizeof(ST_terminalData_t));

    strncpy(card->cardHolderName,"Yehia Mohammed",25);
    strncpy(card->primaryAccountNumber,"456789124",20);
    strncpy(card->cardExpirationDate,"12/19",6);

    terminal->MaxTransAmount=MAX_TRANSACTION;
    terminal->transAmount=20.5;
    strncpy(terminal->transactionDate,"27/11/2019",11);

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);

    if(check_transaction(card,terminal))
    {
       printf("\nThe Transaction is Approved\n\n");
    }
    else
    {
       printf("\nThe Transaction is Declined\n\n");
    }
}

void testCase5(void)
{
    ST_cardData_t *card = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    ST_terminalData_t *terminal = (ST_terminalData_t *) malloc(sizeof(ST_terminalData_t));

    strncpy(card->cardHolderName,"Yehia Mohammed",25);
    strncpy(card->primaryAccountNumber,"456789124",20);
    strncpy(card->cardExpirationDate,"12/19",6);

    terminal->MaxTransAmount=MAX_TRANSACTION;
    terminal->transAmount=6000;
    strncpy(terminal->transactionDate,"27/11/2019",11);

    printf("\nCard Data:\nName: %s\nPAN: %s\nDate: %s\n\n",card->cardHolderName,card->primaryAccountNumber,card->cardExpirationDate);
    printf("Terminal Data:\nAmount: %f\nMax Amount: %f\nDate: %s\n\n",terminal->transAmount,terminal->MaxTransAmount,terminal->transactionDate);

    if(check_transaction(card,terminal))
    {
       printf("\nThe Transaction is Approved\n\n");
    }
    else
    {
       printf("\nThe Transaction is Declined\n\n");
    }
}
