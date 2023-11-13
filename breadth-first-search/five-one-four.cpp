// 514. 自由之路

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int findRotateSteps(string ring, string key) {
    int n = ring.size();
    queue<int> q;
    q.push(0);
    int idx1 = 0;
    int ans = 0;
    int count = 1;
    vector<bool> visited(n);
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size;i++)
        {
            int idx = q.front();
            q.pop();
            if(ring[idx]==key[idx1]){
                visited[idx] = true;
                ans += count;
                idx1++;
                if(idx1==key.size()){
                    return ans;
                }
            }
            // 右
            if(!visited[(idx + 1) % n]){
                q.push((idx + 1) % n);
            }
            if(!visited[(idx - 1 + n) % n]){
                q.push((idx - 1 + n) % n);
            }
            
        }
        count++;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    /* code */
    string ring = "godding";
    string key = "godding";
    int ans = findRotateSteps(ring, key);
    cout << ans;
    return 0;
}
