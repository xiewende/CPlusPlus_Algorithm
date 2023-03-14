// 523. 连续的子数组和

// 解题： 前缀和 + HashMap

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {

    int sum = 0;
    
    int length = nums.size();
    if (length < 2)
    {
        return false;
    }
    
    unordered_map<int, int> visit{{0, -1}};
    for (int i = 0; i < length;i++){
        sum += nums[i];
        // int target = (sum % k + k) % k;
        int target = sum % k;
        if(visit.count(target)){
            int preIndex = visit[target];
            if(i - preIndex >= 2){
                return true;
            }
        }else{
            visit[target] = i;
        }
        
    }
    return false;
}

int main(){
    vector<int> nums{23,2,4,6,7};
    int k = 6;
    bool ans = checkSubarraySum(nums, k);

    cout << ans << endl;
}
