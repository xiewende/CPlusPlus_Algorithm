// 剑指 Offer II 073. 狒狒吃香蕉

// 解题思路：满足某个情况的最值问题

// 1、罗列满足的全部情况，
// 2、二分查找某个值得到最值满足该情况

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 判断在某个值是否满足该情况
bool check(vector<int>& piles, int k, int h){
    int count = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        int curr = piles[i] % k == 0 ? piles[i] / k : (piles[i] / k) + 1;
        count += curr;
    }
    return count <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int min_k = 1;
    int max_k = *max_element(piles.begin(), piles.end());
    int ans;
    // 二分查找最值
    while(min_k <= max_k){
        int mid_k = (min_k + max_k) / 2;
        if(check(piles, mid_k, h)){
            ans = mid_k;
            max_k = mid_k - 1;
        }else{
            min_k = mid_k + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> piles = {312884470};
    int h = 968709470;
    int ans = minEatingSpeed(piles, h);
    cout << ans;
    return 0;
}
