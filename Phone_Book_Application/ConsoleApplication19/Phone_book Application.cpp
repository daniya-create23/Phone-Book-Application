#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;

class phonebook
{
public:
	//defining strings
	std::string first_name[250];
	std::string last_name[250];
	std::string gender[250];
	std::string father_fname[250];
	std::string father_sname[250];
	std::string full_namee[250];
	std::string phone_number[250];
	std::string relation[250];
	std::string address[250];
	std::string e_mail[250];
	int options()
	{//function definition which shows the options of the phonebook and asks the user for his choice

		int a;
		cout << "Welcome to PhoneBook Applictaion!" << endl;
		cout << "Please select your desired option:" << endl;
		cout << "1.Add contact" << endl;
		cout << "2.List" << endl;
		cout << "3.Update contact" << endl;
		cout << "4.Search contact" << endl;
		cout << "5.Delecte contact" << endl;
		cout << "6.Exit Phonebook" << endl;
		cout << "Your option..:  ";
		cin >> a;
		if (a >= 1 && a <= 6)
		{
			return a;
		}
		else
		{

			return 0;
		}

	}
	friend class choosing; //friend function allows class choosing to opt the variables of class phonebook
};
class choosing : public phonebook
{
public:
	int s;
	void add_contacts()
	{//member function contacts is used to add new contacts in the phonebook.
		system("cls");//clears the screen
		cout << "To Add A New Contact In The PhoneBook Please Fill In The Following Following Information..." << endl;
		cout << "How many contacts do you want to add? :";
		cin >> s;
		for (int i = 1; i <= s; i++)//for loop for string arrays
		{//user enters the information asked 
			cout << "Contact No." << i << endl;
			cout << "Enter Your First Name:";
			cin.ignore();
			getline(cin, first_name[i]);
			cout << "Enter Your Last Name:";
			getline(cin, last_name[i]);
			cout << "Enter Your Father's First Name:";
			cin >> father_fname[i];
			cout << "Enter Your Father's Second Name:";
			cin >> father_sname[i];
			cout << "Enter Your Gender:";
			cin >> gender[i];
			cout << "Enter Your Phone Number:";
			cin >> phone_number[i];
			cout << "Enter Your E-Mail Address:";
			cin >> e_mail[i];
			cout << "Enter Your Address:";
			cin >> address[i];
			cout << "Enter Your Realtion:";
			cin >> relation[i];


		}

		cout << "Your Contacts Has Been Added In The PhoneBook!" << endl;

	}friend class lol;//friend function allows class lol to opt memberfunctions and strings of class choosing 
};
class lol
{
	choosing x;//object declaration
public:
	void list()
	{//member function list is used to list the contacts which are available in the phonebook
		int j = 1;
		cout << "Please add contacts first.." << endl;
		Sleep(2000);
		x.add_contacts();//function calling using object function in order for the user to add contacts in the phonebook
		Sleep(1500);
		system("cls");//clears the screen
		cout << "The List of Contacts In Your PhoneBook are..." << endl;
		while (j <= x.s)//while loop until the number of contacts added by the user finishes
		{//displays the contact list
			cout << "Contact No." << j << ".." << endl;
			cout << "Name: " << x.first_name[j] << " " << x.last_name[j] << endl;
			cout << "Father's Name: " << x.father_fname[j] << " " << x.father_sname[j] << endl;
			cout << "Gender: " << x.gender[j] << endl;
			cout << "Phone Number: " << x.phone_number[j] << endl;
			cout << "E-Mail Address: " << x.e_mail[j] << endl;
			cout << "Address: " << x.address[j] << endl;
			cout << "Relation: " << x.relation[j] << endl;
			j++;
		}
	}
	void search()
	{//member function used to search for any contact needed by the user
		cout << "Please add contacts first.." << endl;
		Sleep(2000);
		x.add_contacts();//function calling using object function in order for the user to add contacts in the phonebook
		Sleep(1500);
		system("cls");//clears the screen
		int b;

		cout << "Searching For A Specific Contact.." << endl;
		cout << "How Many Contacts Do You Want To Search For? ";
		cin >> b;//user enters the number of contacts he wants to search
		if (b <= x.s)//condition for the number of contacts searched and number of contacts available in the phonebook
		{
			for (int k = 1; k <= b; k++)//for loop for string arrays
			{

				cout << "Contact No." << k << endl;
				//user enters the required information
				std::string fname, sname, full_name;
				cout << "Enter the First Name:";
				cin >> fname;
				cout << "Enter The Last Name:";
				cin >> sname;
				std::string num;
				cout << "Enter The Phone Number:";
				cin.ignore();
				getline(cin, num);
				if (num == x.phone_number[k] && fname == x.first_name[k] && sname == x.last_name[k])
				{//if the ober information is right then the folloing code lines are executed
					cout << "" << endl;
					cout << "Following Are The Details Of The Contact.." << endl;
					cout << "Name: " << x.first_name[k] << " " << x.last_name[k] << endl;
					cout << "Father's Name: " << x.father_fname[k] << " " << x.father_sname[k] << endl;
					cout << "Gender: " << x.gender[k] << endl;
					cout << "Phone Number: " << x.phone_number[k] << endl;
					cout << "E-Mail Address: " << x.e_mail[k] << endl;
					cout << "Address: " << x.address[k] << endl;
					cout << "Relation: " << x.relation[k] << endl;
				}
				else
				{//condtion false cause the necxt command line to be executed
					cout << "" << endl;
					cout << "No Contact Of Such Name And Number Are Present In Your PhoneBook" << endl;

				}
			}

		}
		else
		{//when the number of contacts searched are more than availble in the phonebook
			cout << "Not Enough Contacts In Your PhoneBook" << endl;
		}
	}

