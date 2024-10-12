/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const vilions = input[1].split(" ").map(Number).slice(1);
const parties = Array(M)
    .fill(0)
    .map((_, idx) => input[2 + idx].split(" ").map(e => Number(e.trim())).slice(1))

/**
 * Solution
 */
const Solution = () => {
    const S = new Set();
    vilions.forEach(person => S.add(person));

    for (let i = 0; i < M; ++i) {
        parties.forEach(party => {
            const hasVilion = party.some(person => S.has(person));

            if (hasVilion)
                party.forEach(person => S.add(person));
        });
    }

    let cnt = 0;

    parties.forEach(party => {
        const noVilion = party.some(person => S.has(person));
        
        if (noVilion)
            ++cnt;
    })
    
    return M - cnt;
}

console.log(Solution());