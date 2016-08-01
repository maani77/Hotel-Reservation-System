#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "Customer.h"
#include "Room.h"
#include "Bill.h"

void customer::main_screen()
{
	cout << "-----------------------------\n";
	cout << "\t\tAdmin Login\n";
	cout << "-----------------------------\n";
	char username[25];
	cout << "\t\t\t\tUser Name = ";
	cin >> username;
	if (strcmp(username, "admin") == 0)
	{
		string pass = "";
		char ch;
		cout << "\n\t\t\t\tPassword  = ";
		ch = _getch();
		while (ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		if (pass == "admin")
		{
			cout << "\n\t\t" << "Access granted";
			int x;
			cout << "=================================================================\n";
			cout << "					PEARL CONTINENTAL HOTEL\n";
			cout << "=================================================================\n";
			cout << "1.Add Customer \t2.CheckOut Customer \n3.Search Customer \n4.Update Customer \t5.Delete Customer\n6.Room Details \t7.Generate Bill \n8.Exit\n";
				cin >> x;
				switch (x){
				case 1:
					add_customer();
					break;
				case 2:
					checkout_customer();
					break;
				case 3:
					search_customer();
					break;
				case 4:
					update_customer();
					break;
				case 5:
					delete_customer();
				case 6:
					room_detail();
					break;
				case 7:
					generate_bill();
					break;
				case 8:
					exit(0);
					break;
				default:
					cout << "wrong choice entered";
				}
		}
		}
		else{
			cout << "Access Denied";
			_getch();
			exit(0);
		}
	}



	void customer::getdata()
	{
		system("cls");
		cout << "Enter Customer ID\n";
		cin >> custm_id;
		exit:
		cout << "Enter Customer Name \n";
		cin >> custm_name;
		ifstream file;
		string nam;
		file.open("customer.txt", ios::in);
		string line;
		while (getline(file, line)) {
			if (line.find(custm_name) != string::npos) {
				cout <<"Name must be unique. Please ReEnter\n" << endl;
				goto exit;
			}
		}
		cout << "Enter Customer Occupation \n";
		cin >> custm_occupation;
		cout << "Enter Customer Age\n";
		cin >> custm_age;
		cout << "\nEnter customer CheckIn Date : ";
	START:
		cout << "\n--------------------------------";
		cout << "\nYear : ";
		cin >> check_inyear;
		cout << "\nMonth : ";
		cin >> check_inmonth;
		cout << "\nDate : ";
		cin >> check_indate;
		int r;
	rtype:
		cout << "\nEnter Room Type :\n1 for Super Luxury\n2 for Luxury\n3 for Delux\n ";
		cin >> r;
		if (r == 1)
			memcpy(roomtype, "Super Luxury", sizeof(roomtype));
		else if (r==2)
			memcpy(roomtype, "Luxury", sizeof(roomtype));
		else if (r == 3)
			memcpy(roomtype, "Delux", sizeof(roomtype));
		else{
			cout << "Invalid Entry Please Re-enter Room Type\n";
			goto rtype;
		}
		cout << "\nEnter Room Charge : ";
		cin >> room_charge;
		if ((check_inmonth == 2) && (check_indate>29))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((check_inmonth>12) || (check_indate>31))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((check_inmonth == 4 || check_inmonth == 6 || check_inmonth == 9 || check_inmonth == 11) && (check_indate>30))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((check_inyear % 4) != 0 && (check_inmonth == 2) && (check_indate>28))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		int q;
		Choice:
		cout << "Do you want to continue (0 for no & 1 for yes)?\n";
		cin >> q;
		if (q == 1){
			system("cls");
			main_screen();
		}
		else if (q == 0){
			cout << "Exiting to login screen\n";
			_getch();
			login_screen();
		}
		else{
			cout << "wrong choice \n";
			goto Choice;
		}
	}

	void customer::display_customer(string custm_nam)
	{
		ifstream file;
		system("cls");
		file.open("customer.txt", ios::in);
		cout << "\n\t\t\t\t    customer Detail \n";
		cout << "\t\t\t_________________________________ \n\n";
		cout << "\t\t\t\t\n Displaying " << custm_nam << "'s Data:\n ";
		string line;
		while (getline(file, line)) {
			if (line.find(custm_nam) != string::npos) {
				cout << "custm_id\tcustm_name\tcustm_age\tcustm_occupation\troomtype\tcheck_inyear\tcheck_inmonth\tcheck_indate\troom_charge\n";
				cout << line << endl;
				goto exit;
			}
		}
		cout << custm_nam << " not found" << endl;
	exit:
		_getch();
	}

void customer::welcomescreen()
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                           HOTEL RESERVATION SYSTEM  " << endl;
	cout << "  										UIIT       " << endl;
	cout << "									GROUP PROJECT          " << endl;
	cout << "                                        ON                   " << endl;
	cout << "                         Object Oriented Concepts in C++  " << endl;
	cout << "                                  (CS-729)               " << endl;
	cout << " =========================================================================== " << endl;
	cout << "                  SUBMITTED BY:					SUBMITTED TO:     " << endl;
	cout << "    AHMED REHAN, TARIQ ISMAIL & SAJID ISHAQ      SIR SAQIB MAJEED" << endl;
	cout << endl << endl;
	cout << "              Press Enter to continue...." << endl << endl << endl << endl;
	_getch();
}

