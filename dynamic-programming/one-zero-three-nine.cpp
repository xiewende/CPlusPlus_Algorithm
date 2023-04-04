// 1039. 多边形三角剖分的最低得分

// 解题思路，区间dp
// 看到最值问题可以想到dp问题

// 寻找子问题
// dp[i][j] : 表示沿着边从顶点i到顶点就，再加上直接从j到i的这条边所组成的多边形
// 子问题：枚举k（i<k<j）计算：从i到k；从k到j的子问题
// 定义dfs(i,)表示从到这个多边形的最低得分枚举包含顶点i和顶点的三角形的顶点k那么这个三角形会把多边形分成两个更小的多边形递归计算最低得分
// dfs(i,j) =  min(dfs(i,k)+dfs(k,j)+values[i]*values[j]*values[k]) 其中 i+1 <= k < j-1;
// 递归出口 dfs(i,i+1)=0 : 只有两个点无法构成三角形
// 入口：dfs(0,length-1)

// 迭代转移方程
// dp[i],[j] =  min(dp(i,k)+dp(k,j)+values[i]*values[j]*values[k]) 其中 i+1 <= k < j-1;
// 倒叙遍历i，顺序遍历j，才满足迭代值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 记忆化搜索递归
int dfs(vector<int>& values, vector<vector<int>>& visited, int left, int right){
    // 递归出口
    if(left+1 == right){
        return 0;
    }
    //记忆化返回
    if(visited[left][right]>-1){
        return visited[left][right];
    }
    // 三个区域找最大
    int res = 0x3f3f3f3f;
    for (int k = left + 1; k < right; k++){
        res = min(res, dfs(values, visited, left, k) + dfs(values, visited, k, right) + values[left] * values[right] * values[k]);
    }
    visited[left][right] = res;
    return res;
}

int minScoreTriangulation(vector<int>& values) {
    int length = values.size();
    vector<vector<int>> visited(length, vector<int>(length, -1));
    return dfs(values, visited, 0, length - 1);
}


// 改成迭代
int minScoreTriangulation1(vector<int>& values) {
    int length = values.size();
    vector<vector<int>> dp(length, vector<int>(length, 0));

    for (int i = length - 3; i >= 0;i--)
    {
        for (int j = i+2; j < length; j++)
        {
            int res = 0x3f3f3f3f;
            for (int k = i + 1; k < j; k++)
            {
                res = min(res, dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
            dp[i][j] = res;
        }
    }
    return dp[0][length - 1];
}


int main(){
    vector<int> values{3, 7, 4, 5};
    
    int ans = minScoreTriangulation1(values);
    cout << ans;
    return 0;
}