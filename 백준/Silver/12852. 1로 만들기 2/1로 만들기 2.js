const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const Solution = () => {
    const N = Number(input[0]);
    const DP = Array(N + 1).fill(0);
    const trace = Array(N + 1).fill(0);

    for (let i = 2; i <= N; ++i) {
        DP[i] = DP[i - 1] + 1;
        trace[i] = i - 1;

        if (i % 2 === 0 && DP[i] > DP[i / 2] + 1) {
            DP[i] = DP[i / 2] + 1
            trace[i] = i / 2;
        }
        
        if (i % 3 === 0 && DP[i] > DP[i / 3] + 1) {
            DP[i] = DP[i / 3] + 1
            trace[i] = i / 3;
        }
    }

    const ans = [];
    let a = N;
    while (a !== 0) {
        ans.push(a);
        a = trace[a];
    }

    return DP[N] + '\n' + ans.join(" ");
}

console.log(Solution());