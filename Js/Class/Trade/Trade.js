import chalk from "chalk";

class Trade {
  win;
  type;
  entry;
  tp;
  sl;
  rr;
  lesson;
  contracts;
  date;

  constructor(win, type, entry, exit, tp, sl, rr, lesson, contracts, date) {
    this.win = win;
    this.type = type;
    this.entry = entry;
    this.exit = exit;
    this.tp = tp;
    this.sl = sl;
    this.rr = rr;
    this.lesson = lesson;
    this.contracts = contracts;
    this.date = date;
  }
  toString() {
    return (
      `
        ${chalk.bgWhite(chalk.black(`Trade:     ${this.date}`))}
        ${this.win ? chalk.green("WIN!") : chalk.red("LOSS!")} ${this.contracts} contracts ${this.type ? chalk.green("LONG") : chalk.red("SHORT")} 
        ${this.entry} ------> ${this.exit}
        ${chalk.green("TP:")} ${this.tp}
        ${chalk.red("SL:")} ${this.sl}
        RR: ${this.rr.toFixed(2)}
        Lesson: ${this.lesson}
      `
    );
  }
}

export default Trade;
