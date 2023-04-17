// 2409. 统计共同度过的日子数

// 解题思路

// 分别计算四个天在一年中的第几天，
// 利用两个人离开的最小值 - 两个到达的最大值 + 1 就是共同度过的日子

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int countDays(string days, vector<int> &perMonthSum){
    int month = stoi(days.substr(0, 2));
    int date = stoi(days.substr(3));
    return perMonthSum[month-1] + date;
}

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    
    vector<int> perMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //每个月天数的前缀数组，方便统计在一年中的第几天
    vector<int> perMonthSum(1,0);
    for (int i = 0; i < perMonth.size();i++)
    {
        perMonthSum.emplace_back(perMonthSum.back() + perMonth[i]);
    }

    //得到在一年中的第几天
    int arriveAlice1 = countDays(arriveAlice, perMonthSum);
    int leaveAlice1 = countDays(leaveAlice, perMonthSum);
    int arriveBob1 = countDays(arriveBob, perMonthSum);
    int leaveBob1 = countDays(leaveBob, perMonthSum);

    // 最小的离开日子 - 最大的到达日子
    return max(0, min(leaveAlice1, leaveBob1) - max(arriveAlice1, arriveBob1) + 1);
}


int main(){
    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";
    int ans = countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
    // int ans = 1;
    cout << ans;
    return 0;
}


