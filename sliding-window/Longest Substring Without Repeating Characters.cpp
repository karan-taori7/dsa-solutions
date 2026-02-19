// Problem: Longest Substring Without Repeating Characters (LeetCode #3)
// Pattern: Sliding Window
// Difficulty: Medium
// Date: 2026-02-19
//
// KEY INSIGHT:
// Expand right pointer freely, shrink left pointer when duplicate found.
// Use a frequency map to track character counts in current window.
//
// COMMON MISTAKE:
// Forgetting to update maxlen before moving the right pointer.
//
// TIME: O(n) — each character visited at most twice
// SPACE: O(n) — frequency map stores window characters


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<char, int> freq;

        while(r < n)
        {
            freq[s[r]]++;                 

            while(freq[s[r]] > 1)        
            {
                freq[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r-l+1); 
            r++;
        }
        return maxlen;
    }
};