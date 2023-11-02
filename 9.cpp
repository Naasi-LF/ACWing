#include <bits/stdc++.h>
using namespace std;
long long n;
const long long N=1e6+10;
long long f[N];
int main()
{
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    if(n==1 || n==2)
    {
        cout << f[n];
        return 0;
    }
    for (long long i = 3; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
        f[i]=f[i]%10007;
    }
    cout << f[n]%10007;
}