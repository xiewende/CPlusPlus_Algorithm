// Offer 48. 最长不含重复字符的子字符串

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> visited;
    int left = 0;
    int right = 0;
    int ans = 0;
    while(right < s.length()){
        visited[s[right]]++;
        while(visited[s[right]] > 1){
            visited[s[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main(){
    string s = "bbbb";
    // cin >> s;
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}