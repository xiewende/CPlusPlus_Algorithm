// 2389. 和有限的最长子序列

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

    int n = nums.size(), m = queries.size();
    sort(nums.begin(), nums.end());
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + nums[i];
    }
    vector<int> answer(m);
    for (int i = 0; i < m; i++) {
        // 二分查找
        answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
    }

    return answer;
}

int main(){

    vector<int> nums{4,5,2,1};
    vector<int> queries{3, 10, 21};

    vector<int> ans = answerQueries(nums, queries);

    for(int zhi : ans){
        cout << zhi << " ";
    }

    return 0;
}