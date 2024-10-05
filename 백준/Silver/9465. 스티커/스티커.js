/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const T = +input[0];

/**
 * Solution
 */
const ans = [];
for (let i = 0; i < T; ++i) {
    const N = +input[1 + 3 * i].trim();
    const stickers = Array(2).fill(0).map((_, level) => input[2 + level + 3 * i].split(" ").map(Number));
    stickers[0].unshift(0);
    stickers[1].unshift(0);

    // 2행 x N+1열 x <안 뽑는 것 | 뽑는 것>
    const DP = Array.from({ length: 2 }, () =>
        Array.from({ length: N + 1 }, () => Array(2).fill(0))
    );
    
    let maxi = 0;
    for (let i = 1; i <= N; ++i) {
        DP[0][i][0] = Math.max(DP[0][i - 1][0], DP[1][i - 1][0], DP[1][i - 1][1]);
        DP[1][i][0] = Math.max(DP[1][i - 1][0], DP[0][i - 1][0], DP[0][i - 1][1]);

        DP[0][i][1] = Math.max(DP[0][i - 1][0], DP[1][i - 1][0], DP[1][i - 1][1]) + stickers[1][i];
        DP[1][i][1] = Math.max(DP[1][i - 1][0], DP[0][i - 1][0], DP[0][i - 1][1]) + stickers[0][i];

        maxi = Math.max(...DP[0][i], ...DP[1][i]);
    }

    ans.push(maxi);
}
console.log(ans.join("\n"));