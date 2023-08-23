// 131. 分割回文串

// 经典回溯法

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isHUI(string s){
    int len = s.length() - 1;
    int i = 0;
    while(i<len){
        if(s[i] != s[len]){
            return false;
        }
        i++;
        len--;
    }
    return true;
}

void backtrack(vector<vector<string>>& ans, vector<string>& curr, string s, int begin, int len) {
    // 若总长度==s的长度，说明切割完成，添加到答案
    if(len == s.length()){
        ans.push_back(curr);
        return;
    }

    for (int i = begin+1; i <= s.length(); i++)
    {   
        // 先提取不一样长度的字串，
        string str = s.substr(begin, i - begin);
        // 若该字串不是回文则跳过
        if(!isHUI(str)){
            continue;
        }
        // 字串是回文
        curr.push_back(str); // 添加到答案
        len += str.length();  // 总长度+1
        backtrack(ans, curr, s, i, len);  // 回溯
        // 状态恢复
        len -= str.length(); 
        curr.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> curr;
    backtrack(ans, curr, s, 0, 0);
    return ans;
}

int main(int argc, char const *argv[])
{

    string s = "a";
    vector<vector<string>> ans = partition(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
