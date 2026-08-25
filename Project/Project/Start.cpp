#include <iostream>
#include <string>
#include "service.h"
#include "client.h"
#include "parc.h"
#include "vacationpark.h"
#include "hotelroom.h"
#include "accommodation.h"
#include "cabin.h"
#include <vector>
#include <iomanip>
#include <fstream>
#define MAX_LENGTH 30
using namespace std;
int choicemaker(string, vector<Client>*, vector<Client>, vector<Parc>*, vector<Parc>, vector<VacationPark>*, vector<Accommodation>*, vector<Accommodation*>&, Client*);
int createClient(vector<Client>*);
int modifyClient(vector<Client>*);
int deleteClient(vector<Client>*);
void changeClientInfo(vector<Client>*, Client*);
void writeOut(vector<Client>, ofstream&);
int createPark(vector<Parc>*, vector<VacationPark>*);
void modifyPark(vector<Parc>*, vector<VacationPark>*, vector<Accommodation*>*);
int createVacationPark(vector<Parc>, vector<Client>, vector<VacationPark>*);
void createAccommodation(vector<Accommodation*>*);
//void showIt(Accommodation*);
void searchAccommodation(vector<Accommodation*>*);
void deleteAccommodation(vector<Accommodation*>*);
void modifyAccommodation(vector<Accommodation*>*);
int id = 0;
int main(void) {
	int choice = 1000;
	int loggedIn = 0;
	string accountInput;
	string account;
	string accountName;
	string binString;
	Client tempLoggedInClient;
	vector<Client> clients;
	vector<VacationPark> vacationParks;
	vector<Parc> parcs;
	vector<Accommodation> accommodations;
	vector<Accommodation*> accommodations2;
	
	

	//test data
	Client testclient1("Ben", "Van Damme", "SKW 2860", "ben@hotmail.com");
	Client testclient2("Jan", "Vetonghen", "Mechelen 2800", "jan@hotmail.com");
	Client testclient3("Swakke", "Jannsens", "Antwerpen 2000", "swakke@hotmail.com");
	VacationPark vacpark("bennys", "skw", "8464", parcs, clients);
	vacationParks.push_back(vacpark);
	
	clients.push_back(testclient1);
	clients.push_back(testclient2);
	clients.push_back(testclient3);
	Luxury luxuryLevel1;
	Hotelroom room1(luxuryLevel1, 5, "front", 2, false);
	
	Hotelroom* hotel1 = new Hotelroom(luxuryLevel1);
	Hotelroom* hotel2 = new Hotelroom(luxuryLevel1);
	accommodations2.push_back(hotel1);
	accommodations2.push_back(hotel2);

	/*Service tempservice;
	Parc tempparc("skw", "skw", tempservice, accommodations2);
	vacationParks.at(0).addParc(tempparc);*/
	

	int vecSize = clients.size();


	while (true)
	{
		ofstream inFile("clients.txt", ios::out);
		writeOut(clients, inFile);
		/*when not logged in*/
		while (loggedIn == 0)
		{
			/*ask to login*/
			cout << "give Login: ";
			cin >> accountInput;
			if (accountInput == "employee")
			{
				account = "employee";
				loggedIn = 1;
			}
			if (accountInput == "owner")
			{
				account = "owner";
				loggedIn = 1;
			}
			if (accountInput == "client")
			{
				cout << "give client email: ";
			 
				account = "client";
				getline(cin, binString);
				getline(cin, accountName);
				for (int i = 0; i < vecSize; i++)
				{
					if (accountName == clients.at(i).getMail())
					{
						tempLoggedInClient = clients.at(i);
						loggedIn = 1;
							
					}
				
				}
				
			}
			
		}
		/*say hello*/
		cout << "hello " << account << " " << tempLoggedInClient.getFirstName() + "\n";
		/*what do you want todo?*/
		while (choice != 100)
		{
			//, & vacationParks, & parcs, & accommodations
			choice = choicemaker(account, &clients, clients, &parcs, parcs, &vacationParks, &accommodations, accommodations2, &tempLoggedInClient);
			/*cout << "\nyour last choice was: " << choice << "\n";*/
			if (choice != 100)
			{
			 
			}
		}
		loggedIn = 0;
		choice = 1000;
		cout << "Logged out" << endl;

		
	}
}

