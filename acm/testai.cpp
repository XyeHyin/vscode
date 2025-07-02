#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Fruit {
    string name;
    int pv, v;
};

signed main() {
    int n;
    cin >> n;
    vector<Fruit> fruits(n);
    for (int i = 0; i < n; ++i) {
        cin >> fruits[i].name >> fruits[i].pv >> fruits[i].v;
    }

    // 计算总v值
    int total_v = 0;
    for (auto &fruit : fruits) {
        total_v += fruit.v;
    }

    // LSY 榨汁机
    int max_lsy = LLONG_MIN;
    vector<Fruit> best_lsy_order;
    for (int i = 0; i < n; ++i) {
        int current_total = fruits[i].pv * 2 + (total_v - fruits[i].v);
        if (current_total > max_lsy) {
            max_lsy = current_total;
            // 选择第i个作为第一个
            vector<Fruit> temp = fruits;
            Fruit first = temp[i];
            temp.erase(temp.begin() + i);
            // 按字典序排序剩余部分
            sort(temp.begin(), temp.end(),
                 [&](const Fruit &a, const Fruit &b) -> bool {
                     return a.name < b.name;
                 });
            // 构建最佳顺序
            best_lsy_order.clear();
            best_lsy_order.push_back(first);
            for (auto &f : temp) {
                best_lsy_order.push_back(f);
            }
        } else if (current_total == max_lsy) {
            // 比较字典序
            // 选择字典序更小的顺序
            vector<Fruit> temp = fruits;
            Fruit first = temp[i];
            temp.erase(temp.begin() + i);
            sort(temp.begin(), temp.end(),
                 [&](const Fruit &a, const Fruit &b) -> bool {
                     return a.name < b.name;
                 });
            vector<Fruit> current_order;
            current_order.push_back(first);
            for (auto &f : temp) {
                current_order.push_back(f);
            }
            // 比较 best_lsy_order 和 current_order
            bool should_update = false;
            for (int j = 0; j < current_order.size(); ++j) {
                if (j >= best_lsy_order.size()) {
                    break;
                }
                if (current_order[j].name < best_lsy_order[j].name) {
                    should_update = true;
                    break;
                } else if (current_order[j].name > best_lsy_order[j].name) {
                    break;
                }
            }
            if (should_update) {
                best_lsy_order = current_order;
            }
        }
    }

    // HXN 榨汁机
    int max_hxn = LLONG_MIN;
    vector<Fruit> best_hxn_order;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            int current_total = fruits[i].pv + fruits[j].v * 2 +
                                (total_v - fruits[i].v - fruits[j].v);
            if (current_total > max_hxn) {
                max_hxn = current_total;
                // 选择第i个作为第一个，j个作为最后一个
                vector<Fruit> temp;
                temp.push_back(fruits[i]);
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        temp.push_back(fruits[k]);
                    }
                }
                // 按字典序排序中间部分
                sort(temp.begin() + 1, temp.end(),
                     [&](const Fruit &a, const Fruit &b) -> bool {
                         return a.name < b.name;
                     });
                temp.push_back(fruits[j]);
                // 构建最佳顺序
                best_hxn_order = temp;
            } else if (current_total == max_hxn) {
                // 比较字典序
                vector<Fruit> temp;
                temp.push_back(fruits[i]);
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        temp.push_back(fruits[k]);
                    }
                }
                sort(temp.begin() + 1, temp.end(),
                     [&](const Fruit &a, const Fruit &b) -> bool {
                         return a.name < b.name;
                     });
                temp.push_back(fruits[j]);

                // 比较 best_hxn_order 和 temp
                bool should_update = false;
                for (int k = 0; k < temp.size(); ++k) {
                    if (k >= best_hxn_order.size()) {
                        break;
                    }
                    if (temp[k].name < best_hxn_order[k].name) {
                        should_update = true;
                        break;
                    } else if (temp[k].name > best_hxn_order[k].name) {
                        break;
                    }
                }
                if (should_update) {
                    best_hxn_order = temp;
                }
            }
        }
    }

    // 比较并输出结果
    if (max_lsy >= max_hxn) {
        cout << "LSY" << endl;
        cout << max_lsy << endl;
        for (auto &fruit : best_lsy_order) {
            cout << fruit.name << endl;
        }
    } else {
        cout << "HXN" << endl;
        cout << max_hxn << endl;
        for (auto &fruit : best_hxn_order) {
            cout << fruit.name << endl;
        }
    }

    return 0;
}