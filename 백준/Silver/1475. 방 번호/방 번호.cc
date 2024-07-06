#include <iostream>

using namespace std;

int main(void)
{
    int cnts[10] = { 0 };
    string numbers;
    cin >> numbers;

    // 0 ~ 9 각각 몇 번이나 등장하는지 cnts 배열에 저장
    for (char numberCharacter : numbers) {
        ++cnts[numberCharacter - '0'];
    }

    int maxCnt = 0;
    // 6, 9를 제외한 숫자들의 등장 횟수를 maxCnt에 저장
    for (int i = 0; i < 10; ++i) {
        if (i == 6 || i == 9)
            continue;

        maxCnt = (cnts[i] > maxCnt) ? cnts[i] : maxCnt;
    }

    // 6과 9의 개수로 필요한 숫자셋이 몇 개인지 계산
    int sixAndNineDiviedBy2 = (cnts[6] + cnts[9] + 1) / 2;
    
    cout << (maxCnt > sixAndNineDiviedBy2 ? maxCnt : sixAndNineDiviedBy2);
}