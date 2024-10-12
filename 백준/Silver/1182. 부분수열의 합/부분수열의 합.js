const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const [N, S] = input[0].split(" ").map(Number);
    const arr = input[1].split(" ").map(Number);

    let ans = 0;
    for (let i = 1; i < 1 << N; ++i) {
        const selected = [];
        for (let j = 0; j < N; ++j) if (i & (1 << j)) selected.push(j);

        const sum = selected.reduce((prev, cur) => prev + arr[cur],0);
        if (sum === S)
            ++ans;
    }   
    return ans;
}

console.log(solution());
