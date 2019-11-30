// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 29/11/2019
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
#include "CustomerOrder.h"
#ifndef SDDS_LINEMANAGER
#define SDDS_LINEMANAGER
class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	Task* Linestart;	
public:
	LineManager(const std::string, std::vector<Task*>& , std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() ;
};
#endif