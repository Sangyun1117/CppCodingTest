//문제
//도영이는 짜파구리 요리사로 명성을 날렸었다.
// 이번에는 이전에 없었던 새로운 요리에 도전을 해보려고 한다.
//
//지금 도영이의 앞에는 재료가 N개 있다.
// 도영이는 각 재료의 신맛 S와 쓴맛 B를 알고 있다.
// 여러 재료를 이용해서 요리할 때, 
// 그 음식의 신맛은 사용한 재료의 신맛의 곱이고, 쓴맛은 합이다.
//
//시거나 쓴 음식을 좋아하는 사람은 많지 않다.
// 도영이는 재료를 적절히 섞어서 요리의 신맛과 쓴맛의 차이를 작게 만들려고 한다.
// 또, 물을 요리라고 할 수는 없기 때문에, 재료는 적어도 하나 사용해야 한다.
//
//재료의 신맛과 쓴맛이 주어졌을 때, 
// 신맛과 쓴맛의 차이가 가장 작은 요리를 만드는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 재료의 개수 N(1 ≤ N ≤ 10)이 주어진다.
// 다음 N개 줄에는 그 재료의 신맛과 쓴맛이 공백으로 구분되어 주어진다.
// 모든 재료를 사용해서 요리를 만들었을 때, 
// 그 요리의 신맛과 쓴맛은 모두 1, 000, 000, 000보다 작은 양의 정수이다.
//
//출력
//첫째 줄에 신맛과 쓴맛의 차이가 가장 작은 요리의 차이를 출력한다.
//
//예제 입력 1
//1
//3 10
//예제 출력 1
//7
//예제 입력 2
//2
//3 8
//5 8
//예제 출력 2
//1
//예제 입력 3
//4
//1 7
//2 6
//3 8
//4 9
//예제 출력 3
//1

#include <iostream>
#include <algorithm>
using namespace std;
using Mat = pair<long long, long long>;
int N;
Mat arr[10] = { };
int nowMin = 1000000000;

void f(Mat mat, int idx, int count) {
	if (idx > N)
		return;
	int cha;
	if (mat.first > mat.second)
		cha = mat.first - mat.second;
	else if (mat.first == mat.second)
		cha = 0;
	else
		cha = mat.second - mat.first;

	if (nowMin > cha && count > 0) {
		//cout << nowMin<<"\n";
		nowMin = cha;
	}



	if (count != 0) {
		Mat tmp = { mat.first * arr[idx].first, mat.second + arr[idx].second };

		f(tmp, idx + 1, count + 1);
		f(mat, idx + 1, count);
	}
	else {
		Mat tmp = {arr[idx].first, arr[idx].second };

		f(tmp, idx + 1, count + 1);
		f(mat, idx + 1, count);
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	f({ 0, 0 }, 0, 0);

	cout << nowMin;
}