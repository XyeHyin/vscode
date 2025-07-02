#include <bits/stdc++.h>
using namespace std;
struct Pos {
    int index;
    double value;
    Pos(int i, double v) : index(i), value(v) {}
    bool operator<(const Pos &r) const { return value > r.value; }
};
int n, m;
int h[105], w[105];
int g[105][105], r[105][105];
int mp(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 < y2)  return (x1 - 1) * (m - 1) + y1 - 1;
    if (x1 == x2 && y1 > y2)  return (x1 - 1) * (m - 1) + y2 - 1 + n * (m - 1);
    if (x1 < x2 && y1 == y2)  return (x1 - 1) * m + y1 - 1 + 2 * n * (m - 1);
    if (x1 > x2 && y1 == y2)  return (x2 - 1) * m + y1 - 1 + 2 * n * (m - 1) + (n - 1) * m;
    return 0;
}
double cal_time(int x1, int y1, int x2, int y2, double cur_t, int op) {
    if (op == 0){
        if (x1 == x2)return w[y1 < y2 ? y1 : y2];
        else return h[x1 < x2 ? x1 : x2];
    }
    if (op == 1){
        if (x1 == x2 && y1 < y2) return w[y1] * 0.5 + h[x1] * 0.5;
        if (x1 == x2 && y1 > y2) return w[y2] * 0.5 + h[x1 - 1] * 0.5;
        if (x1 < x2 && y1 == y2) return w[y1 - 1] * 0.5 + h[x1] * 0.5;
        if (x1 > x2 && y1 == y2)  return w[y1] * 0.5 + h[x2] * 0.5;
    }
    if (op == 2){
        double time;
        if (x1 == x2) {
            if (y1 < y2) {
                time = fmod(w[y1] * 0.5 + cur_t, g[x1][y2] + r[x1][y2]);
                if (time >= g[x1][y2])time = 0;
                else time = g[x1][y2] - time;
                return w[y1] * 0.5 + w[y2] * 0.5 + time;
            } else {
                time = fmod(w[y2] * 0.5 + cur_t, g[x1][y2] + r[x1][y2]);
                if (time >= g[x1][y2]) time = 0;
                else time = g[x1][y2] - time;
                return w[y2] * 0.5 + w[y2 - 1] * 0.5 + time;
            }
        } else {
            if (x1 < x2) {
                time = fmod(h[x1] * 0.5 + cur_t, g[x2][y1] + r[x2][y1]);
                if (time < g[x2][y1]) time = 0;
                else  time = g[x2][y1] + r[x2][y1] - time;
                return h[x1] * 0.5 + h[x2] * 0.5 + time;
            } else {
                time = fmod(h[x2] * 0.5 + cur_t, g[x2][y1] + r[x2][y1]);
                if (time < g[x2][y1]) time = 0;
                else time = g[x2][y1] + r[x2][y1] - time;
                return h[x2] * 0.5 + h[x2 - 1] * 0.5 + time;
            }
        }
    }
    if (op == 3){
        double time;
        if (x1 == x2 && y1 < y2) {
            time = fmod(w[y1] * 0.5 + cur_t, g[x1][y2] + r[x1][y2]);
            if (time >= g[x1][y2])time = 0;
            else time = g[x1][y2] - time;
            return w[y1] * 0.5 + h[x1 - 1] * 0.5 + time;
        }
        if (x1 == x2 && y1 > y2) {
            time = fmod(w[y2] * 0.5 + cur_t, g[x1][y2] + r[x1][y2]);
            if (time >= g[x1][y2]) time = 0;
            else time = g[x1][y2] - time;
            return w[y2] * 0.5 + h[x1] * 0.5 + time;
        }

        if (x1 < x2 && y1 == y2){
            time = fmod(h[x1] * 0.5 + cur_t, g[x2][y1] + r[x2][y1]);
            if (time < g[x2][y1]) time = 0;
            else time = g[x2][y1] + r[x2][y1] - time;
            return w[y1] * 0.5 + h[x1] * 0.5 + time;
        }
        if (x1 > x2 && y1 == y2) {
            time = fmod(h[x2] * 0.5 + cur_t, g[x2][y1] + r[x2][y1]);
            if (time < g[x2][y1]) time = 0;
            else time = g[x2][y1] + r[x2][y1] - time;
            return w[y1 - 1] * 0.5 + h[x2] * 0.5 + time;
        }
    }
    return 0;
}
void setxy(int *x1, int *y1, int *x2, int *y2, int cur) {
    if (cur < n * (m - 1)) {
        *x1 = *x2 = cur / (m - 1) + 1;
        *y1 = cur % (m - 1) + 1;
        *y2 = *y1 + 1;
    } else {
        cur -= n * (m - 1);
        if (cur < n * (m - 1)) {
            *x1 = *x2 = cur / (m - 1) + 1;
            *y2 = cur % (m - 1) + 1;
            *y1 = *y2 + 1;
        } else {
            cur -= n * (m - 1);
            if (cur < (n - 1) * m) {
                *x1 = cur / m + 1;
                *x2 = *x1 + 1;
                *y1 = *y2 = cur % m + 1;
            } else {
                cur -= (n - 1) * m;
                *x2 = cur / m + 1;
                *x1 = *x2 + 1;
                *y1 = *y2 = cur % m + 1;
            }
        }
    }
}
double dj(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,double t) {
    int flag[2 * (n * (m - 1) + (n - 1) * m)];
    double dist[2 * (n * (m - 1) + (n - 1) * m)];
    memset(flag, 0, sizeof(int) * 2 * (n * (m - 1) + (n - 1) * m));
    memset(dist, 0, sizeof(double) * 2 * (n * (m - 1) + (n - 1) * m));
    int cur = mp(x1, y1, x2, y2), to;
    priority_queue<Pos> q;
    double min_dist;
    flag[cur] = 1;
    while (1) {
        double next_dist;
        to = mp(x2, y2, x1, y1);
        next_dist = cal_time(x1, y1, x2, y2, dist[cur] + t, 0);
        if (!flag[to] && (!dist[to] || dist[cur] + next_dist < dist[to])) {
            dist[to] = dist[cur] + next_dist;
            q.push(Pos(to, dist[to]));
        }
        to = -1;
        if (x1 == x2 && y1 < y2 && x1 < n)
            to = mp(x1, y2, x1 + 1, y2);
        if (x1 == x2 && y1 > y2 && x1 > 1)
            to = mp(x1, y2, x1 - 1, y2);
        if (x1 < x2 && y1 == y2 && y1 > 1)
            to = mp(x2, y1, x2, y1 - 1);
        if (x1 > x2 && y1 == y2 && y1 < m)
            to = mp(x2, y1, x2, y1 + 1);
        if (to != -1) {
            next_dist = cal_time(x1, y1, x2, y2, dist[cur] + t, 1);
            if (!flag[to] && (!dist[to] || dist[cur] + next_dist < dist[to])) {
                dist[to] = dist[cur] + next_dist;
                q.push(Pos(to, dist[to]));
            }
        }
        to = -1;
        if (x1 == x2 && y1 < y2 && y2 < m)
            to = mp(x1, y2, x1, y2 + 1);
        if (x1 == x2 && y1 > y2 && y2 > 1)
            to = mp(x1, y2, x1, y2 - 1);
        if (x1 < x2 && y1 == y2 && x2 < n)
            to = mp(x2, y1, x2 + 1, y1);
        if (x1 > x2 && y1 == y2 && x2 > 1)
            to = mp(x2, y1, x2 - 1, y1);
        if (to != -1) {
            next_dist = cal_time(x1, y1, x2, y2, dist[cur] + t, 2);
            if (!flag[to] && (!dist[to] || dist[cur] + next_dist < dist[to])) {
                dist[to] = dist[cur] + next_dist;
                q.push(Pos(to, dist[to]));
            }
        }
        to = -1;
        if (x1 == x2 && y1 < y2 && x1 > 1)
            to = mp(x1, y2, x1 - 1, y2);
        if (x1 == x2 && y1 > y2 && x1 < n)
            to = mp(x1, y2, x1 + 1, y2);
        if (x1 < x2 && y1 == y2 && y1 < m)
            to = mp(x2, y1, x2, y1 + 1);
        if (x1 > x2 && y1 == y2 && y1 > 1)
            to = mp(x2, y1, x2, y1 - 1);
        if (to != -1) {
            next_dist = cal_time(x1, y1, x2, y2, dist[cur] + t, 3);
            if (!flag[to] && (!dist[to] || dist[cur] + next_dist < dist[to])) {
                dist[to] = dist[cur] + next_dist;
                q.push(Pos(to, dist[to]));
            }
        }
        cur = q.top().index;
        min_dist = q.top().value;
        q.pop();
        setxy(&x1, &y1, &x2, &y2, cur);
        if (x1 == x3 && y1 == y3 && x2 == x4 && y2 == y4)  return min_dist;
        else flag[cur] = 1;
    }
}

