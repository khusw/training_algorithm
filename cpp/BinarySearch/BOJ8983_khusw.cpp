/*
    BOJ 8983 사냥꾼
    https://www.acmicpc.net/problem/8983
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int M, N, L, answer;
vector<int> lanes;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N >> L;

    for (int i = 0; i < M; ++i) {
        int lane;
        cin >> lane;
        lanes.push_back(lane);
    }

    sort(lanes.begin(), lanes.end());

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        int temp = L - b;
        if (temp < 0) continue;
        if (upper_bound(lanes.begin(), lanes.end(), a + temp) - lower_bound(lanes.begin(), lanes.end(), a - temp) > 0)
            answer++;
    }

    cout << answer;

    return 0;
}