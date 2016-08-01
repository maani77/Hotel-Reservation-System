#ifndef H_Bill
#define H_Bill
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "Room.h"
using namespace std;
class bill:protected customer
{
public:
	int r_charge;
	char custm_name[25];
	int b;

public:
	void calculate();
	void display_bill();
};
#endif