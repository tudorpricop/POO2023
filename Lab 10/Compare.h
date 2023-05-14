#pragma once

int compare(const int& a, const int& b) {
	return a - b;
}

class Compare {
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class IntCompare : public Compare {
public:
	int CompareElements(void* e1, void* e2) override {
		int* elem1 = (int*)e1;
		int* elem2 = (int*)e2;
		if (*elem1 < *elem2) {
			return -1;
		}
		else if (*elem1 > *elem2) {
			return 1;
		}
		else {
			return 0;
		}
	}
};