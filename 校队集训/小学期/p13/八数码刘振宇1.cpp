#include <bits/stdc++.h>
using namespace std;
class Pt {
  private:
    char str[9];
    int loc9;
    int step;
    int father;
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

  public:
    Pt() {}
    void random_init() {
        int i;
        for (i = 0; i < 9; ++i)
            str[i] = '1' + i;
        while (my_shuffle(), inverse_number() % 2 == 1);
        for (i = 0; str[i] != '9'; ++i);
        loc9 = i;
        father = -1;
        step = 0;
    }
    void bfs() const {
        if (test()) {
            show();
            return;
        }
        int i, dir[4] = {-3, 3, -1, 1};
        bool *flag = new bool[362880];
        memset(flag, 0, sizeof(bool) * 362880);
        Pt cur = *this, *queue = new Pt[362880 / 2];
        int front = 0, rear = 0;
        flag[cur.cantor()] = 1;
        queue[rear++] = cur;
        while (front < rear) {
            cur = queue[front++];
            for (i = 0; i < 4; ++i) {
                Pt tmp = cur;
                tmp.step = cur.step + 1;
                int x = tmp.loc9 / 3, y = tmp.loc9 % 3;
                if (x == 0 && i == 0 || x == 2 && i == 1 || y == 0 && i == 2 ||
                    y == 2 && i == 3)
                    continue;
                tmp.str[tmp.loc9] = tmp.str[tmp.loc9 + dir[i]];
                tmp.loc9 += dir[i];
                tmp.str[tmp.loc9] = '9';
                tmp.father = front - 1;
                int tmp_cantor = tmp.cantor();
                if (!flag[tmp_cantor]) {
                    flag[tmp_cantor] = 1;
                    queue[rear++] = tmp;
                    if (tmp.test()) {
                        show(queue, rear - 1);
                        delete[] queue;
                        delete[] flag;
                        return;
                    }
                }
            }
        }
    }
};

int main() {
    // srand(time(0));
    Pt pt;
    pt.random_init();
    pt.bfs();
    return 0;
}