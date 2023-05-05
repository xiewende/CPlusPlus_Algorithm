// 1003. 检查替换后的词是否有效

#include<iostream>
#include<string>

using namespace std;

// 硬算
bool isValid(string s) {

    int idx = 0;

    while(s.length() > 3 && idx < s.length()){
        string curr = s.substr(idx, 3);
        if(curr == "abc"){
            s = s.substr(0, idx) + s.substr(idx + 3);
            idx = -1;
        }
        idx++;
    }

    return s == "abc";
}

// 栈
bool isValid(string s) {
    string stk;
    for (auto c : s) {
        stk.push_back(c);
        if (stk.size() >= 3 && stk.substr(stk.size() - 3, 3) == "abc") {
            stk.erase(stk.end() - 3, stk.end());
        }
    }
    return stk.empty();
}


int main(int argc, char const *argv[])
{
    /* code */
    string s = "aabcbc";
    bool ans = isValid(s);
    cout << ans;
    return 0;
}
