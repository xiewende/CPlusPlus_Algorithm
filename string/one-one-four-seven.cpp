// 1147. 段式回文

// 解题思路：贪心策略
// 前后缀遍历，遇到相同即分割，就是最大的分割数目

#include<iostream>
#include<string>

using namespace std;

// 递归实现
int longestDecomposition(string text) {
    if (text.empty())
    {
        return 0;
    }
    int len = text.length();
    for (int i = 1; i <= len / 2; i++)
    {
        if(text.substr(0, i) == text.substr(len-i)){
            return 2 + longestDecomposition(text.substr(i, len - 2 * i));
        }
    }
    return 1;
}

// 迭代实现
int longestDecomposition1(string text) {
    int ans = 0;
    while(!text.empty()){
        int i = 1;
        int n = text.length();
        while(i<=n/2 && text.substr(0,i) != text.substr(n-i)){
            i++;
        }
        // 单个字符串不可以切割的时候
        if(i > n/2){
            ans++;
            break;
        }
        ans += 2; // 分割出来 text[:i] text[n-i:]
        text = text.substr(i, n - 2 * i);
    }
    return ans;
}


int main(){
    string text = "abcd";
    int ans = longestDecomposition1(text);
    cout << ans;
    return 0;
}

