// 1023. 驼峰式匹配

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    int len1 = queries.size();
    vector<bool> ans(len1);
    for (int i = 0; i < len1;i++)
    {
        string curr = queries[i];
        bool curr_ans = true;
        int idx = 0;
        for(auto ch : curr){
            if (idx < pattern.length() && pattern[idx]==ch)
            {
                idx++;
            }else{
                if(isupper(ch)){
                    curr_ans = false;
                    break;
                }
            }
        }
        if(idx != pattern.length()){
                curr_ans = false;
        }
        ans[i] = curr_ans;
    }
    return ans;
}

int main(){
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FoBa";
    vector<bool> ans = camelMatch(queries, pattern);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}