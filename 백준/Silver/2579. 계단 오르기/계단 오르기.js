/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let N = +input[0];
let arr = Array(N).fill(0).map((_, idx) => +input[idx + 1].trim());
arr.unshift(0);
/**
 * Solution
 */
const DP = Array.from({ length: N + 1}, () => Array(2).fill(0));
DP[1][0] = arr[1];

for (let i = 2; i <= N; ++i) {
    DP[i][0] = Math.max(DP[i - 2][0], DP[i - 2][1]) + arr[i];
    DP[i][1] = DP[i - 1][0] + arr[i];
}

console.log(Math.max(...DP[N]));
