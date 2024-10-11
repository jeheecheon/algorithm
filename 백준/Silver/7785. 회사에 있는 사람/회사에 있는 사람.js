/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const people = {};
const ans = [];
input.slice(1).forEach(e => {
    const [name, status] = e.trim().split(' ').map(e => e.trim());
    people[name] = status;
});

for (const [name, status] of Object.entries(people)) {
    if (status === "enter")
        ans.push(name);
}

console.log(ans.sort().reverse().join('\n'));