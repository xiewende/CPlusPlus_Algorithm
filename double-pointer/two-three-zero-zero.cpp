// 2300. 咒语和药水的成功对数

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n = spells.size();
    int m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> ans;

    for (int i = 0; i < n;i++)
    {
        int tar = (success + spells[i] -1 ) / spells[i];        
        int len = potions.end() - lower_bound(potions.begin(), potions.end(), tar);
        ans.push_back(len);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> spells = {3,2,1};
    vector<int> pitions = {8,5,8};
    int success = 16;
    vector<int> ans = successfulPairs(spells, pitions, success);
    for(auto tem : ans){
        cout << tem << " ";
    }
    return 0;
}
