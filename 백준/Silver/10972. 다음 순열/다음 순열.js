const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function prevPermutation(arr) {
    let x = -1;
    for (let i = arr.length - 1; i >= 1; --i) {
        if (arr[i - 1] < arr[i]) {
            x = i - 1;
            break;
        }
    }
    if (x === -1)
        return -1;

    let y;
    let mini = Infinity;
    for (let i = x + 1; i < arr.length; ++i) {
        if (arr[i] < mini && arr[i] > arr[x]) {
            mini = arr[i];
            y = i;
        }
    }

    [arr[x], arr[y]] = [arr[y], arr[x]];
    return [...arr.slice(0, x + 1), ...arr.slice(x + 1).sort((a, b) => a - b)];
}

function solution() {
    const arr = input[1].split(" ").map(Number);
    return [prevPermutation(arr)].flat().join(" ");
}

console.log(solution());
