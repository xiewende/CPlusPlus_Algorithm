// 1253. 重构 2 行二进制矩阵

// 贪心：逐个遍历colSum  若是2，两行都得设置为1，此时 upper--；lower--；
//                      若是1，判断upper和lower的大小，谁大就放到哪一行同时改行的和upeer或者lower需要减少1，
//                      若是0跳过即可
// 返回，需要 第一行和upper和第二行和lower同时为0，否则返回{}即可

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int n = colsum.size();
    vector<vector<int>> ans(2, vector<int>(n, 0));

    // 分两次遍历
    // // 先把和为2的遍历完
    // for (int i = 0; i < n; i++)
    // {
    //     if(colsum[i] == 2){
    //         upper--;
    //         lower--;
    //         ans[0][i] = 1;
    //         ans[1][i] = 1;
    //     }
    //     if(upper<0 || lower<0){
    //         return {};
    //     }
    // }
    // // 再遍历1
    // for (int i = 0; i < n; i++)
    // {
    //     if(colsum[i] == 1){
    //         if(upper>0){
    //             upper--;
    //             ans[0][i] = 1;
    //         }else
    //         {
    //             lower--;
    //             ans[1][i] = 1;
    //         }
    //     }else{
    //         continue;
    //     }
    //     if(upper<0 || lower<0){
    //         return {};
    //     }
    // }

    // 统一遍历
    for (int i = 0; i < n; i++)
    {
        if(colsum[i] == 1){
            if(upper>lower){
                upper--;
                ans[0][i] = 1;
            }else
            {
                lower--;
                ans[1][i] = 1;
            }
        }else if(colsum[i] == 2){
            upper--;
            lower--;
            ans[0][i] = 1;
            ans[1][i] = 1;
        }else
        {
            continue;
        }
        if(upper<0 || lower<0){
            return {};
        }
    }

    if(upper==0 && lower==0){
        return ans;
    }
    return {};
}

int main(int argc, char const *argv[])
{
    int upper = 4;
    int lower = 7;
    vector<int> colSum = {2,1,2,2,1,1,1};
    vector<vector<int>> ans = reconstructMatrix(upper, lower, colSum);
    for(auto currs:ans){
        for(auto curr:currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
