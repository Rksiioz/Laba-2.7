#pragma one
#include <string>
#include <iostream>
#include <cmath>

class Money
{
private:
    long banknote;
    unsigned char coin;
public:
    Money();
    Money(double amount);
    const long getBanknote() const;
    const long getCoin() const;
    void init(long banknote, unsigned char coin);
    void init(long long coin);
    void read();
    void display() const;
    std::string toString() const;
    void setBanknote(long banknote);
    void setCoin(unsigned char coin);
    Money add(Money money);
    Money add(int coin);
    Money minus(Money money);
    Money minus(int coin);
    double div(const Money& divider);
    Money div(double divider);
    Money mul(double times);
    bool isEqual(Money money);
    bool isNotEqual(Money money);
    bool isGreatThan(Money money);
    bool isLessThen(Money money);
    bool isGreaterThanOrEqual(Money money);
    bool isLessThanOrEqual(Money money);

    Money operator+(Money money);
    Money operator+(int coin);
    Money operator-(Money money);
    Money operator-(int coin);
    Money operator/(Money divider);
    Money operator/(double divider);
    Money operator*(double times);
    bool operator==(Money money);
    bool operator!=(Money money);
    bool operator>(Money money);
    bool operator<(Money money);
    bool operator>=(Money money);
    bool operator<=(Money money);
};
