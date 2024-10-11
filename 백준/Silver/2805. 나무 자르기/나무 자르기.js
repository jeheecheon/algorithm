/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */

let st = 1, end = 1000000000;

function solve(len) {
    let cut = 0;
    arr.forEach(e => {
        if (e >= len)
            cut += e - len;
    });
    return cut >= M;
}

let ans = 0
while (st <= end) {
    const mid = Math.trunc((st + end + 1) / 2);

    if (solve(mid)) {
        ans = mid;
        st = mid + 1;
    }
    else
        end = mid - 1;
}

console.log(ans);
