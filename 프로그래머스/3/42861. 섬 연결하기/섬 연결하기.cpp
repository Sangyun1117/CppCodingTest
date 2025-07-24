#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int end;
    int value;
    
    bool operator<(const Node &other) const {
        return value > other.value;
    }
};
int solution(int n, vector<vector<int>> costs) {
    vector<vector<Node>> arr(n);
    for(int i=0; i<costs.size(); ++i){
        int n1 = costs[i][0];
        int n2 = costs[i][1];
        int value = costs[i][2];
        arr[n1].push_back({n2, value});
        arr[n2].push_back({n1, value});
    }
    bool *visited = new bool[n]();
    priority_queue<Node> pq;
    pq.push({0,0});
    
    int sum = 0;
    int count = 0;
    while(!pq.empty()){
        Node now = pq.top(); pq.pop();
        int end = now.end;
        int value = now.value;
        if(visited[end])
            continue;
        visited[end] = true;
        sum+=value;
        count++;
        if(count==n)
            break;
        for(Node next : arr[end]){
            if(visited[next.end])
                continue;
            pq.push(next);
        }
    }
        
    return sum;
}