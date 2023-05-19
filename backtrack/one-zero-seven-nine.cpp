// 1079. 活字印刷

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

// 先排序再去重
void dfs(vector<char> &curr,int &ans, string tiles, vector<bool> &visited){
    ans++;
    for (int i = 0; i < tiles.length();i++)
    {   
        // 去重，用过的元素不要用，相同的采取，同一批次中，前一次首先选取了A，下一次是可以选A，得到AA，但是不可以在前一次中轮次中再选取下一个 A
        // AAB
        // i 次的循环中（AAB） 选 第一个A，i+1次循环中不可以选第一个A，但是可以选第二个A，得到 AA
        // 但是在回溯到 i 次的循环中（AAB），是不可以选取第二个A，这样就是和上面的重复，
        if(visited[i] || (i>0 && tiles[i]==tiles[i-1] && !visited[i-1])){ // 当前元素和前一个元素相同，并且 !visited[i-1]：前一个没有被选
            continue;
        }
        // 加入结果
        visited[i] = true;
        curr.emplace_back(tiles[i]);
        dfs(curr, ans, tiles, visited);
        // 从结果中剔除
        visited[i] = false;
        curr.pop_back();
    }
    return;
}
int numTilePossibilities(string tiles) {
    int ans = 0;
    int len = tiles.length();
    // 先排序
    sort(tiles.begin(), tiles.end());
    vector<bool> visited(len, false);
    vector<char> curr;
    dfs(curr,ans, tiles, visited);
    return ans-1;
}


// 计数+来去重
int dfs1(unordered_map<char, int>& count, set<char>& tile, int i) {
    if (i == 0) {
        return 1;
    }
    int res = 1;
    for (char t : tile) {
        if (count[t] > 0) {
            count[t]--;
            res += dfs1(count, tile, i - 1);
            count[t]++;
        }
    }
    return res;
}
int numTilePossibilities1(string tiles) {
    unordered_map<char, int> count;
    set<char> tile;
    int n = tiles.length();
    for (char c : tiles) {
        count[c]++;
        tile.insert(c);
    }
    return dfs1(count, tile, n) - 1;
}





int main(int argc, char const *argv[])
{
    string titles = "CDC";
    int ans = numTilePossibilities(titles);
    cout << ans;
    return 0;
}
