// 85. 最大矩形

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int getJuxing(vector<int>& nums){
    int n = nums.size();
    stack<int> sta; // 存储下标， 底小顶大
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        while(!sta.empty() && nums[i] < nums[sta.top()]){
            // int index = ;
            int height = nums[sta.top()];
            sta.pop();
            int preIdx = sta.empty() ? -1 : sta.top(); // 栈顶元素的前一个元素的下标
            int weight = i - preIdx - 1;  // 卡在中间，例如 【0 3 2 5】 计算高度为2的时候，左index是0这个位置，而不是自身
            ans = max(ans, height * weight);
        }
        sta.push(i);
    }
    while(!sta.empty()){
        // int index = sta.top();
        int height = nums[sta.top()];
        sta.pop();
        int preIdx = sta.empty() ? -1 : sta.top();
        int weight = n - preIdx - 1;
        ans = max(ans, height * weight);
    }

    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> dp(m, 0);

    int ans = 0;

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            // dp[j] = dp[j] + (matrix[i][j] - '0');
            if(matrix[i][j] == '0'){
                dp[j] = 0;
            }else{
                dp[j] = dp[j] + (matrix[i][j] - '0');
            }
        }

        ans = max(ans, getJuxing(dp));
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    // return 0;

    // vector<int> nums = {4,2,0,3,2,5};
    // vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'1'}};
    int ans = maximalRectangle(matrix);
    cout << ans;
}
