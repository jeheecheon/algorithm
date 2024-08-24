/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const n = +input[0];
const results = input.slice(1, n + 1).map(arr => {
    arr = arr.split(' ').map(Number);
    let maxi = 0;
    for (let i = 0; i < arr.length - 2; ++i) {
        for (let j = i + 1; j < arr.length - 1; ++j) {
            for (let k = j + 1; k < arr.length; ++k) {
                const temp = (arr[i] + arr[j] + arr[k]) % 10;
                
                maxi = Math.max(maxi, temp)
            }
        }
    }

    return maxi;
})

let ans = 0;
let val = results[0];
for (let i = 1; i < n; ++i) {
    if (results[i] >= val) {
        ans = i;
        val = results[i];
    }
}

console.log(ans + 1);
