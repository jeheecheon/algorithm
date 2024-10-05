/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
let arr = Array(N).fill(0).map((e, idx) => input[1 + idx].trim());

/**
 * Solution
 */
function isBoj(e) {
    if (e.startsWith("boj.kr/")){
        let num = e.slice(7);
        if (!isNaN(num) && +num >= 1 && +num <= 30000)
            return true;
    }
    return false;
}

arr.sort((a, b) => {
    const isABoj = isBoj(a);
    const isBBoj = isBoj(b);

    if (isABoj && isBBoj)
        return +a.slice(7) - +b.slice(7);
    if (isABoj)
        return 1;
    if (isBBoj)
        return -1;
    if (a.length !== b.length)
        return a.length - b.length;
    return a < b ? -1 : 1;
})

console.log(arr.join('\n'));