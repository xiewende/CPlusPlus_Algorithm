// 1488. 避免洪水泛滥

// 贪心+二分查找

// 1、若某湖只有一天下雨，则答案为-1；
// 2、若某湖多次下雨，我们则需要找到该湖前一次的那天到今天下雨的时候，中间是否有出现天晴抽水的一天
// 所以重点就是找到某湖两次下雨之间的某一个天晴的天即可，这里采用贪心，只需要找到最靠近前一次下雨的天晴天来抽就可以，这里采用二分查找，
// 若找到中间有天晴天，那就设置该天晴天抽数该湖，没有找到说明该湖两次下雨的中间没有天晴天来抽水，直接返回即可。
// 数据存储，
// 哈希表（unordered_map） seen ，key：湖，value：该湖上一次下雨的天
// 集合（set）zeros，代表是天晴的天，这个是有序的，二分查找就是在这里进行


#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();

    vector<int> ans(n, 1);  // 多余的晴天都设置为1，默认抽1号湖

    set<int> zero;  // 没有下雨的天，记录的是哪天
    unordered_map<int, int> seen; // key:哪个湖泊，value：该湖泊的上一个下雨天

    for (int i = 0; i < n; i++)
    {
        /* code */
        int lake = rains[i];

        // 如果是0
        if(lake == 0){
            zero.emplace(i); //
            continue;
        }

        // 找lake前一次下雨的天，有的话，则在判断中间是否有天晴天来抽水
        if(seen.count(lake)>0){
            auto it = zero.upper_bound(seen[lake]); // 找到在该湖下雨的中间是否有天晴天，且是最靠近该湖上一次下雨的天
            if(it==zero.end()){ // 该湖泊上一次下雨的距离今天下雨中间没有晴天，直接返回
                return {};
            }
            // 找到了
            ans[*it] = lake; // 该天晴天设置抽该湖的水
            zero.erase(*it); // 该天用了需要益处
        //
        }
        // 没有
        // 记录该湖的下雨天       
        seen[lake] = i;
        ans[i] = -1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> rains = {2,0,0,0,2};
    vector<int> ans = avoidFlood(rains);
    for(auto tem : ans){
        cout << tem << " ";
    }
    return 0;
}
