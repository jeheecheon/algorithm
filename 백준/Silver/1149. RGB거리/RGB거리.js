/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const houses = input.slice(1).map(house => house.split(" ").map(Number));

/**
 * Solution
 */
const Solution = () => {
    const DP = Array.from({ length: N + 1 }, () => Array(3).fill(0));
    houses.unshift([0, 0, 0])

    for (let i = 1; i <= N; ++i) {
        DP[i][0] = Math.min(DP[i - 1][1], DP[i - 1][2]) + houses[i][0]
        DP[i][1] = Math.min(DP[i - 1][0], DP[i - 1][2]) + houses[i][1]
        DP[i][2] = Math.min(DP[i - 1][0], DP[i - 1][1]) + houses[i][2]
    }

    return Math.min(...DP[N])
}

console.log(Solution());