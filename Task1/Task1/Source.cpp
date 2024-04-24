#include <iostream>
#include "Functions.h"
using namespace std;

int main() {
    Overcoat coat("wool", 100.0);
    cout << "Current coat: " << coat;

    cout << "Enter new coat details:" << endl;
    cin >> coat;

    cout << "Updated coat: " << coat;

    return 0;
}