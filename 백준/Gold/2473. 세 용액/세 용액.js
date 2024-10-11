/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
let ans = [];
let mini = Infinity;

arr.sort((a, b) => a - b);
for (let a = 0; a < arr.length - 2; ++a) {
    for (let b = a + 1; b < arr.length - 1; ++b) {
        const target = -arr[a] - arr[b];
        let st, end, lower, upper;
        
        st = b + 1, end = arr.length - 1;
        while (st < end) {
            const mid = Math.trunc((st + end) / 2);

            if (arr[mid] >= target)
                end = mid;
            else
                st = mid + 1;
        }
        lower = st;

        st = b + 1, end = arr.length - 1;
        while (st < end) {
            const mid = Math.trunc((st + end + 1) / 2);

            if (arr[mid] < target)
                st = mid;
            else
                end = mid - 1;
        }
        upper = st;

        if (Math.abs(arr[a] + arr[b] + arr[lower]) < mini) {
            mini = Math.abs(arr[a] + arr[b] + arr[lower]);
            ans = [arr[a], arr[b], arr[lower]];
        }

        if (Math.abs(arr[a] + arr[b] + arr[upper]) < mini) {
            mini = Math.abs(arr[a] + arr[b] + arr[upper]);
            ans = [arr[a], arr[b], arr[upper]];
        }
    }
}

console.log(...ans);