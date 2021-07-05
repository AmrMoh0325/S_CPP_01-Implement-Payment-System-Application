#ifndef ATM_H_
#define ATM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_Types.h"

#define MAX_TRANSACTION      5000
typedef struct{

    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];

}ST_cardData_t;

typedef struct{

    float transAmount;
    float MaxTransAmount;
    uint8_t transactionDate[11];

}ST_terminalData_t;

typedef struct{
    float Balance;
    uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

//gets credit card related data
ST_cardData_t *get_card_data(void);

//gets terminal related data
ST_cardData_t *get_terminal_data(void);

//performs terminal related checks
uint8_t Terminal_check(ST_cardData_t *card, ST_terminalData_t *terminal);

//performs server related checks
uint8_t Server_check(ST_cardData_t *card, ST_terminalData_t *terminal);

//performs all checks on the trasnsaction
uint8_t check_transaction(ST_cardData_t *card,ST_terminalData_t *terminal);


/************************************************************************************/
//scans a string from the user
void scan_string(uint8_t *buffer,uint32_t max_size);


#endif // ATM_H_




