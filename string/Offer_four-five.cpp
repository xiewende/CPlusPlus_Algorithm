// 面试题45. 把数组排成最小的数

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 回溯比较肯定可以，但是耗费时间
void dfs(vector<int>& nums, vector<bool> &visited, int length, int index, string& curr, string& ans){
    // ans = ans + to_string(nums[index]);
    if(index == length){
        ans = min(ans, curr);
        return;
    }

    for (int i = 0; i < length; i++)
    {
        if(visited[i]){
            continue;
        }
        curr += to_string(nums[i]);
        int add_len = to_string(nums[i]).length();
        int curr_len = curr.length();
        visited[i] = true;
        dfs(nums,visited, length, index + 1, curr, ans);
        visited[i] = false;
        curr = curr.substr(0, curr_len - add_len);
    }
    return;
}

string minNumber(vector<int>& nums) {
    string curr = "";
    string ans = "";
    int len = nums.size();
    vector<bool> visited(len, false);
    for (int i = 0; i < len; i++)
    {
        ans += to_string(nums[i]);
    }
    dfs(nums, visited, len, 0, curr, ans);
    return ans;
}

// 按照一定规则排序
int cmp(string& a, string& b){
    string x = a + b;
    string y = b + a;
    return x < y;
}
// 转换成排序问题
string minNumber1(vector<int>& nums) {
    string ans;
    int len = nums.size();
    vector<string> nums_str;
    for (int i = 0; i < len; i++)
    {
        nums_str.push_back(to_string(nums[i]));
    }
    // 排序
    sort(nums_str.begin(), nums_str.end(), cmp);
    //逐个加起来
    for(int i = 0; i < len; i++){
        ans.append(nums_str[i]);
    }
    return ans;
}


int main(){
    // string curr = "ab";
    // string add = "ced";
    // curr = curr + add;
    // int curr_len = curr.length(); //5
    // int add_lenth = add.length(); //3
    // cout << curr << endl;
    // cout << curr.substr(0, curr_len-add_lenth) << endl;

    vector<int> nums{2, 1};
    string ans = minNumber1(nums);
    cout << ans << endl;
    return 0;
}
