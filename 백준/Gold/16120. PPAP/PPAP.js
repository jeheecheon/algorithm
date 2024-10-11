/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let str = input[0].trim();

/**
 * Solution
 */

const stack = [];
str.split('').forEach(e => {
    stack.push(e);

    while (stack.length >= 4) {
        const str = stack.slice(-4).reduce((prev, cur) => prev + cur, "");
        if (str !== "PPAP")
            break;

        stack.length -= 4;
        stack.push("P");
    }
});

console.log(stack.length === 1 && stack[0] === "P" ? "PPAP" : "NP");