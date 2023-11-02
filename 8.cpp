#include <bits/stdc++.h>
using namespace std;
long long n;
long long f(int x)
{
    if(x==1 || x==2)
        return 1;
    return f(x-1)%10007+f(x-2)%10007;
}
int main()
{
    cin >> n;
    cout << f(n)%10007;
}