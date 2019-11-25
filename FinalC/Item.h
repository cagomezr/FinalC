// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 16/11/2019
// Modified for milestone 2 and clarity:  23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include <ostream>
#include <iomanip>
#include "Utilities.h"
#ifndef SDDS_ITEM
#define SDDS_ITEM
class Item {
	std::string m_name;//Name of Item	
	unsigned int m_serialNumber;// Serial number
	std::string m_description; // description of Item
	unsigned int m_quantity;// Quantity in stock of item
	static size_t m_widthField; // width of  field.
public:
	Item(const std::string& resetsys);// creating an item
	const std::string& getName() const;// get name
	const unsigned int getSerialNumber();//  get serial number, and increase for next part
	const unsigned int getQuantity(); // how much we have on stock
	static void setwidthfield(size_t);// it sets the field for printing to max size static so its  shared by application
	void updateQuantity();// Updates quantity  throws error if it tries to do negative quantity 
	void display(std::ostream& os, bool full) const;// displays items in line
	
};
#endif
