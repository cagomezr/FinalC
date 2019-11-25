// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.r#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <deque>
#include "Utilities.h"
#include "Item.h"
#include "CustomerOrder.h"
#ifndef SDDS_TASK
#define SDDS_TASK
class Task:Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const std::string);
	Task(Task&) = delete;//copy constructor, deleted per specs
	Task& operator=(Task&) = delete;//copy assigment , deleted per specs
	Task(Task&&) = delete; // move constructor, deleted per specs
	Task& operator=(Task&&) = delete; //move asignament deleted per specs
	void runProcess(std::ostream&);
	bool moveTask();	
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};
#endif