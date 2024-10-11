/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = Array(N)
    .fill(0)
    .map((_, idx) => +input[idx + 1]);

/**
 * Solution
 */
let st = 1,
    end = 0x7fffffff;

function solve(len) {
    let cnt = 0;
    arr.forEach((e) => {
        cnt += Math.trunc(e / len);
    });

    return cnt >= M;
}

while (st < end) {
    const mid = Math.trunc((st + end + 1) / 2);

    if (solve(mid)) 
        st = mid;
    else 
        end = mid - 1;
}

console.log(st);