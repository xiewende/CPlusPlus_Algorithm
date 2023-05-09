// 1419. 数青蛙

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
    // 预处理每个字母在 "croak" 中的上一个字母
    char PREVIOUS['s']; // 's' 保证 "croak" 中的任意字符都不会越界
    const string croak = "croakc";
    for (int i = 1; i < croak.length(); i++)
        PREVIOUS[croak[i]] = croak[i - 1];

    int cnt['s']{};
    for (char ch: croakOfFrogs) {
        char pre = PREVIOUS[ch]; // pre 为 ch 在 "croak" 中的上一个字母
        if (cnt[pre]) // 如果有青蛙发出了 pre 的声音
            cnt[pre]--; // 复用一只
        else if (ch != 'c') // 否则青蛙必须从 'c' 开始蛙鸣
            return -1; // 不符合要求
        cnt[ch]++; // 发出了 ch 的声音
    }
    if (cnt['c'] || cnt['r'] || cnt['o'] || cnt['a'])
        return -1; // 有发出其它声音的青蛙，不符合要求
    return cnt['k']; // 最后青蛙们都发出了 'k' 的声音
}

int minNumberOfFrogs(string croakOfFrogs) {
    if (croakOfFrogs.size() % 5 != 0) {
        return -1;
    }
    int res = 0, frogNum = 0;
    vector<int> cnt(4);
    unordered_map<char, int> mp = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
    for (char c : croakOfFrogs) {
        int t = mp[c];
        if (t == 0) {
            cnt[t]++;
            frogNum++;
            if (frogNum > res) {
                res = frogNum;
            }
        } else {
            if (cnt[t - 1] == 0) {
                return -1;
            }
            cnt[t - 1]--;
            if (t == 4) {
                frogNum--;
            } else {
                cnt[t]++;
            }
        }
    }
    if (frogNum > 0) {
        return -1;
    }
    return res;
}


int main(int argc, char const *argv[])
{

    string s = "croakcroak";
    int ans = minNumberOfFrogs(s);
    cout << ans;
    return 0;
}


