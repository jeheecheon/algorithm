const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const N = +input[0];
    const arr = input[1].split(" ").map(Number)
    
    const DP = Array(N + 1).fill(0);
    
    for (let i = 1; i <= N; ++i) {
        arr.forEach((a, idx) => {
            if (i > idx)
                DP[i] = Math.max(DP[i], DP[i - 1 - idx] + a);
        });
    }
    return DP[N];
}

console.log(solution());