#pragma once

#include <iostream>

class Date
{
private:
	unsigned short year;
	unsigned short mounth : 4;
	unsigned short day : 5;

public:
	Date(const Date& pOther) : year(pOther.year), mounth(pOther.mounth), day(pOther.day) {};
	Date(short pDay, short pMounth, short pYear) : day(1), mounth(1), year(1)
	{ setYear(pYear); setMounth(pMounth); setDay(pDay);};

	bool isLeapYear() const { return Date::LeapYear(year); };

	int getDay() const { return day; }
	int getMounth() const { return mounth; }
	int getYear() const { return year; }

	void setDay(short pDay);
	void setMounth(short pMounth);
	void setYear(short pYear);

	void operator-=(int pDays);
	void operator+=(int pDays);

	const Date operator-(int pDays);
	const Date operator+(int pDays);

	int operator-(const Date& other);

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;

	const Date& operator++();
	const Date operator++(int);

	const Date& operator--();
	const Date operator--(int);

	unsigned int toDays() const;

	int differenceInDays(const Date& other) const;
	void print() const;

	static int getMounthDaysNumber(int pMount, int pYear);
	static bool LeapYear(int pYear) { return (pYear % 4 == 0 && pYear % 100 != 0) || (pYear % 400 == 0); };
};

