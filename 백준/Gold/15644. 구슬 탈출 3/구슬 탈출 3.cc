#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<char>> arr;
bool visited[11][11][11][11];
pair<int, int> R, B;

struct State {
    pair<int, int> red;
    pair<int, int> blue;
    int cnt;
    string direct; // 방향 문자열
};

string dirOut (int i, string d) { // 방향 문자열 갱신
   if (i == 0) return d + "R";
   if (i == 1) return d + "L";
   if (i == 2) return d + "D";
   if (i == 3) return d + "U";
}

void bfs() {
    queue<State> q;
    q.push({R, B, 0, ""});
    visited[R.first][R.second][B.first][B.second] = true;

    while (!q.empty()) {
        State cur = q.front();
        int cnt = cur.cnt;
        string direct = cur.direct;
        q.pop();

        if (cnt >= 10) break;

        for (int i = 0; i < 4; ++i) {
            pair<int, int> nR = cur.red;
            pair<int, int> nB = cur.blue;

            int nRx = nR.first, nRy = nR.second; // 빨간 구슬의 다음 위치
            int nBx = nB.first, nBy = nB.second; // 파란 구슬의 다음 위치

            // 빨간 구슬 이동
            while (arr[nRx + dir[i][0]][nRy + dir[i][1]] != '#' && arr[nRx][nRy] != 'O') {
                nRx += dir[i][0]; nRy += dir[i][1];
            }

            // 파란 구슬 이동
            while (arr[nBx + dir[i][0]][nBy + dir[i][1]] != '#' && arr[nBx][nBy] != 'O') {
                nBx += dir[i][0]; nBy += dir[i][1];
            }

            // 파란 구슬이 구멍에 빠진 경우는 무시
            if (arr[nBx][nBy] == 'O') continue;

            // 빨간 구슬이 구멍에 빠진 경우 종료
            if (arr[nRx][nRy] == 'O') {
                cout << cnt + 1 << "\n"; 
                string d = dirOut(i, direct); // 방향 문자열 갱신
                cout << d;
                return;
            }

            // 빨간 구슬과 파란 구슬이 겹치는 경우 이동거리가 더 긴 구슬을 한 칸 뒤로 이동
            if (nRx == nBx && nRy == nBy) {
                if (abs(cur.red.first - nRx) + abs(cur.red.second - nRy) > 
                    abs(cur.blue.first - nBx) + abs(cur.blue.second - nBy)) {
                    nRx -= dir[i][0];
                    nRy -= dir[i][1];
                } else {
                    nBx -= dir[i][0];
                    nBy -= dir[i][1];
                }
            }

            // 방문 여부를 확인하여 중복 방문 방지
            if (!visited[nRx][nRy][nBx][nBy]) {
                string d = dirOut(i, direct); // 방향 문자열 갱신
                visited[nRx][nRy][nBx][nBy] = true;
                q.push({{nRx, nRy}, {nBx, nBy}, cnt + 1, d});
            }
        }
    }
    // 10번 이하로 움직여서 구슬을 빠뜨릴 수 없는 경우
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        string str; cin >> str;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = str[j];
            // R, B 좌표 저장
            if (str[j] == 'R') R = make_pair(i, j);
            if (str[j] == 'B') B = make_pair(i, j);
        }         
    }
    bfs();
    return 0;
}