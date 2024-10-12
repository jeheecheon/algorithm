const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const N = +input[0];
    const arr = input[1].split(" ").map(Number);

    arr.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < N - 1; ++i) {
        for (let j = i + 1; j < N; ++j) {
            const target = -(arr[i] + arr[j]);

            let lower = lowerBound(arr, j + 1, N - 1, target);
            let upper = upperBound(arr, j + 1, N - 1, target);

            if (arr[lower] === target) {
                ans += upper - lower + (arr[upper] === target ? 1 : 0);
            }
        }
    }

    return ans;

    function lowerBound(arr, st, end, target) {
        while (st < end) {
            const mid = Math.floor((st + end) / 2);
            if (arr[mid] >= target) 
                end = mid;
            else 
                st = mid + 1;
        }
        return st;
    }

    function upperBound(arr, st, end, target) {
        while (st < end) {
            const mid = Math.floor((st + end) / 2);
            if (arr[mid] > target)
                end = mid;
            else 
                st = mid + 1;
        }
        return st;
    }
}

console.log(solution());
