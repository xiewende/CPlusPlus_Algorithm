// 剑指 Offer II 015. 字符串中的所有变位词

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

vector<int> findAnagrams(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();

    if(len1 == 0 || len2 == 0){
        return {};
    }
    int left = 0;
    int right = len2 - 1;
    vector<int> ans;
    while(right<len1){
        bool flag = check(p, s.substr(left, len2));
        if(flag){
            ans.push_back(left);
        }
        left++;
        right++;
    }
    return ans;
}


vector<int> findAnagrams1(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();
    vector<int> ans;
    vector<int> visited(26, 0);
    // vector<int> ans(visited.begin(), visited.end())
    for (int i = 0; i < p.length(); i++)
    {
        visited[p[i] - 'a']++;
    }

    int left = 0;
    for (int right = 0; right < len1; right++)
    {
        int curr = s[right] - 'a';
        visited[curr]--;
        while(visited[curr]<0){
            visited[s[left] - 'a']++;
            left++;
        }
        if(right-left+1 == len2){
            ans.push_back(left);
        }
    }
    return ans;
}



int main(){
    string s = "cbaebabacd";
    string p = "abc";
    
    vector<int> ans = findAnagrams1(s, p);
    
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}