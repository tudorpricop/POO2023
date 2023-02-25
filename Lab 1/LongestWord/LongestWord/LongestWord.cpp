#include <iostream>
#include <cstring>

using namespace std;

#pragma warning(disable:4996)

char sentence[1000], word[1000][100], * p;
int n;

int main()
{
    scanf("%[^\n]s", sentence);

    p = strtok(sentence, " ");

    while (p != NULL)
    {
        strcpy(word[n], p);
        n++;
        p = strtok(NULL, " ");
    }

    for (int i=0; i<n-1;i++)
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(word[i]) < strlen(word[j]))
                swap(word[i], word[j]);
            else
                if ((strlen(word[i]) == strlen(word[j])) && strcmp(word[i], word[j])>0)
                    swap(word[i], word[j]);
        }

    for (int i = 0; i < n; i++)
        cout << word[i] << endl;

    return 0;
}