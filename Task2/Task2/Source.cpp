#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    Flat flat1(50.0, 1000.0);
    cout << "Current coat: " << flat1;

    cout << "Enter new coat details:" << endl;
    cin >> flat1;

    cout << "Updated coat: " << flat1;

    return 0;
}