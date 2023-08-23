// 剑指 Offer II 093. 最长斐波那契数列

// 解题思路：动态规划

// dp[j][i] : 代表以 arr[j] 和 arr[i] 为结尾的最长斐波那契数列长度

// 首先遍历 0 <= i < len（i++）; 再遍历 0<=j<i（j--）, 判断原数组是否存在 arr[i]-arr[j]的值，
// 若存在，则 dp[j][i] = dp[k][j] + 1 或者 dp[j][i] = 3，dp[k][j]前面没有满足的，也就是到边了，也就是只有 arr[k],arr[j],arr[i]三个值作为答案的长度3
//                       其中 k < j < i 的

// 返回 ans = max(ans, dp[j][i])  每次得到的值取大，并不是最后的值，因为并不都是以最后两个值结尾才可以得到最长的

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int lenLongestFibSubseq(vector<int>& arr) {
    int len = arr.size();
    if(len < 3){
        return 0;
    }
    unordered_map<int, int> indices;
    for (int i = 0; i < len; i++)
    {
        indices[arr[i]] = i;
    }
    int ans = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    
    for (int i = 0; i < len;i++){
        for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i];j--)
        {
            int k = -1;
            if(indices.count(arr[i]-arr[j])){
                k = indices[arr[i]-arr[j]];
            }
            if(k >= 0){
                dp[j][i] = max(dp[k][j] + 1, 3);
            }
            ans = max(ans, dp[j][i]);
        }  
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8}; // 2 6 8 14 22 
    int ans = lenLongestFibSubseq(arr);
    cout << ans;
    return 0;
}