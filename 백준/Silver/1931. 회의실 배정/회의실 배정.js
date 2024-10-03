/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const n = +input[0].trim();
const arr = Array(n)
    .fill()
    .map((_, idx) => input[idx + 1].trim().split(" ").map(Number));

/**
 * Solution
 */
arr.sort((a, b) => {
    if (a[1] == b[1])
        return a[0] - b[0];
    return a[1] - b[1];
})

let cnt = 0;
let end = 0;
for (let i = 0; i < n; ++i) {
    if (arr[i][0] >= end) {
        end = arr[i][1];
        ++cnt
    }
}

console.log(cnt);
