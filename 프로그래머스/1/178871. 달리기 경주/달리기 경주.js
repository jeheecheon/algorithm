function solution(players, callings) {
    const ranks = {};
    players.forEach((e, i) => ranks[e] = i);
    callings.forEach(name1 => {
        let rank = ranks[name1];
        const name2 = players[rank - 1];
        
        [ranks[name1], ranks[name2]] = [ranks[name2], ranks[name1]];
        [players[rank], players[rank - 1]] = [players[rank - 1], players[rank]]
    });
    return players;
}