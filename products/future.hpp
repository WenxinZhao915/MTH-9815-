#ifndef FUTURE_HPP
#define FUTURE_HPP

#include <iostream>
#include <string>
#include "products.hpp"

using namespace std;

// Future Product Class
class Future : public Product
{
public:
    // Constructor
    Future(string _productId, string _ticker, date _expiryDate, float _notional);
    Future();

    // Get the ticker of the Future
    string GetTicker() const;

    // Get the expiry date of the Future
    date GetExpiryDate() const;

    // Get the notional value of the Future
    float GetNotional() const;

    // Overload the << operator to print the Future
    friend ostream& operator<<(ostream &output, const Future &future);

private:
    string ticker;         // Ticker of the Future
    date expiryDate;       // Expiry date of the Future
    float notional;        // Notional value
};

// Constructor Implementation
Future::Future(string _productId, string _ticker, date _expiryDate, float _notional)
    : Product(_productId, FUTURE), ticker(_ticker), expiryDate(_expiryDate), notional(_notional)
{
}

Future::Future() : Product("", FUTURE), ticker(""), expiryDate(date(1970, Jan, 1)), notional(0.0f)
{
}

// Get the ticker
string Future::GetTicker() const
{
    return ticker;
}

// Get the expiry date
date Future::GetExpiryDate() const
{
    return expiryDate;
}

// Get the notional value
float Future::GetNotional() const
{
    return notional;
}

// Overload the << operator
ostream& operator<<(ostream &output, const Future &future)
{
    output << "Future: " << future.GetTicker() << ", Expiry: " << future.GetExpiryDate()
           << ", Notional: " << future.GetNotional();
    return output;
}

#endif // FUTURE_HPP
