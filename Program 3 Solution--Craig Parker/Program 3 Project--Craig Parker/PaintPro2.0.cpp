/************************************************
*File name: Paint Pro.cpp                       *
*Programmer: Craig Parker                       *
*Purpose: Calculate paint and brushes needed to *
*		  paint a room.							*
*************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(){

	//Variables 
	double oneGalPaint = 350;
	double windowRegulation = 145;
	double windowSize = 18;
	string userName;
	double lengthRoom = 0;
	double widthRoom = 0;
	double heightCeiling = 0;
	int coatsOfPaint = 0;
	double area = 0;
	double totalPaint = 0;
	string paintColor;
	int totalWindows = 0;
	double wallSurfaceArea = 0;
	double volume = 0;
	double btuNeeded = 0;

	//input items
	cout << "Hello and welcome to Paint Pro 2.0!  This program will make figuring out how\n much paint to buy quick and easy!\n";
	cout << "What is your first Name?";
	cin >> userName;
	cout << "Hello " << userName << endl << "Please input the length of the room to be painted in feet. (do not add ft\n abreveation to end)" << endl;
	cin >> lengthRoom;
	cout << "Now " << userName << " Please enter the width of the room to be painted in feet" << endl;
	cin >> widthRoom;
	cout << "Next imput the height of your ceiling in feet" << endl;
	cin >> heightCeiling;
	cout << "What is the paint color?" << endl;
	cin >> paintColor;
	cout << "almost there " << userName << " how many coats of paint to apply?" << endl;
	cin >> coatsOfPaint;
	cout << "Thanks " << userName << " here is what you will need to paint your room" << endl;

	//calculations

	area = ((lengthRoom * 2) + (widthRoom * 2))*heightCeiling;
	totalWindows = area / windowRegulation;
	wallSurfaceArea = area - (totalWindows*windowSize);
	totalPaint = (wallSurfaceArea*coatsOfPaint) / oneGalPaint;
	volume = lengthRoom * widthRoom * heightCeiling;
	btuNeeded = (volume / 650) * 1000;
	

	//Output
	
	cout << "Lenght of Room: " << lengthRoom << " ft." << endl;
	cout << "Width of Room: " << widthRoom << " ft." << endl;
	cout << "Height of ceiling: " << heightCeiling << " ft." << endl;
	cout << "Paint color: " << paintColor << endl;
	cout << "Coats of Paint: " << coatsOfPaint << endl;
	cout << "Total Windows: " << totalWindows << endl;
	cout << "Wall surface area: " << area << " ft."<< endl;
	cout << "Total Gallons of paint: " << totalPaint << endl;
	cout << "BTU's needed: " << btuNeeded << endl;
	cout << endl << "Thank you " << userName << "for using our free trial of paint pro!\n  visit www.paintmasters.com to download the full program for only $2.50!";


	system("pause");
	return 0;
}// end of main 