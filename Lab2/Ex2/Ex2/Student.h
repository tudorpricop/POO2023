#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    float math_grade;
    float english_grade;
    float history_grade;

public:
    // Getter and setter methods for name
    void set_name(string name);
    string get_name() const;

    // Getter and setter methods for math grade
    void set_math_grade(float grade);
    float get_math_grade() const;

    // Getter and setter methods for english grade
    void set_english_grade(float grade);
    float get_english_grade() const;

    // Getter and setter methods for history grade
    void set_history_grade(float grade);
    float get_history_grade() const;

    // Method to retrieve the average grade
    float get_average_grade() const;
};

#endif // STUDENT_H