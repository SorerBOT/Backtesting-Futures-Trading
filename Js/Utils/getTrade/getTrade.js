import inquirer from "inquirer";
import Trade from "../../Class/Trade/Trade.js";

async function getTrade() {
  const answers = await inquirer.prompt([
    {
      name: "contracts",
      type: "number",
      message: "Contracts: ",
      default() {
        return 1;
      }
    },
    {
      name: "type",
      type: "list",
      message: "Type: " + " ".repeat(5),
      choices: [
        "Long",
        "Short"
      ],
      default() { return "Long"; }
    },
    {
      name: "win",
      type: "list",
      message: "Win? "+ " ".repeat(6),
      choices: [
        "Win",
        "Loss"
      ],
      default() { return "Win"; }
    },
    {
      name: "entry",
      type: "number",
      message: "Entry: " + " ".repeat(4),
    },
    {
      name: "exit",
      type: "number",
      message: "Exit: " + " ".repeat(5),
    },
    {
      name: "tp",
      type: "number",
      message: "TP: " + " ".repeat(7),
    },
    {
      name: "sl",
      type: "number",
      message: "SL: " + " ".repeat(7) 
    },
    {
      name: "lesson",
      type: "input",
      message: "Lesson: " + " ".repeat(3) ,
      defualt() {
        return "";
      }
    },
    {
      name: "date",
      type: "input",
      message: "Date: " + " ".repeat(5) ,
      default() {
        const today = new Date();
        const yyyy = today.getFullYear();
        let mm = today.getMonth() + 1; // Months start at 0!
        let dd = today.getDate();
        
        if (dd < 10) dd = '0' + dd;
        if (mm < 10) mm = '0' + mm;
        
        return dd + '/' + mm + '/' + yyyy;
      }
    }
  ]);
  const { win, type, entry, exit, tp, sl, lesson, contracts, date } = answers;
  const rr = Math.abs(entry - tp) / Math.abs(entry - sl);
  
  return new Trade(win == "Win", type == "Long", entry, exit, tp, sl, rr, lesson, contracts, date);
}

export default getTrade;
