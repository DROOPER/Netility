#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
using namespace std;


void initializationmessage() //------------------| MENU FUNCTION |------------------
{
	cout << "*********************  Netility Script *********************" << endl;
	cout << "                          Created By DROOPER" << endl << endl;
	cout << "Tools list:" << endl;
	cout << "1.Check website availability" << endl;
	cout << "2.Check network interfaces" << endl;
	cout << "3.Check my public IP address" << endl;
	cout << "4.Check IP type" << endl;
	cout << "Choose an option: ";
}


void execute(string cmd)  //--------| FUNCTION THAT EXECUTES AND REDIRECTS THE OUTPUT TO FILE |----------
{
	system((cmd + " > " + "results.txt").c_str());

}


void removefile() //---------| FUNCTION THAT DELETES THE OUTPUT FILE |----------
{
	system("del results.txt");

}

void isonline(string &s) //----------------------| CHECKING IF A WEBSITE IS ONLINE |------------------
{
	int k = 0;
	char c[500];
	string ss = "ping " + s + " -n 1";
	execute(ss);
	
	ifstream file("results.txt");
	while (!file.eof())
	{
		file.getline(c, 500);
		if ((c[0] == 'R') && (c[1] == 'e') && (c[2] == 'p') && (c[3] == 'l') && (c[4] == 'y')) { k = 1; break; }
	}
	switch (k)
	{
	case 0: cout<< s << " is offline";
		break;
	case 1: cout << s << " is online";
		break;

	}
	file.close();
	removefile();
}


void netinterfaces() //-----------------| CHECKING NETWORK AVAIBLE INTERFACES |-------------------- 
{
	char c[999]; int k;
	execute("netsh interface show interface");
	
	
	Sleep(999);
	ifstream file("results.txt");
	while (!file.eof())
	{

		file.getline(c, 998);
		k = strlen(c);
		for (int i = 0; i<k; i++)
		{

			cout << c[i];
		}

		cout << endl;

	}

	file.close();
	removefile();

}


void publicip()//------------------| CHECKING PUBLIC IP ADDRESS |----------------------
{
	int k = 0,x; char c[999];

	execute("nslookup myip.opendns.com resolver1.opendns.com");
	system("cls");
	cout << "Public IP Address: ";

	ifstream file("results.txt");
	while (!file.eof())
	{   
		file.getline(c, 999);
		x = strlen(c);
		
	     if (k == 1)
		{
			k = 0;
			for (int i = 0; i < x; i++)
			{
				if ((isdigit(c[i])) || (c[i] == '.')) { cout << c[i]; }

			}
		}
		else if (k == 0)
		{
			for (int i = 0; i < x; i++)
			{
				if ((c[i]=='m')&&(c[i+1]=='y')) { k = 1; }
			}
		}
		
    
	}
	file.close();
	removefile();


}


void iptype() //-----------------------------| CHECKING IP ADDRESS TYPE (DYNAMIC OR STATIC) |-----------------
{
	char c[401], cc[401]; int x, l = 0, xx;
	execute("ipconfig /all");


	ifstream file("results.txt");

	while (!file.eof())
	{
		if (l == 1)
		{
			for (int i = 32; i < x; i++)
			{
				if ((c[i] == 'Y')) { cout << "You have a Dynamic IP Address"; break; }
				else if ((c[i] == 'N') && (c[i + 1] == 'o')) { cout << "You have a Static IP Address"; break; }


			}
			break;
		}

		l = 0;
		file.getline(c, 400);
		if ((c[3] == 'D') && (c[4] == 'H') && (c[5] == 'C') && (c[6] == 'P') && (c[8] == 'E'))
		{
			x = strlen(c);
			while (l == 0)
			{
				file.getline(cc, 400);
				if ((cc[3] == 'P') && (cc[4] == 'h') && (cc[5] == 'y') && (cc[6] == 's') && (cc[7] == 'i')) { break; }
				if ((cc[3] == 'D') && (cc[4] == 'e') && (cc[5] == 'f') && (cc[11] == 'G'))
				{
					xx = strlen(cc);
					if (cc[xx - 1] == '1') { l = 1; break; }
					else break;
				}

			}

		}

	}

	file.close();
	removefile();

}



int main() //---------------| MAIN FUNCTION |------------------
{   

	int n,x,e=1; string s;
	while (e == 1)
	{
		initializationmessage();
		cin >> n;
		switch (n)
		{
		case 1: cout << endl; system("cls"); cout << "Enter website: "; cin >> s; isonline(s);
			break;
		case 2: system("cls"); netinterfaces();
			break;
		case 3: publicip();
			break;
		case 4: system("cls"); iptype();
			break;
		}
		cout << endl;

		cout << endl << endl;
		cout << "1.Return" << endl;
		cout << "2.Exit" << endl;
		cout << "Choose an option:"; cin >> e;
		system("cls");

	}

	return 0;
}
