#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "soa.hpp"
#include "products.hpp"
#include "algoexecutionservice.hpp"
#include "algostreamingservice.hpp"
#include "executionservice.hpp"
#include "guiservice.hpp"
#include "historicaldataservice.hpp"
#include "inquiryservice.hpp"
#include "marketdataservice.hpp"
#include "positionservice.hpp"
#include "pricingservice.hpp"
#include "riskservice.hpp"
#include "streamingservice.hpp"
#include "tradebookingservice.hpp"

using namespace std;

// Function declarations
void InitializeServices(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    PositionService<Bond>& positionService,
    RiskService<Bond>& riskService,
    MarketDataService<Bond>& marketDataService,
    AlgoExecutionService<Bond>& algoExecutionService,
    AlgoStreamingService<Bond>& algoStreamingService,
    GUIService<Bond>& guiService,
    ExecutionService<Bond>& executionService,
    StreamingService<Bond>& streamingService,
    InquiryService<Bond>& inquiryService,
    HistoricalDataService<Position<Bond>>& historicalPositionService,
    HistoricalDataService<PV01<Bond>>& historicalRiskService,
    HistoricalDataService<ExecutionOrder<Bond>>& historicalExecutionService,
    HistoricalDataService<PriceStream<Bond>>& historicalStreamingService,
    HistoricalDataService<Inquiry<Bond>>& historicalInquiryService);

void LinkServices(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    PositionService<Bond>& positionService,
    RiskService<Bond>& riskService,
    MarketDataService<Bond>& marketDataService,
    AlgoExecutionService<Bond>& algoExecutionService,
    AlgoStreamingService<Bond>& algoStreamingService,
    GUIService<Bond>& guiService,
    ExecutionService<Bond>& executionService,
    StreamingService<Bond>& streamingService,
    InquiryService<Bond>& inquiryService,
    HistoricalDataService<Position<Bond>>& historicalPositionService,
    HistoricalDataService<PV01<Bond>>& historicalRiskService,
    HistoricalDataService<ExecutionOrder<Bond>>& historicalExecutionService,
    HistoricalDataService<PriceStream<Bond>>& historicalStreamingService,
    HistoricalDataService<Inquiry<Bond>>& historicalInquiryService);

void ProcessDataFiles(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    MarketDataService<Bond>& marketDataService,
    InquiryService<Bond>& inquiryService);

int main()
{
    cout << TimeStamp() << "Program Starting..." << endl;

    // Step 1: Initialize services
    PricingService<Bond> pricingService;
    TradeBookingService<Bond> tradeBookingService;
    PositionService<Bond> positionService;
    RiskService<Bond> riskService;
    MarketDataService<Bond> marketDataService;
    AlgoExecutionService<Bond> algoExecutionService;
    AlgoStreamingService<Bond> algoStreamingService;
    GUIService<Bond> guiService;
    ExecutionService<Bond> executionService;
    StreamingService<Bond> streamingService;
    InquiryService<Bond> inquiryService;
    HistoricalDataService<Position<Bond>> historicalPositionService(POSITION);
    HistoricalDataService<PV01<Bond>> historicalRiskService(RISK);
    HistoricalDataService<ExecutionOrder<Bond>> historicalExecutionService(EXECUTION);
    HistoricalDataService<PriceStream<Bond>> historicalStreamingService(STREAMING);
    HistoricalDataService<Inquiry<Bond>> historicalInquiryService(INQUIRY);

    cout << TimeStamp() << "Services Initialized." << endl;

    // Step 2: Link services
    LinkServices(
        pricingService,
        tradeBookingService,
        positionService,
        riskService,
        marketDataService,
        algoExecutionService,
        algoStreamingService,
        guiService,
        executionService,
        streamingService,
        inquiryService,
        historicalPositionService,
        historicalRiskService,
        historicalExecutionService,
        historicalStreamingService,
        historicalInquiryService);

    cout << TimeStamp() << "Services Linked." << endl;

    // Step 3: Process data files
    ProcessDataFiles(pricingService, tradeBookingService, marketDataService, inquiryService);

    cout << TimeStamp() << "Program Ending..." << endl;
    system("pause");
    return 0;
}

