#include<bits/stdc++.h>
#define dbg(x) std::cout<<#x<<":"<<x<<" "
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define mem(a,x) memset(a,x,sizeof a)
#define all(x) x.begin(),x.end()
#define arrall(a,n) a+1,a+1+n
#define PII std::pair<int,int>
#define m_p std::make_pair
#define ff first
#define ss second
#define CD const double
#define CI const int
#define int long long
#define itn int
using namespace std;
signed main(void){
    auto start = chrono::high_resolution_clock::now();
    string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    int begin = 0, len=8,count=0;
    while(true){
        if(begin+len>s.size()&&len==8)break;
       string ans=s.substr(begin,len);
       if(len==16)len=8,begin++;
       else len++;
       bool flagn = 0,flagc = 0;
         for(int i=0;i<ans.size();i++){
              if(isdigit(ans[i]))flagn = 1;
              if(ispunct(ans[i]))flagc = 1;
         }
            if(flagn&&flagc)count++;
    }
    cout<<count<<endl;
auto end = chrono::high_resolution_clock::now(); // 结束计时
chrono::duration<double> diff = end - start;     // 计算运行时间
cout << "Time taken by program: " << diff.count()*1000 << "ms" << endl;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
//     auto start = chrono::high_resolution_clock::now();
//     string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
//     int count = 0;
//     for (int len = 8; len <= 16; len++)
//     {
//         int digitCount = 0, punctCount = 0;
//         for (int i = 0; i < len; i++)
//         {
//             if (isdigit(s[i]))
//                 digitCount++;
//             if (ispunct(s[i]))
//                 punctCount++;
//         }
//         if (digitCount > 0 && punctCount > 0)
//             count++;
//         for (int i = len; i < s.size(); i++)
//         {
//             if (isdigit(s[i - len]))
//                 digitCount--;
//             if (ispunct(s[i - len]))
//                 punctCount--;
//             if (isdigit(s[i]))
//                 digitCount++;
//             if (ispunct(s[i]))
//                 punctCount++;
//             if (digitCount > 0 && punctCount > 0)
//                 count++;
//         }
//     }
//     cout << count;
//     auto end = chrono::high_resolution_clock::now(); // 结束计时
//     chrono::duration<double> diff = end - start;     // 计算运行时间
//     cout << "Time taken by program: " << diff.count() << "s" << endl;
//     return 0;
// }