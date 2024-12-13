#ifndef BONDFUTURE_HPP
#define BONDFUTURE_HPP

#include "future.hpp"

// Bond Future Class
class BondFuture : public Future
{
public:
    // Constructor
    BondFuture(string _productId, string _ticker, date _expiryDate, float _notional)
        : Future(_productId, _ticker, _expiryDate, _notional) {}
};

#endif // BONDFUTURE_HPP