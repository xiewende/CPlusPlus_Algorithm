#include<iostream>
#include<vector>
#include<map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> mymap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++){
        int tem = target - nums[i];
        if(mymap.count(tem) > 0 ){
            // result.push_back(mymap.find(tem)->second);
            result.push_back(mymap[tem]);
            result.push_back(i);
            break;
        }
        // mymap[nums[i]] = i;
        mymap.insert({nums[i], i});
    }

    return result;
}

int main()
{
    vector<int> nums = {2,7,11,15};
    // for (int i = 0; i < nums.size();i++){
    //     cout << nums[i] << endl;
    // }
    int a = 9;
    vector<int> ans;
    // cout << a;
    ans = twoSum(nums, a);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }

    return 0;
}
