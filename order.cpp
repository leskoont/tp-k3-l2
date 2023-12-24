// ORDER.cpp
#include "ORDER.h"

ORDER::ORDER() : payerAccount(nullptr), payeeAccount(nullptr), amount(0.0) {
    std::cout << "Default constructor called." << std::endl;
}

ORDER::ORDER(const char* payer, const char* payee, double amt) : amount(amt) {
    payerAccount = new char[strlen(payer) + 1];
    strcpy_s(payerAccount, strlen(payer) + 1, payer);

    payeeAccount = new char[strlen(payee) + 1];
    strcpy_s(payeeAccount, strlen(payee) + 1, payee);

    std::cout << "Parameterized constructor called." << std::endl;
}

ORDER::ORDER(const ORDER& other) : amount(other.amount) {
    payerAccount = new char[strlen(other.payerAccount) + 1];
    strcpy_s(payerAccount, strlen(other.payerAccount) + 1, other.payerAccount);

    payeeAccount = new char[strlen(other.payeeAccount) + 1];
    strcpy_s(payeeAccount, strlen(other.payeeAccount) + 1, other.payeeAccount);

    std::cout << "Copy constructor called." << std::endl;
}

ORDER::~ORDER() {
    delete[] payerAccount;
    delete[] payeeAccount;
    std::cout << "Destructor called." << std::endl;
}

const char* ORDER::getPayerAccount() const {
    return payerAccount;
}

const char* ORDER::getPayeeAccount() const {
    return payeeAccount;
}

double ORDER::getAmount() const {
    return amount;
}

void ORDER::setPayerAccount(const char* payer) {
    delete[] payerAccount;
    payerAccount = new char[strlen(payer) + 1];
    strcpy_s(payerAccount, strlen(payer) + 1, payer);
}

void ORDER::setPayeeAccount(const char* payee) {
    delete[] payeeAccount;
    payeeAccount = new char[strlen(payee) + 1];
    strcpy_s(payeeAccount, strlen(payee) + 1, payee);
}

void ORDER::setAmount(double amt) {
    amount = amt;
}

std::ostream& operator<<(std::ostream& os, const ORDER& order) {
    os << "Payer Account: " << order.payerAccount << "\n";
    os << "Payee Account: " << order.payeeAccount << "\n";
    os << "Amount: " << order.amount << " rubles\n";
    return os;
}

std::istream& operator>>(std::istream& is, ORDER& order) {
    char buffer[100];
    double amt;

    std::cout << "Enter payer account: ";
    is >> buffer;
    order.setPayerAccount(buffer);

    std::cout << "Enter payee account: ";
    is >> buffer;
    order.setPayeeAccount(buffer);

    std::cout << "Enter amount: ";
    is >> amt;
    order.setAmount(amt);

    return is;
}
