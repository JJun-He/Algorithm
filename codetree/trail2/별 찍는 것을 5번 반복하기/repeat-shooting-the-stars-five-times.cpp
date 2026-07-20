#include <iostream>
using namespace std;

void PrintStars() {
    for(int j = 0; j < 10; j++)
        cout << "*";
    cout << endl;
}

int main() {
    for(int i = 0; i < 5; i++)
        PrintStars();
    return 0;
}