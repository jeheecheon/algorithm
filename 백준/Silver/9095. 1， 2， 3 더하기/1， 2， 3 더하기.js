/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const Solution = () => {
    /**
     * 2: 2
     * 3: 4
     * 4: 7
     * 5: 13
     * 6: 24
     * 7: 44
     */

    const DP = Array(11).fill(0);
    DP[0] = DP[1] = 1;
    DP[2] = 2;
    for (let i = 3; i <= 10; ++i)
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];

    const ans = [];
    input.slice(1).map(Number).forEach(num => {
        ans.push(DP[num]);
    });

    return ans.join("\n");
}

console.log(Solution());