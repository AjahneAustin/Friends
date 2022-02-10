

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct friendType		//outside of class because it's own class
	{
		string firstName;
		string lastName;
		string city;
		string cellNum;
		string dob;
	};


class friends
{
private:

	int size;		//size of how many members in data file
	friendType friendArray[20];		//Array of size 20
public:
	//*No parameters since whole object passed*	

	friends();				//Default Constructor
	void loadArray_File();	//Loads file into array
	void printFriends();	//Prints list of friends only
	void printCity();		//Prints List of friends in particular city
	void printArray();		//Prints all information of friend database
	void insertFriend();	//Inserts friend
	void deleteFriend();	//Deletes selected friend
	void printSorted();		//Prints friend list in sorted order
	void searchArray(bool& found, int& pos);		//Searches the array
	int menuOptions();		//Menu selction
	void sortArray();		//Sorts the array by last name
	void saveArray_File();	//Save program to an outfile
};

friends::friends()
{
	size = 0;		//Initializing size to 0
}


void friends::loadArray_File()
{

	ifstream infile;

		infile.open("friend.txt");
		size = 0;
		while (!infile.eof() )
		{
			infile >> friendArray[size].firstName;
			infile >> friendArray[size].lastName;
			infile >> friendArray[size].city;
			infile >> friendArray[size].cellNum;
			infile >> friendArray[size].dob;
			size ++;
		}
		infile.close(); //Close file after loop so reads all the entries
		//cout << "File loaded" << endl;
}

void friends::printFriends(){
	cout << "List of friends: " << endl;
	cout << "_________________" << endl;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << friendArray[i].firstName + " " + friendArray[i].lastName << endl << friendArray[i].city << endl;;

	}
}

void friends::printCity(){
	string userCity;

	cout << "Enter the city you would like to search for: " << endl;
	cin >> userCity;
	for(int i = 0; i < size; i++)
	{
		if(userCity == friendArray[i].city)
		{
			cout << "Name: " << friendArray[i].firstName + " " + friendArray[i].lastName << endl;
			cout << "City: " << friendArray[i].city << endl;
			cout << endl;
		}
	}
}

void friends::printArray(){
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Name: " << friendArray[i].firstName + " " + friendArray[i].lastName << endl;
		cout << "City: " << friendArray[i].city << endl;
		cout << "Cell Phone: " << friendArray[i].cellNum << endl;
		cout << "Date of Birth: " << friendArray[i].dob << endl;
	}
}

void friends::insertFriend(){
	
	cout << "Enter the first name: " << endl;
	cin >>  friendArray[size].firstName;
	
	cout << "Enter the last name: " << endl;
	cin >> friendArray[size].lastName;
	
	cout << "Enter the city: " << endl;
	cin >> friendArray[size].city;
	
	cout << "Enter the Cell Phone Number: " << endl;
	cin >> friendArray[size].cellNum;
	
	cout << "Enter the Date of Birth: " << endl;
	cin >> friendArray[size].dob;
	size++;
}

void friends::deleteFriend(){

	string userDel;
	bool found = false;
	int pos;

	cout << "Enter the name of the friend to DELETE: " << endl;
	searchArray(found, pos);
	if (found == false)
		cout << userDel << " Does not exist" << endl;
	else
	{
		for (int i = pos ; i < size-1; i++)
			friendArray[i] = friendArray[i+1];
		size--;
	}
}

void friends::searchArray(bool& found, int& pos){

	string firstName;
	string lastName;

	cout << "Please enter the first name:" << endl;
	cin >> firstName;

	cout << "Please enter the last name:" << endl;
	cin >> lastName;

	pos = -1;
	found == false;
	for (int i = 0; i < size; i++)
	{
		if (friendArray[i].firstName == firstName && friendArray[i].lastName == lastName)
		{
			found = true;
			pos = i;
			cout << "Name found: " << friendArray[i].firstName + " " + friendArray[i].lastName << endl; 
		}
	}
}

void friends::sortArray(){

	int i, j;
	friendType temp;
	for (int i =0; i < size-1; i++)
	{
		for( int j = 0; j < size - 1; j++)
		{
			if (friendArray[j].lastName >= friendArray[j+1].lastName)
		    {
				temp = friendArray[j];
				friendArray[j] = friendArray[j+1];
				friendArray[j+1] = temp;		 
			}
	    }
    }   
}

int menuOptions()
{
	int choice;

	cout << endl;
	cout << "(1) Print list of all friends" << endl;
	cout << "(2) Prints list of friends in a particular city" << endl;
	cout << "(3) Prints friends list with name, city, and cell, and DOB" << endl;
	cout << "(4) Add a new friend" << endl;
	cout << "(5) Delete a friend" << endl;
	cout << "(6) Sort friends by last name" << endl;
	cout << "(7) Search for a friend" << endl;
	cout << "(8) Save progress" << endl;
	cout << "(9) EXIT" << endl;
	
	cin >> choice;
	return choice;
}

void friends::saveArray_File(){
	ofstream outfile;
	outfile.open("friends.out");

	cout << "Saving in progress... " << endl;
	for(int i = 0; i < size; i++)
	{
		outfile << friendArray[i].firstName + " " + friendArray[i].lastName + " ";
		outfile << friendArray[i].city + " " + friendArray[i].cellNum + " " + friendArray[i].dob << endl;
	}
	outfile.close();
}

int main()
{
	int size;			//Keeps track of num of elements in array
	friends Buddies;	//Declare an object of friends
	int userChoice;		//Stors user selection
	bool found;			//Initializing bool to false
	int pos;
	
	Buddies.loadArray_File();		//Loads text file into array
	
	do{
		userChoice = menuOptions();

		switch (userChoice)
		{
		case 1: Buddies.printFriends();
			break;
		case 2: Buddies.printCity();
			break;
		case 3: Buddies.printArray();
			break;
		case 4: Buddies.insertFriend();
			break;
		case 5: Buddies.deleteFriend();
			break;
		case 6: Buddies.sortArray();
			break;
		case 7: Buddies.searchArray(found, pos);
			break;
		case 8: Buddies.saveArray_File();
			break;
		case 9: cout << "See you next time" << endl;
			return 0;
		default: cout << "Invalid Choice. Please choose an option 1-9" << endl;
			continue;
		}
	
	}while(userChoice != 9);
	

	return 0;
}
