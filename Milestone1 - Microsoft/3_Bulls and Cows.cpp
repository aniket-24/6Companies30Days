/*
Problem Link: https://leetcode.com/problems/bulls-and-cows/
Title: Bulls and Cows
Difficulty: Medium
Author: Aniket Kumar
Language: C++
*/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        string s, g;
        int n = secret.size();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                count1++;
            else
            {
                s.push_back(secret[i]);
                g.push_back(guess[i]);
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                if (s[i] == g[j] && st.find(j) == st.end())
                {
                    count2++;
                    st.insert(j);
                    break;
                }
            }
        }
        return to_string(count1) + "A" + to_string(count2) + "B";
    }
};