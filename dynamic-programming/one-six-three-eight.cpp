// 1638. 统计只差一个字符的子串数目

// 解题思路：动态规划
// 给定字符串 s t，
// 因为是两个字符串的子字符串的相差一个字母的字串个数
// 采取先采取，s[i] != t[j] 分别向右扩展，和向左扩展，相同的长度是多少。向左扩展相同的长度为 count_l；向右扩展的长度为 count_r
// 此时，只有 s[i] != t[j] 的情况下，一共有 （count_l+1）*（count_r+1）个满足题目的字串
// 根据这个分析
// 1、可以暴力解决
// 2、动态规划解决
// dp_l[i][j]: 定义为以在 s[i] t[j]为终点的左边最长相同字串的长度
// dp_r[i][j]: 定义为以在 s[i] t[j]为起点的右边最长相同字串的长度
// 遍历 【i】【j】位置，当 s[i] != t[j] 时，返回 （dp_l[i][j]+1） * (dp_r[i][j]+1)
// dp_l[i][j] = dp[i-1][j-1] + 1 若 s[i]==t[j]  左往右遍历
//              0                若 s[i]!=t[j]
// dp_r[i][j] = dp[i+1][j+1] + 1 若 s[i]==t[j]  右往左遍历
//              0                若 s[i]!=t[j]

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//暴力
int countSubstrings(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();
    int ans = 0;
    for (int i = 0; i < len_s; i++)
    {
        for (int j = 0; j < len_t; j++)
        {   
            // 当s[i] != t[j] 时:
            if(s[i] != t[j]){
                // 左边找相同的最长
                int idx_l = 1;
                while(i-idx_l>=0 && j-idx_l>=0 && s[i-idx_l] == t[j-idx_l]){
                    idx_l++;
                }
                // 右边找最长的相同
                int idx_r = 1;
                while(i+idx_r<len_s && j+idx_r<len_t && s[i+idx_r] == t[j+idx_r]){
                    idx_r++;
                }
                ans = ans + idx_l * idx_r; // 上面遍历的时候从自身开始遍历，所以这里两边都不用+1
            }
        }
    }
    return ans;
}

//动态规划
int countSubstrings(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();
    vector<vector<int>> dp_l(len_s+1, vector<int>(len_t+1, 0));
    vector<vector<int>> dp_r(len_s+1, vector<int>(len_t+1, 0));

    // dp_l[i][j]
    for (int i = 0; i < len_s; i++) {
        for (int j = 0; j < len_t; j++) {
            dp_l[i + 1][j + 1] = s[i] == t[j] ? (dp_l[i][j] + 1) : 0;
        }
    }
    // dp_r[i][j] 
    for (int i = len_s - 1; i >= 0; i--) {
        for (int j = len_t - 1; j >= 0; j--) {
            dp_r[i][j] = s[i] == t[j] ? (dp_r[i + 1][j + 1] + 1) : 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < len_s; i++) {
        for (int j = 0; j < len_t; j++) {
            if (s[i] != t[j]) {
                ans += (dp_l[i][j] + 1) * (dp_r[i + 1][j + 1] + 1);
            }
        }
    }
    
    return ans;
}

int main(){
    string s = "abe";
    string t = "bbc";
    int ans = countSubstrings(s, t);
    cout << ans;
}