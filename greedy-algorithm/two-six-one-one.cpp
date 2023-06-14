// 2611. 老鼠和奶酪

// 解题思路：贪心策略；需要选择reward1的位置是根据 reward1[i]-reward[i]的前K大差值值的位置

// 一、
// 要想恰好吃 K 个reward1得到最大值，我们知道肯定得选择reward1中 前 K 个 reward1-reward2 差值的最大值，只有这样才可能得到最后的最大值，
// 1、计算每块奶酪的差值 diff[i] = reward1[i] - reward2[i];
// 2、按照差值 diff降序排序，若差值相同，按照reward1大的降序排，
// 3、取前K个排序好的值选reward1，后面的都选reward2的值

// 二、
// 1、假设全部奶酪都被第二只老鼠吃掉，也就是全选择reward2，则结果为reward2的和， 记为：sum
// 2、假设下标 i 处的奶酪被第一只老鼠吃了，也就是选择了reward[i], 则结果就变为 sum + (reward1[i] - reward2[i])
// 3、所以我们只需要先创建差值数组 diff[i] = reward1[i] - rewaed2[i],
// 4、选择差值数组中前 K 个最大值 和 sum 相加就是最终答案；也就是说选择reward1[i]会比选择reward2[i]多最多的前 K 大值
// 5、实现上，排序diff，sum连续添加前 K 大的diff[i]值即可


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }else{
        return a[0] > b[0];
    }
}

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size();

    // 库函数求和
    // 相等返回 reward2的和值
    if(k == n){
        return accumulate(reward1.begin(), reward1.end(), 0); 
    }

    // 构造diff数组
    vector<int> diff(n, 0);
    vector<vector<int>> nums(n, vector<int>(3, 0));
    for (int i = 0; i < n;i++)
    {
        diff[i] = reward1[i] - reward2[i];
        nums[i] = vector<int>{diff[i], reward1[i], reward2[i]};
    }

    // p排序
    sort(nums.begin(), nums.end(), cmp);

    // 前 K 大的 diff 值的位置选择reward1[i], 后面选reward2[i]
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(i<k){
            ans += nums[i][1];
        }else{
            ans += nums[i][2];
        }
    }
    return ans;
}

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size();

    // int ans = 0;
    // 求和是因为最后的结果是肯reward2的和基础上加上 reward1和erward2差值的前K个最大值
    int ans = accumulate(reward2.begin(), reward2.end(), 0);

    // reward1和reward2的差值
    vector<int> diff(n);
    for (int i = 0; i < n;i++)
    {
        diff[i] = reward1[i] - reward2[i];
    }

    // 排序差值
    sort(diff.begin(), diff.end());

    // 选择最大的k哥差值添加到答案中
    for (int i = 0; i < k;i++)
    {
        ans += diff[n-i-1];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> reward1 = {1, 1, 3, 4};
    vector<int> reward2 = {4, 4, 5, 1};
    int k = 2;
    int ans = miceAndCheese(reward1, reward2, k);
    cout << ans;
    return 0;
}
