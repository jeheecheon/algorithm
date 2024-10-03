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

const [n, k] = input[0].split(" ").map(Number);
const jewels = Array(n)
    .fill(0)
    .map((_, i) => input[i + 1].split(" ").map(Number));
const bags = Array(k)
    .fill(0)
    .map((_, i) => +input[n + i + 1]);

/**
 * Solution
 */
jewels.sort((a, b) => a[0] - b[0]);
bags.sort((a, b) => a - b);

let maxValue = 0;
let index = 0;
const maxHeap = new Heap((a, b) => a - b);

for (const bag of bags) {
    while (index < n && jewels[index][0] <= bag) {
        maxHeap.push(jewels[index][1]);
        index++;
    }

    if (!maxHeap.isEmpty()) maxValue += maxHeap.pop();
}

console.log(maxValue);
