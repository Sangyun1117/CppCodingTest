#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> indeg;
vector<int> dist;
vector<bool> isCycle;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    adj.assign(N+1, {});
    indeg.assign(N+1, 0);
    dist.assign(N+1, -1);
    isCycle.assign(N+1, true);

    // 그래프 입력
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        indeg[a]++;
        indeg[b]++;
    }

    // 1. 사이클 찾기 (리프 제거 방식)
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 1) {
            q.push(i);
            isCycle[i] = false;
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            indeg[nxt]--;
            if (indeg[nxt] == 1 && isCycle[nxt]) {
                isCycle[nxt] = false;
                q.push(nxt);
            }
        }
    }

    // 2. BFS로 거리 계산
    queue<int> bfs;
    for (int i = 1; i <= N; i++) {
        if (isCycle[i]) {
            dist[i] = 0;
            bfs.push(i);
        }
    }

    while (!bfs.empty()) {
        int cur = bfs.front(); bfs.pop();
        for (int nxt : adj[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                bfs.push(nxt);
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
