/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
let cnt = 0;
arr.sort((a, b) => a - b);

for (let c = 0; c < arr.length; ++c) {
    for (let a = 0; a < arr.length; ++a) {
        if (c === a)
            continue;

        const b = arr[c] - arr[a];

        let st = 0, end = arr.length - 1;

        let found = false;
        while (st <= end) {
            const mid = Math.floor((st + end) / 2);
            if (arr[mid] === b) {
                if (mid !== c && mid !== a) {
                    cnt++;
                    found = true;
                    break;
                } else if (mid === c) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (arr[mid] < b) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (found)
            break;
    }
}

console.log(cnt);