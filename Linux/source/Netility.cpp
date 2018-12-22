#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <string.h>
#include <ctype.h>
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
	system((cmd + " >> " + "results.txt").c_str());

}


void removefile() //---------| FUNCTION THAT DELETES THE OUTPUT FILE |----------
{
	system("rm -rf results.txt");

}

void isonline(string &s) //----------------------| CHECKING IF A WEBSITE IS ONLINE |------------------
{
	int k = 0;
	char c[500];
	string ss = "ping " + s + " -c 1";
	execute(ss);
	system("clear");
	ifstream file("results.txt");
	while (!file.eof())
	{
		file.getline(c, 500);
		if ((c[3] == 'b') && (c[4] == 'y') && (c[5] == 't') && (c[6] == 'e') && (c[7] == 's')) { k = 1; break; }
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
	execute("ip link show");
	
	
	int a=0;
	ifstream file("results.txt");
	while (!file.eof())
	{

		file.getline(c, 998); a++;
		k = strlen(c);
		if (a%2!=0) for (int i = 0; i<k; i++)
		{     if ((i>=3) && (c[i]==':')) break;

			cout << c[i];
		}

		cout << " ";

	}

	file.close();
	removefile();

}


void publicip()//------------------| CHECKING PUBLIC IP ADDRESS |----------------------
{

         
	system("clear");
	cout << "Public IP Address:"<<endl;
  system("curl -s ipinfo.io/ip");

}

void iptype() //-----------------------------| CHECKING IP ADDRESS TYPE |-----------------
{
	char c[401]; int x, l = 0, xx;
	execute("ifconfig -a | grep 'DHCP'");


	ifstream file("results.txt");

file.getline(c,401);
if (c[0]=='D') cout<<"DYNAMIC IP ADDRESS";
else cout<<"STATIC IP ADDRESS";
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
		case 1: cout << endl; system("clear"); cout << "Enter website: "; cin >> s; isonline(s);
			break;
		case 2: system("clear"); netinterfaces();
			break;
		case 3: publicip();
			break;
		case 4: system("clear"); iptype();
			break;
		}
		cout << endl<<endl;

		
		cout << "1.Return" << endl;
		cout << "2.Exit" << endl;
		cout << "Choose an option:"; cin >> e;
		system("clear");

	}

	return 0;
}
