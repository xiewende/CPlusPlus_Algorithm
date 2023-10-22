// 187. 重复的DNA序列

// 字符串+哈希 的使用

#include<iostream>
#include<vector>
#include<unordered_map>
#include<vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    int n = s.length();
    int l = 10;

    unordered_map<string, int> seen;
    vector<string> ans;

    for (int i = 0; i <= n - l;i++)
    {
        string sub = s.substr(i, l);
        seen[sub]++;
        if(seen[sub] == 2){ // 避免重复计算，大于一次的计算一次即可，
            ans.push_back(sub);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    // return 0;

    string s = "AAAAAAAAAAA";
    vector<string> ans = findRepeatedDnaSequences(s);
    for(string a:ans){
        cout << a << " ";
    }

    return 0;
}
