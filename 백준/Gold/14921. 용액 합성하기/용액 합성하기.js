/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const arr = input[1].split(" ").map(Number);

/**
 * Solution
 */
let mini = Infinity;

for (let i = 0; i < arr.length - 1; ++i) {
    let st = i + 1, end = arr.length - 1;

    while (st < end) {
        const mid = Math.trunc((st + end) / 2);

        if (arr[mid] >= -arr[i])
            end = mid;
        else
            st = mid + 1;
    }
    
    if (Math.abs(arr[i] + arr[st]) < Math.abs(mini))
        mini = arr[i] + arr[st]
    
    st = i + 1, end = arr.length - 1;

    while (st < end) {
        const mid = Math.trunc((st + end + 1) / 2);
        
        if (arr[mid] < -arr[i]) 
            st = mid;
        else 
            end = mid - 1;
    }

    if (Math.abs(arr[i] + arr[st]) < Math.abs(mini))
        mini = arr[i] + arr[st]
}

console.log(mini)
