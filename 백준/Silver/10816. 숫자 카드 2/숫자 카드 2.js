/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let arr1 = input[1].split(" ").map(Number);
let arr2 = input[3].split(" ").map(Number);

/**
 * Solution
 */
const ans = [];
arr1 = arr1.sort((a, b) => a - b);

arr2.forEach((e) => {
    let st = 0, end = arr1.length;
    
    while (st < end) {
        let mid = Math.trunc((st + end) / 2);

        if (arr1[mid] >= e)
            end = mid;
        else
            st = mid + 1;
    }
    const lower = st;

    st = 0, end = arr1.length;

    while (st < end) {
        let mid = Math.trunc((st + end) / 2);

        if (arr1[mid] > e)
            end = mid;
        else
            st = mid + 1;
    }
    const upper = st;
    ans.push(upper - lower);
});

console.log(ans.join("\n"));