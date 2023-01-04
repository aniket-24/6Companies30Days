/*
Problem Link: https://leetcode.com/problems/combination-sum-iii/
Title: Combination Sum III
Difficulty: Medium
Author: Aniket Kumar
Language: C++
*/
class Solution
{
public:
    void solve(int ind, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (n < 0 || k < 0)
            return;
        if (n == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i <= 9; i++)
        {
            temp.push_back(i);
            solve(i + 1, n - i, k - 1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, temp, ans);
        return ans;
    }
};