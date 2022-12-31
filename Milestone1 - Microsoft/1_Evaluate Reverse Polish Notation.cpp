/*
Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
Title: Evaluate Reverse Polish Notation
Difficulty: Medium
Author: Aniket Kumar
Language: C++
*/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int n = tokens.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string ch = tokens[i];
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
            {
                int num = stoi(ch);
                st.push(num);
            }
            else
            {
                if (st.size() >= 2)
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int num;
                    if (ch == "+")
                        num = a + b;
                    else if (ch == "-")
                        num = b - a;
                    else if (ch == "*")
                        num = a * b;
                    else
                        num = b / a;
                    st.push(num);
                }
            }
        }
        return st.top();
    }
};