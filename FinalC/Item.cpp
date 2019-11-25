// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 16/11/2019
// Modified for milestone 2 and clarity:  23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Item.h"
size_t Item::m_widthField;//set static variable
//Item Constructor needs using a const  string to extract the information with a utility object
Item::Item(const std::string& record)
{
	Utilities Itembuilder;
	size_t startCode = 0;
	bool moreContent = false;
	m_name= Itembuilder.extractToken(record, startCode, moreContent);
	m_serialNumber = std::stoi(Itembuilder.extractToken(record, startCode, moreContent));
	m_quantity = std::stoi(Itembuilder.extractToken(record, startCode, moreContent));
	m_widthField = Itembuilder.getFieldWidth();
	m_description = Itembuilder.extractToken(record, startCode, moreContent);
	
}
//returns item name
const std::string& Item::getName() const
{
	return m_name;
}
//gets the serial number and   sets the next serial number.
const unsigned int Item::getSerialNumber()
{
	const unsigned int ret = m_serialNumber;
	m_serialNumber++;
	return ret;
}
//gets the item quantity
const unsigned int Item::getQuantity()
{
	return m_quantity;
}
// it sets the field for printing to max size static so its  shared by application
void Item::setwidthfield(size_t newwidth)
{
	m_widthField = newwidth;
}
// Updates quantity  throws error if it tries to do negative quantity 
void Item::updateQuantity()
{
	if (m_quantity > 0)
		m_quantity--;
	else
		throw "No items";
}
// displays items in line
void Item::display(std::ostream& os, bool full) const{
	
	os << std::left << std::setw(m_widthField) <<  m_name;
	std::string serial = std::to_string(m_serialNumber);
	
	os << std::setfill('0') << std::right << " [" << std::setw(6)<< serial <<"]" << std::setfill(' ');
	if (full) {
		os << " Quantity: " << std::left  << std::setw(m_widthField) <<  std::to_string(m_quantity);
		os << " Description: "  << m_description;
	}
	os << std::endl;
}
