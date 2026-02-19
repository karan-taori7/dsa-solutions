// Problem: Max Consecutive Ones III (LeetCode #1004)
// Pattern: Sliding Window
// Difficulty: Medium
// Date: 2026-02-19
//
// KEY INSIGHT:
// Track how many zeros are in the window. When zeros exceed k,
// shrink from the left until you drop a zero.
//
// COMMON MISTAKE:
// Shrinking one step at a time instead of shrinking until zero count <= k.
//
// TIME: O(n) — single pass
// SPACE: O(1) — only counters

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n=nums.size();
       int l=0,r=0;
       int count=0;
       int maxlen=0;
       while(r<n)
       {
        if(nums[r]==0)count++;
        while(count>k)
        {
            if(nums[l]==0)count--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
       } 
       return maxlen;
    }
};