#include<iostream>
using namespace std;

int moveTimes;

// from 为起点柱
// buffer 为中转柱
// to 为目标柱
// 注意参数的顺序
void hanoi(int n, char from, char buffer, char to)
{
    if (n > 0)
    {
        hanoi(n - 1, from, to, buffer);
        cout << "Move " << n <<"\t"<< from << " -> " << to << endl;
        moveTimes++;
        hanoi(n - 1, buffer, from, to);
    }
}

int main()
{
    int n;
    freopen("Input.txt", "r", stdin);
    cin >> n;
    moveTimes = 0;

    hanoi(n, 'A', 'B', 'C');
    cout << "\nMove Times: " << moveTimes << endl;

    return EXIT_SUCCESS;
}