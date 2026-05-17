#include <stdio.h>
#include <stdlib.h>

// clientData structure definition
struct clientData
{
    unsigned int acctNum; // account number
    unsigned int pin;     // NEW FEATURE: account security PIN
    char lastName[15];    // account last name
    char firstName[10];   // account first name
    double balance;       // account balance
};                        // end structure clientData

// prototypes
unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
<<<<<<< HEAD
void displayAllRecords(FILE *fPtr); 
void viewRecord(FILE *fPtr);        
void changePin(FILE *fPtr);         // NEW FEATURE: Change PIN
=======
void displayAllRecords(FILE *fPtr); // NEW: Display all accounts to console
void viewRecord(FILE *fPtr);        // NEW: View a single account's details
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

int main(int argc, char *argv[])
{
    FILE *cfPtr;         // credit.dat file pointer
    unsigned int choice; // user's choice

    // Attempt to open the file for read/update. 
<<<<<<< HEAD
=======
    // If it doesn't exist, create it using "wb+"
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
    if ((cfPtr = fopen("credit.dat", "rb+")) == NULL)
    {
        if ((cfPtr = fopen("credit.dat", "wb+")) == NULL)
        {
            printf("%s: File could not be opened or created.\n", argv[0]);
            exit(-1);
        }
    }

    // enable user to specify action
<<<<<<< HEAD
    while ((choice = enterChoice()) != 8) // Updated exit condition to 8
    {
        switch (choice)
        {
        case 1: textFile(cfPtr); break;
        case 2: updateRecord(cfPtr); break;
        case 3: newRecord(cfPtr); break;
        case 4: deleteRecord(cfPtr); break;
        case 5: displayAllRecords(cfPtr); break;
        case 6: viewRecord(cfPtr); break;
        case 7: changePin(cfPtr); break; // NEW: Change PIN
        default: puts("Incorrect choice"); break;
        } 
    }     

    fclose(cfPtr); 
    return 0;      
} 
=======
    while ((choice = enterChoice()) != 7) // Updated exit condition to 7
    {
        switch (choice)
        {
        // create text file from record file
        case 1:
            textFile(cfPtr);
            break;
        // update record
        case 2:
            updateRecord(cfPtr);
            break;
        // create record
        case 3:
            newRecord(cfPtr);
            break;
        // delete existing record
        case 4:
            deleteRecord(cfPtr);
            break;
        // display all records to console
        case 5:
            displayAllRecords(cfPtr);
            break;
        // view specific record
        case 6:
            viewRecord(cfPtr);
            break;
        // display if user does not select valid choice
        default:
            puts("Incorrect choice");
            break;
        } // end switch
    }     // end while

    fclose(cfPtr); // fclose closes the file
    return 0;      // added return statement
} // end main
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

// create formatted text file for printing
void textFile(FILE *readPtr)
{
<<<<<<< HEAD
    FILE *writePtr; 
    struct clientData client = {0, 0, "", "", 0.0}; // Updated default init
=======
    FILE *writePtr; // accounts.txt file pointer
    
    // create clientData with default information
    struct clientData client = {0, "", "", 0.0};
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    if ((writePtr = fopen("accounts.txt", "w")) == NULL)
    {
        puts("File could not be opened.");
    } 
    else
    {
        rewind(readPtr); 
        fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

<<<<<<< HEAD
        while (fread(&client, sizeof(struct clientData), 1, readPtr) == 1)
        {
            if (client.acctNum != 0)
            {
                // Note: We deliberately do NOT print the PIN to the text file for security
                fprintf(writePtr, "%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
            } 
        }     

        fclose(writePtr); 
        puts("Exported successfully to accounts.txt");
    }                     
} 
=======
        // copy all records from random-access file into text file
        // BUG FIX: checking fread directly prevents duplicate last-line printing
        while (fread(&client, sizeof(struct clientData), 1, readPtr) == 1)
        {
            // write single record to text file
            if (client.acctNum != 0)
            {
                fprintf(writePtr, "%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
            } // end if
        }     // end while

        fclose(writePtr); // fclose closes the file
        puts("Exported successfully to accounts.txt");
    }                     // end else
} // end function textFile
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

