// 1921. 消灭怪物的最大数量

// 贪心算法：先消灭距离最近的怪兽就可以最大值

// 1、先计算出每个距离的怪兽到达城市的时间，方便计算向上取整，得到到达数组 times[i]
// 2、对times进行排序
// 3、遍历时间，判断在每分钟的时间消灭的怪兽，若某分钟大于该怪兽达到的时间，则游戏失败
// 4、遍历完则完成。返回n

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();

    // 构建每个怪兽的到达时间
    vector<int> times(n);
    for (int i = 0; i < n;i++)
    {
        times[i] = (dist[i] - 1) / speed[i] + 1;
    }
    // 进行排序
    sort(times.begin(), times.end());
    // 进行判断
    for (int i = 0; i < n;i++)
    {
        // 到达某时间，若此时大于怪兽到达时间，则说明该时间下怪兽到达成熟了，游戏结束
        if( i>= times[i]){
            return i;
        }
    }
    // 全部可以消化
    return n;
}

int main(int argc, char const *argv[])
{
    vector<int> dist = {1,1,2,3};
    vector<int> speed = {1,1,1,1};
    int ans = eliminateMaximum(dist, speed);
    cout << ans;
    return 0;
}
