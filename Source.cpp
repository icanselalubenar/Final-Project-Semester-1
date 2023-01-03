#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

int duration, price;

struct laundryAcc {
	string name, phone, address;
};

void topBar();
void selectDuration(int selectDuration);

int main()
{
	vector<laundryAcc> ld;

	while (true) {
		string selectMenu, selectType;
		topBar();

		menu:
		cout << "[1] ADD NEW CUSTOMER" << endl;
		cout << "[2] LOGIN CUSTOMER" << endl;
		cout << "[3] EXIT" << endl << endl;
		cout << "SELECT : ";
		getline(cin, selectMenu);

		switch (selectMenu[0])
		{
			case '1':
			regist:
			string in, ip, ia;
			topBar();
			cout << "NAME     : ";
			getline(cin, in);
            
            int found = ld.size();
			for (int i = 0; i < ld.size(); i++)
			{
				if (ld[i].name == in)
				{
					found = 1;
					break;
				}
			}

			if (found == ld.size())
			{
				cout << "PHONE    : ";
				getline(cin, ip);
				cout << "ADDRESS  : ";
				getline(cin, ia);
				
				ld.push_back({in, ip, ia});
			} else {
				cout << endl;
				cout << "NAME ALREADY TAKEN, PLEASE TRY AGAIN!" << endl;
				sleep(2);
				goto regist;
			}

			cout << endl;
			cout << "SUCCESS TO CREATING ACCOUNT!" << endl;
			sleep(3);
			goto menu;
			break;

			case '2':
			string loginName;
			topBar();
			cout << "NAME     : ";
			getline(cin, loginName);

            int found = ld.size();
			for (int i = 0; i < ld.size(); i++)
			{
				if (ld[i].name == loginName)
				{
					found = 1;
					break;
				}
			}

			if (found == ld.size())
			{
				cout << endl;
				cout << "NAME NOT FOUND, PLEASE TRY AGAIN!" << endl;
				sleep(2);
				goto menu;
			} else {
				cout << endl;
				cout << "LOGIN SUCCESSFULLY!" << endl;
				sleep(2);
				goto type;
			}

		}

		type:
		cout << "[1] INPUT BAGS" << endl;
		cout << "[2] INPUT BEDCOVER" << endl;
		cout << "SELECT : ";
		getline(cin, selectMenu);

		switch (selectType[0])
		{
		case '1':
			topBar();
			cout << "LAUNDRY DURATION" << endl;
			cout << "[1] REGULAR" << endl;
			cout << "[2] EXPRESS" << endl;
			cout << "[3] SUPER EXPRESS" << endl;
			cout << "[4] BACK" << endl;
			break;
		}
	}

}
void topBar() {
	system("cls");
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << "|                         AMIKOM LAUNDRY APP                          |" << endl;
	cout << "+---------------------------------------------------------------------+" << endl;
}

void selectDuration(int selectDuration) {
	if (selectDuration == 1) {
		duration = 24;
		price = 7000;
	} else if (selectDuration == 2) {
		duration = 12;
		price = 13000;
	} else if (selectDuration == 3) {
		duration = 6;
		price = 24000;
	} else {
		goto type;
	}
}