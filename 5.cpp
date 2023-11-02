#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> q[N+1];//0~n
vector <int> s[N+1];//0~n
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    // memset (q,0,sizeof(q));
    for (int i = 1; i <= n; i++)
    {
        q[i].push_back(0);
        s[i].push_back(0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            int a;
            // if(i==1 && j==1)
            // {
            //     s[i][j]=a;
            // }
            cin >> a;
            q[i].push_back(a);
            s[i].push_back(0);
        }
//  s[i][j]=max(s[i-1][j],s[i-1][j-1])+q[i][j];
//  s[i][j]=s[i-1][j]+q[i][j]
//  s[i][j]=s[i-1][j-1]+s[i][j]

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            if(i==1 && j==1)
            {
                s[i][j]=q[i][j];//初始值
                continue;
            }
            if(j==1)
            {
                s[i][j]=s[i-1][j]+q[i][j];
                continue;
            }
            if(j==i)
            {
                s[i][j]=s[i-1][j-1]+q[i][j];
                continue;
            }
            s[i][j]=max(s[i-1][j],s[i-1][j-1])+q[i][j];
        }
    int index=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        index = max(s[n][i],index);
    }
    cout << index;
}