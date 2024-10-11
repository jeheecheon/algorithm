/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

/**
 * Solution
 */

const S = {};

const used = Array(1000001);
for (let i = 1; i <= N; ++i) {
    // 배열
    let arr = input[i].split(" ").map(Number);
    
    used.fill(false);

    arr.forEach(e => {
        used[e] = true;
    })

    let sorted = []
    used.forEach((e, idx) => {
        if (e)
            sorted.push(idx);
    })
    
    const converted = [];
    arr.forEach(e => {
        let st = 0, end = sorted.length - 1;

        while (st < end) {
            const mid = Math.trunc((st + end) / 2);

            if (sorted[mid] >= e)
                end = mid;
            else
                st = mid + 1;
        }

        converted.push(st);
    });

    const str = converted.join('');
    if (S[str] !== undefined)
        ++S[str];
    else
        S[str] = 1;
}

const pairs = Array(101).fill(0);
for (let i = 2; i <= 100; ++i) {
    pairs[i] = pairs[i - 1] + i - 1;
}

let ans = 0;
for (const e of Object.values(S))
    ans += pairs[e];

console.log(ans);
