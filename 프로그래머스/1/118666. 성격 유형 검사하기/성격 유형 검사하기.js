const scores = {}
const types = ["R", "T", "C", "F", "J", "M", "A", "N"];
for (const type of types)
    scores[type] = 0;

function solve(a, b) {
    if (scores[a] == scores[b])
        return a.localeCompare(b) > 0 ? b : a;
    
    if (scores[a] < scores[b])
        return b;
    return a;
}

function solution(survey, choices) {
    for (let i = 0; i < survey.length; ++i) {
        const str = survey[i];
        let choice = choices[i];
        
        if (choice == 4)
            continue;
        
        let left = 1
        if (choice < 4) {
            left = 0;
            choice = 4 - choice;
        } else {
            choice -= 4;
        }
        
        scores[str[left]] += choice;
    }
    
    let answer = '';
    
    answer += solve('R', 'T');
    answer += solve('C', 'F');
    answer += solve('J', 'M');
    answer += solve('A', 'N');
    
    return answer;
}