void customer::login_screen()
{
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	
	cout << localtime_s(&timeinfo, &rawtime);
	system("cls");
	customer c;
	char choice;
	cout << endl << endl << endl << endl;
	cout << "                            LOGIN SCREEN\n";
	cout << "              ____________________________________________________  " << endl;
	cout << "                          1.Administrator Login\n";
	cout << "                          2.customer Login\n";
	cout << "                          3.Exit\n";
	cout << "\n\n\n";
	cout << "Enter Choice::   ";
	cin >> choice;
	switch (choice)
	{
	case'1':
		c.main_screen();
		break;
	case '2':
		search_customer();
		break;
	case'3':
		exit(0);
		break;
	default:
		cout << "wrong choice entered\n";
		_getch();
	}
}


void customer::add_customer()
{
	customer c;
	ofstream outf;
	outf.open("customer.txt", ios::out | ios::app);
	c.getdata();
	outf << c.custm_id << "\t" << c.custm_name << "\t" << c.custm_age << "\t" << c.custm_occupation << "\t" << c.roomtype << "\t" << c.check_inyear << "\t" << c.check_inmonth << "\t" << c.check_indate << "\t" << c.room_charge << "\n";
	outf.close();
	_getch();

}
void customer::update_customer(){
	string updateline;
	string line;
	int i = 0;
	ifstream sup;
	sup.open("customer.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Which Customer do you want to Update? Enter Name ";
	cin >> updateline;
	while (getline(sup, line))
	{
		if (line.find(updateline)==string::npos)
		{
			temp << line << endl;
		}
		else
			i++;
	}
	temp.close();
	sup.close();
	if (i > 0){
		remove("customer.txt");
		rename("temp.txt", "customer.txt");
		cout << endl << endl << "Please Enter full Record of the Updated Customer " << endl;
		customer x;
		cout << "Enter Customer ID\n";
		cin >> x.custm_id;
	exit:
		cout << "Enter Customer Name \n";
		cin >> x.custm_name;
		ifstream file;
		string nam;
		file.open("customer.txt", ios::in);
		string line;
		while (getline(file, line)) {
			if (line.find(x.custm_name) != string::npos) {
				cout << "Name must be unique. Please ReEnter\n" << endl;
				goto exit;
			}
		}
		cout << "Enter Customer Occupation \n";
		cin >> x.custm_occupation;
		cout << "Enter Customer Age\n";
		cin >> x.custm_age;
		cout << "\nEnter customer CheckIn Date : ";
	START:
		cout << "\n--------------------------------";
		cout << "\nYear : ";
		cin >> x.check_inyear;
		cout << "\nMonth : ";
		cin >> x.check_inmonth;
		cout << "\nDate : ";
		cin >> x.check_indate;
		int r;
	rtype:
		cout << "\nEnter Room Type :\n1 for Super Luxury\n2 for Luxury\n3 for Delux\n ";
		cin >> r;
		if (r == 1)
			memcpy(x.roomtype, "Super Luxury", sizeof(x.roomtype));
		else if (r == 2)
			memcpy(x.roomtype, "Luxury", sizeof(x.roomtype));
		else if (r == 3)
			memcpy(x.roomtype, "Delux", sizeof(x.roomtype));
		else{
			cout << "Invalid Entry Please Re-enter Room Type\n";
			goto rtype;
		}
		cout << "\nEnter Room Charge : ";
		cin >> x.room_charge;
		if ((x.check_inmonth == 2) && (x.check_indate>29))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((x.check_inmonth>12) || (x.check_indate>31))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((x.check_inmonth == 4 || x.check_inmonth == 6 || x.check_inmonth == 9 || x.check_inmonth == 11) && (x.check_indate>30))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}
		if ((x.check_inyear % 4) != 0 && (x.check_inmonth == 2) && (x.check_indate>28))
		{
			cout << "wrong input!!!\n";
			cout << "\nenter the date again....\n";
			goto START;
		}

			system("cls");
			ofstream outf;
			outf.open("customer.txt", ios::out | ios::app);
			outf << x.custm_id << "\t" << x.custm_name << "\t" << x.custm_age << "\t" << x.custm_occupation << "\t" << x.roomtype << "\t" << x.check_inyear << "\t" << x.check_inmonth << "\t" << x.check_indate << "\t" << x.room_charge << "\n";
			outf.close();
		cout << "Record updated successfully \n";
		_getch();
		main_screen();
	}
	else{
		cout << "Sorry Name Not found!";
		_getch();
		main_screen();
	}
}

