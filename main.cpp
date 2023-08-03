
#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "BankAccount.h"
using namespace std;
int main()
{
double startingBalance;
double annualRate;
SavingsAccount savAcc(startingBalance, annualRate);
CheckingAccount checkAcc(startingBalance, annualRate);

double initProcessCharges;
double depos = 0, withdr = 0;
double totalDepos = 0, totalWithdr = 0;
ServiceAndOwed temp = savAcc.monthlyProc();
int choice;
int account_type;
int Option;
cout << "\t\t\t\t\tWELL FARGOS BANK\n\n";
cout << "\t\t\t\t     420 Montgomery Street\n\n";
cout << "\t\t\t\t    San Francisco, CA 94104\n\n\n\n";

cout<<"Do you want to save and make your financial future secure? Come to us and we will let you want fulfilled with different saving accounts and checking accounts. We provide attractive interest rate and ensure security of your saving from hard work. You can open any WFB Saving Account by visiting any of our branch or online and be assured of wonderful banking services along with personal and digital touch. \n\n";

LOOP:do{
cout<<"Choose Account Type:\n\n \t1.Saving Account\n\t2.Current Account\n\n";
cout<<"Enter your Choice: ";
cin>>account_type;
if (account_type==1){
    cout << "\t\t\t\t\tSAVINGS ACCOUNT\n";
cout<<"\t\t\t\t\t***************\n\n";
cout<<"\t How To Apply?\n";
cout<<"\t _____________\n";
do{
cout<<"\nSelect an Option Below:";
cout << "\n\t1 Create an Account";
cout << "\n\t2 set value of monthly processing charges";
cout << "\n\t3 Deposit";
cout << "\n\t4 Withdrawal";
cout<<"\n\t5 Display Statistics";
cout<<"\n\t6 Quit\n";
cout << "\nEnter your choice: ";
cin>>choice;
if (choice==1){
    //create a savings account
cout << "Enter starting balance of Savings Account: $";
cin >> startingBalance;
annualRate=11.67;
cout << "Annual Interest Rate set by Bank is "<<annualRate<<" % ";
annualRate = annualRate/100;
cout << "\nCreating Savings Account with this data giving annual interest rate 11.67%  ";
SavingsAccount savAcc(startingBalance, annualRate);
cout << "Done!.....\n";}

//set value of monthly processing charges and set it
else if  (choice==2){
//set value of monthly processing charges and set it
cout << "The monthly processing charges set by bank: $";
cin>>initProcessCharges;
checkAcc.setMonthlyCharges(initProcessCharges);

}

//get all the monthly deposits
else if(choice==3){
cout << "\nEnter the deposits one by one. When finished,";
cout << " enter -1:" << endl;

cin >> depos;

while(depos != -1){
//add deposit to total
totalDepos += depos;

cout << fixed << setprecision(2);
cout << "Performing deposit...\n";
savAcc.makeDeposit(depos);
cout << "Done!\n";

//display data of savings account
cout << "\nBalance: $" << savAcc.getBalance();
cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();

cout << "\n\nEnter another deposit amount, or -1 to stop: ";
cin >> depos;
}
}

else if(choice==4){
//use the same method to take all the monthly withdrawals
cout << "\nEnter the withdrawals one by one. When finished,";
cout << " enter -1:" << endl;

cin >> withdr;

while(withdr != -1){
//add withdrawal to total
totalWithdr += withdr;

cout << fixed << setprecision(2);
cout << "Performing withdrawal...\n";
savAcc.makeWithdrawal(withdr);
cout << "Done!\n";

//display data of savings account
cout << "\nBalance: $" << savAcc.getBalance();
cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();

cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
cin >> withdr;
}
}
else if (choice==5){
//display statistics
cout << "\nDone! Here are the monthly statistics: ";
cout << "\nBeginning balance: $" << startingBalance;
cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
cout << "\nTotal amount of deposits: $" << totalDepos;
cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();
cout << "\nTotal amount of withdrawals: $" << totalWithdr;
cout << "\nMonthly charges: $" << initProcessCharges;

//get the service charges in a structure
//and perform monthly processing
ServiceAndOwed temp = savAcc.monthlyProc();

cout << "\nService fees: $" << temp.servCharges;
cout << "\nTotal monthly charges: $" << initProcessCharges + temp.servCharges;

//display ending balance
cout << "\nEnding balance: $" << savAcc.getBalance();}

else if (choice==6){
    goto LOOP;
}
}
while (choice!=7);
}
else if (account_type==2){
     cout << "\t\t\t\t\tCURRENT ACCOUNT\n";
cout<<"\t\t\t\t\t***************\n\n";
cout<<"\t How To Apply?\n";
cout<<"\t _____________\n";
do{
cout<<"\nSelect an Option Below:";
cout << "\n\t1 Create an Account";
cout << "\n\t2 set value of monthly processing charges";
cout << "\n\t3 Deposit";
cout << "\n\t4 Withdrawal";
cout<<"\n\t5 Display Statistics";
cout<<"\n\t6 Quit\n";
cout << "\nEnter your Option: ";
cin>>Option;

//---------------------------------------------------------
//now do the same thing for a current account
//---------------------------------------------------------
if (Option==1){
cout << "\n\n\nCURRENT ACCOUNT\n\n";

cout << "Enter starting balance of Current Account: $";
cin >> startingBalance;

annualRate=6.67;
cout << "Annual Interest Rate set by Bank is "<<annualRate<<" % ";
//update interest rate to be
//correct value because it is in %
annualRate = annualRate/100;

//create a current account object
cout << "\nCreating Current Account with this data...";
CheckingAccount checkAcc(startingBalance, annualRate);
cout << "Done!\n";}
else if (Option==2){

//set value of monthly processing charges and set it
cout << "Enter monthly processing charges: $";
cin >> initProcessCharges;
checkAcc.setMonthlyCharges(initProcessCharges);

//remember, you can only withdraw from this
//checking account
withdr = 0;
totalWithdr = 0;}

//get all the monthly deposits
else if(Option==3){
cout << "\nEnter the deposits one by one. When finished,";
cout << " enter -1:" << endl;

cin >> depos;

while(depos != -1){
//add deposit to total
totalDepos += depos;

cout << fixed << setprecision(2);
cout << "Performing deposit...\n";
savAcc.makeDeposit(depos);
cout << "Done!\n";

//display data of savings account
cout << "\nBalance: $" << savAcc.getBalance();
cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();

cout << "\n\nEnter another deposit amount, or -1 to stop: ";
cin >> depos;
}
}


else if (Option==4){
//get the withdrawals with the same method
cout << "\nEnter the withdrawals one by one. When finished,";
cout << " enter -1:\n";

cin >> withdr;

while(withdr != -1){
//add withdrawal to total
totalWithdr += withdr;

cout << fixed << setprecision(2);
cout << "Performing deposit...\n";
checkAcc.makeWithdrawal(withdr);
cout << "Done!\n";

//display data of current account
cout << "\nBalance: $" << checkAcc.getBalance();
cout << "\nNumber of deposits: " << checkAcc.getNumDeposits();
cout << "\nNumber of withdrawals: " << checkAcc.getNumWithdrawals();

cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
cin >> withdr;
}
}
else if(Option==5){
//display statistics
cout << "Done! Here are the monthly statistics: ";
cout << "\nBeginning balance: $" << startingBalance;
cout << "\nNumber of withdrawals: $" << checkAcc.getNumWithdrawals();
cout << "\nTotal amount of withdrawals: $" << totalWithdr;
cout << "\nInitial monthly charges: $" << initProcessCharges;

//get the service charges and owed amount
//in the structure and perform monthly processing
temp = checkAcc.monthlyProc();

cout << "\nService fees: $" << temp.servCharges;
cout << "\nTotal monthly charges: $" << initProcessCharges + temp.servCharges;
cout << "\nEnding balance: $" << checkAcc.getBalance();
cout << "\nClient owes to bank: $" << checkAcc.getAmountOwed();
cout << endl;}

else if (choice==6){
    goto LOOP;
}}
while (choice!=7);
}
} while (account_type!=2);
return 0;
}