// 剑指 Offer II 034. 外星语言是否排序

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;


bool check(string left, string right, unordered_map<char, int> orderd){
    int i_left = 0;
    int i_right = 0;
    while(i_left<left.length() && i_right<right.length()){
        if(left[i_left] == right[i_right]){
            i_left++;
            i_right++;
        }else{
            if(orderd[left[i_left]]<orderd[right[i_right]]){
                return true;
            }else{
                return false;
            }
        }
    }

    return true;
}

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> orderd;
    char tag = '.'; //随便一个标记符号使之最小
    orderd[tag] = 0;
    for (int i = 0; i < order.length();i++)
    {
        orderd[order[i]] = i + 1;
    }
    for (int i = 0; i < words.size() - 1;i++)
    {
        if(!check(words[i]+tag, words[i+1]+tag, orderd)){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    bool ans = isAlienSorted(words, order);
    cout << ans;
    return 0;
}
