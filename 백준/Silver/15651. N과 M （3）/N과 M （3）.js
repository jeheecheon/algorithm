/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let [N, M] = input[0].split(" ").map(Number);

/**
 * Solution
 */
const used = Array(10).fill(false);
const selected = [];
let ans = [];

solve(0);
function solve(k) {
    if (k === M) {
        ans.push(selected.join(" "));
        return;
    }

    for (let i = 1; i <= N; ++i) {
        // if (used[i])
        //     continue;

        // used[i] = true;
        selected.push(i);
        
        solve(k + 1);

        // used[i] = false;
        selected.length -= 1;
    }
}

console.log(ans.join("\n"));
