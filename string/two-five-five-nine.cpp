// 2559. 统计范围内的元音字符串数

// 解题思路：前缀和查找

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

bool check(string s, unordered_set<char>& yuan){
    int idx = s.length() - 1;
    return yuan.count(s[0]) && yuan.count(s[idx]);
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    unordered_set<char> yuan;
    yuan.emplace('a');
    yuan.emplace('e');
    yuan.emplace('i');
    yuan.emplace('o');
    yuan.emplace('u');

    int len1 = words.size();
    vector<int> words_int(len1, 0);
    for (int i = 0; i < len1;i++)
    {
        if(check(words[i], yuan)){
            words_int[i] = 1;
        }
    }
    vector<int> words_int_sum(len1+1, 0);
    words_int_sum[1] = words_int[0];
    for (int i = 1; i < len1;i++)
    {
        words_int_sum[i+1] = words_int_sum[i] + words_int[i];
    }

    int len2 = queries.size();
    vector<int> ans(len2, 0);
    for (int i = 0; i < len2;i++)
    {
        ans[i] = words_int_sum[queries[i][1]+1] - words_int_sum[queries[i][0]];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> ans = vowelStrings(words, queries);
    for(auto curr : ans){
        cout << curr <<" ";
    }
    return 0;
}
