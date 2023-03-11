// 面试题 17.05. 字母与数字
// 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

//返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。

// 重新定义，数字为 -1，字母为 1，题目转化为 寻求最长的和为 0 的 子数组


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

vector<string> findLongestSubarray(vector<string>& array) {
    unordered_map<int, int> vist {{0,-1}}; // key: 前缀和  value：index
    int sum = 0;
    int maxlength = 0;
    int startIndex = -1;
    for (int i = 0; i < array.size(); i++)
    {
        if(isalpha(array[i][0])){
            sum++;
        }else{
            sum--;
        }

        if(vist.count(sum)){
            int firstIndex = vist[sum];
            if(i - firstIndex > maxlength){
                maxlength = i - firstIndex;
                startIndex = firstIndex + 1;
            }
        }else{
            vist[sum] = i; //记录在内
        }
    }

    if(maxlength == 0){
        return {};
    }

    // return vector<string>(array.begin()+startIndex, array.begin()+startIndex+maxlength);  初始化截断子数组
    vector<string> ans;
    ans.assign(array.begin() + startIndex, array.begin() + startIndex + maxlength);
    return ans;  // assign 截断子数组
}

int main(){
    vector<string> array = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    for(auto tem : array){
        cout << tem ;
    }
    cout << endl;
    vector<string> ans = findLongestSubarray(array);
    for(auto tem : ans){
        cout << tem ;
    }
}
