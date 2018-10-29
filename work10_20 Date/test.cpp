#include"Date.h"
int main()
{
	Date d1(2018, 10, 27);
	//d1.print();

	//(d1 + 100).Print;
	int x = 52;
	Date d2(2018, 10, 27);
	Date olympicDate(2008, 8, 8);
	Date todayDate(2018, 10, 27);
	//cout << (olympicDate>todayDate) << endl;
	//cout << (todayDate<olympicDate) << endl;
	//cout << (todayDate > olympicDate) << endl;
	cout << todayDate-olympicDate << endl;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 <= d2) << endl;
	//cout << d1.operator<=(d2) << endl;

	//cout << (todayDate >= olympicDate) << endl;
	cout << (todayDate <= olympicDate) << endl;
	//cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << d1 - d2 << endl;
	cout << (d1 <= d2) << endl;
	d1 += x;
	d1.Print();
	cout << "......" << endl;
	system("pause");

}