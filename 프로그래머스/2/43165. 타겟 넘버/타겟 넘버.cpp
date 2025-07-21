#include <string>
#include <vector>
using namespace std;
int answer = 0;

void dfs(int num, int target, int depth, vector<int> &numbers){
    if(depth==numbers.size()){
        if(target == num){
            answer = answer + 1;
        }

        return;
    }
    
    dfs(num + numbers[depth], target, depth+1, numbers);
    dfs(num - numbers[depth], target, depth+1, numbers);  
  
}

int solution(vector<int> numbers, int target) {
    dfs(0, target, 0, numbers);

    return answer;
}