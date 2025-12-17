#include <iostream>
using namespace std;
const int ROWS = 10;
const int COLS = 10;
void initializeSeats(int seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 0;
        }
    }
}
void displaySeats(int seats[ROWS][COLS]) {
    cout << "\nSeat Layout (0 = Empty, 1 = Reserved)\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}
void reserveSeat(int seats[ROWS][COLS]) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;
    if (seats[row - 1][col - 1] == 0) {
        seats[row - 1][col - 1] = 1;
        cout << "Seat reserved successfully.\n";
    } else {
        cout << "Seat already reserved.\n";
    }
}
void cancelSeat(int seats[ROWS][COLS]) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;

    if (seats[row - 1][col - 1] == 1) {
        seats[row - 1][col - 1] = 0;
        cout << "Seat reservation cancelled.\n";
    } else {
        cout << "Seat is already empty.\n";
    }
}
void countRowStatus(int seats[ROWS][COLS]) {
    int full = 0, partial = 0, empty = 0;
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 1)
                count++;
        }
        if (count == 0)
            empty++;
        else if (count == COLS)
            full++;
        else
            partial++;
    }
    cout << "\nRow Occupancy Status:\n";
    cout << "Fully Occupied Rows   : " << full << endl;
    cout << "Partially Occupied Rows: " << partial << endl;
    cout << "Empty Rows            : " << empty << endl;
}
int main() {
    int seats[ROWS][COLS];
    int choice;
    initializeSeats(seats);
    do {
        cout << "\n==== Bus Seat Allocation System ====\n";
        cout << "1. Display Seats\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Cancel a Seat\n";
        cout << "4. Count Row Occupancy\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                reserveSeat(seats);
                break;
            case 3:
                cancelSeat(seats);
                break;
            case 4:
                countRowStatus(seats);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
