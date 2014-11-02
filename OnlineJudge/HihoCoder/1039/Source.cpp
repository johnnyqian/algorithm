#include <iostream>
#include <string>
using namespace std;

#define max(a,b) a>b?a:b
int maximumreduce(string str);

int main()
{
    freopen("Input.txt", "r", stdin);
    int n;
    cin >> n;

    while (n--)
    {
        int result = 0;
        string str;
        cin >> str;

        for (char c = 'A'; c <= 'C'; c++)
        {
            for (unsigned int i = 0; i <= str.length(); i++)
            {
                string newStr = str.substr(0, i) + c + str.substr(i);
                result = max(result, maximumreduce(newStr));
            }
        }

        cout << result << endl;
    }

    return 0;
}

int maximumreduce(string str)
{
    string tmp = str;

    while (true)
    {
        unsigned int index = 0;
        bool finished = true;

        while (index < tmp.length())
        {
            int count = 1;
            while ((index + count) < tmp.length() && tmp[index] == tmp[index + count])
            {
                count++;
            }

            if (count > 1)
            {
                finished = false;
                tmp = tmp.substr(0, index) + tmp.substr(index + count); // remove the duplicate char
            }
            else
            {
                index++;
            }
        }

        if (finished)
            return str.length() - tmp.length();
    }
}