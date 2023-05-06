#include "Include/Trade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTrade(Trade trade) {
  printf("Trade: \n");
  // Type
  printf("%s\n", trade.type ? "Long" : "Short");
  // Win / Loss
  printf("%s %d Contracts of %2.lf Points Each!\n", trade.win ? "WIN!" : "LOSS!", trade.contracts, (double) (trade.profit / trade.contracts));
  // Actual Trade
  printf("%2.lf ---> %2.f\n", trade.entry, trade.exit);
  // TP
  printf("TP: %2.lf\n", trade.tp);
  // SL
  printf("SL: %2.lf\n", trade.sl);
  // Lesson
  printf("Lesson: %s\n", trade.lesson);
}

Trade new_Trade(double entry, double exit, double tp, double sl, char* lesson, int contracts) {
  bool win = exit == tp;
  bool type = entry < tp;
  double profit = abs(tp - entry);
  double loss = abs(sl - entry);
  double rr = profit / loss;

  Trade trade = {
    .win = win,
    .type = type,
    .entry = entry,
    .exit = exit,
    .tp = tp,
    .sl = sl,
    .rr = rr,
    .lesson = strdup(lesson),
    .profit = win ? contracts * profit : contracts * (-loss),
    .contracts = contracts
  };

  return trade;
}

Trade getUserInputTrade() {
  double entry, exit, tp, sl;
  int contracts;
  char* lesson = malloc(sizeof(char) * 63 + 1);
  
  printf("Enter Amount of Contracts: ");
  scanf("%d", &contracts);
  
  printf("\nEnter Entry: ");
  scanf("%lf", &entry);
  
  printf("\nEnter Exit: ");
  scanf("%lf", &exit);
  
  printf("\nEnter TP: ");
  scanf("%lf", &tp);
  
  printf("\nEnter SL: ");
  scanf("%lf", &sl);
  
  printf("\nEnter Lesson: ");
  scanf("%[^\n]: ", lesson);
  
  printf("\n");
  
  return new_Trade(entry, exit, tp, sl, lesson, contracts);
}