#include <iostream>
#include <list>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	list<char> chars(s.begin(), s.end());

	int M = 0;
	cin >> M;

	auto it = chars.end();

	for (int i = 0; i < M; ++i)
	{
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (it != chars.begin())
			{
				--it;
			}
			break;
		case 'D':
			if (it != chars.end())
			{
				++it;
			}
			break;
		case 'B':
			if(it == chars.begin())
			{
				break;
			}
			it = chars.erase(--it);
			break;
		case 'P':
			char newChar;
			cin >> newChar;

			it = chars.insert(it, newChar);
			it++;
			break;
		}
	}

	for (char c : chars) {
		cout << c;
	}

}