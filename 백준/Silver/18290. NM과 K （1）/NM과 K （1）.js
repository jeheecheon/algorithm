const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const [N, M, K] = input[0].split(" ").map(Number);
    const board = input.slice(1).map(a => a.split(" ").map(Number))
    
    const dirs = [
        [0, 1],
        [1, 0],
        [-1, 0],
        [0, -1]
    ];
    let ans = -Infinity;

    const vis = Array.from({ length: N }, () => Array(M).fill(false));
    let sum = 0;

    function solve(k) {
        if (k === K) {
            ans = Math.max(ans, sum);
            return;
        }

        for (let i = 0; i < N; ++i) {
            for (let j = 0; j < M; ++j) {
                if (vis[i][j]) 
                    continue;

                let isAdj = false;
                for (const dir of dirs) {
                    const [nx, ny] = [i + dir[0], j + dir[1]];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && vis[nx][ny]) {
                        isAdj = true;
                        break;
                    }
                }

                if (isAdj) 
                    continue;
                
                vis[i][j] = true;
                sum += board[i][j];
    
                solve(k + 1);
    
                sum -= board[i][j];
                vis[i][j] = false;
            }
        }
    } 

    solve(0);

    return ans;
}

console.log(solution());