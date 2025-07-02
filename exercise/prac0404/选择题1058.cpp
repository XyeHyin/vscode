#include <bits/stdc++.h>
using namespace std;
struct Question
{
    int score, optionCount, correctCount;
    string correctOptions;
};
int main()
{
    int N, M;
    cin >> N >> M;
    vector<Question> questions(M);
    for (int i = 0; i < M; i++)
    {
        cin >> questions[i].score >> questions[i].optionCount >> questions[i].correctCount;
        getline(cin, questions[i].correctOptions);
    }
    scanf("\n");
    string s;
    int count[M] = {0};
    for (int i = 0; i < N; i++)
    {
        vector<string> ans;
        getline(cin, s);
        int left = 0, right = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '(')
            {
                left = j;
            }
            if (s[j] == ')')
            {
                right = j;
                string tmp = s.substr(left + 3, right - left - 3);
                ans.push_back(tmp);
            }
        }
        int score = 0;
        for (int j = 0; j < M; j++)
        {
            if (ans[j] == questions[j].correctOptions.substr(1, questions[j].correctOptions.length() - 1))
            {
                score += questions[j].score;
            }
            else
            {
                count[j]++;
            }
        }
        cout << score << endl;
    }
    int max = *max_element(count, count + M);
    if(max!=0){
    cout<<max<<" ";
    bool first = true;
    for (int i = 0; i < M; i++)
    {
        if (count[i] == max)
        {
            if (!first)
            {
                cout << " ";
            }
            cout << i + 1;
            first = false;
        }
    }
    }else if (max == 0){
        cout << "Too simple";
    }
    cout << endl;
    
}