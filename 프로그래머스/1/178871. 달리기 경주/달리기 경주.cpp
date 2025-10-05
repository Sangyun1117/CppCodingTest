#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using info = pair<string, string>;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players.size());
    unordered_map<string, info> rank;
    
    
    rank.insert({players.front(), make_pair("", players[1])}); 
    for(int i=1; i<players.size()-1; ++i){
        rank.insert({players[i], make_pair(players[i-1], players[i+1])}); 
    }
    rank.insert({players.back(), make_pair(players[players.size()-2], "")});
    string lastName = players.back();
    
    for(string call : callings){
        string front = rank[call].first;
        string back = rank[call].second;

        if (front == "") continue; // 이미 선두면 패스

        string frontFront = rank[front].first;
        string backBack = (back == "") ? "" : rank[back].second;

        // 꼴찌인 경우
        if (lastName == call)
            lastName = front;

        // 갱신 순서 중요!!
        rank[call] = {frontFront, front};
        rank[front] = {call, back};
        if (frontFront != "") rank[frontFront].second = call;
        if (back != "") rank[back] = {front, backBack};

    }
    

    for(int i=players.size()-1; i>=0; --i){
        answer[i] = lastName;
        lastName = rank[lastName].first;
    }
    
    return answer;
}