#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date a(4, 2, 29);
	Date b(1, 12, 6);
	
	(a+b).print();
	cout << endl;

	cout << (a == b) << endl;
	cout << (a > b) << endl;
	cout << (a >= b) << endl;
	cout << (a != b) << endl;
}
