// 2511. 最多可以摧毁的敌人城堡数目

#include<iostream>
#include<vector>

using namespace std;

int captureForts(vector<int>& forts) {
    int n = forts.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        if(forts[i] != 1){
            continue;
        }

        //左移动
        int left = i - 1;
        // bool tag = false;
        while(left>=0 && forts[left] == 0){
            left--;
        }
        if(left>=0 && forts[left] == -1){
            ans = max(ans, i-left-1);
        }

        // 右移动
        int right = i + 1;
        // bool tag1 = false;
        while(right<n && right<n && forts[right] == 0){
            right++;
        }
        if(forts[right] == -1){
            ans = max(ans, right-i-1);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> forts = {0,0,1,-1};
    int ans = captureForts(forts);
    cout << ans;
    return 0;
}
