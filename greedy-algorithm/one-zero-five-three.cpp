// 1053. 交换一次的先前排列

// 解题思路
// 记数组 arr 的长度为 n，对于 0≤i<j<n 如果交换 arr[i] 和 arr[j] 后得到的新数组按字典序排列比原数组小，显然有 arr[i]>arr[j]成立
// 因此符合题意要求的交换会使得数组 arr 在下标 iii 处的元素变小。那么为了得到按字典序排列小于原数组的最大新数组，尽可能地保持前面的元素不变是最优的，即让 i 最大化。

// 先从右到左遍历数组，找到第一个满足 arr[i−1]>arr[i] 的下标 i，此时 arr[i−1]就是我们要交换的数字，
// 我们再从右到左遍历数组，找到第一个满足 arr[j]<arr[i−1] 且 arr[j]≠arr[j−1]
// 的下标 j，此时我们交换 arr[i−1] 和 arr[j] 后返回即可

#include<iostream>
#include<vector>

using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        swap(arr[i - 1], arr[j]);
                        return arr;
                    }
                }
            }
        }
        return arr;
}

vector<int> prevPermOpt11(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
}

int main(){
    vector<int> arr(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = prevPermOpt1(arr);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}







