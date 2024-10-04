/*
많이 준 놈이 받는다
서로 선물을 안 줬거나, 선물을 한 횟수가 같다면 선물지수가 높은 쪽이 받는다
선물 지수란 <준 선물 수 - 받은 선물 수>
이것 마저 같다면 선물을 서로 교환 안 함

다음 달에 가장 많은 선물 받는 "수"
gifits 는 "from to"
*/

function solution(friends, gifts) {
    const list = {}
    friends.forEach((name, idx) => list[name] = idx);
    
    const n = friends.length;
    // n * n
    const board1 = Array.from({ length: n}, () => Array.from({ length: n}, () => 0));
    // n * 2
    const board2 = Array.from({ length: n}, () => Array.from({ length: 2}, () => 0));
    
    gifts.forEach((str) => {
        [from, to] = str.split(" ").map(e => list[e]);
        ++board1[from][to];
        ++board2[from][1]; // 준 횟수
        ++board2[to][0]; // 받은 횟수
    });
    
    const cnts = Array(friends.length).fill(0);
    const vis = Array.from({ length: n }, () => Array.from({ length: n}, () => 0))
    
    friends.forEach((from) => {
        const i1 = list[from]
        friends.forEach((to) => {
            const i2 = list[to];
            
            if (i1 != i2 && !vis[i1][i2]) {
                vis[i1][i2] = vis[i2][i1] = true;
                
                // 선물 횟수가 같을 때
                if (board1[i1][i2] == board1[i2][i1]) {
                    const i1Score = board2[i1][1] - board2[i1][0];
                    const i2Score = board2[i2][1] - board2[i2][0];
                
                    if (i1Score > i2Score) {
                        ++cnts[i1];
                    } else if (i1Score < i2Score) {
                        ++cnts[i2];
                    }
                } else if (board1[i1][i2] > board1[i2][i1]) {
                    ++cnts[i1];
                } else {
                    ++cnts[i2];
                }
            }
       });
    });
    
    return Math.max(...cnts);
}