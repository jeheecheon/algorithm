const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

function nextPermutation(arr, st, end) {
    // end에서부터 st 방향으로 배열이 내림차순인지 확인, 내림차순이 아니기 시작하는 첫 인덱스를 변수 x에 대입
    let x = -1;
    for (let i = end; i >= st + 1; --i) {
        if (arr[i - 1] < arr[i]) {
            x = i - 1;
            break;
        }
    }

    // 배열의 원소가 모두 내림차순이면 false 반환
    if (x === -1) 
        return false;

    // (x+1)..end 범위에서 arr[x]보다 값이 크면서 가장 작은 원소의 인덱스를 변수 y에 대입.
    let y;
    let mini = Infinity;
    for (let i = x + 1; i <= end; ++i) {
        if (arr[i] < mini && arr[i] > arr[x]) {
            mini = arr[i];
            y = i;
        }
    }

    // arr[x]와 arr[y]의 값을 교환
    [arr[x], arr[y]] = [arr[y], arr[x]];

    // (x+1)..end 범위의 요소를 오름차순 정렬
    arr.slice(x + 1)
        .sort((a, b) => a - b)
        .forEach((val, idx) => (arr[x + 1 + idx] = val));

    // 사전순으로 다음 순열인 배열로 교환 완료
    return true;
}

function solution() {
    const arr = input[1].split(" ").map(Number);
    return nextPermutation(arr, 0, arr.length - 1) === true ? arr.join(" ") : -1
}

console.log(solution());
