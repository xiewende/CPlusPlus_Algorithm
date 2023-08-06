// 438. 找到字符串中所有字母异位词

// 解题思路：双指针 + haxibiao

#include<iostream>
#include<vector>

using namespace std;

bool judge(vector<int>& seen, vector<int>& curr_seen){
    int n = seen.size();
    for (int i = 0; i < n;i++)
    {
        if(seen[i] != curr_seen[i]){
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int n = s.length();
    int m = p.length();
    if(m>n){
        return {};
    }
    vector<int> ans; // 结果
    vector<int> seen(26, 0); // 记录p字符串的出现次数
    vector<int> curr_seen(26, 0); // 记录窗口下的字符出现次数
    for (int i = 0; i < m;i++)
    {
        seen[p[i] - 'a']++;
        curr_seen[s[i] - 'a']++;
    }
    // 判断0索引开始是否符合
    if(judge(seen, curr_seen)){
        ans.emplace_back(0);
    }

    for (int i = 1; i + m <= n;i++)
    {
        curr_seen[s[i - 1] - 'a']--;
        curr_seen[s[i + m -1] - 'a']++;
        if(judge(seen, curr_seen)){
            ans.emplace_back(i);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s = "abab";
    string p = "ab";
    vector<int> ans = findAnagrams(s, p);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}