int choicemaker(string account, vector<Client>* c, vector<Client> cc, vector<Parc>* p, vector<Parc> pp, vector<VacationPark>* vp, vector<Accommodation>*ac, vector<Accommodation*>& accPtr, Client *client) {
	int choice = 1000;
	int check;
	int vecSize;
	string binString;
	int vecSizeVP = vp->size();
	
	while (vecSizeVP < 1)
	{
		cout << "\nyou need to create a vacation park first" << endl;
		while (account != "owner")
		{
			
			cout << "\nIn order todo that you have to login as owner";
			cout << "\nLogin: ";
			getline(cin, binString);
			getline(cin, account);
		}
		createVacationPark(pp, cc, vp);
		vecSizeVP = vp->size();
	}
	if (account == "employee")
	{
		cout << "choose an option: \n";
		cout << "0) Logout: \n";
		cout << "1) Modify Accommodation: \n";
		cout << "2) Delete Client: \n";
		cout << "3) Modify Client: \n";
		cout << "4) Create Client: \n";
		cout << "5) Modify Booking: \n";
		cout << "6) Delete Booking: \n";
		
		while (choice < 0 || choice > 6)
		{
			cout << "choose an option: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			//clear screen
			cout << "\x1B[2J\x1B[H";
			return 100;
			break;
		case 1:
			searchAccommodation(&accPtr);
			modifyAccommodation(&accPtr);
			return 1;
			break;
		case 2:
			check = deleteClient(c);
			return 2;
			break;
		case 3:
			check = modifyClient(c);
			return 3;
			break;
		case 4:
			check = createClient(c);
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		default:
			break;
		}
	}
	if (account == "owner")
	{
		cout << "choose an option: \n";
		cout << "0) Logout: \n";
		cout << "1) Modify Parc: \n";
		cout << "2) Create Parc: \n";
		cout << "3) Delete Parc: \n";
		cout << "4) Modify Accommodation: \n";
		cout << "5) Delete Accommodation: \n";
		cout << "6) Create Accommodation: \n";
		cout << "7) Create Vacation Park: \n";
		
		while (choice < 0 || choice > 7)
		{
			cout << "choose an option: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			//clear screen
			cout << "\x1B[2J\x1B[H";
			return 100;
			break;
		case 1:
			modifyPark(p, vp, &accPtr);
			return 7;
			break;
		case 2:
			check = createPark(p, vp);
			return 8;
			break;
		case 3:
			return 9;
			break;
		case 4:
			searchAccommodation(&accPtr);
			modifyAccommodation(&accPtr);
			return 10;
			break;
		case 5:
			searchAccommodation(&accPtr);
			deleteAccommodation(&accPtr);
			return 11;
			break;
		case 6:
			createAccommodation(&accPtr);
			return 12;
			break;
		case 7:
			createVacationPark(pp, cc, vp);
			return 13;
			break;
		default:
			break;
		}
	}
	if (account == "client")
	{
		cout << "choose an option: \n";
		cout << "0) Logout: \n";
		cout << "1) Create Booking: \n";
		cout << "2) Modify Booking: \n";
		cout << "3) Change Client Info: \n";
		cout << "4) Contact Employee: \n";
		
		
		while (choice < 0 || choice > 4)
		{
			cout << "choose an option: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			return 100;
			break;
		case 1:
			return 13;
			break;
		case 2:
			return 14;
			break;
		case 3:
			changeClientInfo(c, client);
			return 15;
			break;
		case 4:
			return 16;
			break;
		default:
			break;
		}
	}
	return 0;
}
int createClient(vector<Client>* c)
{
	string binString;
	Client tempClient;
	string temp;
	getline(cin, binString);
	cout << "Client firstname: ";
	getline(cin, temp);
	tempClient.setFirstName(temp);
	cout << "Client lastname: ";
	getline(cin, temp);
	tempClient.setLastName(temp);
	
	cout << "Client email: ";
	getline(cin, temp);
	tempClient.setMail(temp);

	cout << "Client Address: ";
	getline(cin, temp);
	tempClient.setAddress(temp);
	
	c->push_back(tempClient);
	int size = c->size();
	cout << "lengte van customer vector: " << size << "\n";
	return 0;

	

}
int modifyClient(vector<Client>* c) 
{
	string binString;
	Client findClient;
	Client tempClient;
	Client changeClient;
	string temp;
	int found = 0;
	int choice;
	int vecSize = c->size();
	int locationIndex;
	int i = 0;
	cout << "What is the mail address of the client? ";
	cin >> temp;
	getline(cin, binString);
	findClient.setMail(temp);
	while (i < vecSize && found == 0)
	{

		//tempClient = c[i];
		tempClient = c->at(i);
		locationIndex = i;
		if (tempClient.getMail() == findClient.getMail())
		{
			cout << "Account Found:\nFirst name:	" << setw(20) << left << tempClient.getFirstName() << "\nLast name:	" << setw(20) << tempClient.getLastName() << "\nEmail:		" << setw(20) << tempClient.getMail() << "\nAddress:	" << setw(20) << tempClient.getAddress();
			found = 1;
		}
		i++;
	}
	if (found == 1)
	{
		cout << "\nwhat do you want to change?: \n";
		cout << "1) Name\n";
		cout << "2) Email\n";
		cout << "3) Address\n";
		cout << "4) Cancel\n";
		cout << "Choice: ";
		cin >> choice;
		getline(cin, binString);
		switch (choice)
		{
		case 1:
			cout << "First name: ";
			getline(cin, temp);
			c->at(locationIndex).setFirstName(temp);
			cout << "Last name: ";
			getline(cin, temp);
			c->at(locationIndex).setLastName(temp);
			break;
		case 2:
			cout << "Email: ";
			getline(cin, temp);
			c->at(locationIndex).setMail(temp);
			break;
		case 3:
			cout << "Adress: ";
			getline(cin, temp);
			c->at(locationIndex).setAddress(temp);
			break;
		case 4:
			break;
		}

	}
	else
	{
		cout << "\n\nthe Client wasnt found. \n\n";
	}
	return 0;
}

