

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct Pos {
	int y;
	int x;
	int count;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n; //m은 가로, n은 세로
	vector<vector<int>>arr(n, vector<int>(m, 0));
	vector<vector<bool>>visited(n, vector<bool>(m, 0));
	vector<Pos>firstTomato;
	queue<Pos> q;
	int nowTomato = 0;
	int wantTomato = n * m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i, j, 0 });
				visited[i][j] = true;
				nowTomato++;
			}
			else if (arr[i][j] == -1) {
				wantTomato--;
			}
		}
	}

	int answer = 0;
	while (!q.empty()) {
		Pos now = q.front(); q.pop();
		int nowY = now.y;
		int nowX = now.x;
		int nowCount = now.count;

		for (int i = 0; i < 4; ++i) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
				continue;
			if (visited[nextY][nextX] || arr[nextY][nextX] != 0)
				continue;
			visited[nextY][nextX] = true;
			q.push({ nextY, nextX, nowCount + 1 });
			nowTomato++;
			answer = max(answer, nowCount + 1);
		}
	}
	if (nowTomato == wantTomato)
		cout << answer;
	else
		cout << -1;

}