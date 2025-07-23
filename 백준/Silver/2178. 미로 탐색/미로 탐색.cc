//문제 2178 미로찾기(실버 1)
//N×M크기의 배열로 표현되는 미로가 있다.
//
//1	 0	1	1	1	1
//1	 0	1	0	1	0
//1	 0	1	0	1	1
//1	 1 	1	0	1	1
//미로에서 1은 이동할 수 있는 칸을 나타내고, 
// 0은 이동할 수 없는 칸을 나타낸다.
// 이러한 미로가 주어졌을 때, 
// (1, 1)에서 출발하여(N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
// 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
//
//위의 예에서는 15칸을 지나야(N, M)의 위치로 이동할 수 있다.
// 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
//
//입력
//첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
// 다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
// 각각의 수들은 붙어서 입력으로 주어진다.
//
//출력
//첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
//
//예제 입력 1
//4 6
//101111
//101010
//101011
//111011
//예제 출력 1
//15
// 
//예제 입력 2
//4 6
//110110
//110110
//111111
//111101
//예제 출력 2
//9
// 
//예제 입력 3
//2 25
//1011101110111011101110111
//1110111011101110111011101
//예제 출력 3
//38
// 
//예제 입력 4
//7 7
//1011111
//1110001
//1000001
//1000001
//1000001
//1000001
//1111111
//예제 출력 4
//13


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct Node{
	int y;
	int x;
	int count;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	string line;
	vector<vector<int>> miro(N, vector<int>(M));
	vector<vector<bool>>visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; ++i) {
		cin >> line;
		for (int j = 0; j < M; ++j) {
			miro[i][j] = line[j] - '0';
		}
	}

	visited[0][0] = true;
	queue<Node> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int nowY = now.y;
		int nowX = now.x;
		int nowCount = now.count;
		if (nowY == N - 1 && nowX == M - 1) {
			std::cout << nowCount;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
				continue;
			}
			if (miro[nextY][nextX] == 0 || visited[nextY][nextX])
				continue;
			visited[nextY][nextX] = true;
			q.push({ nextY, nextX, nowCount+1 });
		}
	}
}