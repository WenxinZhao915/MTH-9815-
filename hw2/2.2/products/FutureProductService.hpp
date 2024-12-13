#ifndef FUTUREPRODUCTSERVICE_HPP
#define FUTUREPRODUCTSERVICE_HPP

#include <iostream>
#include <map>
#include "future.hpp"
#include "soa.hpp"

// Future Product Service
class FutureProductService : public Service<string, Future>
{
public:
    // Constructor
    FutureProductService();

    // Retrieve Future data
    Future& GetData(string productId);

    // Add a Future to the service
    void Add(Future &future);

private:
    map<string, Future> futureMap; // Map of Futures
};

// Constructor
FutureProductService::FutureProductService()
{
    futureMap = map<string, Future>();
}

// Retrieve Future data
Future& FutureProductService::GetData(string productId)
{
    return futureMap[productId];
}

// Add a Future to the service
void FutureProductService::Add(Future &future)
{
    futureMap.insert(pair<string, Future>(future.GetProductId(), future));
}

#endif // FUTUREPRODUCTSERVICE_HPP
