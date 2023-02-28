#include "Comparer.h"

int compare_name(const Student& s1, const Student& s2) {
    return s1.get_name().compare(s2.get_name());
}

int compare_math_grade(const Student& s1, const Student& s2) {
    if (s1.get_math_grade() > s2.get_math_grade()) {
        return 1;
    }
    else if (s1.get_math_grade() < s2.get_math_grade()) {
        return -1;
    }
    else {
        return 0;
    }
}

int compare_english_grade(const Student& s1, const Student& s2) {
    if (s1.get_english_grade() > s2.get_english_grade()) {
        return 1;
    }
    else if (s1.get_english_grade() < s2.get_english_grade()) {
        return -1;
    }
    else {
        return 0;
    }
}

int compare_history_grade(const Student& s1, const Student& s2) {
    if (s1.get_history_grade() > s2.get_history_grade()) {
        return 1;
    }
    else if (s1.get_history_grade() < s2.get_history_grade()) {
        return -1;
    }
    else {
        return 0;
    }
}

int compare_average_grade(const Student& s1, const Student& s2) {
    if (s1.get_average_grade() > s2.get_average_grade()) {
        return 1;
    }
    else if (s1.get_average_grade() < s2.get_average_grade()) {
        return -1;
    }
    else {
        return 0;
    }
}
