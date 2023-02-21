#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int finalSum;

#include <stdio.h>

int convert(char x[100]) {

    int i = 0, num = 0;

    while (x[i] != '\0') {
        if (x[i] >= '0' && x[i] <= '9') {
            num = num * 10 + (x[i] - '0');
        }
        i++;
    }

    return num;
}


int main()
{
        FILE* readingFile;
        char str[100];

        readingFile = fopen("in.txt", "r");

        while (fgets(str, 100, readingFile) != NULL) {
            int converted = convert(str);
            finalSum += converted;
            //printf("%d\n", converted);
        }

        printf("%d\n", finalSum);

        fclose(readingFile);

        return 0;
}
