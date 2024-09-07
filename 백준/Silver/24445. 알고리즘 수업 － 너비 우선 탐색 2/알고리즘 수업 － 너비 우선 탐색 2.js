/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
let [N, M, R] = input[0].split(" ").map(Number);
--R;
const graph = Array.from({ length: N }, () => []);

for (let i = 1; i <= M; ++i) {
    let [x, y] = input[i].split(" ").map(Number);
    --x, --y;
    graph[x].push(y);
    graph[y].push(x);
}

for (let i = 0; i < N; ++i) graph[i].sort((a, b) => b - a);

const vis = Array.from({ length: N }, () => 0);
vis[R] = 1;
const Q = [R];
let cnt = 1;
while (Q.length) {
    const cur = Q.shift();

    for (const next of graph[cur]) {
        if (vis[next]) continue;

        vis[next] = ++cnt;
        Q.push(next);
    }
}

console.log(vis.join("\n"));
