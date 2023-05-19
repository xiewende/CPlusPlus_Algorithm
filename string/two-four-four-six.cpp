//2446. 判断两个事件是否存在冲突

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool haveConflict(vector<string>& event1, vector<string>& event2) {

    int startHour_1 = stoi(event1[0].substr(0, 2));
    int startMin_1 = stoi(event1[0].substr(3));
    int endHour_1 = stoi(event1[1].substr(0, 2));
    int endMin_1 = stoi(event1[1].substr(3));

    int start_1 = startHour_1 * 60 + startMin_1;
    int end_1 = endHour_1 * 60 + endMin_1;

    int startHour_2 = stoi(event2[0].substr(0, 2));
    int startMin_2 = stoi(event2[0].substr(3));
    int endHour_2 = stoi(event2[1].substr(0, 2));
    int endMin_2 = stoi(event2[1].substr(3));

    int start_2 = startHour_2 * 60 + startMin_2;
    int end_2 = endHour_2 * 60 + endMin_2;

    if((start_1 < start_2 && start_2 <= end_1) ||  (start_2<start_1 && start_1 <= end_2)){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char const *argv[])
{
    vector<string> event1 = {"01:15", "02:00"};
    vector<string> event2 = {"02:00", "03:00"};
    bool ans = haveConflict(event1, event2);
    cout << ans;
    return 0;
}
