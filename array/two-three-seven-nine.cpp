// 2379: 得到 K 个黑块的最少涂色次数

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int minimumRecolors(string blocks, int k) {

    int ans = k;
    int count = 0; // 黑色的连续个数 
    for (int i = 0; i < k; i++)
    {
      if(blocks[i] == 'W'){
          count = count + 1;
      }
    }
    ans = min(ans, count);
    int left = 1;
    int right = left + k - 1; //区间都是左闭右开
    while(right < blocks.length()){
       count = blocks[left - 1] == 'W' ? count - 1 : count;
       count = blocks[right] == 'W' ? count + 1 : count;
       ans = min(ans, count);
       left++;
       right++;
    }
    return ans;
}


int main(){
    string blocks = "W";
    int k = 1;
    cout << blocks << endl;
    int ans = minimumRecolors(blocks, k);
    cout << ans << endl;
    return 0;
}