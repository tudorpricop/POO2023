#include <iostream>
#include "Student.h"
#include "Comparer.h"

using namespace std;

int main() {
    // Create two student objects
    Student s1;
    Student s2;

    // Set and get methods for s1
    s1.set_name("Thomas Shelby");
    cout << "s1 name: " << s1.get_name() << endl;
    s1.set_math_grade(10.0);
    cout << "s1 math grade: " << s1.get_math_grade() << endl;
    s1.set_english_grade(5.5);
    cout << "s1 english grade: " << s1.get_english_grade() << endl;
    s1.set_history_grade(8.5);
    cout << "s1 history grade: " << s1.get_history_grade() << endl;
    cout << "s1 average grade: " << s1.get_average_grade() << endl;

    // Set and get methods for s2
    s2.set_name("Arthur Shelby");
    cout << "s2 name: " << s2.get_name() << endl;
    s2.set_math_grade(4.5);
    cout << "s2 math grade: " << s2.get_math_grade() << endl;
    s2.set_english_grade(10.0);
    cout << "s2 english grade: " << s2.get_english_grade() << endl;
    s2.set_history_grade(9.0);
    cout << "s2 history grade: " << s2.get_history_grade() << endl;
    cout << "s2 average grade: " << s2.get_average_grade() << endl;

    // Comparison functions
    cout << "compare_name: " << compare_name(s1, s2) << endl;
    cout << "compare_math_grade: " << compare_math_grade(s1, s2) << endl;
    cout << "compare_english_grade: " << compare_english_grade(s1, s2) << endl;
    cout << "compare_history_grade: " << compare_history_grade(s1, s2) << endl;
    cout << "compare_average_grade: " << compare_average_grade(s1, s2) << endl;

    return 0;
}
