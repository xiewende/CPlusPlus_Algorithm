// 967. 连续差相同的数字

#include<iostream>
#include<vector>

using namespace std;

void bfs(vector<int>& ans, string curr, int n, int k, int idx){

    if(idx == n){
        ans.push_back(atoi(curr.c_str()));
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if(idx==0){
            if(i==0){
                continue;
            }
            curr += to_string(i);
            bfs(ans,curr, n, k, idx + 1);
            curr = curr.substr(0, curr.length() - 1);
        }else{
            if(abs(i-(curr[curr.length()-1]-'0')) != k){
                continue;
            }
            curr += to_string(i);
            bfs(ans, curr, n, k, idx+1);
            curr = curr.substr(0, curr.length() - 1);
        }
    }
    return;
}

vector<int> numsSameConsecDiff(int n, int k) {

    vector<int> ans;
    string s = "";
    bfs(ans, s, n, k, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 2;
    int k = 2;
    vector<int> ans = numsSameConsecDiff(n, k);
    for(auto cu : ans){
        cout << cu << " ";
    }
    return 0;
}
