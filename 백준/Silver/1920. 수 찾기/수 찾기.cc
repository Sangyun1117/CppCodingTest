#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> arrN;
vector<int> arrM;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		arrN.push_back(tmp);
	}
	cin >> M;

	sort(arrN.begin(), arrN.end());

	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		arrM.push_back(tmp);
	}
	int start = 0;
	int end = N - 1;
	int mid = (start + end) / 2;

	for (int i = 0; i < M; ++i)
		cout<<binary_search(arrN.begin(), arrN.end(), arrM[i]) << "\n";

}