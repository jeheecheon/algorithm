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
const selected = [1];
let ans = [];

solve(0);
function solve(k) {
    if (k === M) {
        ans.push(selected.slice(1).join(" "));
        return;
    }

    for (let i = selected[k]; i <= N; ++i) {
        // if (used[i])
            // continue;

        // used[i] = true;
        selected.push(i);
        
        solve(k + 1);

        // used[i] = false;
        selected.length -= 1;
    }
}

console.log(ans.join("\n"));