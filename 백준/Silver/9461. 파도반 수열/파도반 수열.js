/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const P = input.slice(1).map((e) => Number(e.trim()));

/**
 * Solution
 */
const DP = Array(101).fill(0);
DP[1] = DP[2] = DP[3] = 1;
for (let i = 4; i <= 100; ++i)
    DP[i] = DP[i - 2] + DP[i - 3];

const ans = [];
P.forEach(e => {
    ans.push(DP[e]);
});

console.log(ans.join('\n'));