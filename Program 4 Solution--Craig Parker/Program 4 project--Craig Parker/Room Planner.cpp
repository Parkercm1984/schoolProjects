/************************************************
*File name: Room Planner.cpp                    *
*Programmer: Craig Parker                       *
*Purpose: Calculate AC and window needs for a   *
*		  room.	          						*
*************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(){

	//Variables 
	double windowRegulation = 145;
	string userName;
	double lengthRoom = 0;
	double widthRoom = 0;
	double heightCeiling = 0;
	double area = 0;
	int totalWindows = 0;
	double volume = 0;
	double btuNeeded = 0;
	int userWindows = 0;
	string ACUnit;

	//input items
	cout << "Hello and welcome to Room Planner trial edition!\n  This program will make figuring out\n some basic construction needs quick and easy!\n";
	cout << "What is your first Name?";
	cin >> userName;
	cout << "Hello " << userName << endl << "Please input the length of the room in feet. (do not add ft abreveation to end)" << endl;
	cin >> lengthRoom;
	cout << "Now " << userName << " Please enter the width of the room in feet" << endl;
	cin >> widthRoom;
	cout << "Next imput the height of your ceiling in feet" << endl;
	cin >> heightCeiling;
	
	

	//calculations

	area = lengthRoom * widthRoom;
	totalWindows = area / windowRegulation;
	volume = lengthRoom * widthRoom * heightCeiling;
	btuNeeded = (volume / 650) * 1000;

	//Input
	cout << "Total Windows allowed by code: " << totalWindows << endl;
	cout << "How many windows would you like to place in the room?" << endl;
	cin >> userWindows;

	// calculations
	if (userWindows > totalWindows) {
		cout << "I'm sorry " << userName << "your room can only acomidate " << totalWindows << " per building code" << endl;
	}
	else {
		totalWindows = userWindows;	}

	if (btuNeeded > 100000){
		ACUnit = "G";
	}
	else if (btuNeeded > 75000) {
		ACUnit = "F";
	}
	else if (btuNeeded > 61330) {
		ACUnit = "E";
	}
	else if (btuNeeded > 40000) {
		ACUnit = "D";
	}
	else if (btuNeeded > 27500) {
		ACUnit = "C";
	}
	else if (btuNeeded > 12500) {
		ACUnit = "B";
	}
	else  {
		ACUnit = "A";
	}
	//Output
	cout << endl << "Room Report--------------------------------------" << endl;
	cout << "Lenght of Room: " << lengthRoom << " ft." << endl;
	cout << "Width of Room: " << widthRoom << " ft." << endl;
	cout << "Height of ceiling: " << heightCeiling << " ft." << endl;
	cout << "Room Volume: " << volume << " cu ft." << endl;
	cout << "Total Windows: " << totalWindows << endl;
	cout << "BTU's needed: " << btuNeeded << endl;
	cout << "AC unit needed: " << ACUnit << endl;
	cout << endl << "Thank you " << userName << " for using our free trial of Room Planner!\n  visit www.Contracor.com to download the full program for only $2.50!";


	system("pause");
	return 0;
}// end of main 