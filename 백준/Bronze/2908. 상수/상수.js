/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].trim().split(" ").map(Number);

/**
 * Solution
 */
let a = +N.toString().split("").reverse().join("");
let b = +M.toString().split("").reverse().join("");

console.log(Math.max(a, b));
