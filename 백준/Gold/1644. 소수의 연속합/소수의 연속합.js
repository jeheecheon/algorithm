/**
 * Max Heap
 */
class Heap {
    #heap = [];
    #compare;

    constructor(compareFunction) {
        this.#compare = compareFunction;
    }

    // 부모 인덱스 계산
    #parentIndex(index) {
        return Math.floor((index - 1) / 2);
    }

    // 왼쪽 자식 인덱스 계산
    #leftChildIndex(index) {
        return 2 * index + 1;
    }

    // 오른쪽 자식 인덱스 계산
    #rightChildIndex(index) {
        return 2 * index + 2;
    }

    // 요소 추가
    push(value) {
        this.#heap.push(value);
        this.#heapifyUp();
    }

    // 길이 반환
    size() {
        return parseInt(this.#heap.length);
    }

    // 요소 제거 및 반환
    pop() {
        if (this.#heap.length === 1) return this.#heap.pop();

        const root = this.#heap[0];
        this.#heap[0] = this.#heap.pop(); // 마지막 요소를 루트로
        this.#heapifyDown();
        return root;
    }

    front() {
        // 루트 요소 반환
        return this.#heap.length > 0 ? this.#heap[0] : null;
    }

    #heapifyUp() {
        // 힙을 위로 정렬 (삽입 시)
        let index = this.#heap.length - 1;
        while (index > 0) {
            const parentIdx = this.#parentIndex(index);
            if (this.#compare(this.#heap[parentIdx], this.#heap[index]) >= 0) break;

            [this.#heap[parentIdx], this.#heap[index]] = [this.#heap[index], this.#heap[parentIdx]];
            index = parentIdx;
        }
    }

    #heapifyDown() {
        // 힙을 아래로 정렬 (삭제 시)
        let index = 0;
        const length = this.#heap.length;

        while (this.#leftChildIndex(index) < length) {
            let betterChildIndex = this.#leftChildIndex(index);
            if (
                this.#rightChildIndex(index) < length &&
                this.#compare(
                    this.#heap[this.#rightChildIndex(index)],
                    this.#heap[betterChildIndex]
                ) > 0
            )
                betterChildIndex = this.#rightChildIndex(index);

            if (this.#compare(this.#heap[index], this.#heap[betterChildIndex]) >= 0) break;

            [this.#heap[index], this.#heap[betterChildIndex]] = [
                this.#heap[betterChildIndex],
                this.#heap[index]
            ];
            index = betterChildIndex;
        }
    }

    isEmpty() {
        return this.#heap.length === 0;
    }
}

/**
 * Input
 */
const filePath = process.platform === "linux" ? "/dev/stdin" : "./src/input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const n = +input[0].trim();

/**
 * Solution
 */

const che = Array(n + 1).fill(false);
for (let i = 2; i <= n; ++i) {
    if (che[i])
        continue;

    for (let j = 2 * i; j <= n; j += i)
        che[j] = true
}

const sosu = []
for (let i = 2; i <= n; ++i)
    if (!che[i])
        sosu.push(i);

if (sosu.length == 0) {
    console.log(0);
}
else {
    let st = 0, end = 0;
    let sum = 0;
    let cnt = 0;
    
    while (end < sosu.length + 1) {
        if (sum < n) {
            sum += sosu[end++];
            continue;
        }

        while (sum > n) 
            sum -= sosu[st++]
        
        if (sum == n) {
            ++cnt;
            sum += sosu[end++];
        }
    }
    
    console.log(cnt);
}
