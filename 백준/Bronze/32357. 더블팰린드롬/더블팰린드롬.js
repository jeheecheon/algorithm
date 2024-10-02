// baekjoon 32357

/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let n = +input[0];

let cnt = 0;
for (let i = 1; i <= n; ++i) {
    const str = input[i].trim();

    let st = 0,
        end = str.length - 1;
    let same = true;
    for (; st < str.length / 2; ++st, --end) {
        if (str[st] != str[end]) {
            same = false;
            break;
        }
    }

    if (same) {
        ++cnt;
    }
}

let ans = cnt * (cnt - 1);
ans = Math.max(0, ans);
console.log(ans);