int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n - 1; i++) scanf("%d", &h[i]);
    for (i = n - 1; i >= 2; i--) h[i] -= h[i - 1];
    for (i = 1; i <= m - 1; i++) scanf("%d", &w[i]);
    for (i = m - 1; i >= 2; i--) w[i] -= w[i - 1];
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++)  scanf("%d", &g[i][j]);
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf("%d", &r[i][j]);
    int x1, y1, x2, y2, tx1, ty1, tx2, ty2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    tx1 = x1, ty1 = y1, tx2 = x2, ty2 = y2;
    int q;
    double re = 0;
    scanf("%d", &q);
    int xi1, yi1, xi2, yi2, xi3, yi3, xi4, yi4;
    while (q--) {
        scanf("%d%d%d%d", &xi1, &yi1, &xi2, &yi2);
        re += dj(x1, y1, x2, y2, xi1, yi1, xi2, yi2, re);
        scanf("%d%d%d%d", &xi3, &yi3, &xi4, &yi4);
        re += dj(xi1, yi1, xi2, yi2, xi3, yi3, xi4, yi4, re);
        x1 = xi3, y1 = yi3, x2 = xi4, y2 = yi4;
    }
    re += dj(xi3, yi3, xi4, yi4, tx1, ty1, tx2, ty2, re);
    printf("%.1f\n", re);
    return 0;
}
