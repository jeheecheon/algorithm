// baekjoon 32357

/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let [N, L] = input[0].split(" ").map(Number);
let ans = `${N}`;

for (let i = 1; i < L; ++i) {
    ans = 1 + ans;
}

console.log(ans);
