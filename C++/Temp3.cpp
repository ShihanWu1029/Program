#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
    }

    // Calculate S and pre array
    int S = 0;
    vector<int> pre(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + (a[i] == b[i] ? 1 : 0);
        S += (a[i] == b[i]);
    }

    // Precompute new_match[l][r]
    vector<vector<int>> new_match(N + 1, vector<int>(N + 1, 0));
    for (int k = 1; k <= N; ++k) {
        for (int l = 1; l + k - 1 <= N; ++l) {
            int r = l + k - 1;
            if (l == r) {
                new_match[l][r] = (a[l] == b[l]);
            } else {
                new_match[l][r] = (a[r] == b[l]) + (a[l] == b[r]);
                if (k > 2) {
                    new_match[l][r] += new_match[l + 1][r - 1];
                }
            }
        }
    }

    // Initialize answer array
    vector<int> ans(N + 1, 0);

    // Iterate all possible intervals [l..r]
    for (int l = 1; l <= N; ++l) {
        for (int r = l; r <= N; ++r) {
            int overlap = pre[r] - pre[l - 1];
            int d = new_match[l][r] - overlap;
            int c = S + d;
            if (c >= 0 && c <= N) {
                ans[c]++;
            }
        }
    }

    // Output the result
    for (int c = 0; c <= N; ++c) {
        cout << ans[c] << endl;
    }

    return 0;
}