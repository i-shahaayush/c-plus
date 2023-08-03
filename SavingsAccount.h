
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;
class SavingsAccount : public BankAccount{
private:
//flag to hold status of account
bool status;
bool ACTIVE;
bool INACTIVE;
public:
//class constructor,That will also call constructor of base class
   /*status (to represent an active or inactive account)
   If the balance of a savings account falls below $25,
   it becomes inactive. (The status member could be a flag variable.)
   No more withdrawals may be made until the balance is raised above $25,
   at which time the account becomes active again.*/
SavingsAccount(double b, double air) :
BankAccount(b, air)
{
//check if balance is greater than 25
//to set correct status
       ACTIVE = true;
       INACTIVE = false;
if(balance >= 25){
status = ACTIVE;
}
//otherwise it must be inactive
else{
status = INACTIVE;
}
}
bool getStatus() { return status; }

/*
   makeWithdrawal: A function that checks to see if the account
   is inactive before a withdrawal is made. (No withdrawal will
   be allowed if the account is not active.) A withdrawal is then
   made by calling the base class version of the function.*/
virtual void makeWithdrawal(double w){
//check if status is active
if(status == ACTIVE){
BankAccount::makeWithdrawal(w);
if(balance < 25)
status = INACTIVE;
}
else{
//otherwise, print error message then return
cout << fixed << setprecision(2);
cout << "Withdrawal failed! "<<endl;
cout << "Your Savings Account is inactive :\nBalance: $";
cout << balance << endl;
}
}
   /*makeDeposit: A function that checks to see if the account is
   inactive before a deposit is made. If the account is inactive and
   the deposit brings the balance above $25, the account becomes active again.
   The deposit is then made by calling the base class version of the function.*/
virtual void makeDeposit(double d){
if(status == INACTIVE){
if(d + balance >= 25){
BankAccount::makeDeposit(d);
}
else{
cout << fixed << setprecision(2);
cout << "Deposit failed! Savings account will";
cout << " be inactive after deposit!\n($";
cout << balance << " + $" << d;
cout << " = $" << balance + d << ")\n";
return;
}

}
else{
BankAccount::makeDeposit(d);
}
}
   /*
       monthlyProc: Before the base class function is called,
       this function checks the number of withdrawals.
       If the number of withdrawals for the month is more than 4,
       a service charge of $1 for each withdrawal above 4
       is added to the base class variable that holds the monthly service charges.
       (Don’t forget to check the account balance after the service charge is taken.
       If the balance falls below $25, the account becomes inactive.)
   */
  
virtual ServiceAndOwed monthlyProc(){
  
if(numWithdrawal > 4){
serviceCharges += 1.0 * (numWithdrawal - 4);
           mnCharges += serviceCharges;
}
ServiceAndOwed temp;
temp.servCharges = serviceCharges;
temp.totalOwed = 0.0;
BankAccount::monthlyProc();
if(balance < 25){
status = INACTIVE;
}
return temp;
}
};


#endif
