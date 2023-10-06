// 查找和最小的 K 对数字

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> ans;
    int idx1 = 0;
    int idx2 = 0;

    while(k>0){
        int num1 = nums1[idx1];
        int num2 = nums2[idx2];
        if(num1==num2){
            ans.push_back({num1, num2});
            if(idx1 == n-1){
                idx2++;
            }else if(idx2 == m-1){
                idx1++;
            }else if(nums1[idx1+1]<nums2[idx2+1]){
                idx1++;
            }else{
                idx2++;
            }
        }else if(num1<num2){
            ans.push_back({num1, num2});
            idx2++;
        }else{
            ans.push_back({num2, num1});
            idx1++;
        }
        k--;
    }

    

    return ans;
}