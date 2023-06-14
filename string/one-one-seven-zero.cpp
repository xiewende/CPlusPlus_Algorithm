// 1170. 比较字符串最小字母出现频次

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int f(string s){
    int len = s.length();
    vector<int> seen(26, 0);
    for (int i = 0; i < len; i++)
    {
        seen[s[i] - 'a']++;
    }

    for (int i = 0; i <26 ;i++)
    {
        if(seen[i]>0){
            return seen[i];
        }
    }
    return 0;
}

int check(vector<int>& word, int query){
    int ans = 0;
    for (int i = word.size() - 1; i >= 0; i--)
    {
        if(word[i]>query){
            ans += 1;
        }else{
            break;
        }
    }
    return ans;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    int len1 = queries.size();
    int len2 = words.size();

    vector<int> int_q(len1, 0);
    vector<int> int_w(len2, 0);

    for (int i = 0; i < len1; i++)
    {
        int curr = f(queries[i]);
        int_q[i] = curr;
    }

    for (int i = 0; i < len2; i++)
    {
        int curr = f(words[i]);
        int_w[i] = curr;
    }

    // sort(int_q.begin(), int_q.end());
    sort(int_w.begin(), int_w.end());

    vector<int> ans(len1, 0);
    // 没有二分
    // for (int i = 0; i < len1; i++)
    // {
    //     int curr = check(int_w, int_q[i]);
    //     ans[i] = curr;
    // }
    
    // 二分查找
    for (int i = 0; i < len1; i++) {
        int pos = upper_bound(int_w.begin(), int_w.end(), int_q[i]) - int_w.begin();
        ans[i] = max(0, len2 - pos);
    }
        

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> queries = {"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"};
    vector<string> words = {"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
    vector<int> ans = numSmallerByFrequency(queries, words);
    for(auto curr:ans){
        cout << curr << " ";
    }
    return 0;
}
