// LCP 33. 蓄水

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int storeWater(vector<int>& bucket, vector<int>& vat) {
    int len = bucket.size();
    int max_vat = *max_element(vat.begin(), vat.end());

    if (max_vat == 0) {
        return 0;
    }
    int ans = INT_MAX;
    // 遍历灌水的次数为 k，
    // 判断灌水次数为 k 的时候，遍历每个水桶大小，来判断每个水桶需要升级 t 次来满足倒 K 次能够满足 水缸的容量，每个水桶的升级次数和为T
    // 灌水 k次的时候，需要升级的全部 T 次，k+T 就是全部次数
    // 遍历取最小即可；
    for (int k = 1; k < max_vat, k < ans; k++)
    {
        int t = 0;
        for (int i = 0; i < bucket.size(); i++)
        {   
            //向上取整的值
            int zhi = vat[i] % k == 0 ? vat[i] / k : vat[i] / k + 1;
            t += max(0, zhi-bucket[i]);
        }
        ans = min(ans, k + t);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> bucket = {9,0,1};
    vector<int> vat = {0,2,2};
    int ans = storeWater(bucket, vat);
    cout << ans;
    return 0;
}
