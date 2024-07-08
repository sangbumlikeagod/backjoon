#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream cin("목표값.txt", ios_base::in);

    cin.tie(0);

    string s;
    cin >> s;

    char *pointer_1 = &s[s.length() - 1];

    while (true)
    {
        char *pointer_2 = pointer_1 + 1;
        char *smallest = pointer_1 + 1;

        while (pointer_2 != &s[s.length()])
        {
            if (*pointer_1 < *pointer_2 && *pointer_2 < *smallest)
            {
                smallest = pointer_2;
            }
            ++pointer_2;
        }

        if (*pointer_1 < *smallest)
        {
            swap(*pointer_1, *smallest);
            sort(pointer_1 + 1, &s[s.length()]);
            cout << s;
            break;
        }

        if (pointer_1 == &s[0])
        {
            break;
        }

        --pointer_1;
    }

    return 0;
}