#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'

void solve() {
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;
    a--;
    b--; // 调整为0-based索引

    // 计算顺时针和逆时针的距离
    int cw = (b - a + n) % n;
    int ccw = (a - b + n) % n;

    // 不使用技能的情况
    // 需要计算走cw和ccw需要的最小时间
    // 可以通过动态规划或者贪心计算最少步数
    // 这里采用贪心：
    auto min_steps = [&](int distance, int step) -> int {
        return distance / step + (distance % step != 0);
    };

    int time_without_skill = min(min_steps(cw, x), min_steps(ccw, y));

    // 使用技能的情况
    // 每次使用技能后位置变化为 (current + n/2) % n
    // 尝试使用0到k次技能，计算最小时间
    int min_time = time_without_skill;
    for (int skill_used = 1; skill_used <= min(k, (int)2);
         skill_used++) { // 最多2次技能有不同位置
        // 使用skill_used次技能
        // 每使用一次技能，位置变为 (a + skill_used * (n/2)) % n
        int pos = (a + skill_used * (n / 2)) % n;
        // 计算从pos到b的距离
        int cw_new = (b - pos + n) % n;
        int ccw_new = (pos - b + n) % n;
        int time =
            skill_used + min(min_steps(cw_new, x), min_steps(ccw_new, y));
        min_time = min(min_time, time);
    }

    // 如果k >=2, 可以循环使用技能来达到更多位置，但通常2次足够
    // 根据具体情况可以调整

    cout << min_time << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}