/*
Problem Link: https://leetcode.com/problems/largest-divisible-subset/
Title: Largest Divisible Subset
Difficulty: Medium
Author: Aniket Kumar
Language: C++
*/

class Solution
{
public:
    void solve(int index, int n, int prev, vector<int> &nums, vector<int> &temp, vector<int> &ans, vector<int> &dp)
    {
        if (temp.size() > ans.size())
        {
            ans = temp;
        }
        for (int i = index; i < n; i++)
        {
            if (int(dp[i]) < temp.size() && nums[i] % prev == 0)
            {
                dp[i] = temp.size();
                temp.push_back(nums[i]);
                solve(i + 1, n, nums[i], nums, temp, ans, dp);
                temp.pop_back();
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, -1);
        vector<int> temp, ans;
        solve(0, n, 1, nums, temp, ans, dp);
        return ans;
    }
};