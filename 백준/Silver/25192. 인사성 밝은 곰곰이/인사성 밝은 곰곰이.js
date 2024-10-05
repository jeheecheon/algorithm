/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const arr = Array(N).fill(0).map((_, idx) => input[idx + 1].trim());

/**
 * Solution
 */
let S = new Set();
let ans = 0;
arr.forEach(e => {
    if (e === "ENTER") {
        ans += S.size;
        S = new Set();
    }
    else {
        S.add(e)
    }
});
console.log(ans + S.size);