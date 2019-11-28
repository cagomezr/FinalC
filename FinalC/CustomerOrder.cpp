// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 23/11/2019
//
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"

//static declaration
size_t CustomerOrder::m_widthField;
//basic constructor default settings and values
CustomerOrder::CustomerOrder():m_name(), m_product(), m_cntItem()
{
	m_lstItem = nullptr;
}
// custom constructor, creates one order from string reference
CustomerOrder::CustomerOrder(const std::string& theRecord) : m_name(), m_product(), m_cntItem()
{
	
	Utilities Customerbuilder;
	size_t startCode = 0;
	bool moreContent = false;
	m_name = Customerbuilder.extractToken(theRecord, startCode, moreContent);
	m_product = Customerbuilder.extractToken(theRecord, startCode, moreContent);
	m_cntItem = (std::count(theRecord.begin(), theRecord.end(), Customerbuilder.getDelimiter())) - 1;
	m_lstItem = new ItemInfo * [m_cntItem];
	size_t sentinel = 0;
	while (moreContent) {
		std::string item = Customerbuilder.extractToken(theRecord, startCode, moreContent);
		m_lstItem[sentinel] = new ItemInfo(item);
		++sentinel;
	}
	
	if(m_widthField < Customerbuilder.getFieldWidth()) {
		m_widthField = Customerbuilder.getFieldWidth();
	}
	
}
//copy constructor, throws error, to stop copy operations
CustomerOrder::CustomerOrder(CustomerOrder& na)
{
	throw "no Copy opperations allowed";
}
// move constructor,  references  move asignament operator, doesnt allow exceptions
CustomerOrder::CustomerOrder( CustomerOrder&& movelist) noexcept
{
	*this = std::move(movelist);
}
// move asignament constructor its referenced by move constructor to save  code
CustomerOrder& CustomerOrder::operator=( CustomerOrder&& movelist)noexcept
{
	// move items
	if (this != &movelist) {
		this->m_name = movelist.m_name;
		this->m_product = movelist.m_product;
		this->m_cntItem = movelist.m_cntItem;
		this->m_lstItem = movelist.m_lstItem;
		this->m_widthField = movelist.m_widthField;
	}
	//delete old object
	movelist.m_name ="" ;
	movelist.m_product =""; 	
	movelist.m_cntItem = 0u;	
	movelist.m_lstItem =nullptr;
	//we dont change static member m_widthField
	return *this;
}
// basic  destructor,  destorys all allocated  items in iteminfo to prevent memory leaks
CustomerOrder::~CustomerOrder()
{
	m_name = "";
	m_product = "";
	//destroy item individually
	for (size_t i = 0; i < m_cntItem; i++)
		delete m_lstItem[i];
	// delete the  count item
	m_cntItem = 0u;
	//delete the array
	delete m_lstItem;	
}
//gets if the item identified by string has been filled or not.
bool CustomerOrder::getItemFillState(std::string item) const
{
	bool retval = true;
	for(auto i =0u; i< m_cntItem;i++)
		if (m_lstItem[i]->m_itemName.compare(item) == 0) {
			retval = m_lstItem[i]->m_fillState;
		}
	return retval;
}
//goes through order and  returns if order is  ready or not
bool CustomerOrder::getOrderFillState() const
{
	bool retval = true;
	for (auto i = 0u; i < m_cntItem; i++)
		if ((m_lstItem[i]->m_fillState) == false) {
			retval = false;
		}
	return retval;
}
//fills the item sent by reference, and udates item if its able to. if item is non existant, does nothing
void CustomerOrder::fillItem(Item& item, std::ostream& out)
{

	for (auto i = 0u; i < m_cntItem; i++)
		if (m_lstItem[i]->m_itemName.compare(item.getName()) == 0) {
			if (item.getQuantity() > 0) {
				if (m_lstItem[i]->m_fillState == false) {
					m_lstItem[i]->m_serialNumber = item.getSerialNumber();
					item.updateQuantity();
					m_lstItem[i]->m_fillState = true;
				}
				out << "Filled ";
			}
			else
				out << "Unable to fill ";
			
			out << m_name << ", " << m_product;
			out << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}//no data for  what shoud we do in case of no filled item

}
// displays the object customer order
void CustomerOrder::display(std::ostream& out) const
{
	out << m_name << " - " << m_product << "\n";
	for (auto i = 0u; i < m_cntItem; i++) {
		
		std::string serial = std::to_string(m_lstItem[i]->m_serialNumber);
		out << std::left << "[" << std::setfill('0') << std::setw(6) << serial << "] ";
		out << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName<<" - ";
		(m_lstItem[i]->m_fillState) ? out << "FILLED" : out << "MISSING";
		out << "\n";
	}
}

bool CustomerOrder::empty()
{	
	return ((m_name.empty()) &&(m_cntItem == 0u ));
}
