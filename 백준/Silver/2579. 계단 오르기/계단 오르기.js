/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const scores = input.slice(1).map((e) => Number(e.trim()));
scores.unshift(0);

/**
 * Solution
 */
const DP = Array.from({ length: N + 1 }, () => Array(2).fill(0));
DP[1][0] = scores[1];

for (let i = 2; i <= N; ++i) {
    DP[i][0] = Math.max(DP[i - 2][0], DP[i - 2][1]) + scores[i];
    DP[i][1] = DP[i - 1][0] + scores[i];
}

console.log(Math.max(...DP[N]));