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

let T = +input[0].trim();

/**
 * Solution
 */

const ans = [];

for (let i = 0; i < T; ++i) {
    let arr1 = input[2 + i * 4].split(" ").map(Number);
    const arr2 = input[4 + i * 4].split(" ").map(Number);

    arr1 = arr1.sort((a, b) => a - b);
    arr2.forEach(e => {
        let st = 0;
        let end = arr1.length - 1;

        let pos = 0;

        while (st <= end) {
            const mid = ~~((end + st) / 2);

            if (arr1[mid] == e) {
                pos = 1;
                break;
            }

            if (arr1[mid] > e) 
                end = mid - 1;
            else 
                st = mid + 1;
        }

        ans.push(pos);
    });
}

console.log(ans.join("\n"));