// update balance in record
void updateRecord(FILE *fPtr)
{
<<<<<<< HEAD
    unsigned int account; 
    double transaction;   
    struct clientData client = {0, 0, "", "", 0.0};
=======
    unsigned int account; // account number
    double transaction;   // transaction amount
    
    // create clientData with no information
    struct clientData client = {0, "", "", 0.0};
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    printf("%s", "Enter account to update ( 1 - 100 ): ");
<<<<<<< HEAD
    scanf("%u", &account); 
=======
    scanf("%u", &account); // BUG FIX: %u for unsigned int
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
<<<<<<< HEAD
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
=======
    
    // read record from file
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // display error if account does not exist
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
    if (client.acctNum == 0)
    {
        printf("Account #%u has no information.\n", account);
    }
    else
<<<<<<< HEAD
    { 
=======
    { // update record
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
        printf("%-6u%-16s%-11s%10.2f\n\n", client.acctNum, client.lastName, client.firstName, client.balance);

        printf("%s", "Enter charge ( + ) or payment ( - ): ");
        scanf("%lf", &transaction);
        client.balance += transaction; 

        printf("%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);

<<<<<<< HEAD
        fseek(fPtr, -(long)sizeof(struct clientData), SEEK_CUR); 
=======
        // move file pointer to correct record in file
        // move back by 1 record length
        // BUG FIX: cast sizeof to (long) before negating
        fseek(fPtr, -(long)sizeof(struct clientData), SEEK_CUR); 
        
        // write updated record over old record in file
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
        puts("Balance updated successfully.");
    } 
} 

// delete an existing record
void deleteRecord(FILE *fPtr)
{
<<<<<<< HEAD
    struct clientData client;                      
    struct clientData blankClient = {0, 0, "", "", 0.0}; 
    unsigned int accountNum;                       
=======
    struct clientData client;                      // stores record read from file
    struct clientData blankClient = {0, "", "", 0}; // blank client
    unsigned int accountNum;                       // account number
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    printf("%s", "Enter account number to delete ( 1 - 100 ): ");
<<<<<<< HEAD
    scanf("%u", &accountNum); 
=======
    scanf("%u", &accountNum); // BUG FIX: %u for unsigned int
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
<<<<<<< HEAD
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    if (client.acctNum == 0)
    {
        printf("Account %u does not exist.\n", accountNum);
    } 
=======
    
    // read record from file
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // display error if record does not exist
    if (client.acctNum == 0)
    {
        printf("Account %u does not exist.\n", accountNum);
    } // end if
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
    else
    { 
        fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
        printf("Account %u deleted successfully.\n", accountNum);
<<<<<<< HEAD
    } 
} 
=======
    } // end else
} // end function deleteRecord
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

