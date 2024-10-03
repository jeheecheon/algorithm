/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let [N, M] = input[0].split(" ").map(Number);
const arr = Array(M).fill().map((_, i) => +input[1 + i]);

/**
 * Solution
 */
function solve(k) {
    let cnt = 0;
    for (let i = 0; i < M; ++i) {
        let jewels = arr[i];
        cnt += Math.ceil(jewels / k);
        if (cnt > N)
            return false;
    }
    return true;
}

let end = Math.max(...arr);
let st = 1;
let ans;
while (st <= end) {
    let mid = Math.trunc((st + end) / 2);

    if (solve(mid)) {
        ans = mid;
        end = mid - 1;
    } else {
        st = mid + 1;
    }
}

console.log(ans);