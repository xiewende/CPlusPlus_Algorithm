// 面试题 01.05. 一次编辑

#include<iostream>
#include<string>

using namespace std;

bool oneEditAway(string first, string second) {
    int len1 = first.length();
    int len2 = second.length();
    if(len1-len2>1 || len2-len1>1){
        return false;
    }
    int count = 0;
    int index_large = 0;
    int index_small = 0;

    if(len1 == len2){
        int index = 0;
        while(index<len1){
            if(first[index] != second[index]){
                count++;
            }
            index++;
        }
    }else
    {
        if(len2>len1){
            string tem = second;
            second = first;
            first = tem;

            // len1 = max(len1, len2);
            // len2 = min(len1, len2);
            int tem1 = len2;
            len2 = len1;
            len1 = tem1;
        }
        while (index_large < len1)
        {
            if(first[index_large] != second[index_small]){
                index_large++;
            }else{
                index_large++;
                index_small++;
                
            }
        }
    }
    return (len1 == len2 && count < 2) || (len1 != len2 && index_large == len1 && index_small==len2);
}

int main(){
    string first = "a";
    string second = "ab";
    bool ans = oneEditAway(first, second);
    cout << ans;
    return 0;
}