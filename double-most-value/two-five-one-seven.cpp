// 2517. 礼盒的最大甜蜜度

// 解题思路，最值最值问题 一般利用二分查找+判断是否满足来判断。
// 步骤： 1、列举满足题意得值得范围
//       2、二分查找遍历，判断是否满足题意得范围，进而找到最大或者最小值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 判断最终结果为diff，能都在数组找到至少 k 个值之间两两绝对值是大于OR等于diff的，以此进一步搜索diff的值域
bool check(vector<int>& price, int diff, int k){
    int MIN_VALUE = -diff;
    int count = 0;
    for(auto p : price){
        if(p-MIN_VALUE>=diff){
            MIN_VALUE = p;
            count++;
        }
    }
    return count >= k;
}

int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());

    // 根据题意甜度是根据绝对值得到的 所以最后题意结果肯定是在【0，最大值-最小值】之间的
    int max_p = price[price.size()-1] - price[0];
    int min_p = 0;
    // for (int i = 0; i < price.size();i++)
    // {
    //     max_p = max(max_p, price[i]);
    // }
    int ans = 0;
    // 二分查找【0，最大值-最小值】中的某一个值，进而判断在该值下能否满足题意的第一个最值条件
    while(min_p <= max_p){
        int mid_p = (max_p + min_p) / 2;
        // 判断该值下能否满足题意来判断取值区域
        // 在数组中判断是否有k个数之间的绝对值是大于等于该答案值的，若满足，可以继续加大该答案值
        if(check(price, mid_p, k)){
            ans = mid_p;
            min_p = mid_p + 1;
        }else{
            // 若不满足，缩小该值的值域继续查找
            max_p = mid_p - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> price = {34,116,83,15,150,56,69,42,26};
    int k = 6;
    int ans = maximumTastiness(price, k);
    cout << ans;
    return 0;
}

