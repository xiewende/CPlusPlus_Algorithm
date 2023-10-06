// 823. 带因子的二叉树

// 动态规划

// 定义：dp[i]：以数组下标i为最后也就是根节点的树个数，
// 初始化，全部dp[i] = 1;就是全部单个节点自己
// 状态转移方程

// 遇到arr[i]，需要需要遍历arr[j],其中 j<i，判断是否 curr = arr[i]/arr[j] 是整除，
// 若是，则找到curr的对应下标 jj，此刻 dp[i] = dp[j] * dp[jj], 也就是以arr[j]作为根节点arr[i]的右子树，arr[jj]作为根节点arr[i]的左子树。
// 若不是，跳过则可以。
// 注意可以利用一个map来记录每个值的下标，因为所有值不一样则可以用map
// 返回：
// 最后返回 sum(dp[i]) 即可；

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int numFactoredBinaryTrees(vector<int>& arr) {
    int n = arr.size();
    // 需要先排序才好往前找找整除的数字
    sort(arr.begin(), arr.end());
    int mod = 1e9 + 7;
    // dp数组
    vector<long long> dp(n, 1);
    // 此map记录arr[i]的下标i，也就是 key：arr[i],value：i
    unordered_map<int, int> vIdx;
    vIdx[arr[0]] = 0;
    // 初始答案第一个值
    int ans = 1;
    for (int i = 1; i < n;i++)
    {
        for (int j = 0; j < i;j++)
        {
            // 判断是否可以整除，不是则直接跳过即可
            if(arr[i] % arr[j] != 0){
                continue;
            }
            // 可以整除，判断右子树值是否存在，若存在，则更新以该值为左右子树的数目，也是组合问题，相乘即可
            int curr = arr[i] / arr[j];
            if(vIdx.count(curr)>0){
                long long tem = (dp[j] * dp[vIdx[curr]]) % mod;
                dp[i] = (dp[i] + tem) % mod;
            }
        }
        // 记录答案以及记录arr[i]的下标i；
        ans = (ans + dp[i]) % mod;
        vIdx[arr[i]] = i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 4, 5, 10};
    int ans = numFactoredBinaryTrees(arr);
    cout << ans;
    return 0;
}
