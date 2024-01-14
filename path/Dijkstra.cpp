//最短路径
#include <bits/stdc++.h>
using namespace std;
int G[10][10] {};
int DP[10][10] {};//DP[i][j]到某个点的最短路径,i表示迭代轮数
void Build()
{
    memset(G,0x3f,sizeof(G));//初始化成最大值
    //建图
    for (int i = 1; i <= 5 ; i++)
        G[i][i] = 0;
    G[1][2] = 4;G[2][1] = 4;
    G[1][3] = 3;G[3][1] = 3;
    G[2][3] = 2;G[3][2] = 2;
    G[2][4] = 5;G[4][2] = 5;
    G[3][4] = 3;G[4][3] = 3;
    G[3][5] = 6;G[5][3] = 6;
    G[4][5] = 1;G[5][4] = 1;
}
int main()
{
    Build();
    //从1开始，到5的最短路径
    //加权无向图的问题
    //开始动态规划
    //DP[][1]~DP[][5]
    memset(DP[1],0x3f,sizeof(DP[1]));//初始化最大值
    DP[1][1] = 0;//目的是为了递推
    int index = 1;//初始标志为1
    set<int> Q;//存储已是最小点的位，这里A存不存都行
    for (int i = 2; i <= 5; i++)//从第二趟一直到第五躺
    {
        for (int k = 2; k <= 5; k++)//从2开始，避免边界问题
        {
            DP[i][k] = min(DP[i-1][k],DP[i-1][index]+G[index][k]);
        }
        int current = INT_MAX;
        for (int k = 2; k <= 5; k++)//找最小点所在位置
        {
            auto it = Q.find(k);
            if(it!=Q.end())
                continue;//如何在集合中，就不用判断了
            int save = current;//保护原有数据
            current = min(DP[i][k],current);//更新最小值
            if(current!=save)
                index = k;
            //更新新的index
        }
        Q.insert(index);
    }
    cout << DP[5][5];
}