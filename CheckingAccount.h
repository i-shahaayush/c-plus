#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

class CheckingAccount : public BankAccount
{
private:
double owed;

public:
CheckingAccount(double b, double air) :
BankAccount(b, air)
{
owed = 0.0;
}

//accessor function
double getAmountOwed() const{
return owed;
}

/*
   makeWithdrawal: Before the base class function is called,
   this function will determine if a withdrawal (a check written) will cause
   the balance to go below $0. If the balance goes below $0, a service charge
   of $15 will be taken from the account. (The withdrawal will not be made.)
   If there isn’t enough in the account to pay the service charge, the balance
   will become negative and the customer will owe the negative amount to the bank.
   */
virtual void makeWithdrawal(double w){
  
if(w > balance){
  
cout << fixed << setprecision(2);
cout << "Withdrawal failed! \n";
cout << "Your Checking Account is :\nBalance: $";
cout << balance << endl;
balance -= 15.0;
}
else
BankAccount::makeWithdrawal(w);
  
}
   /*
monthlyProc: Before the base class function is called,
   this function adds the monthly fee of $5 plus $0.10 per
   withdrawal (check written) to the base class variable that
   holds the monthly service charges.
   */
virtual ServiceAndOwed monthlyProc(){
serviceCharges += 5.0;
serviceCharges += 0.1 * numWithdrawal;
mnCharges += serviceCharges;
ServiceAndOwed temp;
temp.servCharges = serviceCharges;
BankAccount::monthlyProc();
if(balance < 0)
owed = 0 - balance;
temp.totalOwed = owed;
owed = 0;
return temp;
}
};
#endif
