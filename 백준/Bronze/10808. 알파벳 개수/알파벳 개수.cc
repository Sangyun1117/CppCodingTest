#include <iostream>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;

	cin >> S;

	int count[26] = { 0, };

	for (int i = 0; i < S.size(); ++i)
	{
		count[S[i] - 'a']++;
	}

	for(int i=0; i<26; ++i)
	{
		cout << count[i] << " ";
	}

}