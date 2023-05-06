#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdio.h>
#include "Include/TradingDay.h"
#include "Include/Trade.h"

int main(int c, char* argv) {
  printTrade(getUserInputTrade());
  
  return 0;
}