int deleteClient(vector<Client>* c)
{
	int temp;
	string temp2;
	string binString;
	int vecSize = c->size();
	cout << "Choose and option: \n";
	cout << "1) List all clients\n";
	cout << "2) Search for a client\n";
	cout << "Choice: ";
	cin >> temp;
	switch (temp)
	{
	case 1:
		for (int i = 0; i < vecSize; i++)
		{
			cout << "\n" << i + 1 << ")" << c->at(i).toString();
			/*cout << i + 1 << ")" << "\nFirst name:	" << setw(20) << left << c->at(i).getFirstName() << "\nLast name:	" << setw(20) << c->at(i).getLastName() << "\nEmail:		" << setw(20) << c->at(i).getMail() << "\nAddress:	" << setw(20) << c->at(i).getAddress() << "\n\n";*/
		}
		cout << "\nGive the number above the client you want to delete (0 tot cancel): ";
		cin >> temp;
		if (temp != 0)
		{
			c->erase(c->begin() + (temp - 1));
		}
		break;
	case 2: 
		getline(cin, binString);
		cout << "Give a name to narrow down the list: ";
		getline(cin, temp2);
		for (int i = 0; i < vecSize; i++)
		{
			if (c->at(i).getFirstName() == temp2)
			{
				cout << "\n" << i + 1 << ")" << c->at(i).toString();
				/*cout << i+1 << ")" << "\First name: " << setw(20) << left << c->at(i).getFirstName() << "\nLast name:	" << setw(20) << c->at(i).getLastName() << "\nEmail:		" << setw(20) << c->at(i).getMail() << "\nAddress:	" << setw(20) << c->at(i).getAddress() << "\n\n";*/
			}
			
		}
		cout << "\nGive the number above the client you want to delete (0 tot cancel): ";
		cin >> temp;
		if (temp != 0)
		{
			c->erase(c->begin() + (temp - 1));
		}
		break;

	default:
		break;
	}
	return 0;
}
void changeClientInfo(vector<Client>* c, Client* client)
{
	int choice;
	string temp2;
	Client tempClient;
	string binString;
	int flag1 = 0;
	int vecSize = c->size();
edit3:
	string mail = client->getMail();
	cout << "Client " << client->getFirstName() << " " << client->getLastName()
		<< ": ";
	cout << "what do you want to change (0 to cancel): " << endl;
	cout << "1) First name" << endl;
	cout << "2) Last name" << endl;
	cout << "3) Email" << endl;
	cout << "4) Address" << endl;
	cout << "choice: ";
	cin >> choice;
	getline(cin, binString);
	switch (choice)
	{
	case 0:
		break;
	case 1:
		cout << "New first name: ";
		
		getline(cin, temp2);
		for (int i = 0; i < vecSize; i++)
		{
			if (mail == c->at(i).getMail())
			{
				c->at(i).setFirstName(temp2);
				client->setFirstName(temp2);
			}
		}
		goto edit3;
		break;
	case 2:
		
		cout << "New last name: ";
		getline(cin, temp2);
		for (int i = 0; i < vecSize; i++)
		{
			if (mail == c->at(i).getMail())
			{
				c->at(i).setLastName(temp2);
				client->setLastName(temp2);
			}
		}
		goto edit3;
		break;
	case 3:
		cout << "New email address: ";
		getline(cin, temp2);
		for (int i = 0; i < vecSize; i++)
		{
			if (temp2 == c->at(i).getMail())
			{
				flag1 = 0;
			}
			flag1 = 1;
		}
		if (flag1 == 1)
		{
			for (int i = 0; i < vecSize; i++)
			{
				if (mail == c->at(i).getMail())
				{
					c->at(i).setMail(temp2);
					client->setMail(temp2);
				}
			}
			flag1 = 0;
		}
		goto edit3;
		break;
	case 4:
		getline(cin, binString);
		cout << "New address: ";
		getline(cin, temp2);
		for (int i = 0; i < vecSize; i++)
		{
			if (mail == c->at(i).getMail())
			{
				c->at(i).setAddress(temp2);
			}
		}
	default:
		break;
	}

}
int createVacationPark(vector<Parc> pp, vector<Client>cc, vector<VacationPark>*vp) {
	string name;
	string address;
	string VAT;
	string binString;
	getline(cin, binString);
	cout << "Give a Vacation Parc name: ";
	getline(cin, name);
	cout << "Give Parc address: ";
	getline(cin, address);
	cout << "give VAT: ";
	getline(cin, VAT);
	VacationPark tempVacationPark(name, address, VAT, pp, cc);
	vp->push_back(tempVacationPark);
	return 0;
}
int createPark(vector<Parc>*p, vector<VacationPark>* vp) {
	string name;
	string address;
	string binString;
	int temp1;
	string temp2;
	bool temp3;
	int vecSizeVP = vp->size();
	Service* extraServices = new Service();
	vector<Accommodation*> accommodations;
	if (vecSizeVP < 1)
	{
		cout << "You need to create a vacation park first" << endl;
	}
	for (int i = 0; i < vecSizeVP; i++)
	{
		cout << "\n" << i + 1 << ")" << "\n" << vp->at(i).getName() << endl;
	}
	cout << "In which vacation park do you want to create the new park: ";
	cin >> temp1;
	getline(cin, binString);
	cout << "\ngive a Parc name: ";
	getline(cin, name);
	cout << "give the Parc address: ";
	getline(cin, address);
	cout << "Bicycle rent (1 or 0): ";
	cin >> temp3;
	extraServices->setBicycleRent(temp3);
	cout << "Bowling (1 or 0): ";
	cin >> temp3;
	extraServices->setBowling(temp3);
	cout << "Kids paradise (1 or 0): ";
	cin >> temp3;
	extraServices->setKidsParadise(temp3);
	cout << "Swim paradise (1 or 0): ";
	cin >> temp3;
	extraServices->setSwimParadise(temp3);
	Parc tempParc(name, address, extraServices, accommodations);
	vp->at(temp1-1).addParc(tempParc);
	/*p->push_back(tempParc);*/
	delete extraServices;
	return 0;

}
//void showIt(Accommodation& accommodation)
//{
//	cout << accommodation.toString();
//}
void modifyPark(vector<Parc>* p, vector<VacationPark>* vp, vector<Accommodation*>* accPtr)
{
	
	int temp1;
	int temp2;
	int temp3;
	int choice;
	int vecSizeParcACC;
	string temp4;
	string binString;
	string name, address;
	vector<Accommodation*> test1;
	vector<Accommodation*> test2;
	Accommodation* test3;
	bool temp5;
	int vecSizeVP = vp->size();
	int vecSizeACC = accPtr->size();
	Service* tempSer = new Service();
	cout << "In which Vacation Park do you want to modify parcs: " << endl;
	for (int i = 0; i < vecSizeVP; i++)
	{
		cout << i + 1 << ")" << vp->at(i).getName() << endl;

	}
	cout << "choice: ";
	cin >> temp1;
	int vecSizeP = vp->at(temp1-1).getParcs().size();
	cout << "In this Vacation Park are the following parcs: " << endl;
	for (int i = 0; i < vecSizeP; i++)
	{
		cout << i+1 << ") " << vp->at(temp1 - 1).getParcs().at(i).getName() << endl;
	}
	cout << "Choose a parc you want to edit: " << endl;
	cout << "choice: ";
	cin >> temp2;
	if ((temp2-1) < vp->at(temp1 - 1).getParcs().size() && temp2 > 0)
	{
		edit3: 
		cout << "What do you want to do: " << endl;
		cout << "0) To cancel" << endl;
		cout << "1) Change the name" << endl;
		cout << "2) Change the address" << endl;
		cout << "3) Change the extra services" << endl;
		cout << "4) Assign accommodations" << endl;
		cout << "5) Remove accommodations" << endl;
		cout << "Choice: ";
		cin >> temp3;
		switch (temp3)
		{
		case 0:
			break;
		case 1:
			cout << "Give a name: ";
			getline(cin, temp4);
			vp->at(temp1 - 1).getParcs().at(temp2 - 1).setName(temp4);
			goto edit3;
			break;
		case 2:
			cout << "Give an address: ";
			getline(cin, temp4);
			vp->at(temp1 - 1).getParcs().at(temp2 - 1).setAddress(temp4);
			goto edit3;
			break;
		case 3:
			cout << "Change extra services: " << endl;
			cout << "Swim paradise (1 or 0): ";
			cin >> temp5;
			tempSer->setSwimParadise(temp5);
			cout << "Bicycle rent (1 or 0): ";
			cin >> temp5;
			tempSer->setBicycleRent(temp5);
			cout << "Bowling (1 or 0): ";
			cin >> temp5;
			tempSer->setBowling(temp5);
			cout << "Kids Paradise (1 or 0): ";
			cin >> temp5;
			tempSer->setKidsParadise(temp5);
			vp->at(temp1 - 1).getParcs().at(temp2 - 1).setExtraService(tempSer);
			delete tempSer;
		case 4:
			cout << "size of acc vector " << vecSizeACC << endl;
			cout << "Which accommodation do you want to add (0 to cancel): " << endl;
			
			for (int i = 0; i < vecSizeACC; i++)
			{
				cout << accPtr->at(i)->toString();
			}
			cout << "choice: ";
			getline(cin, binString);
			cin >> choice;
			
			test1.push_back(accPtr->at(choice-1));

			cout << "test1 size: " <<test1.size() << endl;
			vp->at(temp1 - 1).getParcs().at(temp2 - 1).setAccommodations(test1);
			cout << "size of accommodations: " << vp->at(temp1 - 1).getParcs().at(temp2 - 1).getAccommodations().size();
			goto edit3;
			break;
		case 5:
			vecSizeParcACC = vp->at(temp1 - 1).getParcs().at(temp2 - 1).getSizeOfAcc();
			cout << "size of acc vector " << vecSizeParcACC << endl;
			cout << "Which accommodations do you want to remove (0 to cancel): " << endl;
			/**test2 = vp->at(temp1 - 1).getParcs().at(temp2 - 1).getTest();
			cout << test2->at(0)->toString() << endl;*/
			cout << vp->at(temp1 - 1).getParcs().at(temp2 - 1).getAccommodations().at(0)->toString();
			

			/*cout << vp->at(0).getParcs().at(0).getAccommodations(0)->toString();*/
			
			//for (int i = 0; i < vecSizeParcACC; i++)
			//{
			//	test2 = vp->at(temp1 - 1).getParcs().at(temp2 - 1).getTest();
			//	cout << test2.at(1)->toString() << endl;
			//	/*vp->at(temp1 - 1).getParcs().at(temp2 - 1).getAccommodations(0);*/
			//}
			break;
		default:
			break;
		}
	}
}
void createAccommodation(vector<Accommodation*>* accPtr) {
	int choice = 0;
	int temp1;
	string binString;
	string temp2;
	bool temp3;
	bool bbq;
	bool surround;
	bool breakfast;
	bool cleaningservice;
	string kind;
	Luxury lux;
	Accommodation* accom1;
	
	int vecSize = accPtr->size();
	cout << "\nA hotel room(1) or a cabin(2)?: ";
	cin >> choice;
	getline(cin, binString);
	if (choice == 1)
	{

		id++;
		
		
		kind = "Hotelroom";
		
		Hotelroom *tempRoom = new Hotelroom(lux);
		tempRoom->setID(id);
		cout << "\nFloor: ";
		cin >> temp1;
		getline(cin, binString);
		tempRoom->setFloor(temp1);
		cout << "Location: ";
		getline(cin, temp2);
		tempRoom->setLocation(temp2);
		cout << "Number of beds: ";
		cin >> temp1;
		getline(cin, binString);
		tempRoom->setNrBeds(temp1);
		cout << "Children bed: ";
		cin >> temp3;
		tempRoom->setChildrenBed(temp3);
		cout << "Max amount of people: ";
		cin >> temp1;
		tempRoom->setMaxAmountPeople(temp1);
		cout << "Surface size: ";
		cin >> temp1;
		tempRoom->setSurfaceSize(temp1);
		cout << "Shower: ";
		cin >> temp3;
		tempRoom->setShower(temp3);
		cout << "Bath: ";
		cin >> temp3;
		tempRoom->setBathTub(temp3);
		cout << "Price: ";
		cin >> temp1;
		tempRoom->setPrice(temp1);
		cout << "BBQ: ";
		cin >> bbq;
		cout << "Surround: ";
		cin >> surround;
		cout << "Breakfast: ";
		cin >> breakfast;
		cout << "Cleaning service: ";
		cin >> cleaningservice;
		tempRoom->setLuxuryLevel(bbq, surround, breakfast, cleaningservice, kind);
		accPtr->push_back(tempRoom);
		vecSize = accPtr->size();
		cout << vecSize;
		/*for (int i = 0; i < vecSize; i++)
		{
			cout << accPtr->at(i)->toString();
		}*/
	}
	if (choice == 2)
	{
		
		id++;
		Cabin* tempCabin = new Cabin(lux);
		tempCabin->setID(id);
		cout << "\nnumber of bedrooms: ";
		cin >> temp1;
		tempCabin->setBedrooms(temp1);
		kind = "Cabin";
		cout << "Maximum amount of people: ";
		cin >> temp1;
		tempCabin->setMaxAmountPeople(temp1);
		cout << "Surface size: ";
		cin >> temp1;
		tempCabin->setSurfaceSize(temp1);
		cout << "Shower: ";
		cin >> temp3;
		tempCabin->setShower(temp3);
		cout << "BathTub: ";
		cin >> temp3;
		tempCabin->setBathTub(temp3);
		cout << "Price: ";
		cin >> temp1;
		tempCabin->setPrice(temp1);
		cout << "BBQ: ";
		cin >> bbq;
		cout << "Surround: ";
		cin >> surround;
		cout << "Breakfast: ";
		cin >> breakfast;
		cout << "Cleaning service: ";
		cin >> cleaningservice;
		tempCabin->setLuxuryLevel(bbq, surround, breakfast, cleaningservice, kind);
		accPtr->push_back(tempCabin);
		vecSize = accPtr->size();
		cout << "vecsize: " << vecSize << "\n";
	}
	
}

