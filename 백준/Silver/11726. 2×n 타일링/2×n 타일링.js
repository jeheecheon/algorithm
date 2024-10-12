const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const N = +input[0];
    
    const DP = Array(N + 1).fill(Infinity);
    DP[1] = 1;
    DP[2] = 2;
    for (let i = 3; i <= N; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;

    return DP[N];
}

console.log(solution());