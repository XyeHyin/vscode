#include <bits/stdc++.h>
using namespace std;
class Pt {
  private:
    char str[9];
    int loc9;
    int step;
    int father;
    int manhattan_dis;
    int inverse_number() const {
        int i, j, sum = 0;
        for (i = 1; i < 9; ++i)
            for (j = 0; j < i; ++j)
                if (str[j] != '9' && str[i] < str[j])
                    ++sum;
        return sum;
    }
    void my_shuffle() {
        int i, x, y;
        for (i = 0; i < 10; ++i) {
            x = rand() % 9;
            y = rand() % 9;
            if (x != y) {
                char t = str[x];
                str[x] = str[y];
                str[y] = t;
            }
        }
    }
    bool test() const {
        int i;
        for (i = 0; i < 8; ++i)
            if (str[i] != i + '1')
                return 0;
        return 1;
    }
    struct Compare {
        Pt *q;
        Compare(Pt *p) : q(p) {}
        bool operator()(int a, int b) const {
            return q[a].step + q[a].manhattan_dis >
                   q[b].step + q[b].manhattan_dis;
        }
    };
    void show() const {
        bool flag = test();
        int i;
        char t = flag ? '9' : ' ';
        for (i = 0; i < 9; ++i)
            if (i % 3 == 2)
                cout << (str[i] == '9' ? t : str[i]) << endl;
            else
                cout << (str[i] == '9' ? t : str[i]) << ' ';
        cout << "第" << step << "步---------------\n";
    }

    int cantor() const {
        static const int fac[] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};
        int i, j, t, sum = 0;
        for (i = 0; i < 8; ++i) {
            t = 0;
            for (j = i + 1; j < 9; ++j)
                if (str[i] > str[j])
                    ++t;
            sum += t * fac[i];
        }
        return sum;
    }
    void show(const Pt *queue, int index) const {
        if (index != -1) {
            show(queue, queue[index].father);
            queue[index].show();
        }
    }
    int manhattan() const {
        int i, sum = 0;
        for (i = 0; i < 9; ++i)
            if (str[i] != '9')
                sum += abs((str[i] - '1') / 3 - i / 3) +
                       abs((str[i] - '1') % 3 - i % 3);

        return sum;
    }

  public:
    Pt() {}
    void random_init() {
        int i;
        for (i = 0; i < 9; ++i)
            str[i] = '1' + i;
        while (my_shuffle(), inverse_number() % 2 == 1)
            ;
        for (i = 0; str[i] != '9'; ++i)
            ;
        loc9 = i;
        father = -1;
        step = 0;
        manhattan_dis = manhattan();
    }
    void ID_A_star() const{
        if (test()){
            show();
            return;
        }
        int max_d = 0;
        bool finished = 0;
        Pt ans[64];
        ans[0] = *this;
        while (!finished){
            dfs(ans, 0, max_d, finished);
            ++max_d;
        }
    }
    void dfs(Pt *ans, int d, int max_d, bool &finished) const{
        int i;
        static const int dir[4] = {-3, 3, -1, 1};
        int dis = ans[d].manhattan();
        if (!dis){
            for (i = 0; i <= d; ++i){
                ans[i].step = i;
                ans[i].show();
            }
            finished = 1;
            return;
        }
        if (d + dis <= max_d && !finished){
            for (i = 0; i < 4; ++i){
                int x = ans[d].loc9 / 3, y = ans[d].loc9 % 3;
                if (x == 0 && i == 0 || x == 2 && i == 1 || y == 0 && i == 2 ||
                    y == 2 && i == 3)
                    continue;
                ans[d + 1] = ans[d];
                ans[d + 1].str[ans[d].loc9] = ans[d].str[ans[d].loc9 + dir[i]];
                ans[d + 1].loc9 += dir[i];
                ans[d + 1].str[ans[d + 1].loc9] = '9';
                dfs(ans, d + 1, max_d, finished);
            }
        }
    }
};

int main() {
    // srand(time(0));
    Pt pt;
    pt.random_init();
    pt.ID_A_star();
    return 0;
}