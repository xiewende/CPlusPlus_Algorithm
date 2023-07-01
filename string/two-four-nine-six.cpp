// 2496. 数组中字符串的最大值

#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool check(string s){
    for(char tem : s){
        if(tem < '0' || tem >'9'){
            return false;
        }
    }
    // 只包括数字
    return true;
}

int maximumValue(vector<string>& strs) {
    int n = strs.size();
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        string str = strs[i];
        bool b = check(str);
        if(b){
            ans = max(ans, stoi(str));
        }else{
            int len = str.length();
            ans = max(ans, len);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> strs = {"alic3","bob","3","4","00000"};
    int ans = maximumValue(strs);
    cout << ans;
    return 0;
}
