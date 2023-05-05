// 剑指 Offer II 019. 最多删除一个字符得到回文

#include<iostream>
#include<string>

using namespace std;

bool checkPalindrome(const string& s, int low, int high) {
    while(low <= high){
        if(s[low] != s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}


bool validPalindrome(string s) {
    int left = 0;
    int right = s.length()-1;
    int diff = 0;
    while(left<=right){
        if(s[left] != s[right]){
            return checkPalindrome(s, left, right - 1) || checkPalindrome(s, left + 1, right);
        }else{
            left++;
            right--;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{

    string s = "abc";
    bool ans = validPalindrome(s);
    cout << ans;
    return 0;
}
