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
	std::vector<Task*> AssemblyLine;//A container containing all the references of the Task objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled;//A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed;//A queue of customer orders completed
	unsigned int m_cntCustomerOrder;//The number of CustomerOrder objects the assembly line started with.
	Task* Linestart;//beggining of the Assembly line.	
	Task* Lineend;//end of the Assembly line.	
public:
	LineManager(const std::string, std::vector<Task*>& , std::vector<CustomerOrder>&);//custom constructor 
	bool run(std::ostream&);// this function performs one cycle of operations on the assembly line 
	void displayCompleted(std::ostream&) const;//displays all the orders that were completed
	void validateTasks() ;//validates each task on the assembly line
};
#endif