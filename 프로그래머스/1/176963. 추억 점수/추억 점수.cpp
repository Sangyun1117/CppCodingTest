#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map <string,int> map;
    
    for(int i=0; i<name.size(); ++i){
        map.insert(make_pair(name[i], yearning[i]));
    }
    for(int i=0; i<photo.size(); ++i){
        int sum = 0;
        for(int j=0; j<photo[i].size(); ++j){
            
            if(map.find(photo[i][j])!=map.end()){
                sum+=map.find(photo[i][j])->second;
            }
        }
        answer.push_back(sum);
    }
    return answer;
}