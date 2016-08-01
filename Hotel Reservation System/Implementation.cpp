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

void customer::welcomescreen()
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                           COMPUTERISED MANAGEMENT SYSTEM  " << endl;
	cout << "  	                       APIIT SD INDIA, PANIPAT       " << endl;
	cout << "                             INDIVIDUAL  ASSINGMENT         " << endl;
	cout << "                                       ON                   " << endl;
	cout << "                       Further Programming Concepts in C++  " << endl;
	cout << "                                  (CE00314-2)               " << endl;
	cout << "              ____________________________________________________  " << endl;
	cout << endl << endl << endl << endl;
	cout << "                  SUBMITTED BY:		      SUBMITTED TO:     " << endl;
	cout << "                   Prince kumar          Ms. Deepti Dhingra   " << endl;
	cout << "                   (PT082219)               (LECTURER)      " << endl;
	cout << endl << endl;
	cout << "              Press Enter to continue...." << endl << endl << endl << endl;
	getch();
}

void customer::welcomescreen()
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                           COMPUTERISED MANAGEMENT SYSTEM  " << endl;
	cout << "  	                       APIIT SD INDIA, PANIPAT       " << endl;
	cout << "                             INDIVIDUAL  ASSINGMENT         " << endl;
	cout << "                                       ON                   " << endl;
	cout << "                       Further Programming Concepts in C++  " << endl;
	cout << "                                  (CE00314-2)               " << endl;
	cout << "              ____________________________________________________  " << endl;
	cout << endl << endl << endl << endl;
	cout << "                  SUBMITTED BY:		      SUBMITTED TO:     " << endl;
	cout << "                   Prince kumar          Ms. Deepti Dhingra   " << endl;
	cout << "                   (PT082219)               (LECTURER)      " << endl;
	cout << endl << endl;
	cout << "              Press Enter to continue...." << endl << endl << endl << endl;
	getch();
}

void customer::add_customer()
{
	customer c;
	ofstream outf;
	outf.open("customer.txt", ios::out | ios::app | ios::binary);
	c.getdata();
	outf.write((char*)&c, sizeof(c));
	outf.close();
	_getch();

}

void customer::search_customer()
{
	fstream file;
	customer c;
	int i = 1;
	char nam[25];
	file.open("customer.txt", ios::in);
	cout << "\t\t\t\t    customer Detail \n";
	cout << "\t\t\t_________________________________ \n\n";
	cout << "\t\t\t\t\n Enter name to Search: ";
	cin >> nam;
	file.seekg(0, ios::beg);
	while (file.read((char *)&c, sizeof(customer)))
	{
		if (c.compare(nam))
		{
			cout << "\t\t\t\t custm_id" << "              " << "custm_name \n" << endl;
			cout << "                      " << c.custm_id << "              " << c.custm_name;
			cout << "\n\t\t\t_________________________________________ ";
			cout << "\n\t\t\t     ...Thank you for using ^_^ ... ";
			i = 0;
			break;
		}
	}
	file.close();
	if (i)
	{
		cout << "Sorry!!!! Record Not found";
	}
	getch();
}

void customer::search_customer()
{
	fstream file;
	customer c;
	int i = 1;
	char nam[25];
	file.open("customer.txt", ios::in);
	cout << "\t\t\t\t    customer Detail \n";
	cout << "\t\t\t_________________________________ \n\n";
	cout << "\t\t\t\t\n Enter name to Search: ";
	cin >> nam;
	file.seekg(0, ios::beg);
	while (file.read((char *)&c, sizeof(customer)))
	{
		if (c.compare(nam))
		{
			cout << "\t\t\t\t custm_id" << "              " << "custm_name \n" << endl;
			cout << "                      " << c.custm_id << "              " << c.custm_name;
			cout << "\n\t\t\t_________________________________________ ";
			cout << "\n\t\t\t     ...Thank you for using ^_^ ... ";
			i = 0;
			break;
		}
	}
	file.close();
	if (i)
	{
		cout << "Sorry!!!! Record Not found";
	}
	getch();
}

void customer::checkout_customer()
{
	system("cls");
	cout << "\n\t\t\t_______________________________________" << endl;
	cout << "\n\t\t\t\t  HOTEL MANAGEMENT SYSTEM " << endl;
	cout << "\n\t\t\t_______________________________________\n\n" << endl;
	cout << "\t\t\t\t  All customer Detail \n";
}

void room::room_detail()
{

	system("cls");
	cout << "\n\t\t\t____________________________________" << endl;
	cout << "\n\t\t\t\tHOTEL MANAGEMENT SYSTEM " << endl;
	cout << "\n\t\t\t____________________________________\n" << endl;
	cout << "\t\t\t\tAll customer Detail \n";
	cout << left << setw(10) << "roomtype" << left << setw(15) << "room_charge" << endl;
}

void bill::calculate()
{
	system("cls");

	cout << "\n Enter Room type:";
	cout << "\n Select 1 for Super Luxary \n Select 2 for Luxary \n Select 3 for Delux \n";
	cin >> b;
	if (b = 1)
	{
		r_charge = 4000;
	}
	else
		if (b = 2)
		{
			r_charge = 3000;
		}
		else
			if (b = 3)
			{
				r_charge = 2000;
			}
			else{
				cout << "\n Wrong choice ...";
				cout << "\n ERROR: Room is not allocated.";
				cout << "\n Bill cannot be created ";
			}

			cout << "\n Enter the bill amount of restaurant:";
			cin >> food;
			cout << "\n Enter other charges:";
			cin >> oc;
			cout << "\n Enter customer name:";
			cin >> custm_name;
			cout << "\n Enter number of days:";
			cin >> r_day;
			room = r_charge * r_day;
			t = (int)room + food + oc;
			ser = (int)(0.05*t);
			total = t + ser;
}

void bill::display_bill()
{
	system("CLS");
	cout << "\n________________________________________________________________________________";
	cout << "\n                              Marriott Luxury Hotel                       ";
	cout << "\n                        ____________________________________                  ";
	cout << "\n                               Chandigarh , Punjab-070.                        ";
	cout << "\n                                   Tel :- 12253636                               ";
	cout << "\n--------------------------------------------------------------------------------";
	cout << "\n      Customer name : " << custm_name;
	cout << "\n                              ";
	cout << "\n      Stayed for " << r_day << " days";
	cout << "\n      Room charges    : " << r_charge << "(Per day)";
	cout << "\n      Room charges    : " << room << "(total)";
	cout << "\n      Restaurant bill : " << food;
	cout << "\n      Other charges   : " << oc;
	cout << "\n                          Ser.tax % = 5%";
	cout << "\n                          Ser.tax   =" << ser;
	cout << "\n      Bill Amount >>>>>> Rs " << total;
	cout << "\n                              ";
	cout << "\n      THANK YOU !!!!!";
	cout << "\n      Visit Again !";
}



  void customer::generate_bill()
  {
	  Generatebill b;
	  b.calculate();
	  b.display_bill();

  }
