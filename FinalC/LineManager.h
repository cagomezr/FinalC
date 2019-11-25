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
#include <deque>
#include <vector>
#include "Utilities.h"
#include "Item.h"
#include "Task.h"
#include "CustomerOrder.h"hg
#ifndef SDDS_LINEMANAGER
#define SDDS_LINEMANAGER
class Linemanager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
public:
	Linemanager(const std::string);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};
#endif