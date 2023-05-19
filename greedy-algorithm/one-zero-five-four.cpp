// 1054. 距离相等的条形码

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    //先排序,左到右，出现次数多的数字在左
    // sort(barcodes.begin(), barcodes.end());
    int len = barcodes.size();
    unordered_map<int, int> visited; //key:数字，value：出现的次数
    for (int i = 0; i < len;i++)
    {
        visited[barcodes[i]]++;
    }
    vector<int> tem;
    for(auto iter = visited.begin(); iter != visited.end();iter++)
    {
        tem.emplace_back(iter->second);
    }
    // 排序 tem
    sort(tem.begin(), tem.end());
    // 构建按照次数出现多少的来排序barcodes
    vector<int> new_barcodes;
    for (int i = tem.size()-1; i >=0; i--)
    {
        for(auto iter = visited.begin(); iter != visited.end();iter++){
            if(tem[i] == iter->second){
                vector<int> curr(iter->second, iter->first);
                new_barcodes.insert(new_barcodes.end(), curr.begin(), curr.end());
                visited.erase(iter);
                break;
            }
        }
    }

    // 先从左到右替换
    for (int i = 1; i < len; i++)
    {   
        // 遇到相同元素，替换后面的那一个
        if(new_barcodes[i]==new_barcodes[i-1]){ 
            //从某最右边找到第一个不等于 barcodes[i] 的值与之替换
            int right = i+1;
            while(right<len && new_barcodes[right] == new_barcodes[i]){
                right++;
            }
            // 替换
            if(right==len){
                break;
            }
            swap(new_barcodes[i], new_barcodes[right]);
        }
    }
    // 再右到左替换
    for (int i = len-2; i >= 0; i++)
    {   
        // 遇到相同元素，替换后面的那一个
        if(new_barcodes[i]==new_barcodes[i+1]){ 
            //从某最右边找到第一个不等于 barcodes[i] 的值与之替换
            int right = i-1;
            while(right>=0 && new_barcodes[right] == new_barcodes[i]){
                right--;
            }
            // 替换
            swap(new_barcodes[i], new_barcodes[right]);
        }
    }

    return new_barcodes;
}

// 找到最近的一个不同的就可以替换
vector<int> rearrangeBarcodes_replace(vector<int>& new_barcodes) {
    int len = new_barcodes.size();
    for (int i = 1; i < len; i++)
    {   
        // 遇到相同元素，替换后面的那一个
        if(new_barcodes[i]==new_barcodes[i-1]){ 
            //从某最右边找到第一个不等于 barcodes[i] 的值与之替换
            int right = i+1;
            while(right<len && new_barcodes[right] == new_barcodes[i]){
                right++;
            }
            // 替换
            if(right==len){
                break;
            }
            swap(new_barcodes[i], new_barcodes[right]);
        }
    }
    return new_barcodes;
}

vector<int> rearrangeBarcodes1(vector<int>& barcodes) {
    //先排序,左到右，出现次数多的数字在左
    // sort(barcodes.begin(), barcodes.end());
    int len = barcodes.size();
    unordered_map<int, int> visited; //key:数字，value：出现的次数
    for (int i = 0; i < len;i++)
    {
        visited[barcodes[i]]++;
    }
    vector<int> tem;
    for(auto iter = visited.begin(); iter != visited.end();iter++)
    {
        tem.emplace_back(iter->second);
    }
    // 排序 tem
    sort(tem.begin(), tem.end());
    // 构建按照次数出现多少的来排序barcodes
    vector<int> new_barcodes;
    for (int i = tem.size()-1; i >=0; i--)
    {
        for(auto iter = visited.begin(); iter != visited.end();iter++){
            if(tem[i] == iter->second){
                vector<int> curr(iter->second, iter->first);
                new_barcodes.insert(new_barcodes.end(), curr.begin(), curr.end());
                visited.erase(iter);
                break;
            }
        }
    }

    //左到右替换
    vector<int> new_barcodes = rearrangeBarcodes_replace(new_barcodes);
    reverse(new_barcodes.begin(), new_barcodes.end());
    //右到左替换
    vector<int> new_barcodes = rearrangeBarcodes_replace(new_barcodes);
    return new_barcodes;
}


int main(int argc, char const *argv[])
{
    vector<int> barcodes = {4,9,9,9,9,4,6,9,6,4};
    vector<int> ans = rearrangeBarcodes(barcodes);
    for(auto tem:ans){
        cout << tem << " ";
    }
    return 0;
}
