#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <cstring>

class ORDER {
private:
    char* payerAccount;
    char* payeeAccount;
    double amount;

public:
    // ������������ � ����������
    ORDER();
    ORDER(const char* payer, const char* payee, double amt);
    ORDER(const ORDER& other);
    ~ORDER();

    // ������ �������
    const char* getPayerAccount() const;
    const char* getPayeeAccount() const;
    double getAmount() const;

    void setPayerAccount(const char* payer);
    void setPayeeAccount(const char* payee);
    void setAmount(double amt);

    // ������������� �������� ���������� � �������
    friend std::ostream& operator<<(std::ostream& os, const ORDER& order);
    friend std::istream& operator>>(std::istream& is, ORDER& order);
};

#endif // ORDER_H
