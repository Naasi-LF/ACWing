//斐波那契递归做法
#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
    if(x==0 || x==1)
        return x;
    else return f(x-1)+f(x-2);
}
int main()
{
    int n;
    cin >> n;
    cout << f(n);
}