// create and insert record
void newRecord(FILE *fPtr)
{
    struct clientData client = {0, 0, "", "", 0.0};
    unsigned int accountNum; 

    printf("%s", "Enter new account number ( 1 - 100 ): ");
<<<<<<< HEAD
    scanf("%u", &accountNum); 
=======
    scanf("%u", &accountNum); // BUG FIX: %u for unsigned int
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
<<<<<<< HEAD
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    if (client.acctNum != 0)
    {
        printf("Account #%u already contains information.\n", client.acctNum);
    } 
=======
    
    // read record from file
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // display error if account already exists
    if (client.acctNum != 0)
    {
        printf("Account #%u already contains information.\n", client.acctNum);
    } // end if
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
    else
    { 
        // NEW: Prompts user to create a PIN along with other info
        printf("%s", "Enter lastname, firstname, balance, and a 4-digit PIN\n? ");
        scanf("%14s%9s%lf%u", client.lastName, client.firstName, &client.balance, &client.pin);

        client.acctNum = accountNum;
        
<<<<<<< HEAD
=======
        // move file pointer to correct record in file
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
        fseek(fPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
        printf("Account %u created successfully.\n", accountNum);
<<<<<<< HEAD
    } 
} 

// display all active records to the console
void displayAllRecords(FILE *fPtr)
{
    struct clientData client = {0, 0, "", "", 0.0};

    rewind(fPtr); 

    printf("\n%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
    printf("---------------------------------------------\n");

    while (fread(&client, sizeof(struct clientData), 1, fPtr) == 1)
    {
        if (client.acctNum != 0)
        {
            printf("%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        }
    }
    printf("---------------------------------------------\n");
} 

// view details of a specific record
void viewRecord(FILE *fPtr)
{
    struct clientData client = {0, 0, "", "", 0.0};
    unsigned int accountNum;

    printf("%s", "Enter account number to view ( 1 - 100 ): ");
    scanf("%u", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    if (client.acctNum == 0)
    {
        printf("Account #%u has no information.\n", accountNum);
    }
    else
    {
        printf("\n%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
        printf("---------------------------------------------\n");
        printf("%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        printf("---------------------------------------------\n");
    }
} 

// NEW FEATURE: change the PIN of an existing account securely
void changePin(FILE *fPtr)
{
    struct clientData client = {0, 0, "", "", 0.0};
    unsigned int accountNum, inputPin, newPin;

    printf("Enter account number for PIN change ( 1 - 100 ): ");
    scanf("%u", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    if (client.acctNum == 0)
    {
        printf("Account %u does not exist.\n", accountNum);
    }
    else
    {
        // Authenticate user before allowing PIN change
        printf("Enter your current PIN: ");
        scanf("%u", &inputPin);

        if (inputPin == client.pin) 
        {
            printf("Authentication successful. Enter new 4-digit PIN: ");
            scanf("%u", &newPin);
            
            client.pin = newPin;

            // Move pointer back and overwrite the record
            fseek(fPtr, -(long)sizeof(struct clientData), SEEK_CUR); 
            fwrite(&client, sizeof(struct clientData), 1, fPtr);
            
            printf("PIN for account %u updated successfully.\n", accountNum);
        }
        else 
        {
            printf("Authentication failed. Incorrect PIN.\n");
        }
    }
}
=======
    } // end else
} // end function newRecord
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

// NEW FEATURE: display all active records to the console
void displayAllRecords(FILE *fPtr)
{
    struct clientData client = {0, "", "", 0.0};

    rewind(fPtr); // start from beginning of file

    printf("\n%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
    printf("---------------------------------------------\n");

    // read through entire file
    while (fread(&client, sizeof(struct clientData), 1, fPtr) == 1)
    {
        // display record if it exists
        if (client.acctNum != 0)
        {
            printf("%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        }
    }
    printf("---------------------------------------------\n");
} // end function displayAllRecords

// NEW FEATURE: view details of a specific record
void viewRecord(FILE *fPtr)
{
    struct clientData client = {0, "", "", 0.0};
    unsigned int accountNum;

    // obtain number of account to view
    printf("%s", "Enter account number to view ( 1 - 100 ): ");
    scanf("%u", &accountNum);

    // move file pointer to correct record in file
    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    
    // read record from file
    fread(&client, sizeof(struct clientData), 1, fPtr);
    
    // display error if record does not exist
    if (client.acctNum == 0)
    {
        printf("Account #%u has no information.\n", accountNum);
    }
    else
    {
        // display the specific record
        printf("\n%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
        printf("---------------------------------------------\n");
        printf("%-6u%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
        printf("---------------------------------------------\n");
    }
} // end function viewRecord

// enable user to input menu choice
unsigned int enterChoice(void)
{
    unsigned int menuChoice; 
    printf("%s", "\nEnter your choice\n"
                 "1 - store a formatted text file of accounts called\n"
                 "    \"accounts.txt\" for printing\n"
                 "2 - update an account\n"
                 "3 - add a new account\n"
                 "4 - delete an account\n"
                 "5 - display all active accounts to console\n"
                 "6 - view a specific account\n"
<<<<<<< HEAD
                 "7 - change account PIN\n"
                 "8 - end program\n? ");
=======
                 "7 - end program\n? ");
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed

    scanf("%u", &menuChoice); 
    return menuChoice;
<<<<<<< HEAD
}
=======
} // end function enterChoice
>>>>>>> dd4931f254265616bb1d84a0c288964ed561e1ed
