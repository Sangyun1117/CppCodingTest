#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct Node{
    int x;
    int y;
    int count;
};
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size(); //세로길이, Y
    int m = maps[0].size(); //가로길이, X
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    Node start = {0, 0, 1};
    queue<Node> q;
    q.push(start);
    visited[0][0] = true;
    while(!q.empty()){
        Node now = q.front(); q.pop();
        int nowX = now.x;
        int nowY = now.y;
        int count = now.count;
        if(nowX==m-1 && nowY==n-1){
            answer = count;
            break;
        }
        for(int i=0; i<4; ++i){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if(nextX<0 || nextX >= m || nextY <0 || nextY >= n)
                continue;
            if(maps[nextY][nextX] == 0 || visited[nextY][nextX])
                continue;
            visited[nextY][nextX] = true;
            q.push({nextX, nextY, count+1});
                
        }
        
    }
    return answer;
}