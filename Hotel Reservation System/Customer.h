#ifndef H_Customer
#define H_Customer
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "Room.h"
using namespace std;
class customer:protected room
{
protected:
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_indate;
	char roomtype[20];
	char custm_name[30];
	char custm_occupation[20];
//Bills
	float total;
	int food;
	float ser;
	int t;
	int oc;
	int r_day;


public:
	int compare(char[]);
	void getdata();
	void putdata();
	void welcomescreen();
	void login_screen();
	void add_customer();
	void delete_customer();
	void update_customer();
	void search_customer();
	void main_screen();
	void display_customer(string);
	void checkout_customer();
	void generate_bill();
};
#endif