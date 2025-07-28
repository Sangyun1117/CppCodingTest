//문제
//N - Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
//
//N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N이 주어진다. (1 ≤ N < 15)
//
//	출력
//	첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
//
//	예제 입력 1
//	8
//	예제 출력 1
//	92

#include <iostream>
#include <vector>
using namespace std;
int N;
int answer = 0;
vector<bool> issue1;
vector<bool> issue2;
vector<bool> issue3;
void f(int y) {

	if (y == N) {
		answer++;
		return;
	}
	for (int x = 0; x < N; ++x) {
		if (issue1[x]|| issue2[x + y]|| issue3[x - y + N - 1])
			continue;
		issue1[x] = true;
		issue2[x + y] = true;
		issue3[x - y + N - 1] = true;
		f(y + 1);
		issue1[x] = false;
		issue2[x + y] = false;
		issue3[x - y + N - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	issue1 = vector<bool>(N, false);
	issue2 = vector<bool>(2*N - 1, false);
	issue3 = vector<bool>(2*N - 1, false);
	f(0);
	cout << answer;
}