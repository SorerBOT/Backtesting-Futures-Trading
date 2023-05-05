#include "Trade.h"
#include <stdio.h>

void printTrade(Trade trade) {
  int profit;
  int exit = trade.win ? trade.tp : trade.sl;

  if (trade.type) profit = trade.tp - trade.entry;
  else profit = trade.entry - trade.tp;
  
  printf("Trade: \n");
  // Type
  printf("%s\n", trade.type ? "Long" : "Short");
  // Win / Loss
  printf("%s\n", trade.win ? "WIN!" : "LOSS!");
  // Actual Trade
  printf("%d ---> %d\n", trade.entry, exit);
  // TP
  printf("TP: %d\n", trade.tp);
  // SL
  printf("SL: %d\n", trade.sl);
  // Profit
  printf("Profit: %d", profit);
  
}
