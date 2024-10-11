/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

/**
 * Solution
 */

const paired = Array(M + 1).fill(0);
const lampsSet = [];

input.slice(1).forEach(a => {
    const [lampCnt, ...lamps] = a.split(' ').map(Number);
    lamps.forEach(b => ++paired[b]);
    lampsSet.push(lamps);
});

let pos = false;
for (const a of lampsSet) {
    a.forEach(b => --paired[b]);

    if (Math.min(...paired.slice(1)) !== 0) {
        pos = true;
        break;
    }

    a.forEach(b => ++paired[b]);
}

console.log(pos ? 1 : 0);
