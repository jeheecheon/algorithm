/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const str = input[0].trim();

/**
 * Solution
 */
const N = str.length;

const S = new Set();
for (let i = 1; i <= N; ++i) { // i는 뽑을 길이
    for (let j = 0; j + i <= N; ++j) {
        S.add(str.slice(j, j + i))
    }
}
console.log(S.size);