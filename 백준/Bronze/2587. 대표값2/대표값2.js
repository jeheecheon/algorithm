/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let n = input.length;
let arr = [];
for (let i = 0;i < n; ++i) {
    arr.push(+input[i]);
}
/**
 * Solution
 */
let sum = arr.reduce((prev, cur) => prev + cur, 0);
console.log(sum / n);
arr.sort();
let mid = (n / 2).toFixed(0);
console.log(arr[mid - 1]);
