/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let [N, M] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
arr.sort((a, b) => a - b);

const used = Array(N).fill(false);
const selected = [0];
let ans = [];
const S = new Set();

solve(0);
function solve(k) {
    if (k === M) {
        const pair = selected.slice(1).map(idx => arr[idx]).join(" ");

        if (!S.has(pair)) {
            S.add(pair)
            ans.push(pair);
        }
        return;
    }

    for (let i = 0; i < N; ++i) {
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
