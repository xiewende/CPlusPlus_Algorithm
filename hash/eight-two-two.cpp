// 822. 翻转卡片游戏

// 解题思路：哈希表, 
// 首次遍历前后两个数组相同位置说明该数字不可能满足情况，记录在Hash中，
// 再次遍历，其余数字不在Hash中的都是想要的值，取最小就可

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int flipgame(vector<int>& fronts, vector<int>& backs) {
    int n = fronts.size();
    unordered_set<int> seen;
    for (int i = 0; i < n; i++)
    {
        if(fronts[i] == backs[i]){
            seen.emplace(fronts[i]);
        }
    }
    // 不在hash里面的值都可以作为最后结果
    int ans = INT_MAX;
    for (int i = 0; i < n;i++)
    {
        if(seen.count(fronts[i])>0 && seen.count(backs[i])>0){
            continue;
        }
        int min_fb;
        if(seen.count(fronts[i])==0 && seen.count(backs[i])>0){
            min_fb = fronts[i];
        }else if(seen.count(fronts[i])>0 && seen.count(backs[i])==0){
            min_fb = backs[i];
        }else{
             min_fb = min(fronts[i], backs[i]);
        }
        // 取最大
        ans = min(ans, min_fb);
    }
    return ans==INT_MAX ? 0 : ans;
}

int main(int argc, char const *argv[])
{
    vector<int> fronts = {1,1};
    vector<int> backs = {1,2};
    int ans = flipgame(fronts, backs);
    cout << ans;
    return 0;
}
