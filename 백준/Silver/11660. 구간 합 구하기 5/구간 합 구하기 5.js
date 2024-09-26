/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let [n, m] = input[0].split(" ").map(Number);
const arr = Array.from({ length: n + 1 });
arr[0] = Array.from({ length: n + 1 }).fill(0);
for (let i = 1; i <= n; ++i) {
    arr[i] = input[i].split(" ").map(Number);
    arr[i].unshift(0);
}

const preSum = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));

for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= n; ++j) {
        preSum[i][j] = arr[i][j] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
    }
}

const ans = [];
for (let i = 0; i < m; ++i) {
    const [x1, y1, x2, y2] = input[i + 1 + n].split(" ").map(Number);
    ans.push(preSum[x2][y2] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1] + preSum[x1 - 1][y1 - 1]);
}

console.log(ans.join("\n"));
