#include "Student.h"
using namespace std;

// Getter and setter methods for name
void Student::set_name(string name) {
    this->name = name;
}

string Student::get_name() const {
    return name;
}

// Getter and setter methods for math grade
void Student::set_math_grade(float grade) {
    math_grade = grade;
}

float Student::get_math_grade() const {
    return math_grade;
}

// Getter and setter methods for english grade
void Student::set_english_grade(float grade) {
    english_grade = grade;
}

float Student::get_english_grade() const {
    return english_grade;
}

// Getter and setter methods for history grade
void Student::set_history_grade(float grade) {
    history_grade = grade;
}

float Student::get_history_grade() const {
    return history_grade;
}

// Method to retrieve the average grade
float Student::get_average_grade() const {
    return (math_grade + english_grade + history_grade) / 3;
}
