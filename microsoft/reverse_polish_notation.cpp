// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        set<string> st({"+", "-", "/", "*"});
        stack<int> stk;
        for (auto s : tokens)
        {
            if (st.find(s) == st.end())
            {
                stk.push(stoi(s));
                // cout<<stoi(s);
            }
            else
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if (s == "+")
                    a += b;
                else if (s == "-")
                    a = b - a;
                else if (s == "*")
                    a *= b;
                else if (s == "/")
                    a = b / a;
                stk.push(a);
                // cout<<a<<" "<<b<<endl;
            }
        }
        return stk.top();
    }
};
int main()
{

    return 0;
}
