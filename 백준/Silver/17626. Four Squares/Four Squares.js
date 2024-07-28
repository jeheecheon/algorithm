/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().trimEnd();

/**
 * Solution
 */
const n = +input;

const dp = new Array(n + 1).fill(0);

for (let i = 1; i <= n; ++i) {
    dp[i] = i;
    for (let j = 1; j * j <= i; ++j) {
        dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
    }
}

console.log(dp[n]);