	void update()
	{//member function used when the user wants to modify the deatials of contact in the phonebook
		cout << "Please add contacts first.." << endl;
		Sleep(2000);
		x.add_contacts();//function calling using object function in order for the user to add contacts in the phonebook
		Sleep(1500);
		system("cls");//clears the screen

		cout << "Enter The Number Of Contacts Your Want To Modify: ";
		cout << "" << endl;
		int h;
		cin >> h;//user enters the number of contacts he wants to modify
		if (h <= x.s)//condition for the number of contacts entered by the user and number of contacts available in the phonebook
		{
			for (int l = 1; l <= x.s; h++)//for loop for string arrays
			{//user enters the required information
				cout << "For Modifying A Specific Contact.." << endl;
				cout << "Enter The First Name Of The Contact You Want To Modify: ";
				std::string fName;
				cin >> fName;
				cout << "Enter The Last Name Of The Contact You Want To Modify: ";
				string sName;
				cin.ignore();
				getline(cin, sName);
				if (fName == x.first_name[l] && sName == x.last_name[l])
				{//if the ober information is right then the folloing code lines are executed
					int p;
					cout << "Which Information Do You Want To Change?.. " << endl;
					cout << "" << endl;
					cout << "Enter 1 for First Name" << endl;
					cout << "Enter 2 for Last Name" << endl;
					cout << "Enter 3 for Father's First Name" << endl;
					cout << "Enter 4 for Father's Last Name" << endl;
					cout << "Enter 5 for Gender" << endl;
					cout << "Enter 6 for Phone Number" << endl;
					cout << "Enter 7 for Email" << endl;
					cout << "Enter 8 for Address" << endl;
					cout << "Enter 9 for Relation" << endl;
					cout << "" << endl;
					cout << "Your Option: ";
					cin >> p;//user enters the option he wants to modify
					if (p == 1)
					{
						cout << "" << endl;
						cout << "Enter the Modified First Name: ";
						string n;
						cin >> n;
						x.first_name[l] = n;
					}
					if (p == 2)
					{
						cout << "Enter The Modified Second Name: ";
						string m;
						cin >> m;
						x.last_name[l] = m;
					}
					if (p == 3)
					{
						cout << "Enter The Modified Father's First Name: ";
						string q;
						cin >> q;
						x.father_fname[l] = q;
					}
					if (p == 4)
					{
						cout << "Enter The Modified Father's Last Name: ";
						string w;
						cin >> w;
						x.father_sname[l] = w;
					}
					if (p == 5)
					{
						cout << "Enter The Modified Gender: ";
						string e;
						cin >> e;
						x.gender[l] = e;
					}
					if (p == 6)
					{
						cout << "Enter The Modified Phone Number: ";
						string r;
						cin >> r;
						x.phone_number[l] = r;
					}
					if (p == 7)
					{
						cout << "Enter The Modified E-mail: ";
						string t;
						cin >> t;
						x.e_mail[l] = t;
					}
					if (p == 8)
					{
						cout << "Enter The Modified Address: ";
						string o;
						cin >> o;
						x.address[l] = o;
					}
					if (p == 9)
					{
						cout << "Enter The Modified Relation: ";
						string h;
						cin >> h;
						x.relation[l] = h;
					}
					system("cls");//clears the screen
								  //following modified results are displayed
					cout << "The Modified deatils Of Your Contact Are.... " << endl;
					cout << "Name: " << x.first_name[l] << " " << x.last_name[l] << endl;
					cout << "Father's Name: " << x.father_fname[l] << " " << x.father_sname[l] << endl;
					cout << "Gender: " << x.gender[l] << endl;
					cout << "Phone Number: " << x.phone_number[l] << endl;
					cout << "E-Mail Address: " << x.e_mail[l] << endl;
					cout << "Address: " << x.address[l] << endl;
					cout << "Relation: " << x.relation[l] << endl;
				}
				else
				{//condtion false cause the necxt command line to be executed
					cout << "" << endl;
					cout << "No Contact Of Such Name Is Present In Your PhoneBook" << endl;
				}
				l++;

			}


		}
		else
		{//when the number of contacts searched are more than availble in the phonebook
			cout << "Not Enough Contacts In Your PhoneBook" << endl;
		}


	}
	void del()
	{//member function used to delete the contacts needed by the user
		cout << "Please add contacts first.." << endl;
		Sleep(2000);
		x.add_contacts();//function calling using object function in order for the user to add contacts in the phonebook
		Sleep(1500);
		system("cls");//clears the screen

		cout << "For Deleting A Contact " << endl;
		cout << "Enter the Number Of Contacts Your want To Delete: ";
		int g;
		cin >> g;//user enters the number of contacts he wants to delete
		cout << "" << endl;

		if (g <= x.s)//condition for the number of contacts entered by the user and number of contacts available in the phonebook
		{
			for (int u = 1; u <= x.s; u++)//for lopp for string aarrays
			{//user entrs the desired information
				cout << "Enter The First Name Of The Contact You Want To Delete: ";
				string fnaame;
				cin >> fnaame;
				string *d;
				d = &fnaame;
				cout << "Enter The Last Name Of The Contact You Want To Delete: ";
				string snaame;
				cin >> snaame;
				string *v;
				v = &snaame;
				if (fnaame == x.first_name[u] && snaame == x.last_name[u])
				{//if the ober information is right then the folloing code lines are executed
					cout << "" << endl;
					cout << "Following Are The Details Of The Contact Before Deleting.." << endl;
					cout << "Name: " << x.first_name[u] << " " << x.last_name[u] << endl;
					cout << "Father's Name: " << x.father_fname[u] << " " << x.father_sname[u] << endl;
					cout << "Gender: " << x.gender[u] << endl;
					cout << "Phone Number: " << x.phone_number[u] << endl;
					cout << "E-Mail Address: " << x.e_mail[u] << endl;
					cout << "Address: " << x.address[u] << endl;
					cout << "Relation: " << x.relation[u] << endl;
					cout << "" << endl;
					Sleep(2000);
					cout << "THIS CONTACT WILL BE DELETED!" << endl;
					cout << "" << endl;
					Sleep(2000);
					//following function is used to erase the string informations
					(x.first_name[u]).clear();
					(x.last_name[u]).clear();
					(x.father_fname[u]).clear();
					(x.father_sname[u]).clear();
					(x.gender[u]).clear();
					(x.phone_number[u]).clear();
					(x.e_mail[u]).clear();
					(x.address[u]).clear();
					(x.relation[u]).clear();
					//deleted contact details are viewed
					cout << "Following Are The Details Of The Deleted Contact.." << endl;
					cout << "Name: " << x.first_name[u] << " " << x.last_name[u] << endl;
					cout << "Father's Name: " << x.father_fname[u] << " " << x.father_sname[u] << endl;
					cout << "Gender: " << x.gender[u] << endl;
					cout << "Phone Number: " << x.phone_number[u] << endl;
					cout << "E-Mail Address: " << x.e_mail[u] << endl;
					cout << "Address: " << x.address[u] << endl;
					cout << "Relation: " << x.relation[u] << endl;
					system("pause");
				}
				else
				{//condtion false cause the necxt command line to be executed
					cout << "" << endl;
					cout << "No Contact Of Such Name Is Present In Your PhoneBook" << endl;
				}
				u++;
			}

		}
		else
		{//when the number of contacts searched are more than availble in the phonebook
			cout << "Not Enough Contacts In Your PhoneBook" << endl;
		}



	}

