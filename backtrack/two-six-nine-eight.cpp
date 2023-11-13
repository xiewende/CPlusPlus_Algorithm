// 2698. 求一个整数的惩罚数

#include<iostream>
#include<vector>

using namespace std;


bool isOK(int n, string s, int idx){
    if(idx==s.length() && n==0 ){
        return true;
    }
    if(idx==s.length()){
        return false;
    }

    for (int i = 1; idx + i <= s.length();i++)
    {
        int curr = atoi(s.substr(idx, i).c_str());
        if(n-curr < 0){
            continue;
        }
        n = n - curr;
        // dfs
        bool ans = isOK(n, s, i+idx);
        if(ans){
            return true;
        }
        n = n + curr;
    }

    return false;
}


int punishmentNumber(int n) {

    int ans = 0;

    for (int i = 1; i <= n;i++)
    {
        
        if(isOK(i, to_string(i*i), 0)){
            ans += i * i;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 37;
    // bool is = isOK(n, to_string(n*n), 0);
    // cout << is;
    int ans = punishmentNumber(n);
    cout << ans;
    return 0;
}
