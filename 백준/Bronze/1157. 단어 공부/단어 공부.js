/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let str = input[0].trim();

/**
 * Solution
 */

const vis = Array(26).fill(0);
str = str.toLowerCase();
for (let i = 0; i < str.length; ++i) ++vis[str.charCodeAt(i) - "a".charCodeAt(0)];

let maxiIdx = 0;
let maxi = 0;
for (let i = 0; i < 26; ++i) {
    if (vis[i] > maxi) {
        maxi = vis[i];
        maxiIdx = i;
    }
}

let sorted = [...vis].sort((a, b) => a - b);
if (sorted[sorted.length - 1] === sorted[sorted.length - 2]) {
    console.log("?");
} else {
    console.log(String.fromCharCode("A".charCodeAt(0) + maxiIdx));
}
