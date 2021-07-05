#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_Types.h"
#include "ATM.h"
#include "TestCases.h"


//Normal app
int main()
{
    uint8_t input;
    ST_cardData_t *card;
    ST_terminalData_t *terminal;
    while(1)
    {
        system("cls");
        printf("Enter Card Data:\n");
        card=get_card_data();
        printf("\nEnter Terminal Data:\n");
        terminal=get_terminal_data();

        if(check_transaction(card,terminal))
        {
            printf("\nThe Transaction is Approved\n\n");
        }
        else
        {
            printf("\nThe Transaction is Declined\n\n");
        }

        printf("Do you wish to continue(y/n)?  ");
        fflush(stdin);
        while(input!='y' && input != 'n')
        {
            fflush(stdin);
            scanf("%c",&input);
        }
        input=0;
        free(card);
        free(terminal);
        if (input=='n')
        {
            break;
        }

    }
    return 0;
}



//App for testing
/*int main(void)
{
    testCase1();
    printf("\n===========================================================\n");
    testCase2();
    printf("\n===========================================================\n");
    testCase3();
    printf("\n===========================================================\n");
    testCase4();
    printf("\n===========================================================\n");
    testCase5();
    printf("\n===========================================================\n");
}*/






