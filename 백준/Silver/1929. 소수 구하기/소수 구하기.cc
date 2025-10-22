#include <iostream>
#include <vector>
using namespace std;
long long M, N;

void calc() {
	vector<bool> arr(N + 1, false);
	arr[1] = true;

	//에라토스체네스의 채
	for (long long i = 2; i <= N; ++i) {
		if (arr[i])
			continue;
		if (i >= M)
			cout << i << "\n";
		for (long long j = i * i; j <= N; j += i) {
			arr[j] = true;
		}
	}


}

int main() {
	cin >> M >> N;
	calc();
}