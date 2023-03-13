// 2383. 赢得比赛需要的最少训练时长

#include<iostream>
#include<vector>

using namespace std;

int minNumberOfHours(int initialEnergy, int initialExperience,
                     vector<int>& energy, vector<int>& experience) {
    int lengthEn = energy.size();
    int lengthEx = experience.size();

    int ans = 0;

    // 判断精力值够不够完成所有的
    int sumEn = 0;
    for (int i = 0; i < lengthEn;i++)
    {
        sumEn += energy[i];
    }

    ans = sumEn >= initialEnergy ? sumEn - initialEnergy + 1 : 0;

    // 解决经验值：
    for (int i = 0; i < lengthEx; i++){
        if(initialExperience <= experience[i]){
            int sub = experience[i] - initialExperience + 1;
            initialExperience += sub;
            ans = ans + sub;
        }
        initialExperience += experience[i];
    }

    return ans;
}


int main(){
    int initialEnergy = 1;
    int initialExperience = 1;
    vector<int> energy{1,1,1,1};
    vector<int> experience{1,1,1,50};

    int ans = minNumberOfHours(initialEnergy, initialExperience, energy, experience);
    cout << ans << endl;
}