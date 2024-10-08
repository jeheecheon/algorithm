/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];

/**
 * Solution
 */
let che = Array(1100001).fill(false);
che[1] = true;
for (let i = 2; i <= 1100000; ++i) {
    if (che[i])
        continue;

    for (let j = i * 2; j <= 1100000; j += i)
        che[j] = true;
}

for (let i = N; i <= 1100000; ++i) {
    if (che[i])
        continue;

    if (String(i) === String(i).split('').reverse().join('')) {
        console.log(i);
        break;
    }
}
