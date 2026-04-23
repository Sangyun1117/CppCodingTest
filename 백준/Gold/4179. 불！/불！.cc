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

	int R, C;

	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	vector<vector<int>> jihoonDist(R, vector<int>(C, -1));
	vector<vector<int>> fireDist(R, vector<int>(C, -1));

	queue <pos> fireQueue;
	queue <pos> jihoonQueue;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				fireQueue.push({ i, j });
				fireDist[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				jihoonQueue.push({ i, j });
				jihoonDist[i][j] = 0;
			}
		}
	}

	int count = 0;

	while(!fireQueue.empty())
	{
		pos current = fireQueue.front(); fireQueue.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
			if (board[nextX][nextY] == '#' || board[nextX][nextY] == 'F') continue;
			if (fireDist[nextX][nextY] != -1) continue;
			fireDist[nextX][nextY] = fireDist[current.first][current.second] + 1;
			fireQueue.push({ nextX, nextY });
		}
	}

	while (!jihoonQueue.empty())
	{
		pos current = jihoonQueue.front(); jihoonQueue.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
				if (fireDist[current.first][current.second] != -1 && jihoonDist[current.first][current.second] >= fireDist[current.first][current.second])
					continue;
				else {
					cout << jihoonDist[current.first][current.second] + 1;
					return 0;
				}
			}
			if (board[nextX][nextY] == '#' || board[nextX][nextY] == 'F') continue;
			if (jihoonDist[nextX][nextY] != -1) continue;

			jihoonDist[nextX][nextY] = jihoonDist[current.first][current.second] + 1;
			jihoonQueue.push({ nextX, nextY });
		}
	}
	cout << "IMPOSSIBLE";

}