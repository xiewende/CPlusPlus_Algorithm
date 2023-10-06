// 647. 回文子串

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n;i++)
    {
        dp[i][i] = 1;
    }

    int ans = n;
    for (int i = n - 1; i >= 0;i--)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(s[i] == s[j]){
                if(j-i<=1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i + 1][j - 1];
                }
                ans += dp[i][j];
            }
        }
    }
    // return accumulate(dp.begin(), dp.end(), 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "aaaaa";
    int ans = countSubstrings(s);
    cout << ans;
    return 0;
}
