// 剑指 Offer II 037. 小行星碰撞

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (auto aster : asteroids) {
        bool alive = true;
        while (alive && aster < 0 && !st.empty() && st.back() > 0) {
            alive = st.back() < -aster; // aster 是否存在
            if (st.back() <= -aster) {  // 栈顶小行星爆炸
                st.pop_back();
            }
        }
        if (alive) {
            st.push_back(aster);
        }
    }
    return st;
}

int main(int argc, char const *argv[])
{

    vector<int> asteroids = {10,2,-5};
    vector<int> ans = asteroidCollision(asteroids);
    for (auto curr: ans)
    {
        cout << curr << " ";
    }
    return 0;
}
