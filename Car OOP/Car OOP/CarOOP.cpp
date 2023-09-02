#include <iostream>
#include <string>

using namespace std;

class Car {
public:
	string brand;
	int production_year;
	string owner;
	void running() {
		cout << brand << " is running..." << endl;
	}
	void stopping() {
		cout << brand << " is stopping..." << endl;
	}
	void reversing() {
		cout << brand << " is moving backwards" << endl;
	}
};

int main() {
	Car car1, car2;

	car1.brand = "Lexus";
	car1.production_year = 2023;
	car1.owner = "Levi";

	car2.brand = "SantaFe";
	car2.production_year = 2023;
	car2.owner = "Marco";

	cout << "The " << car1.production_year << " " << car1.brand << " car is owned by " << car1.owner << endl;
	cout << "\n\n";
	car1.running();
	car1.reversing();
	car1.stopping();

	cout << "\n\nThe " << car2.production_year << " " << car2.brand << " car is owned by " << car2.owner << endl;
	cout << "\n\n";
	car2.running();
	car2.reversing();
	car2.stopping();

	return 0;
}