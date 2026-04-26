#include <iostream>

using namespace std;
using ll = long long;

int pow(int a, int b, int c) {

	if (b == 1) {
		return a % c;
	}
	else {
		ll temp = pow(a, b / 2, c);
		temp = (temp * temp) % c;
		if(b % 2 == 0) {
			return temp;
		}
		else {
			return temp * a % c;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c);
}