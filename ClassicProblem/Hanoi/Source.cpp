#include<iostream>
using namespace std;

int moveTimes;

// from Ϊ�����
// buffer Ϊ��ת��
// to ΪĿ����
// ע�������˳��
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