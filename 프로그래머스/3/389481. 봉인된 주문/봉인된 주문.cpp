#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long strToNum(string s)
{
    long long num = 0;
    for(char c : s)
    {
        num = num * 26 + (c - 'a');
    }
    return num;
}

string numToStr(long long num, int len)
{
    string s(len, 'a');
    for(int i = len - 1; i >= 0; i--)
    {
        s[i] = char('a' + (num % 26));
        num /= 26;
    }
    return s;
}

string solution(long long n, vector<string> bans) {
    vector<vector<long long>> banByLen(12);

    for(string b : bans)
    {
        banByLen[b.length()].push_back(strToNum(b));
    }
    
    int len = 1;
    
    while(true)
    {
        long long total = 1;
        for(int i=0;i<len;i++)
            total *= 26;

        long long valid = total - banByLen[len].size();

        if(n > valid)
        {
            n -= valid;
            len++;
        }
        else
            break;
    }
    
    sort(banByLen[len].begin(), banByLen[len].end());

    long long target = n - 1;
    
    for(long long b : banByLen[len])
    {
        if(b <= target)
            target++;
        else
            break;
    }

    return numToStr(target, len);
}