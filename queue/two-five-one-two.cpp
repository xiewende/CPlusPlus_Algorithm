// 2512. 奖励最顶尖的 K 名学生

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

static bool cmp(pair<int,int> a, pair<int, int> b){
    // return a.second > b.second;
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

    unordered_set<string> seenP(positive_feedback.begin(), positive_feedback.end());
    unordered_set<string> seenN(negative_feedback.begin(), negative_feedback.end());

    priority_queue<pair<int,int> , vector<pair<int,int>>, decltype(&cmp)> que(cmp);

    // int n =
    for (int i = 0; i < student_id.size();i++)
    {
        string str = report[i];
        int score = 0;
        // string s = "";
        int p = 0;
        for (int q = 0; q < str.size(); q++) {
            p = q;
            while (str[p] != ' ' && p < str.size()) {
                p++;
            }
            string temp = str.substr(q, p - q);
            // vec.push_back(stoi(tmp));
            if(seenP.count(temp)>0){
                score += 3;
            }
            if(seenN.count(temp)>0){
                score -= 1;
            }
            q = p;
        }
        que.push({score, student_id[i]});
    }

    vector<int> ans(k);
    int idx = 0;
    while(k--){
        auto curr = que.top();
        que.pop();
        ans[idx++] = curr.second;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
