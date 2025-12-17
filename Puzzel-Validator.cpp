#include <iostream>
#include <string>
using namespace std;
const int MAX = 20;
void inputPuzzle(char grid[MAX][MAX], int &rows, int &cols) {
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter crossword grid (# for blocked cells):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
}
int countHorizontalWords(char grid[MAX][MAX], int rows, int cols, string &longest) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        string word = "";
        for (int j = 0; j <= cols; j++) {
            if (j < cols && grid[i][j] != '#') {
                word += grid[i][j];
            } else {
                if (word.length() >= 3) {
                    count++;
                    if (word.length() > longest.length())
                        longest = word;
                }
                word = "";
            }
        }
    }
    return count;
}
int countVerticalWords(char grid[MAX][MAX], int rows, int cols, string &longest) {
    int count = 0;

    for (int j = 0; j < cols; j++) {
        string word = "";
        for (int i = 0; i <= rows; i++) {
            if (i < rows && grid[i][j] != '#') {
                word += grid[i][j];
            } else {
                if (word.length() >= 3) {
                    count++;
                    if (word.length() > longest.length())
                        longest = word;
                }
                word = "";
            }
        }
    }
    return count;
}
int main() {
    char grid[MAX][MAX];
    int rows, cols;
    string longest = "";

    inputPuzzle(grid, rows, cols);

    int horizontal = countHorizontalWords(grid, rows, cols, longest);
    int vertical = countVerticalWords(grid, rows, cols, longest);

    cout << "\nCrossword Puzzle Analysis\n";
    cout << "--------------------------\n";
    cout << "Horizontal Words: " << horizontal << endl;
    cout << "Vertical Words  : " << vertical << endl;
    cout << "Longest Word    : " << longest << endl;

    return 0;
}
