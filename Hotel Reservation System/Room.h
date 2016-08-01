#ifndef H_Room
#define H_Room
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
using namespace std;
class room
{
	public:
	char roomtype[20];
	int room_charge;
	//Bills
	long roombill;

public:
	void room_detail();
	void room_bill();
};
#endif