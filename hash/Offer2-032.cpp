// 剑指 Offer II 032. 有效的变位词

#include<iostream>
#include<vector>

using namespace std;

bool isAnagram(string s, string t) {
    vector<int> a(26, 0);
    vector<int> b(26, 0);
    for (int i = 0; i < s.length();i++)
    {
        a[s[i] - 'a']++;
    }
     for (int i = 0; i < t.length();i++)
    {
        b[t[i] - 'a']++;
    }

    for (int i = 0; i < 26;i++)
    {
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}