void InitializeServices(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    PositionService<Bond>& positionService,
    RiskService<Bond>& riskService,
    MarketDataService<Bond>& marketDataService,
    AlgoExecutionService<Bond>& algoExecutionService,
    AlgoStreamingService<Bond>& algoStreamingService,
    GUIService<Bond>& guiService,
    ExecutionService<Bond>& executionService,
    StreamingService<Bond>& streamingService,
    InquiryService<Bond>& inquiryService,
    HistoricalDataService<Position<Bond>>& historicalPositionService,
    HistoricalDataService<PV01<Bond>>& historicalRiskService,
    HistoricalDataService<ExecutionOrder<Bond>>& historicalExecutionService,
    HistoricalDataService<PriceStream<Bond>>& historicalStreamingService,
    HistoricalDataService<Inquiry<Bond>>& historicalInquiryService)
{
    cout << TimeStamp() << "Services Initializing..." << endl;
    // Initialization logic if needed
    cout << TimeStamp() << "Services Initialized." << endl;
}

void LinkServices(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    PositionService<Bond>& positionService,
    RiskService<Bond>& riskService,
    MarketDataService<Bond>& marketDataService,
    AlgoExecutionService<Bond>& algoExecutionService,
    AlgoStreamingService<Bond>& algoStreamingService,
    GUIService<Bond>& guiService,
    ExecutionService<Bond>& executionService,
    StreamingService<Bond>& streamingService,
    InquiryService<Bond>& inquiryService,
    HistoricalDataService<Position<Bond>>& historicalPositionService,
    HistoricalDataService<PV01<Bond>>& historicalRiskService,
    HistoricalDataService<ExecutionOrder<Bond>>& historicalExecutionService,
    HistoricalDataService<PriceStream<Bond>>& historicalStreamingService,
    HistoricalDataService<Inquiry<Bond>>& historicalInquiryService)
{
    cout << TimeStamp() << "Linking Services..." << endl;
    pricingService.AddListener(algoStreamingService.GetListener());
    pricingService.AddListener(guiService.GetListener());
    algoStreamingService.AddListener(streamingService.GetListener());
    streamingService.AddListener(historicalStreamingService.GetListener());
    marketDataService.AddListener(algoExecutionService.GetListener());
    algoExecutionService.AddListener(executionService.GetListener());
    executionService.AddListener(tradeBookingService.GetListener());
    executionService.AddListener(historicalExecutionService.GetListener());
    tradeBookingService.AddListener(positionService.GetListener());
    positionService.AddListener(riskService.GetListener());
    positionService.AddListener(historicalPositionService.GetListener());
    riskService.AddListener(historicalRiskService.GetListener());
    inquiryService.AddListener(historicalInquiryService.GetListener());
    cout << TimeStamp() << "Services Linked." << endl;
}

void ProcessDataFiles(
    PricingService<Bond>& pricingService,
    TradeBookingService<Bond>& tradeBookingService,
    MarketDataService<Bond>& marketDataService,
    InquiryService<Bond>& inquiryService)
{
    cout << TimeStamp() << "Processing Data Files..." << endl;

    // Process price data
    ifstream priceData("prices.txt");
    if (priceData.is_open())
    {
        pricingService.GetConnector()->Subscribe(priceData);
        priceData.close();
        cout << TimeStamp() << "Price Data Processed." << endl;
    }

    // Process trade data
    ifstream tradeData("trades.txt");
    if (tradeData.is_open())
    {
        tradeBookingService.GetConnector()->Subscribe(tradeData);
        tradeData.close();
        cout << TimeStamp() << "Trade Data Processed." << endl;
    }

    // Process market data
    ifstream marketData("marketdata.txt");
    if (marketData.is_open())
    {
        marketDataService.GetConnector()->Subscribe(marketData);
        marketData.close();
        cout << TimeStamp() << "Market Data Processed." << endl;
    }

    // Process inquiry data
    ifstream inquiryData("inquiries.txt");
    if (inquiryData.is_open())
    {
        inquiryService.GetConnector()->Subscribe(inquiryData);
        inquiryData.close();
        cout << TimeStamp() << "Inquiry Data Processed." << endl;
    }

    cout << TimeStamp() << "Data Files Processed." << endl;
}
