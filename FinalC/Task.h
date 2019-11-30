// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 29/11/2019
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
class Task:public Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const std::string);//custon constructor
	
	Task(Task&) = delete;//copy constructor, deleted per specs
	Task& operator=(Task&) = delete;//copy assigment , deleted per specs
	Task(Task&&) = delete; // move constructor, deleted per specs
	Task& operator=(Task&&) = delete; //move asignament deleted per specs
	void runProcess(std::ostream&);// runs a single cycle of the assembly line for the current task.
	bool moveTask();//	 moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill state for the current Item is true
	void setNextTask(Task&);// stores the provided Task object's reference into the m_pNextTask pointer.
	bool getCompleted(CustomerOrder&);//– Removes the last CustomerOrder from the queue, places it in the parameter and returns true. If the CustomerOrder queue is empty, return false.
	void validate(std::ostream&);// writes the name of the Item this Task is responsible for into the parameter: ostream
	Task& operator+=(CustomerOrder&&);// Moves the parameter onto the front of the CustomerOrder queue.
};
#endif