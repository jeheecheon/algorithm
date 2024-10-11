
/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];

/**
 * Solution
 */
const serialRank = new Map();
const rankSerial = new Map();

for (let i = 1; i <= N; ++i) {
    const serial = input[i].trim();
    serialRank.set(serial, i);
    rankSerial.set(i, serial);
}

let cnt = 0;
for (let i = 1; i <= N; ++i) {
    const serial = input[i + N].trim();
    const rank = serialRank.get(serial);

    if (rank > i) {
        ++cnt;

        for (let j = rank; j > i; --j) {
            const ser = rankSerial.get(j - 1);
            serialRank.set(ser, j);
            rankSerial.set(j, ser);
        }
        serialRank.set(serial, i);
        rankSerial.set(i, serial);
    }
}

console.log(cnt);
