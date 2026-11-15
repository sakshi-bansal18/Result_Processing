/*
 * Project 9: Result Processing System Using Templates
 * Subject : Object-Oriented Programming Using C++ (CIC-211)
 *
 * Demonstrates: function templates, class template, generic programming,
 *               encapsulation, constructors, input validation.
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// ---------------------------------------------------------------
// FUNCTION TEMPLATE 1: largest of three values (works for any type
// that supports the > operator: int, double, char, ...)
// ---------------------------------------------------------------
template <typename T>
T largestOfThree(T a, T b, T c) {
    T maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

// ---------------------------------------------------------------
// FUNCTION TEMPLATE 2: average of three numeric values
// static_cast<double> avoids integer division (e.g. 85+92+78)/3
// ---------------------------------------------------------------
template <typename T>
double averageOfThree(T a, T b, T c) {
    return (static_cast<double>(a) + static_cast<double>(b) +
            static_cast<double>(c)) / 3.0;
}

// ---------------------------------------------------------------
// CLASS TEMPLATE: stores a student's name and a score of type T
// ---------------------------------------------------------------
template <typename T>
class StudentResult {
private:                       // encapsulation: data is private
    string name;
    T score;
public:
    // constructor with default arguments
    StudentResult(string n = "", T s = T()) : name(n), score(s) {}

    void setScore(T s)      { score = s; }
    T getScore() const      { return score; }
    string getName() const  { return name; }

    void display() const {
        cout << "Student: " << left << setw(12) << name
             << " | Score: " << score << endl;
    }
};

// ---------------------------------------------------------------
// Template helper: reads a score of type T and validates 0-100.
// T appears only in the return type, so it is called as readScore<int>(...)
// ---------------------------------------------------------------
template <typename T>
T readScore(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0 && value <= 100) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // drop leftovers
            return value;
        }
        cout << "Invalid input! Enter a number between 0 and 100.\n";
        cin.clear();                                              // reset error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');      // discard bad input
    }
}

// ---------------------------------------------------------------
// Generic driver: reads 3 students, then shows highest and average
// ---------------------------------------------------------------
template <typename T>
void processStudents(const string& typeName) {
    cout << "\n--- Processing " << typeName << " scores ---\n";
    string names[3];
    T scores[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> names[i];
        scores[i] = readScore<T>("Enter score (0-100): ");
    }

    StudentResult<T> s1(names[0], scores[0]);
    StudentResult<T> s2(names[1], scores[1]);
    StudentResult<T> s3(names[2], scores[2]);

    cout << "\nResults:\n";
    s1.display();
    s2.display();
    s3.display();

    cout << fixed << setprecision(2);
    cout << "Highest score : "
         << largestOfThree(s1.getScore(), s2.getScore(), s3.getScore()) << endl;
    cout << "Average score : "
         << averageOfThree(s1.getScore(), s2.getScore(), s3.getScore()) << endl;
    cout.unsetf(ios::fixed);
    cout << setprecision(6);   // restore default precision
}

// ---------------------------------------------------------------
int main() {
    int choice;
    do {
        cout << "\n===== RESULT PROCESSING SYSTEM =====\n"
             << "1. Process integer scores\n"
             << "2. Process floating-point scores\n"
             << "3. Largest of three (int / double / char demo)\n"
             << "0. Exit\n"
             << "Choice: ";

        if (!(cin >> choice)) {            // non-numeric menu input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: processStudents<int>("integer"); break;
            case 2: processStudents<double>("floating-point"); break;
            case 3:
                cout << "Largest int    : " << largestOfThree(10, 45, 32) << endl;
                cout << "Largest double : " << largestOfThree(72.5, 68.25, 90.75) << endl;
                cout << "Largest char   : " << largestOfThree('a', 'z', 'm') << endl;
                break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
