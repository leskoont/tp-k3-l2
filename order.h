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
    // Конструкторы и деструктор
    ORDER();
    ORDER(const char* payer, const char* payee, double amt);
    ORDER(const ORDER& other);
    ~ORDER();

    // Методы доступа
    const char* getPayerAccount() const;
    const char* getPayeeAccount() const;
    double getAmount() const;

    void setPayerAccount(const char* payer);
    void setPayeeAccount(const char* payee);
    void setAmount(double amt);

    // Перегруженные операции извлечения и вставки
    friend std::ostream& operator<<(std::ostream& os, const ORDER& order);
    friend std::istream& operator>>(std::istream& is, ORDER& order);
};

#endif // ORDER_H
