#pragma once
class Date
{
	int year;
	int month; 
	int day;
public:
	Date();
	Date(int, int, int);

	int getYear()const;
	int getMonth()const;
	int getDay()const;
	void setYear(int);
	void setMonth(int);
	int getMaxDay();
	void setDay(int);
	void print()const;

	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);
	Date operator+(int);
	Date operator-(int);
	Date operator+(Date);
	Date operator-(Date);
	Date& operator+=(int);
	Date& operator-=(int);
	Date& operator+=(Date);
	Date& operator-=(Date);

	bool operator <(Date);
	bool operator >(Date);
	bool operator <=(Date);
	bool operator >=(Date);
	bool operator ==(Date);
	bool operator !=(Date);
};

