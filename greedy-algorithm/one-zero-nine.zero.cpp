// 1090. 受标签影响的最大值

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

// 超出时间控制
void dfs(vector<pair<int, int>> &values_labels, int count, int numWanted, int &ans, int curr_sum, int useLimit, unordered_map<int,int> visited, vector<bool>& visited11){
    ans = max(ans, curr_sum);

    for (int i = 0; i < values_labels.size();i++)
    {
        if(visited11[i] || visited[values_labels[i].second] >= useLimit || count >= numWanted){
            continue;
        }
        // 增加这个数字
        curr_sum += values_labels[i].first;
        visited[values_labels[i].second]++;
        visited11[i] = true;
        count++;
        // 递归
        dfs(values_labels, count, numWanted, ans, curr_sum, useLimit, visited, visited11);
        // 状态恢复
        curr_sum -= values_labels[i].first;
        visited[values_labels[i].second]--;
        visited11[i] = false;
        count--;
    }
    return;
}

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
    int len = values.size();

    // 构造 values[i]和labels[i]的对应关系，并且按照从小到大排序
    vector<pair<int, int>> values_labels;
    for (int i = 0; i < len; i++)
    {
        values_labels.push_back({values[i], labels[i]});
    }
    sort(values_labels.begin(), values_labels.end(), cmp);
    // 记录labels[i]出现的次数
    unordered_map<int, int> visited;

    // 递归找值，超出时间限制
    // vector<bool> visited11(len, false);
    // int curr_sum = 0;
    // int ans = 0;
    // dfs(values_labels,0, numWanted, ans, curr_sum, useLimit, visited, visited11);

    // 贪心算法
    // 要使得最后的值越大，那么每次取得值越左越大的好，
    // 所以从左开始遍历数组，每次判断 values[i] 是否可取
    // 若可取，肯定就是最大的组成
    // 若不可取，则跳过
    int ans = 0;
    int count = 0;
    for (int i = 0; i < len; i++)
    {   
        // 选取数字个数达到个数，既可以退出
        if(count >= numWanted){
            break;
        }
        // 若某个values值对应的 label 重复次数过多，则跳过
        if(visited[values_labels[i].second] >= useLimit){
            continue;
        }
        // 直接要某个值
        ans += values_labels[i].first;
        visited[values_labels[i].second]++;
        count++;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> values = {9,8,8,7,6};
    vector<int> labels = {0,0,0,1,1};
    int numWanted = 3;
    int useLimit = 1;
    int ans = largestValsFromLabels(values, labels, numWanted, useLimit);
    cout << ans;
    return 0;
}
