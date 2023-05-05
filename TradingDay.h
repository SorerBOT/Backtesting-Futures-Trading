#include "Trade.h"

#ifndef TRADINGDAY 
#define TRADINGDAY 

typedef struct TradingDay {
  int amountOfTrades;
  Trade trades[10];
  char date[10];
  int pl;
  int wl;
  char* lesson;
} TradingDay;

#endif // !TRADINGDAY
