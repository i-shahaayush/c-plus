#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;
//to return Service Charge and Total amount by monthlyProc we define
//the following structure
struct ServiceAndOwed{
double servCharges;
double totalOwed;
};
class BankAccount{
//member variables
protected:
double balance;
int numDeposits;
int numWithdrawal;
double annualIntRate;
double mnCharges;
double serviceCharges;
public:

//constructor to accept balance and annual interest rate
BankAccount(double mybalance, double air){
//check for invalid input
if(mybalance < 0){
cout << "Error! Balance cannot start with";
cout << " a negative amount!\n";
cout << "Now terminating!\n";
exit(0);
}
if(air < 0){
cout << "Error! Annual interest rate";
cout << " cannot be negative!\n";
cout << "Now terminating!\n";
exit(0);
}

//set balance and annual interest rate
//to argumented values
balance = mybalance;
annualIntRate = air;
       //set the other variable to 0
numDeposits = 0;
numWithdrawal = 0;
mnCharges = 0.0;
serviceCharges = 0.0;
}

//accessor functions
double getBalance()
{ return balance;
}
int getNumDeposits() 
{return numDeposits; 
}
int getNumWithdrawals()
{return numWithdrawal; 
}
double getAnnualIntRate() 
{return annualIntRate; 
}
double getMonthlyCharges() 
{
    return mnCharges; }

//mutator functions
void setAnnualIntRate(double air){
//validate input using while loop
while(air < 0){
cout << "Negative values for annual interest ";
cout << "rates not accepted! Enter again: ";
cin >> air;
}
annualIntRate = air;
}

void setMonthlyCharges(double mc){
//validate input using while loop
while(mc < 0){
cout << "Negative values for monthly charges ";
cout << "are not accepted! Enter again: ";
cin >> mc;
}
mnCharges = mc;
}
/*
   makeDeposit: A virtual function that accepts an argument for the amount of the deposit.
   The function should add the argument to the account balance. It should also increment
   the variable holding the number of deposits.
   */
virtual void makeDeposit(double d){
balance += d;
numDeposits++;
}
//makeWithdrawal: A virtual function that accepts an argument for the amount of the withdrawal. The function should subtract the argument from the balance. It should also increment the variable holding the number of withdrawals./
virtual void makeWithdrawal(double w){
balance -= w;
       numWithdrawal++;
}
/*
   calcInt: A virtual function that updates the balance by calculating the monthly interest earned by the account, and adding this interest to the balance. This is performed by the following formulas:
   Monthly Interest Rate = (Annual Interest Rate / 12)
   Monthly Interest = Balance * Monthly Interest Rate
   Balance = Balance + Monthly Interest
   */
virtual void calcInt(){
balance += (annualIntRate/12.0)*balance;
}
/*
monthlyProc(): A virtual function that subtracts the monthly service charges from the balance,
calls the calcInt function, and then sets the variables that hold the number of withdrawals,
number of deposits, and monthly service charges to zero.
*/
virtual ServiceAndOwed monthlyProc(){
balance -= mnCharges;
       calcInt();
numDeposits = 0;
numWithdrawal = 0;
mnCharges = 0.0;
serviceCharges = 0.0;
ServiceAndOwed temp;
return temp;
}
};
#endif