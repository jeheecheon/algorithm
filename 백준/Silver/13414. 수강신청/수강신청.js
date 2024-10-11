/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [K, L] = input[0].split(" ").map(Number);

/**
 * Solution
 */
const S = new Map();
input.slice(1).map(e => e.trim()).forEach((e, idx) => {
    S.set(e, idx);
});

let ans = Array(L).fill(-1);
for (const [id, rank] of S)
    ans[rank] = id;

ans = ans.filter(e => e !== -1);

console.log(ans.slice(0, K).join('\n'));