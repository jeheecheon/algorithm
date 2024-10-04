function solution(sequence, k) {
    let st = 0, end = 0;
    let sum = 0, cnt = 0;
    let len = 0x7fffffff;
    let ans;

    while (end - 1 < sequence.length) {
        if (sum < k) {
            sum += sequence[end++];
            continue;
        }

        while (sum > k)
            sum -= sequence[st++];
        
        if (sum == k) {
            if (end - st < len) {
                len = end - st;
                ans = [st, end - 1];
            }
            sum -= sequence[st++];
        }
    }
    
    return ans;
}