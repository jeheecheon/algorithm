const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function solution() {
    const [_, M] = input[0].split(" ").map(Number);
    const arr = input[1].split(" ").map(Number);
    
    let sum = arr[0];
    let st = 0;
    let end = 0;
    let maxi = -Infinity;
    while (end < arr.length) {
        if (end - st + 1 < M) {
            sum += arr[++end];
            continue;
        }
         
        maxi = Math.max(sum, maxi);

        sum = sum - arr[st++] + arr[++end];
    }

    return maxi;
}

console.log(solution());
