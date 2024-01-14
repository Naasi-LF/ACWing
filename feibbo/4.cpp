//斐波那契 矩阵快速幂做法
//无需掌握，只需要了解下
//我上课说的推导流程比代码更重要
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;//数字过大进行取模

//matrix n矩阵
struct mat
{
    //五行五列二维数组(数组开的大一些)
    long long a[5][5];
};

//两个矩阵相乘,返回矩阵
mat mul(mat a,mat b)
{
    mat ans;//结果
    memset(ans.a,0,sizeof ans.a);//初始化:ans为mat类型的结构体,ans.a为矩阵
    for (int i = 0; i < 2;i++)
        for (int j = 0;j < 2;j++)
            for (int k = 0;k < 2;k++)
                ans.a[i][j] += (a.a[i][k] * b.a[k][j]) % mod;//a和b为mat类型的结构体,a.a和b.a为矩阵
    return ans;
}

//n代表指数
long long quick_power(long long n)
{
    mat ans,res;//ans为结果矩阵,res为系数矩阵
    
    memset(ans.a,0,sizeof ans.a);//初始化结果矩阵
    ans.a[0][0] = 1;
    ans.a[1][0] = 1;
    
    memset(res.a,0,sizeof res.a);//初始化系数矩阵
    res.a[0][0] = 1;
    res.a[0][1] = 1;
    res.a[1][0] = 1;
    res.a[1][1] = 0;
    
    //核心代码,快速幂算法
    while (n)
    {
        if (n & 1) ans = mul(res,ans);//res和ans两个矩阵不能颠倒
        n >>= 1;//指数减半
        res = mul(res,res);//底数平方
    }
    return ans.a[0][0];//ans.a[0][0]即图中的f(n)
}

int main()
{
    int n;
    cin >> n;
    //1 1 2 3 5 8 13 21 34
    if (n == 1 || n == 2) cout << 1 << endl;
    else cout << quick_power(n - 2) << endl; 
    return 0;
}