void searchAccommodation(vector<Accommodation*>* accPtr) {
	string binString;
	string temp1;
	Luxury lux1;
	int choice;
	int vecSize = accPtr->size();
	if (vecSize > 0)
	{
		cout << "\nHow you want to search: ";
		cout << "\n1) List";
		cout << "\n2) ID";
		cout << "\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < vecSize; i++)
			{
				cout << "\nnumber: " << i + 1 << ")";
				cout << accPtr->at(i)->toString();
				lux1 = accPtr->at(i)->getLuxuryLevel();
				cout << lux1.toString();

			}
			break;
		case 2:
			cout << "Give an ID: ";
			cin >> choice;
			for (int i = 0; i < vecSize; i++)
			{
				if (accPtr->at(i)->getID() == choice)
				{
					cout << "\n\nnumber: " << i + 1 << ")";
					cout << accPtr->at(i)->toString();
				}
			}

		default:
			break;

		}
	}
}
void deleteAccommodation(vector<Accommodation*>* accPtr)
{
	int number;
	string binString;
	int vecSize = accPtr->size();
	if (vecSize > 0)
	{
		cout << "\nWhich number do you want to remove (press 0 to cancel): ";
		cin >> number;
		getline(cin, binString);
		if (number != 0)
		{
			delete accPtr->at(number - 1);
			accPtr->erase(accPtr->begin() + (number - 1));
		}
	}
	else {
		cout << "No accommodations present!\n";
	}

	
}
void modifyAccommodation(vector<Accommodation*>* accPtr)
{
	int number;
	string binString;
	Luxury lux;
	string kind;
	int temp1;
	string temp2;
	bool temp3;
	int vecSize = accPtr->size();
	if (vecSize > 0)
	{
		cout << "\nWhich number do you want to modify (press 0 to cancel): ";
		cin >> number;
		if (number != 0)
		{
			
		
			lux = accPtr->at(number-1)->getLuxuryLevel();
			kind = lux.getAccommodationKind();
			if (kind == "Hotelroom")
			{
				Hotelroom* tempHotel = new Hotelroom(lux);
				Hotelroom* ptrH = dynamic_cast<Hotelroom*> (accPtr->at(number - 1));
				edit:
				cout << "What do you want to modify: " << endl;
				cout << "0) to cancel" << endl;
				cout << "1) Maximum amount of people" << endl;
				cout << "2) Surface size" << endl;
				cout << "3) Shower" << endl;
				cout << "4) Bath" << endl;
				cout << "5) Floor" << endl;
				cout << "6) Location" << endl;
				cout << "7) Number of beds" << endl;
				cout << "8) Children bed" << endl;
				cout << "9) Price" << endl;
				cout << "Luxury level: " << endl;
				cout << "10) BBQ" << endl;
				cout << "11) Surround" << endl;
				cout << "12) Breakfast" << endl;
				cout << "13) Cleaning service" << endl;
				cout << "choice: ";
				cin >> temp1;
				getline(cin, binString);
				switch (temp1)
				{
				case 0:
					break;
				case 1:
					cout << "New amount of maximum people: ";
					cin >> temp1;
					tempHotel->setMaxAmountPeople(temp1);
					ptrH->setMaxAmountPeople(temp1);
					goto edit;
					break;
				case 2:
					cout << "New surface size: ";
					cin >> temp1;
					tempHotel->setSurfaceSize(temp1);
					ptrH->setSurfaceSize(temp1);
					goto edit;
					break;
				case 3:
					cout << "Shower 1 or 0: ";
					cin >> temp3;
					tempHotel->setShower(temp3);
					ptrH->setShower(temp3);
					goto edit;
					break;
				case 4:
					cout << "Bath tub 1 or 0: ";
					cin >> temp3;
					tempHotel->setBathTub(temp3);
					ptrH->setBathTub(temp3);
					goto edit;
					break;
				case 5:
					cout << "Which floor: ";
					cin >> temp1;
					tempHotel->setFloor(temp1);
					ptrH->setFloor(temp1);
					goto edit;
					break;
				case 6:
					cout << "Location: ";
					getline(cin, temp2);
					tempHotel->setLocation(temp2);
					ptrH->setLocation(temp2);
					goto edit;
					break;
				case 7:
					cout << "Number of beds: ";
					cin >> temp1;
					tempHotel->setNrBeds(temp1);
					ptrH->setNrBeds(temp1);
					goto edit;
					break;
				case 8:
					cout << "Children bed 1 or 0: ";
					cin >> temp3;
					tempHotel->setChildrenBed(temp3);
					ptrH->setChildrenBed(temp3);
					goto edit;
					break;
				case 9:
					cout << "Price: ";
					cin >> temp1;
					tempHotel->setPrice(temp1);
					ptrH->setPrice(temp1);
					goto edit;
					break;
				case 10:
					cout << "BBQ 1 or 0: ";
					cin >> temp3;
					lux.setBbq(temp3);
					goto edit;
					break;
				case 11:
					cout << "Surround 1 or 0: ";
					cin >> temp3;
					lux.setSurroundSystem(temp3);
					goto edit;
					break;
				case 12:
					cout << "Breakfast 1 or 0: ";
					cin >> temp3;
					lux.setBreakfastService(temp3);
					goto edit;
					break;
				case 13:
					cout << "Cleaning service 1 or 0: ";
					cin >> temp3;
					lux.setCleaningService(temp3);
					goto edit;
					break;
				default:
					break;
				}
				ptrH->setLuxuryLevelQuick(lux);
				/*accPtr->at(number-1) = tempHotel;*/
			}
			if (kind == "Cabin")
			{
				Cabin* tempCabin = new Cabin(lux);
				Cabin* ptrC = dynamic_cast<Cabin*> (accPtr->at(number - 1));
				edit2:
				cout << "What do you want to modify: " << endl;
				cout << "0) to cancel" << endl;
				cout << "1) Number of bedrooms" << endl;
				cout << "2) Maximum amount of people" << endl;
				cout << "3) Surface size" << endl;
				cout << "4) Shower" << endl;
				cout << "5) Bath" << endl;
				cout << "6) Price" << endl;
				cout << "Luxury level: " << endl;
				cout << "7) BBQ" << endl;
				cout << "8) Surround" << endl;
				cout << "9) Breakfast" << endl;
				cout << "10) Cleaning service" << endl;
				cout << "choice: ";
				cin >> temp1;
				getline(cin, binString);
				switch (temp1)
				{
				case 0:
					break;
				case 1:
					cout << "Amount of bedrooms: ";
					cin >> temp1;
					tempCabin->setBedrooms(temp1);
					ptrC->setBedrooms(temp1);
					goto edit2;
					break;
				case 2:
					cout << "Maximum amount of people: ";
					cin >> temp1;
					tempCabin->setMaxAmountPeople(temp1);
					ptrC->setMaxAmountPeople(temp1);
					goto edit2;
					break;
				case 3:
					cout << "Surface size: ";
					cin >> temp1;
					tempCabin->setSurfaceSize(temp1);
					ptrC->setSurfaceSize(temp1);
					goto edit2;
					break;
				case 4:
					cout << "Shower 1 or 0: ";
					cin >> temp3;
					tempCabin->setShower(temp3);
					ptrC->setShower(temp3);
					goto edit2;
					break;
				case 5:
					cout << "Bath tub 1 or : ";
					cin >> temp3;
					tempCabin->setShower(temp3);
					ptrC->setBathTub(temp3);
					goto edit2;
					break;
				case 6:
					cout << "Price: ";
					cin >> temp1;
					tempCabin->setPrice(temp1);
					ptrC->setPrice(temp1);
					goto edit2;
					break;
				case 7:
					cout << "BBQ 1 or 0: ";
					cin >> temp3;
					lux.setBbq(temp3);
					goto edit2;
					break;
				case 8:
					cout << "Surround 1 or 0: ";
					cin >> temp3;
					lux.setSurroundSystem(temp3);
					goto edit2;
					break;
				case 9: 
					cout << "Breakfast 1 or 0: ";
					cin >> temp3;
					lux.setBreakfastService(temp3);
					goto edit2;
					break;
				case 10:
					cout << "Cleaning service 1 or 0: ";
					cin >> temp3;
					lux.setCleaningService(temp3);
					goto edit2;
					break;
				default:
					break;
				}
				/*tempCabin->setLuxuryLevelQuick(lux);
				accPtr->at(number - 1) = tempCabin;*/
				ptrC->setLuxuryLevelQuick(lux);
			}

		}
	}
	else {
		cout << "No accommodations present!\n";
	}
}
void writeOut(vector<Client> clients, ofstream& inFile)
{
	int id;
	string name;
	int price;
	int vecSizeC = clients.size();
	
	if (!inFile)
	{
		cerr << "file could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < vecSizeC; i++)
	{
		inFile << clients.at(i).toStringFile();
	}
	inFile.close();

	/*while (inFile >> id >> name >> price)
	{
		cout << (id, name, price);
	}*/
}