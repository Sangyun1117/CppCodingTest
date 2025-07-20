#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited;

void dfs(int start, int n, vector<vector<int>> computers){
    stack<int> s;
    s.push(start);
    visited[start] = true;
    
    while(!s.empty()){
        int now = s.top(); s.pop();
        for(int i=0; i<n; ++i){
            if(!visited[i] && computers[now][i] == 1){
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited = vector<bool>(n,false);
    
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    
    
    return answer;
}