#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin >> n;
   int nn = n;
   int sum = 0;
   while(n--){
    int a;
    cin >> a;
    sum += a;
   }
   cout<<sum<<endl;
   double avg = (double)sum / n;
   printf("average = %.1f\n", avg);
}