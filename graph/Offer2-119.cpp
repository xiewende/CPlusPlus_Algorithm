// 剑指 Offer II 119. 最长连续序列

// 解题思路：哈希表， O(n)时间复杂度

// 哈希表的作用一是为了去重，而是为了后面遍历好找

// 1、先将数组元素放到哈希表中，

// 2、遍历哈希表，只需要在遍历到的 num 下逐步 num+1, 判断哈希表中是否存在 num+1 的值，同时记录长度

// 需要注意的是，不需要每个num都去逐步+1来判断，我们只需要在nums中的某一个顺序的最小值开始找，取其中最大就好
// 假如 num-1 存在于哈希表中，则可以跳过该num，直到遍历到 num-1 才会判断其升序的值(就是逐步+1)
// 例子：100，4，3，2，1，

// num=100，首先num-1=99不存在哈希表中，则+1判断，得到无，结果以num=100升序的长度为1；
// num=4，首先num-1存在哈希表中，跳过
// num=3，首先num-1存在哈希表中，跳过
// num=2，首先num-1存在哈希表中，跳过
// num=1，首先num-1=0不存在哈希表中，则逐步+1判断，得到最大为4，答案长度就是4个

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> nums_set;
    for(int num : nums){
        nums_set.emplace(num);
    }
    int ans = 0;
    for(auto num : nums_set){
        // 判断 num-1 是否在哈希表中，若在则跳过
        if(nums_set.count(num-1)){
            continue;
        }
        // num 为某一顺序的最小值，逐步+1判断其长度
        int curr_num = num;
        int curr_len = 1;
        while(nums_set.count(curr_num+1)){
            curr_num += 1;
            curr_len += 1;
        }
        ans = max(ans, curr_len);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {100, 4, 200, 2, 3, 1};
    int ans = longestConsecutive(nums);
    cout << ans;
    return 0;
}
