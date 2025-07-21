#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int *server = new int[players.size()]();
    for(int i=0; i<players.size(); ++i){
        int addServer = (players[i]/m) - server[i];
        if(addServer <= 0)
            continue;
        for(int j=i; j<i+k; ++j){
            if(j>=players.size())
                break;
            server[j]+=addServer;
        }
        answer += addServer;
    }
    delete []server;
    return answer;
}