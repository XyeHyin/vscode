#include<bits/stdc++.h>
using namespace std;

struct Student
{
    int id, de, cai, total;
    int flag;
};

bool cmp(Student a, Student b)
{
    if (a.flag != b.flag)
        return a.flag < b.flag;
    else if (a.total != b.total)
        return a.total > b.total;
    else if (a.de != b.de)
        return a.de > b.de;
    else
        return a.id < b.id;
}

int main()
{
    int n, l, h;
    cin >> n >> l >> h;
    vector<Student> stu(n);
    vector<Student> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].de >> stu[i].cai;
        stu[i].total = stu[i].de + stu[i].cai;
        if (stu[i].de < l || stu[i].cai < l)
            continue;
        else if (stu[i].de >= h && stu[i].cai >= h)
            stu[i].flag = 1;
        else if (stu[i].de >= h && stu[i].cai < h)
            stu[i].flag = 2;
        else if (stu[i].de >= stu[i].cai)
            stu[i].flag = 3;
        else
            stu[i].flag = 4;
        ans.push_back(stu[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].id << " " << ans[i].de << " " << ans[i].cai << endl;
    }
    cout << endl;
}