/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input: string[] = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const [n, m] = input[0].split(" ").map(Number);

function GCD(a: number, b: number): number {
    if (b === 0) return a;
    return GCD(b, a % b);
}

const gcd = GCD(n, m);
const lcm = (n * m) / gcd;

console.log(gcd, lcm);