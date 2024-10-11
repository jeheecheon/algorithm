/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr1 = input[1].split(" ").map(Number);
const arr2 = input[2].split(" ").map(Number);

/**
 * Solution
 */
arr1.sort((a, b) => a - b);
arr2.sort((a, b) => a - b);
const ans = [];
arr1.forEach(e => {
    let st = 0, end = arr2.length - 1;

    while (st < end) {
        const mid = Math.trunc((st + end) / 2);

        if (arr2[mid] >= e)
            end = mid;
        else
            st = mid + 1;
    }

    if (arr2[st] !== e)
        ans.push(e)
    
});
console.log(ans.length);
console.log(ans.join(" "));