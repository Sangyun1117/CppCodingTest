#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int bigW = wallet[0] > wallet[1] ? wallet[0] : wallet[1];
    int smallW = wallet[0] < wallet[1] ? wallet[0] : wallet[1];
    int bigB = bill[0] > bill[1] ? bill[0] : bill[1];
    int smallB = bill[0] < bill[1] ? bill[0] : bill[1];
    while(smallB > smallW || bigB > bigW){
        bigB /= 2 ;
        if(bigB <smallB){
            int tmp = bigB;
            bigB = smallB;
            smallB = tmp;
        }
        ++answer;
    }
    return answer;
}