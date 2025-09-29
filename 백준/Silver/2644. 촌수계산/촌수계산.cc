//문제
//우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다.
//이러한 촌수는 다음과 같은 방식으로 계산된다.
//기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다.
//예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 
//아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
//
//여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 
//주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.
//
//입력
//사람들은 1, 2, 3, …, n(1 ≤ n ≤ 100)의 연속된 번호로 각각 표시된다.
//입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 
//둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다.
//그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다.
//넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x, y가 각 줄에 나온다.
//이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
//
//각 사람의 부모는 최대 한 명만 주어진다.
//
//출력
//입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다.
//어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다.
//이때에는 - 1을 출력해야 한다.
//
//예제 입력 1
//9
//7 3
//7
//1 2
//1 3
//2 7
//2 8
//2 9
//4 5
//4 6
//예제 출력 1
//3
//예제 입력 2
//9
//8 6
//7
//1 2
//1 3
//2 7
//2 8
//2 9
//4 5
//4 6
//예제 출력 2
//- 1

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int find1, find2;
vector<vector<int>> arr;
vector <bool> visited;
int* dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> find1 >> find2 >> m;

	arr = vector<vector<int>>(n + 1);
	visited = vector<bool>(n + 1, false);
	dist = new int[n + 1];
	memset(dist, -1, sizeof(int) * (n + 1));

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	queue<int> q;
	q.push(find1);
	dist[find1] = 0;
	int result = -1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == find2) {
			result = dist[now];
			break;
		}
		for (int next : arr[now]) {
			if (visited[next]) {
				continue;
			}
			q.push(next);
			visited[next] = true;
			dist[next] = dist[now] + 1;
		}
	}
	cout << result;
}