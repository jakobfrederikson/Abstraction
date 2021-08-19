#include <iostream>
using namespace std;

class Media
{
protected:
	string title;
	float price;
public:
	Media(string s = "_d_", float a = 0)
	{
		title = s;
		price = a;
	}

	virtual void display() = 0; // displaying interface for the rest of the derived classes. which I think means that these functions need to be overwritten within their class if they inherit from media
	virtual void getData() = 0;
};

class Tape : public Media
{
private:
	float time;
public:
	Tape(string s = "_d_", float a = 0, float t = 0)
	{
		title = s;
		price = a;
		time = t;
	}

	void getData()
	{
		cout << endl;
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter playing time: ";
		cin >> time;
	}

	void display()
	{
		cout << endl;
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
		cout << "Playing time: " << time << endl;
	}
};

class Book : public Media
{
private:
	int pages;
public:
	Book(string s = "_d_", float a = 0, int p = 0)
	{
		title = s;
		price = a;
		pages = p;
	}

	void getData()
	{
		cout << endl;
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter pages: ";
		cin >> pages;
	}

	void display()
	{
		cout << endl;
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
		cout << "Pages: " << pages << endl;
	}
};

int main()
{
	Media* media_array[100];

	int choice = 0;
	int dataChoice = 0;
	int arraySpot = 0;

	do 
	{
		cout << "Enter data for a: " << endl;
		cout << "[1] Book" << endl;
		cout << "[2] Tape" << endl;
		cin >> dataChoice;

		if (dataChoice == 1)
		{
			media_array[arraySpot] = new Book;
		} 
		else
		{
			media_array[arraySpot] = new Tape;
		}

		media_array[arraySpot]->getData();
		arraySpot++;

		cout << "\n\nWould you like to:" << endl;
		cout << "[1] Continue" << endl;
		cout << "[2] View data entered" << endl;
		cin >> choice;
		cout << endl;

	} while (choice != 2);
	
	for (int i = 0; i < arraySpot; i++)
	{
		media_array[i]->display();
	}

	return 0;
}

