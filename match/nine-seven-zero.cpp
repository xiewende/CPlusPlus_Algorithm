// 970. 强整数

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound) {
    set<int> x_visited;
    set<int> y_visited;
    for (int i = 0;; i++)
    {
        int curr_x = pow(x, i);
        if(curr_x > bound){
            break;
        }
        if(x_visited.count(curr_x)){
            break;
        }
        x_visited.emplace(curr_x);
    }

    for (int i = 0;; i++)
    {
        int curr_y = pow(y, i);
        if(curr_y > bound){
            break;
        }
        if(y_visited.count(curr_y)){
            break;
        }
        y_visited.emplace(curr_y);
    }

    unordered_set<int> ans;
    // for (int i = 2; i <= bound; i++)
    // {
    //     for (int j = 1; j < i;j++)
    //     {
    //         if(x_visited.count(j)>0 && y_visited.count(i-j)){
    //             ans.emplace_back(i);
    //             break;
    //         }
    //     }
    // }
    for (auto iter_x = x_visited.begin(); iter_x != x_visited.end(); iter_x++){

        for (auto iter_y = y_visited.begin(); iter_y != y_visited.end(); iter_y++){
            int value = *iter_x + *iter_y;
            if(value<=bound){
                ans.emplace(value);
            }else{
                break;
            }
        }
    }

    return vector<int>(ans.begin(), ans.end());
}



int main(int argc, char const *argv[])
{
    /* code */
    int x = 2;
    int y = 3;
    int bound = 10;
    vector<int> ans = powerfulIntegers(x, y, bound);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}
