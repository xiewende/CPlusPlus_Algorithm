// 1616. 分割两个字符串得到回文串

#include<iostream>
#include<string>

using namespace std;

// 判断某个字符串是否是回文串
bool checkSelfPalindrome(string a, int left, int right){
    while(left < right && a[left] == a[right]){
        left++;
        right--;
    }
    return left >= right;
}

// 判断 a_前 + b_后 是不是回文串
bool checkConcatenation(string a, string b){
    int length = a.length();

    // left 指针从字符串 a 的左边往右边遍历
    int left = 0; 
    // right 指针从字符串 b 的右边往左边遍历
    int right = length - 1;
    while(left < right && a[left] == b[right]){
        left++;
        right--;
    }
    
    // 到中间都是相等，肯定是回文
    // 若 指针left 和 right能够相遇，则遍历的两个子字符串组合起来就是 回文串
    if(left >= right){
        return true;
    }

    // 若指针 left 和 right 没有相遇，则要判断字符串 a b的中间段字符串是不是回文串
    // 在两个指针遍历后，两边是相等，a 的左边 和 b 的右边 是属于回文的
    // 接下来判断 是需要在 left 指针截断 还是 right 指针截断
    // 接下来判断中间那段是不是回文，
    // 若中间是回文。那整段也就是回文
    // 中间那段：
    // left 指针断开的话就是判断 b 的中间段是不是回文串
    // right 指针断开的话就是判断 a 的中间段是不是回文串
    return checkSelfPalindrome(a, left, right) || checkSelfPalindrome(b, left, right);
}

bool checkPalindromeFormation1(string a, string b) {
    return checkConcatenation(a, b) || checkConcatenation(b, a);
}


// 错误解答，理解不够透彻
bool checkPalindromeFormation(string a, string b) {

    int length = a.length();
    if(length == 1){
        return true;
    }
    bool ans = false;

    int left0 = 0;
    int right0 = length - 1;
    while (left0 < right0)
    {
        if(a[left0] == b[right0]){

            if(left0 == right0 -1 || left0 == right0){
                ans = true;
            }
            left0++;
            right0--;
        }else{
            break;
        }
    }
    int left1 = 0;
    int right1 = length - 1;
    while (left1 < right1)
    {
        if(b[left1] == a[right1]){
            if(left1 == right1 -1 || left1 == right1){
                ans = true;
            }
            left1++;
            right1--;
        }else{
            break;
        } 
    }
    return ans;
}

int main(){
    string a = "fecab"; // m=1
    string b = "abdef";  
    bool ans = checkPalindromeFormation1(a, b);
    cout << ans;
}