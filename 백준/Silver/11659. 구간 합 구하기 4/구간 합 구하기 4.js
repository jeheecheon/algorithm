/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const Solution = () => {
    const ans = [];
    const arr = input[1].split(" ").map(Number);
    const DP = Array(arr.length + 1).fill(0);

    for (let i = 1; i <= arr.length; ++i)
        DP[i] = DP[i - 1] + arr[i - 1];

    input.slice(2).forEach(a => {
        const [b, c] = a.split(" ").map(Number);
        ans.push(DP[c] - DP[b - 1]);
    })

    return ans.join("\n");
}

console.log(Solution());