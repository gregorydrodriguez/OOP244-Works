/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
class Account {
    int m_number;
    double m_balance;
    void setEmpty();

   public:
    Account();
    Account(int number, double balance);
    std::ostream& display() const;
    operator bool() const;
    operator int() const;
    operator double() const;
    bool operator~() const;
    Account& operator=(int setAccount);
    Account& operator=(Account& account);
    Account& operator+=(double deposit);
    Account& operator-=(double withdrawal);
    Account& operator<<(Account& account);
    Account& operator>>(Account& account);
};

double operator+(const Account& account, const Account& account2);
double operator+=(double& balance, const Account& account);

}  // namespace sdds
#endif  // SDDS_ACCOUNT_H_