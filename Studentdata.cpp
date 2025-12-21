#include <iostream>
#include <vector>
using namespace std;
struct Student {
    string name;
    string rollnumber;
    int batch;
    char section;
    bool isEnrolled;
};
Student inputStudent() {
    Student s;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter rollnumber: ";
    cin >> s.rollnumber;
    cout << "Enter batch: ";
    cin >> s.batch;
    cout << "Enter section: ";
    cin >> s.section;
    int enrolled;
    cout << "Is enrolled? (1 for yes, 0 for no): ";
    cin >> enrolled;
    s.isEnrolled = enrolled;
    return s;
}
void outputStudent(const Student& s) {
    cout << "Name: " << s.name << "\n";
    cout << "Rollnumber: " << s.rollnumber << "\n";
    cout << "Batch: " << s.batch << "\n";
    cout << "Section: " << s.section << "\n";
    cout << "Enrolled: " << (s.isEnrolled ? "Yes" : "No") << "\n";
    cout << "------------------------\n";
}
int main() {
    vector<Student> students;
    int n;
    cout << "How many Students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter student " << i + 1 << ":\n";
        students.push_back(inputStudent());
    }
    while (true) {
        char sec;
        cout << "\nEnter section (or X to exit): ";
        cin >> sec;
        if(sec == 0 || sec ==0) {
            cout << "Exiting program.\n";
            break;
        }
        bool found = false;
        cout << "\nStudents in section " << sec << ":\n";
        cout << "========================\n";
        for (const auto& s : students) {
            if (s.section == sec) {
                outputStudent(s);
                found = true;
            }
        }
        if (!found) {
            cout << "No students found in section " << sec << ".\n";
        }
    }
    return 0;
}