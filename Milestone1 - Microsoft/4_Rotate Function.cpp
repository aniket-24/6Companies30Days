/*
Problem Link: https://leetcode.com/problems/rotate-function/
Title: Rotate Function
Difficulty: Medium
Author: Aniket Kumar
Language: C++
*/

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prev += (i * nums[i]);
        }

        int ans = prev;
        for (int i = 1; i < n; i++)
        {
            int f = prev + sum - (n * nums[n - i]);
            prev = f;
            ans = max(ans, f);
        }
        return ans;
    }
};