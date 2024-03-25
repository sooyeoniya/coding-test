// 이분탐색: 메모리 3972KB 시간 312ms
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500002];
int N, M, card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card;
		arr[i] = card;
	}
	sort(arr, arr + N); // 이분탐색을 위해 오름차순 정렬

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << upper_bound(arr, arr + N, card) - lower_bound(arr, arr + N, card)<<" ";
	}
}

// 해시맵: 메모리 43828KB 시간 480ms
// 풀이 시간: 44m33s83
// 시간 복잡도: O(N)
// 공간 복잡도: O(N)
#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> m; // 카드 숫자 num, 해당 숫자 num의 개수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) { // 개수 카운트
		int num; cin >> num;
		m[num]++;
	}
	cin >> M;
	for (int i = 0; i < M; ++i) { // 바로 출력
		int num; cin >> num;
		cout << m[num] << " ";
	}
    return 0;
}
