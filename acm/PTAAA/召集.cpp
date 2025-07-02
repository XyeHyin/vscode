#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

void solve() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }
    vector<vector<int>> dist(m + 1, vector<int>(m + 1, INF));
    for (int i = 1; i <= m; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < r; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
        dist[e][s] = min(dist[e][s], w);
    }
    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int min_distance_sum = INF;
    for (int i = 1; i <= m; ++i) {
        int distance_sum = 0;
        for (int j = 0; j < n; ++j) {
            distance_sum += dist[students[j]][i];
        }
        min_distance_sum = min(min_distance_sum, distance_sum);
    }

    cout << min_distance_sum << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}