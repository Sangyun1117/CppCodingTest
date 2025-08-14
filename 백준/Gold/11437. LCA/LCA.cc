//문제
//N(2 ≤ N ≤ 50, 000)개의 정점으로 이루어진 트리가 주어진다.
// 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.
//
//두 노드의 쌍 M(1 ≤ M ≤ 10, 000)개가 주어졌을 때, 
// 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.
//
//입력
//첫째 줄에 노드의 개수 N이 주어지고, 
// 다음 N - 1개 줄에는 트리 상에서 연결된 두 정점이 주어진다.
// 그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 
// 다음 M개 줄에는 정점 쌍이 주어진다.
//
//출력
//M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.
//
//예제 입력 1
//15
//1 2
//1 3
//2 4
//3 7
//6 2
//3 8
//4 9
//2 5
//5 11
//7 13
//10 4
//11 15
//12 5
//14 7
//6
//6 11
//10 9
//2 6
//7 6
//8 13
//8 15
//예제 출력 1
//2
//4
//2
//1
//3
//1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using Line = pair<int, int>; //서로 연결된 노드
//using Info = pair<int, int>; //depth, 부모
struct Info {
	int depth;
	int parent;
};
int N, M;
//Line nodes[50000];
vector<int> adj[50001];
//vector<Line> nodes;
Info infos[50001] = { 0,0 };
//vector<Info> infos;

void dfs(int root, int parent) {
	
	infos[root].parent = parent;
	infos[root].depth = infos[parent].depth + 1;
	for (int nxt : adj[root]) {
		if (nxt != parent) dfs(nxt, root);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	//infos = vector<Info>(N + 1, {0,0});
	infos[1] = { 1,0 };

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		//nodes.push_back({ a,b });
		adj[a].push_back(b);
		adj[b].push_back(a);
		//nodes[i] = { a,b };
	}

	dfs(1,0);

	//int count = 1;
	//while (count < N) {
	//	for (int i = 0; i < N - 1; ++i) {
	//		int first = nodes[i].first;
	//		int second = nodes[i].second;
	//		if (infos[first].depth != 0 && infos[second].depth == 0) {
	//			infos[second].depth = infos[first].depth + 1;
	//			infos[second].parent = first;
	//			++count;
	//		}
	//		else if (infos[first].depth == 0 && infos[second].depth != 0) {
	//			infos[first].depth = infos[second].depth + 1;
	//			infos[first].parent = second;
	//			++count;
	//		}
	//	}
	//}

	//for (int i = 0; i < N+1; ++i) {
	//	cout << depth[i] << "\n";
	//}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;

		while (infos[a].depth != infos[b].depth) {
			if (infos[a].depth > infos[b].depth)
				a = infos[a].parent;
			else
				b = infos[b].parent;
		}

		while (a != b) {
			a = infos[a].parent;
			b = infos[b].parent;
		}

		cout << a << "\n";
	}

}