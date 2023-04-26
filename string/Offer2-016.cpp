// 剑指 Offer II 016. 不含重复字符的最长子字符串

// 解题思路：双指针+哈希记录

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = s.length();
    // vector<int> visited(26, 0);
    unordered_map<char, int> visited;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < len; right++)
    {
        visited[s[right]]++;
        while(visited[s[right]]> 1) {
            visited[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}
