/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let [n, x] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);

let sum = 0;
for (let i = 0; i < x; ++i) sum += arr[i];
let ans = sum;

let st = 0;
let end = x - 1;
let cnt = 1;

while (end + 1 < n) {
    sum += arr[++end];
    sum -= arr[st++];

    if (sum > ans) {
        ans = sum;
        cnt = 1;
    } else if (sum == ans) {
        ++cnt;
    }
}

if (ans == 0) {
    console.log("SAD");
} else {
    console.log(`${ans}\n${cnt}`);
}
