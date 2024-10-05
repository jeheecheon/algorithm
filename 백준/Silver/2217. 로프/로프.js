/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const arr = Array(N).fill(0).map((_, i) => +input[1 + i].trim());

/**
 * Solution
 */
arr.sort((a, b) => b - a);
arr.unshift(0);

let maxi = 0;
for (let i = 1; i <= N; ++i)
    maxi = Math.max(arr[i] * i, maxi);

console.log(maxi);