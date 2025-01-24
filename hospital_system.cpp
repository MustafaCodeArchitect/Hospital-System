/*
███╗░░░███╗██╗░░░██╗░██████╗████████╗░█████╗░███████╗░█████╗░
████╗░████║██║░░░██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝██╔══██╗
██╔████╔██║██║░░░██║╚█████╗░░░░██║░░░███████║█████╗░░███████║
██║╚██╔╝██║██║░░░██║░╚═══██╗░░░██║░░░██╔══██║██╔══╝░░██╔══██║
██║░╚═╝░██║╚██████╔╝██████╔╝░░░██║░░░██║░░██║██║░░░░░██║░░██║
╚═╝░░░░░╚═╝░╚═════╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝
*/
#include<iostream>
using namespace std;

	const int Specialization = 20;
	const int Max_queue = 5;

	string names[Specialization+1][Max_queue];
	int status[Specialization+1][Max_queue];
	int Len_queue[Specialization+1];

	int menu()
	{
		int choice = -1;
		while(choice == -1) 
		{
			cout << "\nEnter Your Choice\n";
			cout << "1) Add A New Patient\n";
			cout << "2) Print All Patients\n";
			cout << "3) Get Next Patient\n";
			cout << "4) Exit\n";

			cin >> choice;
			if(!(choice >= 1 && choice <=4)) {
				cout << "Invalid Choice, Try Again\n";
				choice = -1;
			}

		}
		return choice;
	}

	// Move each patient to the left. E.g if patient in position 5, it will be in 4
	// Help in removing patient
	void shift_left(int spec, string names_sp[], int status_sp[]) 
	{
		int Len = Len_queue[spec];
		for(int i = 1; i < Len; ++i) 
		{
			names_sp[i-1] = names_sp[i];
			status_sp[i-1] = status_sp[i];
		}
		Len_queue[spec]--;
	}

	// Move each patient to the right. E.g if patient in position 5, it will be in 6
	// Help in adding patient
	void shift_right(int spec, string names_sp[], int status_sp[])
	{
		int len = Len_queue[spec];
		for(int i = len-1; i >= 0; --i) {
			names_sp[i+1] = names_sp[i];
			status_sp[i+1] = status_sp[i];
		}
		Len_queue[spec]++;
	}

	bool Add_Patient() {
		int spec;
		string name;
		int st;
		cout << "Enter Specialization, Name, Status: ";
		cin >> spec >> name >> st;

		int pos = Len_queue[spec];
		if(pos >= Max_queue) {
			cout << "Sorry We Can't Add More Patients For This Specialization\n";
			return false;
		}

		else{
			if(st == 0) // regular add
			{
				names[spec][pos] = name;
				status[spec][pos] = st;
				Len_queue[spec]++;
			}

			else{ 
				// urgent, add to begin. Shift, then add
				shift_right(spec, names[spec],status[spec]);
				names[spec][0] = name;
				status[spec][0] = st;
			}
		}
		return true;
	}
	
	void Print_Patient(int spec, string names_sp[], int status_sp[])
	{
		int Len = Len_queue[spec];
		if(Len == 0) 
			return;
		
		
		cout << "There are " << Len << " patients in specialization " << spec << "\n";
		for(int i = 0; i < Len; ++i) {
			cout << names_sp[i] << " ";
			if(status_sp[i])
				cout << "Urgent\n";
			else
				cout << "Regular\n";
		}
		cout << "\n";
	}
	
	void Print_All_Patients()
	{
		cout << "********************\n";
		for(int i = 0; i <Specialization; ++i) 
			Print_Patient(i, names[i], status[i]);
	}

	void Get_Next_Patient() {
		int Spec;
		cout << "Enter Specialization: ";
		cin >> Spec;

		int Len = Len_queue[Spec];
		if(Len == 0) {
			cout<<"No patients at the moment. Have rest, Dr\n";
			return;
		}

		// Let patient goes to dr
		cout << names[Spec][0] << " Please go With the dr\n";

		// delete the patient in position 0
		shift_left(Spec, names[Spec], status[Spec]);

	}
	void Hospital_system() {
		while(true) 
		{
		int choice = menu();
			if(choice == 1)
				Add_Patient();
			else if(choice == 2)
				Print_All_Patients();
			else if(choice == 3)
				Get_Next_Patient();
			else
			{
				cout << "Ok\n";
				break;
			}
		}
	}

	int main() {
		Hospital_system();
		return 0;
	}
	