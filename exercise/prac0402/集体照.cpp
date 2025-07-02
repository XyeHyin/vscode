#include <bits/stdc++.h>
using namespace std;
struct person
{
    string name;
    int high;
};
bool cmp(person a, person b)
{
    if (a.high != b.high)
        return a.high > b.high;
    else
        return a.name < b.name;
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<person> people(N);
    for (int i = 0; i < N; i++)
    {
        cin >> people[i].name >> people[i].high;
    }
    sort(people.begin(), people.end(), cmp);
    bool zuo = false, lastPai = true, middle = true;
    vector<string> ans;
    int m = N / K;
    int plus = N % m;
    int mid = m / 2 + 1;
    int pai = 1, personNum = people.size();
    for (int i = 0; i < m + plus; i++)
    {
        if ((m + plus) % 2 != 0)
        {
            zuo = true;
        }
        if (zuo)
        {
            ans.insert(ans.begin(), people[i].name);
            zuo = false;
            continue;
        }
        else
        {
            ans.push_back(people[i].name);
            zuo = true;
            continue;
        }
    }
    for (int i = m + plus; i < people.size(); i++)
    {
        int temp = pai;
        pai = (int)(i-m-plus) / m;
        if (pai != temp)
        {
            middle = true;
            if(m%2==0){
                zuo = false;
            }
        }

        if (m % 2 != 0)
        {
            if (middle)
            {
                ans.push_back(people[i].name);
                middle = false;
                zuo = true;
                continue;
            }
        }
        if (zuo)
        {
            ans.insert(ans.begin() + plus + m + m * (pai), people[i].name);
            zuo = false;
            continue;
        }
        else
        {
            ans.push_back(people[i].name);
            zuo = true;
            continue;
        }
    }
    for (int i = 0;i<m+plus;i++){
        if (i == 0){
            cout<<ans[i];
        }
        else{
            cout<<" "<<ans[i];
        }
    }
    cout<<endl;
    int cnt = 0;
    for (int i = m+plus;i<ans.size();i++){
        cout<<ans[i];
        cnt++;
        if(cnt != m){
            cout<<" ";
        }
        else{
            cout<<endl;
            cnt = 0;
        }
    }
        return 0;
}