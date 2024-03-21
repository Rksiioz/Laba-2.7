
#include "Money.h"

Money::Money()
{
    this->init(0, 0);
}

Money::Money(double amount)
{
    double intPart;
    double fracPart;

    fracPart = modf(amount, &intPart);

    this->init(intPart, fracPart * 100);
}

const long Money::getBanknote() const
{
    return this->banknote;
}

const long Money::getCoin() const
{
    return this->coin;
}

void Money::init(long hrn, unsigned char kop)
{
    this->banknote = hrn;
    this->coin = kop;
}

void Money::init(long long coin)
{
    this->init(coin / 100, coin % 100);
}

void Money::read()
{
    std::cout << "Hrn: ";
    std::cin >> this->banknote;
    std::cout << "Kop: ";
    std::cin >> (int &)this->coin;
}

void Money::display() const
{
    std::cout << this->toString() << std::endl;
}

std::string Money::toString() const
{
    std::string result;

    result = std::to_string(this->banknote) + '.' + std::to_string(this->coin);

    return result;
}

void Money::setBanknote(long hrn)
{
    this->banknote = hrn;
}

void Money::setCoin(unsigned char kop)
{
    this->coin = kop;
}

Money Money::add(Money money)
{
    int kop = money.banknote * 100 + money.coin;

    return this->add(kop);
}

Money Money::add(int coins)
{
    Money result;

    int coin = this->banknote * 100 + this->coin + coins;

    result.init(coin);

    return result;
}

Money Money::minus(Money money)
{
    int coin = money.banknote * 100 + money.coin;

    return this->minus(coin);
}

Money Money::minus(int c)
{
    Money result;
    int coin = (this->banknote * 100 + this->coin) - c;
    result.init(coin);

    return result;
}

double Money::div(const Money& divider)
{
    long long this_amount = this->banknote * 100 + this->coin;
    long long divider_amount = divider.banknote * 100 + divider.coin;

    if (divider_amount == 0) {
        return 0.0;
    }

    double divided_amount = static_cast<double>(this_amount) / static_cast<double>(divider_amount);

    return divided_amount;
}


Money Money::div(double divider)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) / divider;
    result.init((long long)coin);

    return result;
}

Money Money::mul(double times)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) * times;

    result.init((long long)coin);

    return result;
}

bool Money::isEqual(Money money) {
    return this->banknote == money.banknote && this->coin == money.coin;
}

bool Money::isNotEqual(Money money) {
    return this->banknote != money.banknote || this->coin != money.coin;
}

bool Money::isGreatThan(Money money) {
    return this->banknote > money.banknote || (this->banknote == money.banknote && this->coin > money.coin);
}

bool Money::isLessThen(Money money) {
    return this->banknote < money.banknote || (this->banknote == money.banknote && this->coin < money.coin);
}

bool Money::isGreaterThanOrEqual(Money money) {
    return this->isGreatThan(money) || this->isEqual(money);
}

bool Money::isLessThanOrEqual(Money money) {
    return this->isLessThen(money) || this->isEqual(money);
}


Money Money::operator+(Money money)
{
    return this->add(money);
}

Money Money::operator+(int kop)
{
    return this->add(kop);
}

Money Money::operator-(Money money)
{
    return this->minus(money);
}

Money Money::operator-(int coin)
{
    return this->minus(coin);
}

Money Money::operator/(Money divider)
{
    return this->div(divider);
}

Money Money::operator/(double divider)
{
    return this->div(divider);
}

Money Money::operator*(double times)
{
    return this->mul(times);
}

bool Money::operator==(Money money)
{
    return this->isEqual(money);
}

bool Money::operator!=(Money money){
    return this->isNotEqual(money);
};

bool Money::operator>(Money money){
    return this->isGreatThan(money);
};

bool Money::operator<(Money money){
    return this->isLessThen(money);
};

bool Money::operator>=(Money money){
    return this->isGreaterThanOrEqual(money);
};

bool Money::operator<=(Money money){
    return this->isLessThanOrEqual(money);
};
