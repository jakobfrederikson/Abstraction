#include <iostream>
using namespace std;

class SHAPE
{
protected:
	double a;
	double b;
public:
	void getData()
	{
		cout << endl;
		cout << "Enter base: ";
		cin >> a;
		cout << "Enter height: ";
		cin >> b;
	}

	virtual void displayArea() = 0;
};

class TRIANGLE : public SHAPE
{
public:
	void displayArea()
	{
		cout << "\nTriangle area = " << (b * a) / 2 << endl;
	}
};

class RECTANGLE : public SHAPE
{
public:
	void displayArea()
	{
		cout << "\nRectangle area = " << b * a << endl;
	}
};

int main()
{
	TRIANGLE t;
	RECTANGLE r;

	int choice = 0;
	int shapeChoice = 0;

	do 
	{
		cout << "Find area for :" << endl;
		cout << "[1] Triangle" << endl;
		cout << "[2] Rectangle" << endl;
		cin >> shapeChoice;
		
		if (shapeChoice == 1)
		{
			t.getData();
			t.displayArea();
		}
		else
		{
			r.getData();
			r.displayArea();
		}

		cout << "Would you like to: " << endl;
		cout << "[1] Continue" << endl;
		cout << "[2] Exit" << endl; 
		cin >> choice;
		cout << endl;

	} while (choice != 2);
}
