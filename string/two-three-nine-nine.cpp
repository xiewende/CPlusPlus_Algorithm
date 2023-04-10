// 2399. 检查相同字母间的距离

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkDistances(string s, vector<int>& distance) {
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        char curr = s[i];
        for (int j = i + 1; j < length; j++)
        {
            if(s[j] == curr){
                int dis = j - i - 1;
                if(distance[curr-'a'] != dis){
                    return false;
                }
            }
        }
    }
    return true;
}