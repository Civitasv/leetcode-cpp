#include <iostream>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 32; i > 0; --i)
        {
            // shift left
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};