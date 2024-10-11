/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
arr.sort((a, b) => a - b);
let left = 0;
let right = arr.length - 1;
let answer = [0, 0];
let mini = Infinity;

while (left < right) {
    const sum = arr[left] + arr[right];

    if (Math.abs(sum) < Math.abs(mini)) {
        mini = sum;
        answer = [arr[left], arr[right]];
    }

    if (sum > 0)
        --right;
    else
        ++left;
}

console.log(...answer)