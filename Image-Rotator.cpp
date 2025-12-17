#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;
    int a[100][100], rotated[100][100];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rotated[n - 1 - j][i] = a[i][j];
        }
    }
    cout << "\nMatrix after 90 degree counterclockwise rotation:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
