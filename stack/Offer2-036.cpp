// 剑指 Offer II 036. 后缀表达式

#include<iostream>
#include<vector>
#include<stack>
#include<string>
// #include<algorithm>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> mystack;
    int len = tokens.size();
    for (int i = 0; i < len; i++)
    {
        string curr = tokens[i];
        if (curr == "+"){
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();
            int ans = b + a;
            mystack.push(ans);
        }else if (curr == "-"){
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();
            int ans = b - a;
            mystack.push(ans);
        }else if (curr == "*"){
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();
            int ans = b * a;
            mystack.push(ans);
        }else if (curr == "/"){
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();
            int ans = b / a;
            mystack.push(ans);
        }else{
            mystack.push(stoi(curr)); // string 转 int
        }
    }

    return mystack.top();
}

int main(int argc, char const *argv[])
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = evalRPN(tokens);
    cout << isdigit('2') << endl;
    // cout << ans;
    return 0;
}
