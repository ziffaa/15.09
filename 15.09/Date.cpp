#include "Date.h"
#include <iostream>

using namespace std;

Date::Date()
{
    setYear(0);
    setMonth(1);
    setDay(1);
}

Date::Date(int y, int m, int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

int Date::getYear()const
{
    return year;
}

int Date::getMonth()const
{
    return month;
}

int Date::getDay()const
{
    return day;
}

void Date::setYear(int y)
{
    year = (y <= 0) ? 0 : y;
}

void Date::setMonth(int m)
{
    while (true)
    {
        if (m > 12)
        {
            setYear(year + 1);
            m -= 12;
        }
        else if (m <= 0)
        {
            setYear(year - 1);
            m += 12;
        }
        else
        {
            month = m;
            return;
        }
    }
}

int Date::getMaxDay()
{
    if (getMonth() == 2)
    {
        return (getYear() % 4 == 0) ? 29 : 28;
    }
    else if (getMonth() >= 8)
    {
        return (getMonth() % 2 == 0) ? 31 : 30;
    }
    else
    {
        return !(getMonth() % 2 == 0) ? 31 : 30;
    }
}

void Date::setDay(int d)
{
    //if (getMonth() == 2)
    //{
    //    day = (d >= (getYear() % 4 == 0) ? 29 : 28) ? ((getYear() % 4 == 0) ? 29 : 28) : (d <= 1) ? 1 : d;
    //}
    //else if(getMonth() >= 8)
    //{
    //    day = (getMonth() % 2 == 0) ? ((d >= 31) ? 31 : (d <= 1) ? 1 : d) : ((d >= 30) ? 30 : (d <= 1) ? 1 : d);
    //}
    //else
    //{
    //    day = !(getMonth() % 2 == 0) ? ((d >= 31) ? 31 : (d <= 1) ? 1 : d) : ((d >= 30) ? 30 : (d <= 1) ? 1 : d);
    //}
    while (true)
    {
        if (d > getMaxDay())
        {
            d -= getMaxDay();
            setMonth(month + 1);
        }
        else if (d <= 0)
        {
            setMonth(month - 1);
            d += getMaxDay();
        }
        else
        {
            day = d;
            return;
        }
    }
}

void Date::print()const
{
    cout << getYear() << "." << getMonth() << "." << getDay();
}

Date& Date::operator++()
{
    setDay(day + 1);
    return *this;
}

Date& Date::operator--()
{
    setDay(day - 1);
    return *this;
}

Date Date::operator++(int)
{
    Date temp(year, month, day);
    setDay(day + 1);
    return temp;
}

Date Date::operator--(int)
{
    Date temp(year, month, day);
    setDay(day - 1);
    return temp;
}

Date Date::operator+(int a)
{
    Date temp(year, month, day);
    temp.setDay(day + a);
    return temp;
}

Date Date::operator-(int a)
{
    Date temp(year, month, day);
    temp.setDay(day - a);
    return temp;
}

Date Date::operator+(Date a)
{
    Date temp(year, month, day);
    temp.setYear(temp.getYear() + a.getYear());
    temp.setMonth(temp.getMonth() + a.getMonth());
    temp.setDay(temp.getDay() + a.getDay());
    return temp;
}

Date Date::operator-(Date a)
{
    Date temp(year, month, day);
    temp.setYear(temp.getYear() - a.getYear());
    temp.setMonth(temp.getMonth() - a.getMonth());
    temp.setDay(temp.getDay() - a.getDay());
    return temp;
}

Date& Date::operator+=(int a)
{
    setDay(day + a);
    return *this;
}

Date& Date::operator-=(int a)
{   
    setDay(day - a);
    return *this;
}

Date& Date::operator+=(Date a)
{
    setYear(getYear() + a.getYear());
    setMonth(getMonth() + a.getMonth());
    setDay(getDay() + a.getDay());
    return *this;
}

Date& Date::operator-=(Date a)
{
    setYear(getYear() - a.getYear());
    setMonth(getMonth() - a.getMonth());
    setDay(getDay() - a.getDay());
    return *this;
}

bool Date::operator<(Date a)
{
    return(getDay() < a.getDay() || getMonth() < a.getMonth() || getYear() < a.getYear());
}

bool Date::operator>(Date a)
{
    return(getDay() > a.getDay() || getMonth() > a.getMonth() || getYear() > a.getYear());
}

bool Date::operator==(Date a)
{
    return(getDay() == a.getDay() && getMonth() == a.getMonth() && getYear() == a.getYear());
}

bool Date::operator<=(Date a)
{
    return((getDay() < a.getDay() || getMonth() < a.getMonth() || getYear() < a.getYear()) || *this == a);
}

bool Date::operator>=(Date a)
{
    return((getDay() > a.getDay() || getMonth() > a.getMonth() || getYear() > a.getYear()) || *this == a);
}

bool Date::operator!=(Date a)
{
    return !(*this == a);
}



