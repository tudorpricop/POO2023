#include "Canvas.h"
#include <iostream>
using namespace std;

int main()
{
    Canvas canvas(20, 10);

    char choice;
    do {
        cout << "Choose a command to: draw, fill, print or clear\n";
        cout << "1. Circle\n";
        cout << "2. Filled circle\n";
        cout << "3. Rectangle\n";
        cout << "4. Filled rectangle\n";
        cout << "5. Set point\n";
        cout << "6. Line\n";
        cout << "7. Print\n";
        cout << "8. Clear\n";
        cout << "9. Exit\n\n";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case '1':
            canvas.DrawCircle(10, 5, 4, '*');
            break;
        case '2':
            canvas.FillCircle(10, 5, 4, '*');
            break;
        case '3':
            canvas.DrawRect(5, 2, 15, 8, '*');
            break;
        case '4':
            canvas.FillRect(5, 2, 15, 8, '*');
            break;
        case '5':
            canvas.SetPoint(10, 5, '*');
            break;
        case '6':
            canvas.DrawLine(5, 2, 15, 8, '*');
            break;
        case '7':
            canvas.Print();
            break;
        case '8':
            canvas.Clear();
            break;
        case '9':
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    } while (true);

    return 0;
}