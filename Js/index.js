import getTrade from "./Utils/getTrade/getTrade.js";
import { readFileSync, writeFileSync } from "fs";

console.clear();

const path = "./trades.json";

const jsonString = readFileSync(path);

const trades = JSON.parse(jsonString);

trades.trades.push(await getTrade());

writeFileSync(path, JSON.stringify(trades), "utf8");
