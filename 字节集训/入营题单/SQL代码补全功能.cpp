#include <bits/stdc++.h>
using namespace std;
string solution(int num, vector<string> data,string input) {
    vector<string> a;
    for ( auto word : data)  if (word.find(input) == 0)  a.push_back(word);
    if (a.empty())  return "-1";
    sort(a.begin(), a.end());
    string ans;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
        if (i != a.size() - 1) ans += ",";
    }
    return ans;
}

int main() {
    // 你可以在这里添加更多测试用例
    vector<string> testData1 = {
        "select",          "from",    "where",      "limit", "origin_log_db",
        "event_log_table", "user_id", "from_mobile"};
    vector<string> testData2 = {
        "select",    "from",    "where",      "limit",   "group", "having",
        "in",        "index",   "inner",      "insert",  "like",  "log_db",
        "log_table", "user_id", "group_name", "group_id"};

    cout << (solution(8, testData1, "f") == "from,from_mobile")
              << endl;
    cout << (solution(16, testData2, "g") == "group,group_name,group_id")
              << endl;
    cout << (solution(16, testData2, "m") == "-1") << endl;

    return 0;
}