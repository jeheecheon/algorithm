/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs")
    .readFileSync(filePath)
    .toString()
    .trim()
    .split("\n");

const [S, E, Q] = input[0].split(' ').map(e => e.trim());

/**
 * Solution
 */

function convertToNum(str) {
    return str
        .split(':')
        .reduce((prev, cur, idx) => prev + cur * (idx === 0 ? 60 : 1) ,0);
}

const [start, end, streamEnd] = [convertToNum(S), convertToNum(E), convertToNum(Q)];

const map = {};

input.slice(1).forEach(e => {
    const [timeIn24, name] = e.trim().split(" "); 
    const time = convertToNum(timeIn24);
    
    if (time <= start) {
        map[name] = 1;
    }
    else if (time >= end && time <= streamEnd) {
        if (map[name])
            map[name] = 2;
    }
});

let ans = 0;
for (const cnt of Object.values(map)) {
    if (cnt >= 2)
        ++ans;
}

console.log(ans);
