// 1044. 最长重复子串

// 长度是肯定知道的 在[0,n]区间中，故可以利用二分查找的方法
// 利用字符串哈希来减少查找时间

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int check(string s, int l){
    int n = s.length();
    unordered_map<string, int> seen;
    for (int i = 0; i <= n - l; i++)
    {
        string sub = s.substr(i, l);
        seen[sub]++;
        if(seen[sub]>1){
            return i;
        }
    }
    return -1;
}
// 二分+字符串哈希表
string longestDupSubstring(string s) {
    int n = s.length();

    int left = 1;
    int right = n - 1;
    string ans = "";
    while(left <= right){
        int mid = (left + right) / 2;

        int idx = check(s, mid);

        if(idx>0){
            left = mid + 1;
            ans = s.substr(idx, mid);
        }else{
            right = mid - 1;
        }
    }
    return ans;
}

int check1(int l, int n, vector<unsigned long long>& h, vector<unsigned long long>& p){
    // unordered_map<long long, int> seen;
    unordered_set<long long> seen;
    for (int i = 1; i+l-1 <= n; i++)
    {
        // string sub = s.substr(i, l);
        int j = i + l - 1; //

        long long ha = h[j] - h[i-1] * p[j-i+1];

        if(seen.count(ha)>0){
            return i-1;
        }
        seen.emplace(ha);
    }
    return -1;
}

// 二分+字符串哈希，快速找到某个字符串对应的哈希值
string longestDupSubstring1(string s) {
    int n = s.length();

    int P = 131313;
    vector<unsigned long long> h(n + 10);
    vector<unsigned long long> p(n + 10);
    p[0] = 1;

    // 计算每个字符串的前缀和哈希
    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i] * P; // 通过P的i次幂；
        h[i + 1] = h[i] * P + s[i]; // 直接公式累加
    }

    int left = 1;
    int right = n - 1;
    string ans = "";
    while(left <= right){
        int mid = (left + right) / 2;

        int idx = check1(mid, n, h, p);

        if(idx>0){
            left = mid + 1;
            ans = s.substr(idx, mid);
        }else{
            right = mid - 1;
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    string s = "aa";
    string as = longestDupSubstring1(s);
    cout << as;
    return 0;
}
