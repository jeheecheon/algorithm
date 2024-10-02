/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let n = +input[0];
let arr = Array(n);
for (let i = 0; i < n; ++i)
    arr[i] = input[i + 1].trim().split(" ").map(Number);

/**
 * Solution
 */
const vis = Array(1000001).fill(false);
arr.sort((a, b) => a[0] - b[0]);

let last = -1;
for (let i = 0; i < n; ++i) {
    if (arr[i][0] < last) {
        last = last + arr[i][1];
    } else {
        last = arr[i][0] + arr[i][1];
    }
}

console.log(last);
