// 1105. 填充书架

// 动态规划

// dp[i]: 表示前 i 本书的所用的最小高度

// 放置第 i 本书的时候，假定前j本书放在书架上了，其中 j<i; 前j本书放好后，剩余的 【j,j+1，...,i】这几本书放在最后一层，这层书的最高就是这层书架的高度，由此得到状态转移方程

// dp[i] = min(dp[j-1], max(Height)) : 遍历 j Height为【j，j+1，。。，i】的最大高度 ，其中 0<j<=i;

#include<iostream>
#include<vector>

using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int len = books.size();
    vector<int> dp(len+1, 0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 1; i <= len; i++)
    {
        int max_height = 0;
        int curr_width = 0;
        for (int j = i; j > 0; j--)
        {   
            curr_width += books[j-1][0];
            if(curr_width > shelfWidth){
                break;
            }
            max_height = max(max_height, books[j-1][1]);
            dp[i] = min(dp[i], dp[j-1] + max_height);
        }
    }
    return dp[len];
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};  //   {7,3},{8,7},{2,7},{2,5}
    int shelfWidth = 4;
    int ans = minHeightShelves(books, shelfWidth);
    cout << ans;
    return 0;
}
