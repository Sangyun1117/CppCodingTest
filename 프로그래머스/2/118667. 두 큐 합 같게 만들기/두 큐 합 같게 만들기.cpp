#include <string>
#include <vector>
#include <queue>
using namespace std;

long long arraySum(vector<int> &vq, queue<int> &q){
    int sum = 0;
    for(int num : vq){
        sum+= num;
        q.push(num);
    }
    return sum;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<int> q1;
    queue<int> q2;
    long long firstArraySum = arraySum(queue1, q1);
    long long secondArraySum = arraySum(queue2, q2);
    if((firstArraySum+secondArraySum)%2 != 0) //총 합이 홀수면 절대 같아질 수 없음
        return answer;
    int count = 0;
    int maxCount = queue1.size() * 2 + queue2.size() * 2;
    while(count<maxCount){
        if(firstArraySum == secondArraySum){
            answer = count;
            break;
        }
        else if(firstArraySum > secondArraySum){
            int newNum = q1.front(); q1.pop();
            q2.push(newNum);
            firstArraySum -= newNum;
            secondArraySum += newNum;

        }
        else{
            int newNum = q2.front(); q2.pop();
            q1.push(newNum);
            firstArraySum += newNum;
            secondArraySum -= newNum;
        }
        count++;
    }
    
    
    return answer;
}