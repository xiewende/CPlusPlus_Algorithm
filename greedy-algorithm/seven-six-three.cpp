// 763. 划分字母区间

#include<iostream>
#include<vector>
#include<string>

using namespace std;


// 方法：
// 先记录每个字符最后出现的下标
// 定义 start，end为某个片段的开始和结束，初始为0
// 遍历字符串，遍历得到c时，计算 c最后出现的坐标和当前最远坐标的最大值，end = max(end, lastIdx[c])
// 若遍历到的下标i等于end的时候，说明这个片段就是最佳的，应该重新启动另外一个片段

vector<int> partitionLabels(string s) {
    int n = s.length();
    // 记录每个字母的最后出现的位置
    vector<int> lastIdx(26);
    for (int i = 0; i < n; i++)
    {
        lastIdx[s[i] - 'a'] = i;
    }
    // 每个片段的起点和结束点
    int start = 0;
    int end = 0;
    // 答案
    vector<int> ans;
    // 开始遍历
    for (int i = 0; i < n; i++)
    {
        // 计算end，每次更新改片段内的所有字母的最遥远的坐标
        end = max(end, lastIdx[s[i]-'a']);
        // 一个片段结束，当遍历到该最遥远的坐标时，一个片段结束
        if(i == end){
            ans.push_back(end-start+1);
            start = i + 1;
            end = start;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s = "eccbbbbdec";
    vector<int> ans = partitionLabels(s);
    for(auto tem : ans){
        cout << tem << " ";
    }
    return 0;
}
