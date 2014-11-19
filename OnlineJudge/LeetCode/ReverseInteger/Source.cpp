#include <iostream>

using namespace std; 

class Solution {
public:
    int reverse(int x) {
        long long result = 0LL;
        while (x != 0)
        {
            result = result * 10 + x % 10;

            if (result<INT_MIN || result>INT_MAX)
                return 0;

            x = x / 10;
        }
        return (int)result;
    }

    // official solution
    // explanation : https://oj.leetcode.com/discuss/16020/why-compared-with-214748364-in-the-solution
    int reverse_official(int x) {
        int ret = 0;
        while (x != 0) {
            // handle overflow/underflow
            if (abs(ret) > 214748364) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-123) << endl;
    cout << s.reverse_official(1000000003) << endl;

    return 0;
}