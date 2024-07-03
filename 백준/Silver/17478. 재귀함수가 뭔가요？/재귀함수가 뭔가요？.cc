#include <iostream>
#include <vector>

using namespace std;

vector<string> arr1 = {
	"\"재귀함수가 뭔가요?\"",
	"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
	"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
	"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};
vector<string> arr2 = {
	"\"재귀함수가 뭔가요?\"",
	"\"재귀함수는 자기 자신을 호출하는 함수라네\""
};

int N;

void indent(int i) {
	while (i--) 
		cout << "____";
}

void solve(int i) {
	if (i < 0)
		return;

	vector<string>* pv = (i == 0) ? &arr2 : &arr1;

	for (auto str : *pv) {
		indent(N - i);
		cout << str << '\n';
	}

	solve(i - 1);

	indent(N - i);
	cout << "라고 답변하였지." << '\n';
}

int main(void) {
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
  cin >> N;
  solve(N);
}
