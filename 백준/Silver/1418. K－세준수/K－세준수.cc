#include <iostream>
using namespace std;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int cnt = 0;
    // 에라토스테네스의 체 원리
    for (int i = 2; i <= N; ++i) {
        if (arr[i]) continue;
        for (int j = i; j <= N; j += i)
            arr[j] = max(arr[j], i);
    }
    for (int i = 1; i <= N; ++i)
        if (arr[i] <= K) cnt++;
    cout << cnt;
    return 0;
}