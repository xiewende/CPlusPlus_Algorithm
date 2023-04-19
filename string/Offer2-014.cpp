// 剑指 Offer II 014. 字符串中的变位词

// 方法一：固定窗口大小的滑动窗口：固定窗口大小为len1，判断s2的每个串口大小为len1的字串和s1是否满足

// 方法二：双指针，判断 【left，right】是否等于len。

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool check(string s1, string s){

    vector<int> visited(26, 0);

    // vector<int> ans(visited.begin(), visited.end())
    for (int i = 0; i < s1.length(); i++)
    {
        visited[s1[i] - 'a']++;
    }

    for (int i = 0; i < s.length();i++)
    {
        visited[s[i] - 'a']--;
    }

    for (int i = 0; i < 26;i++)
    {
        if (visited[i] != 0){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int left = 0;
    int right = len1 - 1;
    while(right<len2){
        bool ans = check(s1, s2.substr(left, len1));
        if(ans){
            return ans;
        }
        left++;
        right++;
    }
    return false;
}

bool checkInclusion1(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    vector<int> visited(26, 0);
    // vector<int> ans(visited.begin(), visited.end())
    for (int i = 0; i < s1.length(); i++)
    {
        visited[s1[i] - 'a']++;
    }

    int left = 0;
    for (int right = 0; right < len2; right++)
    {
        int curr = s2[right] - 'a';
        visited[curr]--;
        while(visited[curr]<0){
            visited[s2[left] - 'a']++;
            left++;
        }
        if(right-left+1 == len1){
            return true;
        }
    }
    return false;
}



int main(){
    string s1 = "ab";
    string s2 = "eidboaoo";
    bool ans = checkInclusion1(s1, s2);
    cout << ans;
    return 0;
}