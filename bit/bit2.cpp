#include <bits/stdc++.h>
using namespace std;
const int N =1020;
int f[N],n;
int main()
{
    cin >> n;
    f[1]=0;f[2]=0;f[3]=0;f[4]=1;
    for (int i = 5; i <= n; i++)
        f[i]= f[i-1]+f[i-2]+f[i-3]+pow(2,(i-3))-1;
    for (int i = 1; i <= n; i++)
        cout << i << ":" << f[i] << endl;
}