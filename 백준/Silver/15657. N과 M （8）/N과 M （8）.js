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
arr.sort((a, b) => a -b);
let ans = "";
const vis = Array(8).fill(false);
const picked = [0];
const solve = (k) => {
    if (k == M) {
        ans += picked.slice(1).map(e => arr[e]).join(" ") + "\n";
        return;
    }

    for (let i = picked[k]; i < N; ++i) {
        // if (vis[i])
        //     continue;

        // vis[i] = true;
        picked.push(i);

        solve(k + 1);

        // vis[i] = false;
        picked.pop();
    }
};

solve(0);
console.log(ans);