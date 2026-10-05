#include <iostream>
#include <limits>

using namespace std;

// Function Prototypes
void inputGrades(double& g1, double& g2, double& g3);
double calculateAverage(const double g1, const double g2, const double g3);
char getLetterGrade(const double average);
void clearInputError();

int main() {
    int choice;
    double grade1 = 0.0, grade2 = 0.0, grade3 = 0.0;
    bool gradesEntered = false;

    do {
        cout << "\n--- Student Grade Management Menu ---\n";
        cout << "1. Input Grades\n";
        cout << "2. Calculate and Display Average\n";
        cout << "3. Assign and Display Letter Grade\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            clearInputError();
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                inputGrades(grade1, grade2, grade3);
                gradesEntered = true;
                break;
            case 2:
                if (!gradesEntered) {
                    cout << "Please input grades first (Option 1).\n";
                } else {
                    double avg = calculateAverage(grade1, grade2, grade3);
                    cout << "Average Grade: " << avg << "\n";
                }
                break;
            case 3:
                if (!gradesEntered) {
                    cout << "Please input grades first (Option 1).\n";
                } else {
                    double avg = calculateAverage(grade1, grade2, grade3);
                    char letter = getLetterGrade(avg);
                    cout << "Letter Grade: " << letter << "\n";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

void clearInputError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Pass-by-reference modifies variables in main
void inputGrades(double& g1, double& g2, double& g3) {
    cout << "Enter three grades separated by spaces (0-100): ";
    cin >> g1 >> g2 >> g3;
    
    // Validate grades are numbers and within 0-100
    while (cin.fail() || g1 < 0 || g1 > 100 || g2 < 0 || g2 > 100 || g3 < 0 || g3 > 100) {
        clearInputError();
        cout << "Invalid input. Grades must be numeric and between 0 and 100.\n";
        cout << "Enter three grades separated by spaces (0-100): ";
        cin >> g1 >> g2 >> g3;
    }
    cout << "Grades successfully updated.\n";
}

// Pass-by-value, read-only (const)
double calculateAverage(const double g1, const double g2, const double g3) {
    return (g1 + g2 + g3) / 3.0;
}

// Pass-by-value, read-only (const)
char getLetterGrade(const double average) {
    if (average >= 90.0) return 'A';
    if (average >= 80.0) return 'B';
    if (average >= 70.0) return 'C';
    if (average >= 60.0) return 'D';
    return 'F';
}
