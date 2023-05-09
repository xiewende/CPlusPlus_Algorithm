// 剑指 Offer II 038. 每日温度

#include<iostream>
#include<stack>
#include<vector>
#include<utility>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int len = temperatures.size();
    vector<int> ans(len, 0);
    stack<pair<int, int>> mystack; // 第一个是元素，第二个是该元素的下标；也可以只放下标
    mystack.push({temperatures[0],0});

    for (int i = 1; i < len;i++)
    {   
        while (!mystack.empty() && temperatures[i]>mystack.top().first)
        {
            /* code */
            auto curr = mystack.top();
            mystack.pop();
            ans[curr.second] = i - curr.second;
        }
        mystack.push({temperatures[i], i});
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> tem = {30,40,50,60};
    vector<int> ans = dailyTemperatures(tem);
    for(auto curr:ans){
        cout << curr << " ";
    }
    return 0;
}
