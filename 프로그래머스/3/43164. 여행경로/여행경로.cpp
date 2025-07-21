#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> answer;
bool visited[10000];

bool dfs(vector<vector<string>> &tickets, vector<string>& route, int depth){
    
    if(depth==tickets.size()){
        answer = route;
        return true;
    }
    for(int i=0; i<tickets.size(); ++i){
        if(!visited[i] && route.back() == tickets[i][0]){
            visited[i] = true;
            route.push_back(tickets[i][1]);
            if(dfs(tickets, route, depth + 1))
                return true;
            route.pop_back();
            visited[i] = false;
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> route = {"ICN"};
    
    dfs(tickets, route, 0);
    
    return answer;
}