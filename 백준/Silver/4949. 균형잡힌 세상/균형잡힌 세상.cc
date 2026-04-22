#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true)
	{
		string s;
		getline(cin, s);

		if (s == ".")
		{
			break;
		}

		stack<char> st;

		bool isBalanced = true;

		for (char c : s)
		{
			if (c == '(' || c == '[')
			{
				st.push(c);
			}
			else if (c == ')' || c == ']')
			{
				if (st.empty())
				{
					isBalanced = false;
					break;
				}

				char top = st.top();
				st.pop();

				if (top == '(' && c != ')' || top == '[' && c != ']')
				{
					isBalanced = false;
					break;
				}
			}
		}

		if(isBalanced == true && st.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}

}