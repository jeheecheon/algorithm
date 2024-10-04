/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

/**
 * Solution
 */
let ans = "";
const vis = Array(N + 1).fill(false);
const picked = [];
const solve = (k) => {
    if (k == M) {
        ans += picked.join(" ") + '\n';
        return;
    }

    for (let i = 1; i <= N; ++i) {
        // if (vis[i])
        //     continue;

        // vis[i] = true;
        picked.push(i);

        solve(k + 1);
        
        // vis[i] = false;
        picked.pop();
    }
}

solve(0);
console.log(ans);