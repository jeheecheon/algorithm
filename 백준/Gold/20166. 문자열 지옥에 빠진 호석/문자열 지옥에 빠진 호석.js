/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M, K] = input[0].split(" ").map(Number);
const board = Array(N).fill(0).map((_, idx) => input[1 + idx].trim());

/**
 * Solution
 */

const dirs = [
    [1, 0],
    [0, 1],
    [-1, 0],
    [0, -1],
    [1, 1],
    [-1, -1],
    [1, -1],
    [-1, 1]
]

const ans = [];
const DP = new Map();

input.slice(N + 1).map(e => e.trim()).forEach(e => {
    let cnt = 0;
    if (DP.has(e)) {
        ans.push(DP.get(e));
    }
    else {
        for (let i = 0; i < N; ++i) {
            for (let j = 0; j < M; ++j) {
                const stack = [];
                stack.push([0, i, j]);
    
                while (stack.length) {
                    const [a, cx, cy] = stack.pop(); // a는 반복 횟수
    
                    if (board[cx][cy] !== e[a])
                        continue;
    
                    if (a === e.length - 1) {
                        ++cnt;
                        continue;
                    }
    
                    for (const [dx, dy] of dirs) {
                        let [nx, ny] = [cx + dx, cy + dy];
    
                        if (nx === -1)
                            nx = N - 1;
                        else if (nx === N)
                            nx = 0;
                        if (ny === -1)
                            ny = M - 1;
                        else if (ny === M)
                            ny = 0;
                        
                        stack.push([a + 1, nx, ny])
                    }
                }
            }
        }
    
        ans.push(cnt)
        DP.set(e, cnt);
    }
});

console.log(ans.join('\n'));
