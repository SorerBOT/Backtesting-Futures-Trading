#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include "TradingDay.h"
#include "Trade.h"

int main(int c, char* argv) {
  Trade trade = {
    .win = true, 
    .type = true, 
    .entry = 4000, 
    .tp = 4010, 
    .sl = 3995, 
    .rr = 5, 
    .lesson = { 'a'}
  };
  
  printTrade(trade);

  return 0;
}
