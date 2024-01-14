#include <bits/stdc++.h>
using namespace std;
int DP[1020],nums[1020];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    //3~n-1
    DP[3] = nums[3];
    DP[4] = max(nums[3],nums[4]);
    for(int i = 5 ; i <= n-1 ; i++)
        DP[i] = max(DP[i-1],DP[i-2]+nums[i]);
    int p1 = DP[n-1]+nums[1];//偷第一个数的情况
    memset(DP,0,sizeof(DP));//将DP滞空
    //2~n
    DP[2] = nums[2];
    DP[3] = max(nums[3],nums[2]);
    for(int i = 4 ; i <= n ; i++)
        DP[i] = max(DP[i-1],DP[i-2]+nums[i]);
    int p2 = DP[n];//不偷第一个数的情况
    cout << max(p1,p2);
}