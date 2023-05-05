#ifndef TRADE
#define TRADE 

#include <stdbool.h>

typedef struct {
  bool win;
  bool type;
  int entry;
  int tp;
  int sl;
  int rr;
  char lesson[32];
} Trade;

void printTrade(Trade trade);

#endif // !TRADE
