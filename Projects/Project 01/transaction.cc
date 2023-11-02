/*************************************************************************
    This is the implementation file for the Transaction class. For more 
		information about the class see Transaction.h.
    Students are expected to implement some of the functions shown 
		below.
	Patricia Lindner	Ohio University EECS	September 2023
*************************************************************************/
#include "transaction.h"
using namespace std;

Transaction::Transaction(Date d, string p, int num, double amt){
	num = num;
	date = d;
	other_party = p;
	amount = amt;
}

// Input and output functions
void Transaction::make_transaction(std::istream& ins){ // INPUT (num, d, p, amt)
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	other_party.  */

	// Input from terminal (has labels)

	cout << "Make a Transaction." << endl;
	cout << "Transaction Number (int):  ";
	cin >> num;
	cout << "Today's Date (mm/dd/yyyy): ";
	cin >> date;
	cout << "Receiving Party (name):    ";
	cin >> other_party;
	cout << "Transfer Amount (double):  ";
	cin >> amount;
	cout << endl;


	// Input from file (no labels)

	ins >> num;
	ins >> date;
	ins >> other_party;
	ins >> amount;

}

void Transaction::output(std::ostream& outs)const{ // OUTPUT (num, d, p, amt)
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/

	// Output to terminal (has labels)

	cout << "Transaction Number: " << num << endl;
	cout << "Today's Date:		 " << date << endl;
	cout << "Receiving Party:	 " << other_party << endl;
	cout << "Transfer Amount:	 " << amount << endl;


	// Output to file (no labels)

	outs << num;
	outs << date;
	outs << other_party;
	outs << amount;
	
}

ostream& operator << (ostream& outs, const Transaction& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Transaction& c){
	c.make_transaction(ins);
	return ins;
}