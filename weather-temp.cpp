#include <iostream>
#include <iomanip>
using namespace std;
const int DAYS = 7;
const int TIMES = 4;
void inputTemperatures(float temp[DAYS][TIMES]) {
    cout << "Enter temperature readings for 7 days (4 readings per day):\n";

    for (int i = 0; i < DAYS; i++) {
        cout << "\nDay " << i + 1 << ":\n";
        for (int j = 0; j < TIMES; j++) {
            cout << "  Reading " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }
}
void findHighLow(float temp[DAYS][TIMES], float &highest, float &lowest) {
    highest = temp[0][0];
    lowest = temp[0][0];

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < TIMES; j++) {
            if (temp[i][j] > highest)
                highest = temp[i][j];
            if (temp[i][j] < lowest)
                lowest = temp[i][j];
        }
    }
}
void calculateAverages(float temp[DAYS][TIMES], float avg[DAYS]) {
    for (int i = 0; i < DAYS; i++) {
        float sum = 0;
        for (int j = 0; j < TIMES; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / TIMES;
    }
}
void displayResults(float temp[DAYS][TIMES], float avg[DAYS], float high, float low) {
    cout << "\nWeather Temperature Analysis\n";
    cout << "------------------------------------------------------------\n";
    cout << left << setw(6) << "Day"
         << setw(8) << "T1"
         << setw(8) << "T2"
         << setw(8) << "T3"
         << setw(8) << "T4"
         << setw(10) << "Average" << endl;
    cout << "------------------------------------------------------------\n";
    for (int i = 0; i < DAYS; i++) {
        cout << left << setw(6) << i + 1;
        for (int j = 0; j < TIMES; j++) {
            cout << setw(8) << fixed << setprecision(1) << temp[i][j];
        }
        cout << setw(10) << fixed << setprecision(2) << avg[i] << endl;
    }
    cout << "------------------------------------------------------------\n";
    cout << "Highest Temperature of the Week: " << high << endl;
    cout << "Lowest Temperature of the Week : " << low << endl;
}
int main() {
    float temperatures[DAYS][TIMES];
    float averages[DAYS];
    float highest, lowest;
    inputTemperatures(temperatures);
    findHighLow(temperatures, highest, lowest);
    calculateAverages(temperatures, averages);
    displayResults(temperatures, averages, highest, lowest);
    return 0;
}