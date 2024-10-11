/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

/**
 * Solution
 */
const deque = [];
const ans = [];
input.slice(1).forEach(e => {
    let [command, num] = e.trim().split(" ");
    num = +num;

    switch (command) {
        case "push_back":
            deque.push(num);
            break;
        case "push_front":
            deque.unshift(num);
            break;
        case "front":
            ans.push(deque.length ? deque[0] : -1);
            break;
        case "back":
            ans.push(deque.length ? deque[deque.length - 1] : -1);
            break;
        case "size":
            ans.push(deque.length);
            break;
        case "empty":
            ans.push(deque.length ? 0 : 1);
            break;
        case "pop_front":
            if (deque.length)
                ans.push(deque.shift());
            else
                ans.push(-1);
            break;
        case "pop_back":
            if (deque.length)
                ans.push(deque.pop());
            else
                ans.push(-1);
            break;
    }
});

console.log(ans.join('\n'));