/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const [s, p] = input[0].split(" ").map(Number);
const DNA = input[1];
const [A, C, G, T] = input[2].split(" ").map(Number);

let q = 0,
    w = 0,
    e = 0,
    r = 0;
for (let i = 0; i < p; ++i) {
    switch (DNA[i]) {
        case "A":
            ++q;
            break;
        case "C":
            ++w;
            break;
        case "G":
            ++e;
            break;
        case "T":
            ++r;
            break;
    }
}

let ans = 0;
if (q >= A && w >= C && e >= G && r >= T) ++ans;

let st = 0,
    end = p - 1;
while (end + 1 < s) {
    switch (DNA[st]) {
        case "A":
            --q;
            break;
        case "C":
            --w;
            break;
        case "G":
            --e;
            break;
        case "T":
            --r;
            break;
    }
    ++st;
    ++end;

    switch (DNA[end]) {
        case "A":
            ++q;
            break;
        case "C":
            ++w;
            break;
        case "G":
            ++e;
            break;
        case "T":
            ++r;
            break;
    }

    if (q >= A && w >= C && e >= G && r >= T) ++ans;
}

console.log(ans);
