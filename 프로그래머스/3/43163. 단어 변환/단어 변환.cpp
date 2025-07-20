#include <string>
#include <vector>
#include <queue>

using namespace std;

struct state{
    string st;
    int count;
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<state> q;
    vector<bool> visited(words.size(), false);
    // for(int i=0; i<words.size(); ++i){
    //     if(begin == words[i])
    //         visited[i] = true;
    // }
    q.push({begin, 0});
    
    while(!q.empty()){
        state now = q.front(); q.pop();
        string nowSt = now.st;
        int count = now.count;
        
        if(target == nowSt){
            answer = count;
            break;
        }
        for(int idx = 0; idx < words.size(); idx++){
            string next = words[idx];
            if(visited[idx])
                continue;
            int different = 0;
            for(int i=0; i<next.length(); ++i){
                if(nowSt[i] != next[i])
                    different++;
            }
            if(different==1){
                q.push({next, count + 1});
                visited[idx] = true;
            }
        }
    }
    
    
    return answer;
}