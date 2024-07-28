/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const N = +input[0];
const shirts = input[1].split(" ").map(Number);
const [T, P] = input[2].split(" ").map(Number);

console.log(
    shirts.reduce((prev, cur) => {
        return prev + Math.ceil(cur / T);
    }, 0)
);
console.log(Math.trunc(N / P), N % P);