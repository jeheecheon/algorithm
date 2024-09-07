/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const board = Array.from({ length: 5 });
input.forEach((v, i) => {
    board[i] = v.trim().split(" ");
});

const dirs = [
    [0, 1],
    [1, 0],
    [-1, 0],
    [0, -1]
];

const s = new Set();
for (let i = 0; i < 5; ++i) {
    for (let j = 0; j < 5; ++j) {
        const Q = [{ point: { x: i, y: j }, word: board[i][j] }];

        while (Q.length != 0) {
            const { point, word } = Q.pop();

            if (word.length == 6) {
                s.add(word);
                continue;
            }

            for (const [dx, dy] of dirs) {
                const [nx, ny] = [point.x + dx, point.y + dy];

                if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;

                Q.unshift({ point: { x: nx, y: ny }, word: word + board[nx][ny] });
            }
        }
    }
}

console.log(s.size);
