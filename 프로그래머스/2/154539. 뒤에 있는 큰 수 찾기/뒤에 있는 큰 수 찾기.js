function solution(numbers) {
    let answer = [];
    const S = [];
    
    numbers.forEach((e, idx) => {
        while (S.length > 0 && S[S.length - 1][0] < e) {
            answer.push([e, S[S.length - 1][1]]);
            S.pop();
        }

        S.push([e, idx]);
    });
    
    while (S.length > 0) {
        answer.push([-1, S[S.length - 1][1]]);
        S.pop();
    }
    answer = answer.sort((a, b) => a[1] - b[1]).map(e => e[0]);
    return answer;
}