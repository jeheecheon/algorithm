const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const Solution = () => {
    const [N, M] = input[0].split(" ").map(Number);

    const vis = Array(N + 1).fill(false);
    const lines = input.slice(1).map(a => a.split(" ").map(Number));
    
    const graph = Array.from({ length: N + 1 }, () => []);
    lines.forEach(line => {
        const [from, to] = line;
        graph[from].push(to);
        graph[to].push(from);
    });

    let ans = 0;

    for (let i = 1; i <= N; ++i) {
        if (vis[i])
            continue;

        ++ans;
        const queue = [];
        queue.unshift(i)
        while (queue.length) {
            const cur = queue.pop();

            for (const next of graph[cur]) {
                if (vis[next])
                    continue;

                vis[next] = true;
                queue.unshift(next);
            }
        }
    }

    return ans;
}

console.log(Solution());