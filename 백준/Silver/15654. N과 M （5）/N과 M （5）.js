/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
arr.sort((a, b) => a - b);

let ans = "";
const vis = Array(8).fill(false);
const picked = [1];
const solve = (k) => {
    if (k == M) {
        ans += picked.slice(1).join(" ") + "\n";
        return;
    }

    for (let i = 0; i < N; ++i) {
        if (vis[i])
            continue;

        vis[i] = true;
        picked.push(arr[i]);

        solve(k + 1);

        vis[i] = false;
        picked.pop();
    }
};

solve(0);
console.log(ans);