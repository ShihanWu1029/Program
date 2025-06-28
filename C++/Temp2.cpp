#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 10;

int first_occur[MAX_N];
int count_[MAX_N];
int contrib[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    memset(first_occur, -1, sizeof(first_occur));
    memset(count_, 0, sizeof(count_));
    unordered_set<int> s;

    for (int i = 0; i < N; ++i) {
        int num = a[i];
        if (first_occur[num] == -1) {
            first_occur[num] = i;
            contrib[num] = s.size();
            s.insert(num);
        }
        count_[num]++;
    }

    long long ans = 0;
    for (int y = 1; y <= N; ++y) {
        if (count_[y] >= 2) {
            ans += contrib[y];
        }
    }

    cout << ans << '\n';

    return 0;
}