const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const Solution = () => {
    const N = +input[0].trim();
    const dist = Array.from({ length: N + 1 }, () => Array(N + 1).fill(Infinity));

    // 입력
    input.slice(2).map(a => a.trim().split(" ").map(Number)).forEach(a => {
        const [from, to, val] = a;
        dist[from][to] = Math.min(dist[from][to], val); // 같은 경로 중 더 작은 비용 선택
    });
    
    // i에서 i로 가는 경로는 0
    for (let i = 1; i <= N; ++i)
        dist[i][i] = 0;
    
    // 플로이드
    for (let k = 1; k <= N; ++k)
        for (let i = 1; i <= N; ++i)
            for (let j = 1; j <= N; ++j)
                dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist.slice(1).map(a => a.slice(1).map(e => e === Infinity ? 0 : e).join(" ")).join('\n');
}

console.log(Solution());