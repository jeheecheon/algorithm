/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let T = +input[0];
for (let i = 1; i <= T; ++i) {
    let [k, DNA] = input[i].split(" ");
    k = +k;

    const M = new Map();
    let [A, G, T, C] = new Array(4).fill(0);

    for (let i = 0; i < DNA.length; ++i) {
        if (DNA[i] === "A") ++A;
        else if (DNA[i] === "G") ++G;
        else if (DNA[i] === "T") ++T;
        else ++C;
    }
    M["" + A + G + T + C] = 1;

    let st = 0,
        end = k - 1;
    while (end + 1 < DNA.length) {
        if (DNA[st] === "A") --A;
        else if (DNA[st] === "G") --G;
        else if (DNA[st] === "T") --T;
        else --C;

        ++st;
        ++end;

        if (DNA[end] === "A") ++A;
        else if (DNA[end] === "G") ++G;
        else if (DNA[end] === "T") ++T;
        else ++C;

        const key = "" + A + G + T + C;
        if (M[key] === undefined) M[key] = 1;
        else ++M[key];
    }

    let maxi = 0;
    for (const key in M) 
        maxi = Math.max(maxi, M[key]);

    console.log(maxi);
}
