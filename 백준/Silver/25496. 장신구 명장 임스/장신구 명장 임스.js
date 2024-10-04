/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let [P, M] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
arr = arr.sort((a, b) => a - b);
console.log(arr.reduce((prev, cur) => {
    if (P < 200) {
        P += cur;
        return prev + 1;
    }
    return prev;
}, 0))