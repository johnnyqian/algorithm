#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i<n; i++)
            A[0] ^= A[i];
        return A[0];
    }
};

int main()
{
    int arr[9] ={ 1, 1, 2, 2, 3, 4, 4, 5, 5};
    Solution s;
    cout << s.singleNumber(arr, 9) << endl;

    return 0;
}