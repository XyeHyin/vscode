#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                words.push_back(string(1, i) + string(1, j) + string(1, k));
            }
        }
    }
    vector<string> guesses(5);
    vector<int> a(5), b(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> guesses[i] >> a[i] >> b[i];
    }
    vector<string> answers;
    for (string word : words)
    {
        bool ispossible = true;
        for (int i = 0; i < 5; i++)
        {
            int matchA = 0, matchB = 0;
            for (int j = 0; j < 3; j++)
            {
                if (word[j] == guesses[i][j])
                    matchB++;
                if (find(guesses[i].begin(), guesses[i].end(), word[j]) != guesses[i].end())
                    matchA++;
            }
            if (matchA != a[i] || matchB != b[i])
            {
                ispossible = false;
                break;
            }
        }
        if (ispossible)
            answers.push_back(word);
    }
    cout << answers.size() << endl;
    for (string answer : answers){
        cout << answer << endl;
    }
}