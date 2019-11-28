// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Item.h"
#ifndef SDDS_CUSTOMERORDER
#define SDDS_CUSTOMERORDER
struct ItemInfo
{
	std::string m_itemName;//name of item
	unsigned int m_serialNumber = 0; // 
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};
class CustomerOrder {
	std::string m_name;//customer name
	std::string m_product;//  product name
	unsigned int m_cntItem;//amount of  items  ordered
	ItemInfo** m_lstItem;//array of  iteminfo objects with the order
	static size_t m_widthField;// the  width of the  filed for displayrf
public:
	CustomerOrder();//basic constructor default settings and values
	CustomerOrder(const std::string& );// custom constructor, creates one order from string reference
	CustomerOrder(CustomerOrder&);//copy constructor, throws error, to stop copy operations
	CustomerOrder& operator=( CustomerOrder&) = delete;//copy assigment has been deleted
	CustomerOrder( CustomerOrder&&)noexcept; // move constructor,  references  move asignament operator, doesnt allow exceptions
	CustomerOrder& operator=(CustomerOrder&&)noexcept;// move asignament constructor its referenced by move constructor to save  code
	~CustomerOrder();// basic  destructor,  destorys all allocated  items in iteminfo to prevent memory leaks
	bool getItemFillState(std::string) const;//gets if the item identified by string has been filled or not.
	bool getOrderFillState() const;//goes through order and  returns if order is  ready or not
	void fillItem(Item& item, std::ostream&);//fills the item sent by reference, and udates item if its able to.
	void display(std::ostream&) const;// displays the object customer order
	bool empty();//returns false if empty
};

#endif