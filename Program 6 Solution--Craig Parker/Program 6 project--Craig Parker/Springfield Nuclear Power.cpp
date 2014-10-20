/************************************************
*File name: Springfield Nuclear Power.cpp       *
*Programmer: Craig Parker                       *
*Purpose: Manage customer power rates           *
*		  	          					     	*
*************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

string get_cust_ID();
double get_cust_kwh();
double calc_charge(double numKwhours, bool goldCheck);
void display_cust_data(string customerID, double numKwHours, double totalCustomerCharge);
void display_final_report(double totalKwHours, int totalNumCustomers, double totalCharges);
bool gold_star_deduct(string customerID);

int main(){
	
	int totalNumCustomers = 0;
	double totalKwHours = 0;
	double totalCharges = 0;
	string custID;
	double numCustKWH = 0;
	double totalCustCharge = 0;
	bool goldCheck;
	

	cout << "Welcome to Springfield Power Customer Input:" << endl;
	cout << "---------------------------------------------------" << endl << endl;
	custID = get_cust_ID();

	if (custID == "END" || custID == "end"){
		cout << "No customers entered.   Goodbye and thank you for using Springfield Power." << endl;
	}
	else {
	 numCustKWH = get_cust_kwh();
		
		while (custID != "END" && custID != "end"){
		
		goldCheck = gold_star_deduct(custID);
		totalCustCharge = calc_charge(numCustKWH, goldCheck);
		
		display_cust_data(custID, numCustKWH, totalCustCharge);

			totalNumCustomers = totalNumCustomers + 1;
			totalKwHours = totalKwHours + numCustKWH;
			totalCharges = totalCharges + totalCustCharge;

						
			custID = get_cust_ID();

			if (custID == "END" || custID == "end"){
				cout << "goodbye";
			}
			else {
				numCustKWH = get_cust_kwh();
			}
		}//end while loop

		display_final_report(totalKwHours,totalNumCustomers,totalCharges);

	}//end else
	
}//end main

//-------------------------------functions--------------------------------------------------------------------

string get_cust_ID(){
	string customerID;

	cout << "Input Customer ID" << endl;
	cin >> customerID;

	return customerID;
}//end get_cust_ID

double get_cust_kwh(){
	double numKwHours;

	cout << "Input KW Hours used" << endl;
	cin >> numKwHours;

	return numKwHours;

}//end get_cust_kwh

double calc_charge(double numKwHours, bool gold){

	
	const double firstCharge = 0.12;
	const double secondaryCharge = 0.09;
	const double tertiaryCharge = 0.06;
	const double finalCharge = 0.04;
	const double FIRST_LIMIT = 300;
	const double SECONDARY_LIMIT = 300;
	const double TERTIARY_LIMIT = 400;
	double totalCustomerCharge = 0;
	double overFirstCharge = 0;
	double overSecondaryCharge = 0;
	double overTertiaryCharge = 0;
	const double NUM1 = 1000;
	const double NUM2 = 600;
	const double NUM3 = 300;
	const double GOLD_DISC = 0.05;
	double goldDiscount;

	overFirstCharge = firstCharge * FIRST_LIMIT;
	overSecondaryCharge = secondaryCharge * SECONDARY_LIMIT;
	overTertiaryCharge = tertiaryCharge * TERTIARY_LIMIT;

	if (numKwHours > NUM1){
		totalCustomerCharge = (finalCharge * (numKwHours - NUM1)) + (overFirstCharge + overSecondaryCharge + overTertiaryCharge);
	}
	else if (numKwHours > NUM2){
		totalCustomerCharge = (tertiaryCharge * (numKwHours - NUM2)) + (overFirstCharge + overSecondaryCharge);
	}
	else if (numKwHours > NUM3){
		totalCustomerCharge = (secondaryCharge * (numKwHours - NUM3)) + overFirstCharge;
	}
	else {
		totalCustomerCharge = firstCharge * numKwHours;
	}

	if (gold == true){
		goldDiscount = totalCustomerCharge * GOLD_DISC;
		totalCustomerCharge = totalCustomerCharge - goldDiscount;
	}
	return totalCustomerCharge;

} //end  calc_charge

void display_cust_data(string customerID, double numKwHours, double totalCustomerCharge){

	cout << "CUST_ID" << setw(12) << "KWHours" << setw(15) << "Charge ($)" << endl;
	cout << setw(7) << customerID << setw(12) << numKwHours << setw(15) << setprecision(2) << fixed << totalCustomerCharge << endl << endl;

	
}//end display_cust_data

void display_final_report(double totalKwHours, int totalNumCustomers, double totalCharges){
	double avgKwHours = 0;

	avgKwHours = totalKwHours / totalNumCustomers;

	cout << string(50, '\n');

	cout << "Springfield Power Customer Report" << endl;
	cout << "--------------------------------------------------------" << endl;

	cout << "Total Customers: " << totalNumCustomers << endl;
	cout << "Total KW Hours: " << totalKwHours << endl;
	cout << "Average KW Hours: " << avgKwHours << endl;;
	cout << "Total Charges: $" << setprecision(2) << fixed << totalCharges << endl;

}//end display_final_report

bool gold_star_deduct(string customerID){
	bool goldStar;

	if (customerID.substr(0, 1) == "8" || customerID.substr(0, 1) == "9"){
		goldStar = true;
		cout << endl << "----------------Congradulations gold star member!--------------------" << endl;
	}
	else{
	goldStar = false;
}
	return goldStar;
}//end gold_star_deduct