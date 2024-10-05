/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let T = +input.shift();

/**
 * Solution
 */
let ans = [];

for (let i = 0; i < T; ++i) {
    input.shift();
    const arr = input.shift().split(" ").map(Number);

    let profit = 0;
    let maxi = 0;

    for (let i = arr.length - 1; i >= 0; --i) {
        if (arr[i] > maxi) 
            maxi = arr[i];
        else if (arr[i] < maxi) 
            profit += maxi - arr[i];
    }

    ans.push(profit);
}

console.log(ans.join("\n"));