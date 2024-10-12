/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, P, Q] = input[0].split(" ").map(Number);

/**
 * Solution
 */
const Solution = () => {
    const M = new Map();

    const solve = (i) => {
        if (M.has(i)) 
            return M.get(i);

        const value = solve(Math.floor(i / P)) + solve(Math.floor(i / Q));
        M.set(i, value);
        return value;
    };

    M.set(0, 1);

    return solve(N);
}

console.log(Solution());