void customer::search_customer()
{
	ifstream file;
	string nam;
	system("cls");
	file.open("customer.txt", ios::in);
	cout << "\n\t\t\t\t    customer Detail \n";
	cout << "\t\t\t_________________________________ \n\n";
	cout << "\t\t\t\t\n Enter name to Search: ";
	cin >> nam;
	string line;
	while (getline(file, line)) {
		if (line.find(nam) != string::npos) {
			cout << line << endl;
			goto exit;
		}
	}	
	cout << nam << " not found" << endl;
	exit:
	_getch();
	login_screen();
}



void customer::checkout_customer()
{
	system("cls");
	customer a;
	cout << "\n\t\t\t_______________________________________" << endl;
	cout << "\n\t\t\t\t  HOTEL MANAGEMENT SYSTEM " << endl;
	cout << "\n\t\t\t_______________________________________\n\n" << endl;
	cout << "\t\t\t\t  All customer Detail \n";
	cout << "Enter Customer's Name\n";
	cin >> a.custm_name;
	string c(a.custm_name);
	a.display_customer(c);
	a.generate_bill();
	_getch();
}

void room::room_detail()
{
	system("cls");
	cout << "\n\t\t\t____________________________________" << endl;
	cout << "\n\t\t\t\tHOTEL MANAGEMENT SYSTEM " << endl;
	cout << "\n\t\t\t____________________________________\n" << endl;
	cout << "\t\t\t\tAll customer Detail \n";
	cout << left << setw(10) << roomtype << left << setw(15) << room_charge << endl;
	_getch();
}

void bill::calculate()
{
	system("cls");
	bill x;
g:
	cout << "\n Enter Room type:";
	cout << "\n Select 1 for Super Luxary \n Select 2 for Luxary \n Select 3 for Delux \n";
	cin >> b;
	if (b == 1)
	{
		r_charge = 4000;
	}
	else if (b == 2)
	{
		r_charge = 3000;
	}
	else
		if (b == 3)
		{
			r_charge = 2000;
		}
		else{
			cout << "\n Wrong choice ...";
			cout << "\n ERROR: Room is not allocated.";
			cout << "\n Bill cannot be created ";
			goto g;
		}

		cout << "\n Enter the bill amount of restaurant:";
		cin >> food;
		cout << "\n Enter other charges:";
		cin >> oc;
		cout << "\n Enter customer name:";
		cin >> custm_name;
		cout << "\n Enter number of days:";
		cin >> r_day;
		roombill = r_charge * r_day;
		t = roombill + food + oc;
		ser = (0.05*t);
		total = t + ser;
		ofstream outf;
		outf.open("bill.txt", ios::out | ios::app);
		outf << custm_name << "\t" << r_charge << "\t" << food << "\t" << t << "\t" << roombill << "\t" << ser << "\t" << total << "\t" << room_charge << "\n";
		outf.close();
		_getch();
}

void bill::display_bill()
{
	system("CLS");
	cout << "\n________________________________________________________________________________";
	cout << "\n                             Pearl Continental Hotel                       ";
	cout << "\n                        ____________________________________                  ";
	cout << "\n                               Rawalpindi , Punjab.                        ";
	cout << "\n                                   Tel :- 1234567                               ";
	cout << "\n--------------------------------------------------------------------------------";
	cout << "\n      Customer name : " << custm_name;
	cout << "\n                              ";
	cout << "\n      Stayed for " << r_day << " days";
	cout << "\n      Room charges    : " << r_charge << "(Per day)";
	cout << "\n      Room charges    : " << roombill << "(total)";
	cout << "\n      Restaurant bill : " << food;
	cout << "\n      Other charges   : " << oc;
	cout << "\n                          Ser.tax % = 5%";
	cout << "\n                          Ser.tax   =" << ser;
	cout << "\n      Bill Amount >>>>>> Rs " << total;
	cout << "\n                              ";
	cout << "\n      THANK YOU !!!!!";
	cout << "\n      Visit Again !";
	_getch();
}
void customer::delete_customer(){
	string deleteline;
	string line;
	int i = 0;
	ifstream sup;
	sup.open("customer.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Which Customer do you want to remove? Enter Name ";
	cin >> deleteline;
	while (getline(sup, line))
	{
		if (line.find(deleteline)==string::npos)
		{
			temp << line << endl;
		}
		else
			i++;
	}
	temp.close();
	sup.close();
	if (i > 0){
		remove("customer.txt");
		rename("temp.txt", "customer.txt");
		cout << endl << endl << endl;
		cout << "Record deleted successfully \n";
			_getch();
		main_screen();
	}
	else{
		cout << "Sorry Name Not found!";
		_getch();
		main_screen();
	}
}


  void customer::generate_bill()
  {
	  bill b;
	  b.calculate();
	  b.display_bill();

  }
