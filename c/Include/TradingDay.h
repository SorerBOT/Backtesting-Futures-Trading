#include "Trade.h"

#ifndef TRADINGDAY 
#define TRADINGDAY 

typedef struct TradingDay {
  int amountOfTrades;
  Trade* trades;
  char date[10];
  double pl;
  double wl;
  char* lesson;
} TradingDay;

void printTradingDay(TradingDay tradingDay, bool info);
TradingDay new_TradingDay(int amountOfTrades, Trade* trades, char date[10], char* lesson);

#endif // !TRADINGDAY