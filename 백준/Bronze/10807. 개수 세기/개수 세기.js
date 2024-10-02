/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let arr = input[1].trim().split(" ").map(Number);
let find = +input[2].trim();

/**
 * Solution
 */
console.log(arr.reduce((acc, cur) => (cur === find ? acc + 1 : acc), 0));
