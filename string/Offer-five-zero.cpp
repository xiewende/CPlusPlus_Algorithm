// 剑指 Offer 50. 第一个只出现一次的字符

#include<iostream>
#include<string>
#include<vector>

using namespace std;

char firstUniqChar(string s) {
    vector<int> visited(26, 0);
    for (int i = 0; i < s.length();i++)
    {
        visited[s[i] - 'a']++;
    }

    for (int i = 0; i < s.length();i++)
    {
        if(visited[s[i] - 'a'] == 1){
            return s[i];
        }
    }
    return ' ';
}

int main(){
    string s = "abaccdeff";
    char ans = firstUniqChar(s);
    cout << ans;
    return 0;
}