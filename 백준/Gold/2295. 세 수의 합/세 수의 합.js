/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const arr = Array(N).fill(0).map((_, idx) => +input[idx + 1]);

/**
 * Solution
 */
arr.sort((a, b) => a - b);
const two = [];
for (let i = 0; i < N; ++i)
    for (let j = i; j < N; ++j)
        two.push(arr[i] + arr[j]);
two.sort((a, b) => a - b);

let pos = false;

for (let i = N - 1; i > 0; --i) {
    for (let j = 0; j < i; ++j) {
        let st = 0; let end = two.length - 1;

        let num = arr[i] - arr[j];

        while (st < end) {
            const mid = Math.trunc((st + end) / 2);

            if (two[mid] >= num)
                end = mid;
            else
                st = mid + 1;
        }

        if (two[st] === num) {
            console.log(arr[i]);
            pos = true;
            break;

        }
    }
    if (pos)
        break;
}