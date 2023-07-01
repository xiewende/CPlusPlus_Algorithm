// 739. 每日温度

// 单调栈经典题目

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        // 检索栈顶元素
        while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
            s.pop();
        }
        // 记录答案
        ans[i] = s.empty() ? 0 : s.top() - i;
        // 入栈
        s.push(i);
     }
     return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    for(auto curr:ans){
        cout << curr << " ";
    }
    return 0;
}
