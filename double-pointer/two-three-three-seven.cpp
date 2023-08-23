// 2337. 移动片段得到字符串

// 解题思路：双指针，模拟

// 不能由 start 变成 target 一共有三种情况：
// 1、去掉 空格('_') 后，start 和 target 不等；相对位置要一致
// 2、start L 左侧空格数小于 target L 左侧空格数。例如：start=_L；target=__L
// 3、start R 右侧空格数小于 target R 右侧空格数。例如：start=R_；target=R__

#include<iostream>
#include<string>

using namespace std;

bool canChange(string start, string target) {
    int n = start.length();

    int i = 0; // start的下标
    int j = 0; // target的下标

    while(i<n && j<n){
        while (i<n && start[i]=='_')
        {
            i++;
        }
        while(j<n && target[j]=='_'){
            j++;
        }

        if(i<n && j<n){
            // 第一种情况
            if(start[i] != target[j]){
                return false;
            }
            // 第二和第三种情况
            char c = start[i];
            if((c == 'L' && i<j) || (c=='R' && i>j)){
                return false;
            }
            i++;
            j++;
        }
    }
    // 剩余的一定要确定都是 '_';
    while(i<n){
        if(start[i] != '_'){
            return false;
        }
        i++;
    }
    while(j<n){
        if(target[j] != '_'){
            return false;
        }
        j++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s1 = "_L__R__R_";
    string s2 = "L______RR";
    bool ans = canChange(s1, s2);
    cout << ans << endl;
    return 0;
}
