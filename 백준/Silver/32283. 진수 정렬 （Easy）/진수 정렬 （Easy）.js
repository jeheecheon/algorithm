const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const N = +input[0];
    const targetBinary = input[1];

    const arr = [];
    for (let i = 0; i < (1 << N); i++) {
        const binaryStr = i.toString(2).padStart(N, '0');
        arr.push(binaryStr);
    }

    arr.sort((a, b) => {
        const acnt = a.split("").filter(x => x === '1').length;
        const bcnt = b.split("").filter(x => x === '1').length;
        
        if (acnt === bcnt) {
            return a.split("").reverse().join("").localeCompare(b.split("").reverse().join(""));
        }
        return acnt - bcnt;
    });

    return arr.indexOf(targetBinary);
}

console.log(solution());
