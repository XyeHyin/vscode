#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
class Pt // 拼图游戏类
{
  private:
    char str[9];       // 存放字符1~9，字符9表示空位
    int loc9;          // 存放字符9(9的位置)
    int step;          // 存放步数
    int father;        // 存放搜索树中父结点的在数组中的下标
    int manhattan_dis; // 存放与目标状态的曼哈顿距离
    // 返回序列1~8的逆序数
    // 注意在其计算逆序数时，未考虑字符9
    int inverse_number() const {
        int i, j, sum = 0;
        for (i = 1; i < 9; ++i)
            for (j = 0; j < i; ++j)
                if (str[j] != '9' && str[i] < str[j])
                    ++sum;
        return sum;
    }

    // 随机打乱

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

    // 测试是否已经完成拼图

    bool test() const {
        int i;
        for (i = 0; i < 8; ++i)
            if (str[i] != i + '1')
                return 0;
        return 1;
    }

    // 显示函数，完成拼图9显示为9，否则显示空格

    void show() const{
        bool flag = test(); // flag记录是否已经完成拼图
        int i;
        char t = flag ? '9' : ' '; // t存放应该如何显示9
        for (i = 0; i < 9; ++i)
            if (i % 3 == 2) // 3个数换一行
                cout << (str[i] == '9' ? t : str[i]) << endl;
            else
                cout << (str[i] == '9' ? t : str[i]) << ' ';
        cout << "第" << step << "步---------------\n";
    }

    int cantor() const{
        static const int fac[] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};
        int i, j, t, sum = 0;
        for (i = 0; i < 8; ++i){
            t = 0;
            for (j = i + 1; j < 9; ++j)
                if (str[i] > str[j])
                    ++t;
            sum += t * fac[i];
        }
        return sum;
    }
    void show(const Pt *queue, int index) const    {
        if (index != -1)
        {
            show(queue, queue[index].father);
            queue[index].show();
        }
    }

    int manhattan() const

    {

        int i, sum = 0;

        for (i = 0; i < 9; ++i)

            if (str[i] != '9')

                sum += abs((str[i] - '1') / 3 - i / 3) +
                       abs((str[i] - '1') % 3 - i % 3);

        return sum;
    }

  public:
    Pt()

    {}

    void random_init()

    {

        int i;

        // 顺序初始化

        for (i = 0; i < 9; ++i)

            str[i] = '1' + i;

        // 使用STL中的random_shuffle或自编的my_shuffle

        // 随机打乱

        // while(random_shuffle(str,str+9),inverse_number()%2==1);

        while (my_shuffle(), inverse_number() % 2 == 1)
            ;

        // 设置loc9

        for (i = 0; str[i] != '9'; ++i)
            ;

        loc9 = i;

        // 设置初始状态的父结点为-1，步数为0

        father = -1;

        step = 0;

        // 设置初始状态的曼哈顿距离

        manhattan_dis = manhattan();
    }

    void bfs() const{
        if (test()){
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
        while (front < rear){
            cur = queue[front++];
            for (i = 0; i < 4; ++i){
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
                if (!flag[tmp_cantor]){
                    flag[tmp_cantor] = 1;
                    queue[rear++] = tmp;
                    if (tmp.test()){
                        show(queue, rear - 1);
                        delete[] queue;
                        delete[] flag;
                        return;
                    }
                }
            }
        }
    }

    struct Compare

    {

        Pt *q;

        Compare(Pt *p) : q(p) {}

        bool operator()(int a, int b) const

        {

            return q[a].step + q[a].manhattan_dis >

                   q[b].step + q[b].manhattan_dis;
        }
    };

    void A_star() const

    {

        if (test())

        {

            show();

            return;
        }

        int i, dir[4] = {-3, 3, -1, 1};

        bool *flag = new bool[362880];

        memset(flag, 0, sizeof(bool) * 362880);

        Pt cur = *this, *queue = new Pt[362880 / 2];

        Compare compare(queue);

        int *heap = new int[362880 / 2];

        int heap_len = 0, rear = 0;

        flag[cur.cantor()] = 1;

        queue[rear++] = cur;

        heap[heap_len++] = 0;

        while (heap_len)

        {

            int father = heap[0];

            cur = queue[father];

            pop_heap(heap, heap + heap_len, compare);

            --heap_len;

            for (i = 0; i < 4; ++i)

            {

                Pt tmp = cur;

                int x = tmp.loc9 / 3, y = tmp.loc9 % 3;

                if (x == 0 && i == 0 || x == 2 && i == 1 || y == 0 && i == 2 ||
                    y == 2 && i == 3)

                    continue;

                tmp.str[tmp.loc9] = tmp.str[tmp.loc9 + dir[i]];

                tmp.loc9 += dir[i];

                tmp.str[tmp.loc9] = '9';

                tmp.father = father;

                int tmp_cantor = tmp.cantor();

                if (!flag[tmp_cantor])

                {

                    flag[tmp_cantor] = 1;

                    tmp.step = cur.step + 1;

                    tmp.manhattan_dis = tmp.manhattan();

                    heap[heap_len++] = rear;

                    queue[rear++] = tmp;

                    push_heap(heap, heap + heap_len, compare);

                    if (tmp.test())

                    {

                        show(queue, rear - 1);

                        delete[] queue;

                        delete[] flag;

                        delete[] heap;

                        return;
                    }
                }
            }
        }
    }

    void ID_A_star() const

    {

        if (test())

        {

            show();

            return;
        }

        int max_d = 0;

        bool finished = 0;

        Pt ans[64];

        ans[0] = *this;

        while (!finished)

        {

            dfs(ans, 0, max_d, finished);

            ++max_d;
        }
    }

    void dfs(Pt *ans, int d, int max_d, bool &finished) const

    {

        int i;

        static const int dir[4] = {-3, 3, -1, 1};

        int dis = ans[d].manhattan();

        if (!dis)

        {

            for (i = 0; i <= d; ++i)

            {

                ans[i].step = i;

                ans[i].show();
            }

            finished = 1;

            return;
        }

        if (d + dis <= max_d && !finished)

        {

            for (i = 0; i < 4; ++i)

            {

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

int main()

{

    // srand(time(0));

    Pt pt;

    pt.random_init();

    // pt.bfs();

    // pt.A_star();

    pt.ID_A_star();

    return 0;
}