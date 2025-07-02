#include <bits/stdc++.h>
using namespace std;
int main()
{
    double N, sum = 0;
    int count = 0;
    cin >> N;
    string a;
    for (int i = 0; i < N; i++)
    {

        string a;
        cin >> a;
        bool legal = true;
        int pointPosition = -1;
        for (int j = 0; j < a.size(); j++)
        {
            if (!isdigit(a[j]) && a[j] != '.' && !(j == 0 && a[j] == '-'))
            {
                legal = false;
                break;
            }
            if (a[j] == '.')
            {
                if (pointPosition != -1)
                {
                    legal = false;
                    break;
                }
                pointPosition = j;
            }
        }
        if (pointPosition != -1 && a.size() - pointPosition > 3)
        {
            legal = false;
        }
        double num = 0;
        if (legal)
        {
            num = stod(a);
            if (num > 1000 || num < -1000)
            {
                legal = false;
            }
        }
        if (legal)
        {
            sum += num;
            count++;
        }
        else
        {
            cout << "ERROR: " << a << " is not a legal number" << endl;
        }
    }
    double average = sum / count;
    switch (count)
    {
    case 0:
        cout<< "The average of 0 numbers is Undefined\n" << endl;
        break;
    
    case 1:
        printf("The average of 1 number is %.2f\n", sum);
        break;
    default:
        printf("The average of %d numbers is %.2f\n", count, average);
        break;
    }
}