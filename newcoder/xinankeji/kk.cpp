#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename F> class SparseTable {
  public:
    int n;
    vector<vector<T>> st;
    vector<int> logTable;
    F merge;
    T defaultValue;
    SparseTable(const vector<T> &arr, F mergeFunc, T defaultVal)
        : merge(mergeFunc), defaultValue(defaultVal) {
        n = arr.size();
        logTable.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }
        int K = logTable[n] + 1;
        st.assign(n, vector<T>(K));
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int L, int R) {
        int j = logTable[R - L + 1];
        return merge(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    auto orMerge = [](int a, int b) -> int { return a | b; };
    SparseTable<int, decltype(orMerge)> st_or(arr, orMerge, 0);
    auto andMerge = [](int a, int b) -> int { return a & b; };
    SparseTable<int, decltype(andMerge)> st_and(arr, andMerge, ~0);
    int L = 1, R = 3;
    int res_or = st_or.query(L, R);
    int res_and = st_and.query(L, R);

    cout << "区间 [" << L << ", " << R << "] 按位或结果: " << res_or << "\n";
    cout << "区间 [" << L << ", " << R << "] 按位与结果: " << res_and << "\n";
    }
    

    return 0;
}