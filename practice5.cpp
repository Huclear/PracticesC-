#include <iostream>

bool transferMoney(Account& from, Account& to, double amount);

class Account {
    friend bool transferMoney(Account& from, Account& to, double amount);
private:
    int accountNumber;
    double balance;
    double interestRate;
public:
    Account(int _accountNumber, double _balance, double _interestRate) {
        this->accountNumber = _accountNumber;
        this->balance = _balance;
        this->interestRate = _interestRate;
    }
    void deposit(double addSumm) {
        this->balance += addSumm;
    }
    bool takeFromBalance(double amount) {
        if (amount > this->balance)return false;
        this->balance -= amount;
        return true;
    }

    double withDrawAll() {
        double currentBalance = this->balance;
        this->balance = 0;
        return currentBalance;
    }
    double getBalance() {
        this->balance = balance + balance * interestRate / 12;
        return this->balance;
    }
    double getInterest() {
        return balance * interestRate / 12;
    }
    double getAccountNum() {
        return this->accountNumber;
    }
    void setInterestRate(double newInterest) {
        this->interestRate = newInterest;
    }
};


int main()
{
    Account* acc1 = new Account(1, 1000, 5);
    Account* acc2 = new Account(2, 1000, 6);
    transferMoney(*acc1, *acc2, 100);
    acc1->getBalance();
}

bool transferMoney(Account& from, Account& to, double amount) {
    try
    {
        if (from.takeFromBalance(amount)) {
            to.deposit(amount);
            return true;
        }
        return false;
    }
    catch (const std::exception&)
    {
        return false;
    }
}