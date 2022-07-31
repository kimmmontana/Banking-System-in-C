//Kim M. Montana | BSCS 1-1 | Structure-BankTransaction
#include <stdio.h>
#include <conio.h>

//Declarations
int acc_num, trans_num;
void DisplaySelectAccount();
void DisplayTransaction();
void DisplayDatabase();
int Bal_Inquiry(int acc_numB);
int Deposit(int acc_numD);
int Withdrawal(int acc_numW);
struct bankaccounts
{
    int cardnum;
    char name[80];
    float bal;
};
//initialization of entities
struct bankaccounts clients[5] = {
    {20221, "Leni Robredo", 25000.00},
    {20222, "Isko Moreno", 25000.00},
    {20223, "Manny Pacquiao", 25000.00},
    {20224, "Ping Lacson", 25000.00},
    {20225, "Bongbong Marcos", 25000.00}};

//main function
int main()
{
    system("cls");
    int i;
    start:; 
    DisplaySelectAccount(); //displays select account
    printf("Enter (number) to proceed:");
    scanf("%d", &acc_num); //inputs selected account
    if(acc_num == 6){
    system("cls");
    goto end;};

    
    system("cls");
    
    DisplayTransaction();  //displays transaction operation
    printf("Enter (number) to proceed:");
    scanf("%d", &trans_num); //imputs intended transaction
    
    system("cls");

    switch (trans_num)  //checks the value of trans_num
    {
    case 1: 
        
        if(Bal_Inquiry(acc_num)!= 0)
        goto start;
        break;
    case 2:
    
        if(Deposit(acc_num)!= 0)
        goto start;
        break;
    case 3:
        
        if(Withdrawal(acc_num)!= 0)
        goto start;
        break;
    
    };
    end:;
    printf("Thank you for using STARBANK...\n");
    
    DisplayDatabase();

    printf("\nSource Code by: Kim M. Montana\nYear and Section: BSCS 1-1");

getch();

return 0;
}
//functions
void DisplaySelectAccount()
{
    int i;
    printf("-----------------------SELECT ACCOUNT---------------------------\n");
    printf("Welcome to STARBANK ATM!\n");
    printf("Hello user, please select your card number that is shown below:\n");
    for(i=0;i<5;i++)
    {
        printf("\n(%d) %d\n", i+1, clients[i].cardnum);
    }
    printf("\n(6) Exit\n");
    printf("----------------------------------------------------------------\n");
}

void DisplayTransaction()
{
    printf("-----------------------STARBANK TRASACTIONS----------------\n");
    printf("Now, please select a type of transactions you wanted to do:\n");
    printf("\n(1) BALANCE INQUIRY\n\n(2) DEPOSIT\n\n(3) WITHDRAWAL\n");
    printf("-----------------------------------------------------------\n");
}

void DisplayDatabase()
{
    FILE *fpv;
    fpv = fopen("./BankDatabase.txt","w");
    fprintf(fpv,"-----------------------STARBANK DATABASE------------------------------\n");
    int i;
    fprintf(fpv,"\n\tCARD NUMBER\tNAME\t\t\tBALANCE\n\n");
    for(i=0;i<5;i++)
    {
        fprintf(fpv,"\t%d\t\t%s\t\tP %.2f\n\n", clients[i].cardnum, clients[i].name, clients[i].bal);
    };
    fprintf(fpv,"----------------------------------------------------------------------");
    fclose(fpv);
}
int Bal_Inquiry(int acc_numB)
{
int ans;
printf("-----------------------BALANCE INQUIRY-------------------------\n");
printf("CARD NUMBER: %d\n", clients[acc_numB -1].cardnum);
printf("NAME: %s\n", clients[acc_numB -1].name);
printf("\nBALANCE INQUIRY: P %.2f",clients[acc_numB -1].bal);
printf("\n-------------------------------------------------------------\n");
printf("Would you like to do another transaction? (1)Yes (0)No : ");
scanf("%d", &ans);
system("cls");
return ans;
};

int Deposit(int acc_numD)
{
int ans;
float deposit_amt;
printf("-----------------------DEPOSIT-------------------------\n");
printf("CARD NUMBER: %d\n", clients[acc_numD -1].cardnum);
printf("NAME: %s\n", clients[acc_numD -1].name);
printf("\nCURRENT BALANCE: P %.2f",clients[acc_numD -1].bal);
printf("\nPlease enter amount you want to deposit: ");
scanf("%f", &deposit_amt);
clients[acc_numD-1].bal += deposit_amt; // process
printf("\n(Kindly insert your cash below...)\n");
printf("\nNEW BALANCE: P %.2f",clients[acc_numD -1].bal);
printf("\n------------------------------------------------------\n");
printf("Would you like to do another transaction? (1)Yes (0)No : ");
scanf("%d", &ans);
system("cls");
return ans;
};

int Withdrawal(int acc_numW)
{
int ans;
float withdrawal_amt;
printf("-----------------------WITHDRAWAL-------------------------\n");
printf("CARD NUMBER: %d\n", clients[acc_numW -1].cardnum);
printf("NAME: %s\n", clients[acc_numW -1].name);
printf("\nCURRENT BALANCE: P %.2f",clients[acc_numW -1].bal);
r:printf("\nPlease enter amount you want to withdraw: ");
scanf("%f", &withdrawal_amt);
if(clients[acc_numW-1].bal >= withdrawal_amt) //checks if balance is greater than withdraw value
{
    clients[acc_numW-1].bal -= withdrawal_amt; // process
    printf("\nNEW BALANCE: P %.2f",clients[acc_numW -1].bal);
    printf("\nKindly get your cash below...");
    printf("\n------------------------------------------------------\n");
    printf("Would you like to do another transaction? (1)Yes (0)No : ");
    scanf("%d", &ans);
    system("cls");
    return ans;
}
else
    {printf("\ninsufficient balance.");
    goto r;}
};