#include <iostream>
#include <string>

using namespace std;

class Lion {
public:
	string name;
	string gender;
	int age;
	void sleeping() {
		cout << "sleeping..." << endl;
	}
	void eating() {
		cout << "eating..." << endl;
	}
	void dying() {
		cout << "dying..." << endl;
	}
};

int main() {

	Lion lion1, lion2;

	lion1.name = "John";
	lion1.gender = 'M';
	lion1.age = 7;

	lion2.name = "Grace";
	lion2.gender = 'F';
	lion2.age = 75;

	cout << "Lion1's name is " << lion1.name << endl;
	cout << "Lion1's gender is " << lion1.gender << endl;
	cout << "Lion1's age is " << lion1.age << endl;
	cout << "Lion1 is now.. "; // function cannot be after <<
	lion1.sleeping();

	cout << "Lion2's name is " << lion2.name << endl;
	cout << "Lion2's gender is " << lion2.gender << endl;
	cout << "Lion2's age is " << lion2.age << endl;
	cout << "Lion2 is now.. "; // function cannot be after <<
	lion2.sleeping();

	return 0;
}