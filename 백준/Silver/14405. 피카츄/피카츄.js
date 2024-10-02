/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

let str = input[0].trim();

/**
 * Solution
 */

const regex = /^(pi|ka|chu)+$/;

if (regex.test(str)) {
    console.log("YES");
} else {
    console.log("NO");
}