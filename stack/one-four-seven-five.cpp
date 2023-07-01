// 1475. 商品折扣后的最终价格

// 单调栈，底小顶大

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> s;
    // 后到前遍历
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && prices[i] < s.top())
        {
            s.pop();
        }

        ans[i] = s.empty() ? prices[i] : prices[i] - s.top();
        s.push(prices[i]);
    }
    return ans;
}

vector<int> finalPrices1(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> s;
    // 前到后遍历
    for (int i = 0; i < n; i++)
    {
        // 可以打折
        while (!s.empty() && prices[i] <= prices[s.top()])
        {
            ans[s.top()] = prices[s.top()] - prices[i];
            s.pop();
        }
        // ans[i] = s.empty() ? prices[i] : prices[i] - s.top();
        s.push(prices[i]);
        ans[i] = prices[i];
    }
    return ans;
}