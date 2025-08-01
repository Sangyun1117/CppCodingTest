//문제
//지훈이는 미로에서 일을 한다.지훈이를 미로에서 탈출하도록 도와주자!
//
//미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 
// 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
//
//지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
//
//불은 각 지점에서 네 방향으로 확산된다.
//
//지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
//
//지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
//
//입력
//입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다.단, 1 ≤ R, C ≤ 1000 이다.R은 미로 행의 개수, C는 열의 개수이다.
//
//다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
//
//각각의 문자들은 다음을 뜻한다.
//
//#: 벽
//. : 지나갈 수 있는 공간
//J : 지훈이의 미로에서의 초기위치(지나갈 수 있는 공간)
//F : 불이 난 공간
//J는 입력에서 하나만 주어진다.
//
//출력
//지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
//
//지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.
//
//예제 입력 1
//4 4
//####
//#JF#
//#..#
//#..#
//예제 출력 1
//3


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct Pos {
	int y;
	int x; 
};

int bfs(Pos start,vector<Pos>& fires, vector<vector<char>>& v) {
	queue<Pos> fireQ;
	vector<vector<int>> visitedFire(R, vector<int>(C, -1));
	for (Pos fire : fires) {
		visitedFire[fire.y][fire.x] = 0;
		fireQ.push(fire);
	}
	while (!fireQ.empty()) {
		Pos now = fireQ.front(); fireQ.pop();
		int y = now.y;
		int x = now.x;

		for (int i = 0; i < 4; ++i) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				continue;
			if (v[nextY][nextX] == '#' || v[nextY][nextX] == 'F' || visitedFire[nextY][nextX] != -1)
				continue;
			visitedFire[nextY][nextX] = visitedFire[y][x] + 1;
			fireQ.push({ nextY, nextX });
		}
	}


	queue<Pos> q;
	q.push(start);

	vector<vector<int>> visited(R, vector<int>(C, -1));
	visited[start.y][start.x] = 0;

	while (!q.empty()) {
		Pos now = q.front(); q.pop();
		int y = now.y;
		int x = now.x;

		if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
			if (visitedFire[y][x] == -1 || visited[y][x] <= visitedFire[y][x])
				return visited[y][x] + 1;
			else
				continue;
		}

		for (int i = 0; i < 4; ++i) {
			int nextY = now.y + dy[i];
			int nextX = now.x + dx[i];

			if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				continue;

			if (visited[nextY][nextX] != -1 || v[nextY][nextX] != '.')
				continue;
			if (visitedFire[nextY][nextX] != -1 && visitedFire[nextY][nextX] <= visited[y][x] + 1)
				continue;
			visited[nextY][nextX] = visited[y][x] + 1;
			q.push({ nextY, nextX});
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	vector<vector<char>> v(R, vector<char>(C));

	Pos start;
	vector<Pos> fires;
	for (int i = 0; i < R; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; ++j) {
			v[i][j] = tmp[j];
			if (tmp[j] == 'J')
				start = { i, j };
			else if (tmp[j] == 'F')
				fires.push_back({ i, j });
		}
	}
	int answer = bfs(start, fires, v);
	if (answer == -1)
		cout << "IMPOSSIBLE";
	else
		cout << answer;
}









