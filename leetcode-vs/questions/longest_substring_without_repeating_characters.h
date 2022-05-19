#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> chars;

        int max_length = 0;
        int lo = 0, hi = 0;
        while (hi < s.length())
        {
            if (chars.find(s[hi]) != chars.end())
            {
                max_length = max(max_length, hi - lo);
                while (lo < hi && s[lo] != s[hi])
                {
                    chars.erase(s[lo]);
                    lo++;
                }
                lo++;
            }
            chars.insert(s[hi++]);
        }
        return max(max_length, hi - lo);
    }
};