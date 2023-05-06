#ifndef TRADE
#define TRADE 

#include <stdbool.h>

typedef struct {
  bool win;
  bool type;
  double entry;
  double exit;
  double tp;
  double sl;
  double rr;
  char* lesson;
  double profit;
  int contracts;
} Trade;

void printTrade(Trade trade);
Trade new_Trade(double entry, double exit, double tp, double sl, char* lesson, int contracts);
Trade getUserInputTrade();

#endif // !TRADE