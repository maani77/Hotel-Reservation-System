// Hotel Reservation System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "Implementation.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	customer view;
	view.welcomescreen();
	view.login_screen();
	return 0;
}

