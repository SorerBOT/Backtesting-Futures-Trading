#include <Include/TradingDay.h>
#include <stdlib.h>
#include <stdbool.h>

void printTradingDay(TradingDay tradingDay, bool info) {
    printf("Trading Day: \n");
    // date
    printf("Date: %s\n", tradingDay.date);
    // amount of trades
    printf("Trades Taken: %d\n", tradingDay.amountOfTrades);
    // pl
    printf("P/L: %2.f\n", tradingDay.pl);
    // wl
    printf("W/L: %2.f\n", tradingDay.wl);
    // lesson
    printf("Lesson: \n %s\n", tradingDay.lesson);

    if (info) {
        printf("Trades: \n");
        for (int i = 0; i < tradingDay.amountOfTrades; i++) printTrade(tradingDay.trades[i]);
    }
}

TradingDay new_TradingDay(int amountOfTrades, Trade* trades, char date[10], char* lesson) {
  double pl = 0;
  int wonTrades = 0;

  for (int i = 0; i < amountOfTrades; i++) {
    if (trades[i].win) wonTrades++;
    pl += trades[i].profit;
  }
  
  TradingDay tradingDay = {
    .amountOfTrades = amountOfTrades,
    .trades = trades,
    .date = strdup(date),
    .pl = pl,
    .wl = (double) (wonTrades / amountOfTrades),
    .lesson = strdup(lesson)
  };
}