	void decision(int z, choosing obj2, lol obj3)
	{//member function decion for calling out the member functions desired to the option chosen by the user
		if (z >= 1 && z <= 6)//only options available are 6
		{//if the user enters the integer in between 1 and 6 the followin line of codes are executed
			if (z == 1)
			{
				obj2.add_contacts();//calling of memeber function in class choosing if the user enters 1

			}
			else if (z == 2)
			{
				obj3.list();//calling of memeber function in class lol if the user enters 2

			}
			else if (z == 3)
			{
				obj3.update();//calling of memeber function in class lol if the user enters 3

			}
			else if (z == 4)
			{
				obj3.search();//calling of memeber function in class lol if the user enters 4

			}
			else if (z == 5)//calling of memeber function in class lol if the user enters 5
			{
				obj3.del();
			}
			else if (z == 6)//exiting the phonebook
			{
				cout << "Exiting Phonebook..." << endl;
				Sleep(800);
				cout << "THANK YOU!" << endl;
			}

		}
		else
		{//if the user enter any other nuumber than in between 1 and 6 the following line of command is executed
			cout << "Invlide Input!" << endl;
		}
	}
};

int main()
{//main function
	phonebook obj1;//declaring an object of class phonebook
	int x = obj1.options();//declaring the value returned by the member function "options" when called
	choosing obj2;//declaring an object of class choosing
	lol obj3;//declaring an object of class clol
	obj3.decision(x, obj2, obj3);//member function "decision" is called using object
}








