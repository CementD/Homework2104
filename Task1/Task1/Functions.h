#include <iostream>
#include <cstring>
using namespace std;

class Overcoat {
    char* facon;
    double price;

public:
    Overcoat(const char* pFacon, double pPrice) : price(pPrice) {
        int length = strlen(pFacon);
        facon = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            facon[i] = pFacon[i];
        }
        facon[length] = '\0';
    }

    Overcoat(Overcoat&& obj) : facon{ obj.facon }, price{ obj.price } {
        obj.facon = nullptr;
        obj.price = 0;
    }

    ~Overcoat() {
        delete[] facon;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            delete[] facon;
            int length = strlen(other.facon);
            facon = new char[length + 1];
            for (int i = 0; i < length; ++i) {
                facon[i] = other.facon[i];
            }
            facon[length] = '\0';
            price = other.price;
        }
        return *this;
    }


    bool operator==(const Overcoat& other) const {
        return (strcmp(facon, other.facon) == 0);
    }

    bool operator>(const Overcoat& other) const {
        return (price > other.price);
    }

    friend istream& operator>>(istream& in, Overcoat& coat) {
        cout << "Enter the price: ";
        in >> coat.price;
        char buffer[100];
        in.get();
        cout << "Enter the facon: ";
        in.getline(buffer, 100);
        int length = strlen(buffer);
        coat.facon = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            coat.facon[i] = buffer[i];
        }
        coat.facon[length] = '\0';
        return in;
    }


    friend ostream& operator<<(ostream& out, const Overcoat& coat) {
        out << "Facon: " << coat.facon << "; Price: " << coat.price << endl;
        return out;
    }
};
