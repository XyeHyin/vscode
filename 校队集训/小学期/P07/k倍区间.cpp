#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ADT;
void merge1(long long &sum, const ADT a[], long long lena, const ADT b[],
            long long lenb, ADT c[]) {
    long long i = 0, j = 0, k = 0;
    while (i < lena && j < lenb)
        if (b[j] < a[i]) {
            if (j + lena - k > 0)
                sum += j + lena - k;
            c[k++] = b[j++];
        } else {
            if (i - k > 0)
                sum += i - k;
            c[k++] = a[i++];
        }

    while (i < lena) {
        if (i - k > 0)
            sum += i - k;
        c[k++] = a[i++];
    }
    while (j < lenb) {
        if (j + lena - k > 0)
            sum += j + lena - k;
        c[k++] = b[j++];
    }
}
void merge_sort(long long &sum, ADT arr[], unsigned long long len) {
    unsigned long long i, m = 1;
    ADT *tarr = new ADT[len];
    while (m < len) {
        for (i = 0; i < len; i += 2 * m)
            merge1(sum, &arr[i], i + m < len ? m : len - i, &arr[i + m],
                   i + 2 * m < len ? m : len - i - m, &tarr[i]);
        m *= 2;
        for (i = 0; i < len; i += 2 * m)
            merge1(sum, &tarr[i], i + m < len ? m : len - i, &tarr[i + m],
                   i + 2 * m < len ? m : len - i - m, &arr[i]);
        m *= 2;
    }
    delete[] (tarr);
}
//逆序数
long long ni(vector<long long> &v) {
    long long size = v.size();
    long long sum = 0, i, j;
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (v[j] < v[i])
                sum++;
    return size * (size - 1) / 2 - sum;
}
//归并排序求逆序数
long long ni1(vector<long long> &v) {
    long long size = v.size();
    long long sum = 0;
    long long *v1 = new long long[size];
    for (sum = 0; sum < size; sum++)
        v1[sum] = v[sum];
    sum = 0;
    merge_sort(sum, v1, size);
    delete[] v1;

    return size * (size - 1) / 2 - sum;
}
int main() {
    long long n, k;
    cin >> n >> k;
    map<long long, vector<long long>> m;
    long long i, x, y = 0, sum = 0, sum0 = 0;
    for (i = 0; i < n; i++) {
        cin >> x;
        y += x;
        if (y % k == 0 && y / k >= 0)
            sum0++;
        if (y < 0)
            m[(y % k + k) % k].push_back(y / k - 1);

        else
            m[y % k].push_back(y / k);
    }

    for (map<long long, vector<long long>>::iterator it = m.begin();
         it != m.end(); it++)
        sum += ni(it->second);
    cout << sum + sum0;
}