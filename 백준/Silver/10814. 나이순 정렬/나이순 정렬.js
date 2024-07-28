/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
    .readFileSync(filePath)
    .toString()
    .trimEnd()
    .split("\n");

/**
 * Solution
 */
const n = +input[0];
const people = [];
for (let i = 1; i <= n; ++i) {
    const [age, name] = input[i].split(" ");
    people.push([+age, name, i]);
}

people.sort((a, b) => {
    if (a[0] === b[0]) {
        return a[2] - b[2];
    }
    return a[0] - b[0];
});

const result = [];
people.forEach((p) => {
    result.push(`${p[0]} ${p[1]}\n`);
});

console.log(result.join(""));
