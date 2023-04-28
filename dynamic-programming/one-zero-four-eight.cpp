// 1048. 最长字符串链

// 参照最长递增子数组的解法问题

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

static int cmp(string a, string b){
    return a.length() < b.length();
}

bool check(string second, string first){
    int i = 0;
    int j = 0;
    int diff = 0;
    while(i<second.length() && j<first.length()){
        if(second[i] == first[j]){
            i++;
            j++;
        }else{
            diff++;
            i++;
        }
    }
    return diff == 1 || (diff==0 && i == second.length()-1);
}

int longestStrChain(vector<string>& words) {
    // 按照长度排序
    sort(words.begin(), words.end(), cmp);
    int len = words.size();
    vector<int> dp(len, 1);
    int ans = 1;
    for (int i = 1; i < len;i++)
    {
        int curr = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if(words[j].length() < words[i].length()-1){
                break;
            }
            if(words[j].length() == words[i].length()){
                continue;
            }
            if(check(words[i], words[j])){
                curr = max(curr, dp[j]+1);
            }
        }
        dp[i] = curr;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"a","b","ab","bac"};
    int ans = longestStrChain(words);
    cout << ans;
    return 0;
}
