#include <bits/stdc++.h>
int main(){
    std::string s, ss,i="0";
    std::cin >> s;
    reverse_copy(s.begin(), next(s.begin(), s.size() / 2), back_inserter(ss));
    ss = s.substr(0, s.size() / 2 + s.size() % 2) + ss;
    if (s==std::string(s.size(),'9')) {std::cout << 1 << std::string(std::max(0,(int)s.size()-1), '0') << 1 << std::endl;return 0;}
    if (ss[ss.size() / 2] == '9'&&ss<=s) {
        while (ss[ss.size() / 2 + stoi(i)] == '9') ss[ss.size() / 2 - stoi(i) - !(s.size() & 1)] = '0',ss[ss.size() / 2 + stoi(i)] = '0',i=std::to_string(stoi(i)+1);
        ss[ss.size() / 2 + stoi(i)] = ++ss[ss.size() / 2 - stoi(i) - !(s.size() & 1)];
    } else s.size() & 1 ? ss[s.size() / 2] += ss <= s: ss[s.size() / 2] = ss[s.size() / 2 - 1] += ss <= s;
    std::cout << ss << std::endl;
}