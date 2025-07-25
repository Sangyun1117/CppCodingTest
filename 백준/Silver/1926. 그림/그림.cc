

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Pos = pair<int, int>;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	queue<Pos> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int maxWidth = 0;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && arr[i][j]==1) {
				count++;
				Pos startPos = { i, j };
				q.push(startPos);
				visited[i][j] = true;
				int nowWidth = 1;
				while (!q.empty()) {
					Pos now = q.front(); q.pop();
					int nowY = now.first;
					int nowX = now.second;
					for (int k = 0; k < 4; ++k) {
						int nextY = nowY + dy[k];
						int nextX = nowX + dx[k];

						if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
							continue;
						if (visited[nextY][nextX] || arr[nextY][nextX] == 0)
							continue;
						visited[nextY][nextX] = true;
						q.push({ nextY, nextX });
						nowWidth++;
					}
					maxWidth = max(maxWidth, nowWidth);
				}
			}
		}
	}
	cout << count << "\n" << maxWidth;
}