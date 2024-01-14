//斐波那契递推做法
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+20;
int f[N];
int main()
{
    f[0]=0;f[1]=1;
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout << f[n];
}