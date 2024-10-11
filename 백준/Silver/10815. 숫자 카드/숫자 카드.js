/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr1 = input[1].split(" ").map(Number);
const arr2 = input[3].split(" ").map(Number);

/**
 * Solution
 */
arr1.sort((a, b) => a - b);
const ans = [];
arr2.forEach(e => {
    let st = 0, end = arr1.length - 1;
    while (st < end) {
        const mid = Math.trunc((st + end) / 2);

        if (arr1[mid] >= e)
            end = mid;
        else
            st = mid + 1;
    }
    ans.push(arr1[st] === e ? 1 : 0);
});
console.log(ans.join(" "));