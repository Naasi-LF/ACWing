#include <bits/stdc++.h>
using namespace std;
const int N = 1020;
int dp[N],nums[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i=3;i<=n;i++)
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    cout << dp[n];
}
