#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int sudoku[9][9] = {0};
int rows[9][9] = {0};
int columns[9][9] = {0};
int area[9][9] = {0};

bool backtracking(int row, int col){
    if (row == 9){ return true; }
    if (sudoku[row][col] != 0) {
        if (col == 8){
            return backtracking(row + 1, 0);
        } else {
            return backtracking(row, col + 1);
        }
    }

    for (int i = 1; i <= 9; i++){
        if (rows[row][i - 1] == 0 && columns[col][i - 1] == 0 && area[(row / 3) * 3 + col / 3 ][i - 1] == 0){
            rows[row][i - 1] = 1; 
            columns[col][i - 1] = 1;
            area[(row / 3) * 3 + col / 3 ][i - 1] = 1;
            sudoku[row][col] = i;

            bool isEnd;
            if (col == 8){
                isEnd = backtracking(row + 1, 0);
            } else {
                isEnd = backtracking(row, col + 1);
            }

            if (isEnd) return true;
            else {
                sudoku[row][col] = 0;
                rows[row][i - 1] = 0;
                columns[col][i - 1] = 0;
                area[(row / 3) * 3 + col / 3 ][i - 1] = 0;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2239.txt", ios_base::in);    
    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            if (s[j] != '0'){
                rows[i][s[j] - '0' - 1] = 1;
                columns[j][s[j] - '0' - 1] = 1;
                area[(i / 3) * 3 + j / 3][s[j] - '0' - 1] = 1;
            }
            sudoku[i][j] = s[j] - '0';
        }
    }
    backtracking(0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
    

}

