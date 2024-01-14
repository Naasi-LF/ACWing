#include <bits/stdc++.h>  
// pow(a,b)  a^b   #include <cmath> / <math.h>
// for(b) a*=a
using namespace std;
const int N = 1020;
int DP[N],n;
int main()
{
    cin >> n;
    DP[1]=0;DP[2]=0;DP[3]=1;
    for(int i=4;i<=n;i++)
    {
        DP[i]=DP[i-1]+DP[i-2]+DP[i-3]+pow(2,(i-3));
    }
    cout << DP[n];
}