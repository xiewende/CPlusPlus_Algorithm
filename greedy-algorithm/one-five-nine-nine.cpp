// 1599. 经营摩天轮的最大利润

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    int max_profit = 0;
    int count = 0;
    int waiting = 0;
    int up = 0;  // 统计上过的人数
    int ans = -1;
    for (int i = 0; i < customers.size(); i++)
    {
        waiting += customers[i]; // 等待人数

        //转动一次
        count++; // 转动次数
        int curr_up = waiting >= 4 ? 4 : waiting; //本次可以上的人数 
        waiting = waiting >= 4 ? waiting - 4 : 0; //还剩等待人数

        up = up + curr_up; 
        int profit = up * boardingCost - count * runningCost;

        if(profit > max_profit){  //判断是否存在最大利润
            max_profit = profit;
            ans = count;
        }
    }

    // 剩余等待人数继续上车
    while (waiting > 0)
    {
        count++; // 转动次数
        int curr_up = waiting >= 4 ? 4 : waiting; //本次可以上的人数 
        waiting = waiting - 4; //还剩等待人数
        up = up + curr_up;
        int profit = up * boardingCost - count * runningCost;
        if(profit > max_profit){
            max_profit = profit;
            ans = count;
        }
    }

    return ans;
}

int main(){
    vector<int> customers{3,4,0,5,1};
    int boardingCost = 1;
    int runningCost = 92;
    int ans = minOperationsMaxProfit(customers, boardingCost, runningCost);
    cout << ans;
}