#ifndef EURODOLLARFUTURE_HPP
#define EURODOLLARFUTURE_HPP

#include "future.hpp"

// EuroDollar Future Class
class EuroDollarFuture : public Future
{
public:
    // Constructor
    EuroDollarFuture(string _productId, string _ticker, date _expiryDate, float _notional)
        : Future(_productId, _ticker, _expiryDate, _notional) {}
};

#endif // EURODOLLARFUTURE_HPP
