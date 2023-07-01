// 1177. 构建回文串检测

// 哈希表 + 字符出现次数的前缀和 + 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    int n = s.length(), q = queries.size(), sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        int bit = 1 << (s[i] - 'a');
        sum[i + 1] = sum[i] ^ bit; // 该比特对应字母的奇偶性：奇数变偶数，偶数变奇数
    }

    vector<bool> ans(q); // 预分配空间
    for (int i = 0; i < q; i++) {
        auto &query = queries[i];
        int left = query[0], right = query[1], k = query[2];
        int m = __builtin_popcount(sum[right + 1] ^ sum[left]);
        ans[i] = m / 2 <= k;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "abcda";
    vector<vector<int>> queries = {};
    vector<bool> ans = canMakePaliQueries(s, queries);
    return 0;
}

