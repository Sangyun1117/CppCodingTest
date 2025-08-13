//문제
//처음에 왼쪽이 큐의 뒤, 오른쪽이 큐의 앞인 가로 방향의 빈 큐가 존재한다.
// 이 큐에서 공이나 가림막을 하나씩 큐의 뒤에 삽입하거나, 
// 큐의 가장 앞에 있는 공이나 가림막을 꺼낼 수 있으며, 
// 큐를 시계방향이나 반시계방향으로 90도 회전시킬 수 있다.

//큐 안의 가림막은 중력의 영향을 받지 않지만, 
// 큐 안의 공은 중력의 영향을 받는다.따라서 큐를 세로 방향으로 회전시켰을 때, 
// 큐의 가장 아래에 있는 가림막보다 아래에 있는 공들은 모두 떨어져 큐에서 꺼내지게 된다.

//또한, 큐가 세로 방향이면 공을 새로 넣더라도 넣은 공 아래에 가림막이 존재하지 않는 경우 곧바로 큐에서 꺼내지게 된다.

//$Q$개의 쿼리가 주어질 때, 처음 빈 상태의 큐에 주어진 쿼리들을 순서대로 수행하는 프로그램을 작성하시오.
//
//입력
//첫 번째 줄에 쿼리의 개수
//$Q$가 주어진다.
//
//두 번째 줄부터
//$Q$개의 줄에 걸쳐 첫 번째 쿼리부터 순서대로 각 쿼리의 정보가 순서대로 주어진다.
//
//push b : 큐의 뒤에 공 하나를 삽입한다.
//push w : 큐의 뒤에 가림막 하나를 삽입한다.
//pop : 큐에서 가장 앞쪽에 있는 공이나 가림막을 하나 꺼낸다.큐가 빈 상태면 아무 일도 일어나지 않는다.
//rotate l : 큐를 반시계 방향으로 90도 회전시킨다.
//rotate r : 큐를 시계 방향으로 90도 회전시킨다.
//count b : 현재 큐에 들어있는 공의 개수를 출력한다.
//count w : 현재 큐에 들어있는 가림막의 개수를 출력한다.
//출력
//count b 쿼리와 count w 쿼리의 정답을 한 줄에 하나씩 순서대로 출력한다.
//
//제한
//
//$1 ≤ Q ≤ 500\, 000$ 
//마지막 쿼리는 count b이다.
//예제 입력 1
//9
//push b
//push w
//push b
//push b
//count b
//count w
//pop
//rotate r
//count b
//예제 출력 1
//3
//1
//2
//예제 입력 2
//13
//push b
//rotate r
//count b
//rotate r
//push b
//push w
//rotate r
//push b
//push b
//count b
//rotate l
//push b
//count b
//예제 출력 2
//0
//1
//2

#include <iostream>
#include <deque>
using namespace std;

int N;
string command;
string obj;
deque<int> gravityQueue;//ball = 0, window = 1
int countBall = 0;
int countWindow = 0;
int state = 0;

void drop() {
	if (state == 1) {
		while (!gravityQueue.empty() && gravityQueue.back() == 0) {
			gravityQueue.pop_back();
			--countBall;
		}
	}
	if (state == 3) {
		while (!gravityQueue.empty() && gravityQueue.front() == 0) {
			gravityQueue.pop_front();
			--countBall;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> command;
		if (command == "push") {
			cin >> obj;
			if (obj == "b") {
				gravityQueue.push_back(0);
				++countBall;
				drop();
			}
			else {
				gravityQueue.push_back(1);
				++countWindow;
			}
		}
		else if (command == "pop") {
			if (gravityQueue.empty())
				continue;
			int tmp = gravityQueue.front();
			if (tmp == 0)
				--countBall;
			else
				--countWindow;
			gravityQueue.pop_front();
			drop();
		}
		else if (command == "rotate") {
			cin >> obj;
			if (obj == "r") {
				state = state != 0 ? --state : 3;
				drop();
			}
			else {
				state = (state + 1) % 4;
				drop();
			}
		}
		else if (command == "count") {
			cin >> obj;
			if (obj == "b") {
				cout << countBall << "\n";
			}
			else {
				cout << countWindow << "\n";
			}
		}

	}
}