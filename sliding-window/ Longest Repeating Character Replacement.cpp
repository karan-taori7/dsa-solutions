// Problem: Longest Repeating Character Replacement (LeetCode #424)
// Pattern: Sliding Window
// Difficulty: Medium
// Date: 2026-02-19
//
// KEY INSIGHT:
// Window is valid when (window size - max frequency char) <= k.
// Only track the max frequency, never decrease it.
//
// COMMON MISTAKE:
// Recalculating max frequency every time instead of just tracking it.
//
// TIME: O(n) — single pass
// SPACE: O(1) — only 26 characters in frequency array

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        int hash[26] = {0};
        int maxlen = 0, maxfreq = 0;

        while(r < n) {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);

            while((r - l + 1) - maxfreq > k) {
                hash[s[l] - 'A']--;
                l++;
                for(int i = 0; i < 26; i++)
                    maxfreq = max(maxfreq, hash[i]);
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};