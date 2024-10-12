const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const Solution = () => {
    const N = Number(input[0]);
    if (N === 1)
        return 0;
    const DP = Array(N + 1).fill(0);

    for (let i = 2; i <= N; ++i) {
        DP[i] = DP[i - 1] + 1;

        if (i % 2 === 0) 
            DP[i] = Math.min(DP[i], DP[i / 2] + 1)
        
        if (i % 3 === 0) 
            DP[i] = Math.min(DP[i], DP[i / 3] + 1)
    }
    return DP[N];
    const ans = [];

    let st = DP[N];
    for (let i = N; i >= 1; --i) {
        if (DP[i] === st) {
            ans.push(i)
            --st;
        }
    }
    return DP[N] + '\n' + ans.join(' ');
}

console.log(Solution());