#include <iostream>

using namespace std;

void func1(int a, int b, int n) {
	if (n == 0)
		return;

	func1(a, 6 - a - b, n - 1);
	cout << a << " " << b << "\n";
	func1(6 - a - b, b, n - 1);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	func1(1, 3, N);

}