// 剑指 Offer II 020. 回文子字符串的个数

#include<iostream>
#include<string>

using namespace std;

bool check(string s, int left, int right){
    while(left<=right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int countSubstrings(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len;j++)
        {
            if(check(s, i, j)){
                ans++;
            }
        }
    }
    return ans + len;
}

int main(int argc, char const *argv[])
{
    string s = "aaa";
    int ans = countSubstrings(s);
    cout << ans;
    return 0;
}
