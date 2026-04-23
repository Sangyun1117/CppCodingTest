#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pos = pair<int, int>;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> m >> n;

	vector<vector<int>> map(n, vector<int>(m, 0));

	queue <pos> q;

	int allTomato = 0;
	int checkTomato = 0;
	int day = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i, j });
				checkTomato++;
			}

			if (map[i][j] != -1) allTomato++;
		}
	}

	while (!q.empty()) {
		pos cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0) {
				map[nx][ny] = map[cur.first][cur.second] + 1;
				day = max(day, map[nx][ny]);
				checkTomato++;
				q.push({ nx, ny });
			}
		}
	}

	if (checkTomato < allTomato)
	{
		cout << -1;
	}
	else
	{
		cout << day-1;
	}

}