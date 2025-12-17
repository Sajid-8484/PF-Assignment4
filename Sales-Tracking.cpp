#include <iostream>
using namespace std;
const int PRODUCTS = 5;
const int DAYS = 7;
void inputSales(float sales[PRODUCTS][DAYS]) {
    cout << "Enter sales for 5 products over 7 days:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        for (int j = 0; j < DAYS; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}
void calculateRevenue(float sales[PRODUCTS][DAYS], float revenue[PRODUCTS]) {
    for (int i = 0; i < PRODUCTS; i++) {
        revenue[i] = 0;
        for (int j = 0; j < DAYS; j++) {
            revenue[i] += sales[i][j];
        }
    }
}
int findMaxProduct(float revenue[PRODUCTS]) {
    int maxIndex = 0;
    for (int i = 1; i < PRODUCTS; i++) {
        if (revenue[i] > revenue[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int findBestDay(float sales[PRODUCTS][DAYS]) {
    float dayTotal[DAYS] = {0};

    for (int j = 0; j < DAYS; j++) {
        for (int i = 0; i < PRODUCTS; i++) {
            dayTotal[j] += sales[i][j];
        }
    }

    int bestDay = 0;
    for (int j = 1; j < DAYS; j++) {
        if (dayTotal[j] > dayTotal[bestDay]) {
            bestDay = j;
        }
    }
    return bestDay;
}
int main() {
    float sales[PRODUCTS][DAYS];
    float revenue[PRODUCTS];

    inputSales(sales);
    calculateRevenue(sales, revenue);

    int maxProduct = findMaxProduct(revenue);
    int bestDay = findBestDay(sales);

    cout << "\nWeekly Revenue for Each Product:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "Product " << i + 1 << ": " << revenue[i] << endl;
    }

    cout << "\nProduct with Maximum Weekly Revenue: Product "
         << maxProduct + 1 << endl;

    cout << "Best Sales Day Overall: Day " << bestDay + 1 << endl;

    return 0;
}

