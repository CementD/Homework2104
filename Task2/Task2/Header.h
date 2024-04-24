#include <iostream>
using namespace std;

class Flat {
	double size;
	double price;

public:
	Flat(double pSize, double pPrice) : size(pSize), price(pPrice) {}

	bool operator==(const Flat& other) const {
		return (size == other.size);
	}

	Flat& operator=(const Flat& other) {
		if (this != &other) {
			size = other.size;
			price = other.price;
		}
		return *this;
	}

	bool operator>(const Flat& other) const {
		return (price > other.price);
	}

    Flat(Flat&& obj) : size(obj.size), price(obj.price) {
		obj.size = 0;
		obj.price = 0;
	}

	friend istream& operator>>(istream& in, Flat& flat) {
		cout << "Enter the size: ";
		in >> flat.size;
		cout << "Enter the price: ";
		in >> flat.price;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Flat& flat) {
		out << "Size: " << flat.size << "; Price: " << flat.price << endl;
		return out;
	}
};