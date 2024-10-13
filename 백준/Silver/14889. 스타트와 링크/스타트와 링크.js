const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const N = +input[0];
    const arr = input.slice(1).map((a) => a.trim().split(" ").map(Number));

    let dif = Infinity;

    for (let i = 0; i < 1 << N; ++i) {
        const team1 = [];
        const team2 = []

        for (let j = 0; j < N; ++j) {
            if (i & (1 << j))
                team1.push(j);
            else
                team2.push(j);
        }

        if (team1.length !== N / 2)
            continue;

        let score1 = 0;
        for (let a = 0; a < team1.length; ++a) {
            for (let b = a + 1; b < team1.length; ++b) {
                score1 += arr[team1[a]][team1[b]];
                score1 += arr[team1[b]][team1[a]];
            }
        }

        let score2 = 0;
        for (let a = 0; a < team2.length; ++a) {
            for (let b = a + 1; b < team2.length; ++b) {
                score2 += arr[team2[a]][team2[b]];
                score2 += arr[team2[b]][team2[a]];
            }
        }

        dif = Math.min(dif, Math.abs(score1 - score2));
    }

    return dif;
}

console.log(solution());
