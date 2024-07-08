#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("목표값.txt", ios_base::in);

    string s;
    cin >> s;
    char *pointer_1 = (char *)s.c_str() + (s.length() - 1) * sizeof(char);
    // cout << *pointer_1 << '\n';

    while (true)
    {
        // cout << *pointer_1 << '\n';
        char *pointer_2 = pointer_1 + sizeof(char);
        char *smallest = pointer_1 + sizeof(char);

        // cout << *pointer_2 << '\n';
        while (true)
        {
            if (pointer_2 == (char *)s.c_str() + s.length() * sizeof(char))
            {
                break;
            }
            if (*pointer_2 < *smallest)
            {
                smallest = pointer_2;
            }
            // cout << *pointer_2 << ' ' << *smallest << '\t';
            pointer_2 += sizeof(char);
        }
        if (smallest)
        {
            // cout << "sex" << *smallest << *pointer_1 << (bool)(*smallest > *pointer_1) << '\n';
            if (*pointer_1 < *smallest)
            {
                swap(pointer_1, smallest);
                cout << *pointer_1 << '\t' << *smallest << '\n';
                cout << s;
                break;
            }
        }
        if (pointer_1 == (char *)s.c_str())
        {
            break;
        }
        pointer_1 -= sizeof(char);
    }
}