// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 29/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.r#pragma once
#include "Task.h"
//custon constructor
Task::Task(const std::string record):Item(record)
{
	m_pNextTask =nullptr;
}
// runs a single cycle of the assembly line for the current task.
void Task::runProcess(std::ostream& out)
{
	if (m_orders.size() != 0u)
		if (!(m_orders.back().getItemFillState(this->getName())))
			m_orders.back().fillItem(*this, out);
}
//	 moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill state for the current Item is true
bool Task::moveTask()
{
	if (m_orders.size() != 0u)
		if ((m_orders.back().getItemFillState(this->getName())) && (m_pNextTask != nullptr)) {

			*m_pNextTask += std::move(m_orders.back());
			m_orders.pop_back();
		}
	return (m_orders.size() == 0u) ? false : true;;
}
// stores the provided Task object's reference into the m_pNextTask pointer.
void Task::setNextTask(Task& nexttask)
{
	if (this != &nexttask)
		m_pNextTask = &nexttask;
}
//– Removes the last CustomerOrder from the queue, places it in the parameter and returns true. If the CustomerOrder queue is empty, return false.
bool Task::getCompleted(CustomerOrder& sending)
{
	bool retval = false;
	if (m_orders.size() != 0u)
		if (m_orders.back().getOrderFillState()) {
			sending = std::move(m_orders.back());
			m_orders.pop_back();
			retval = true;
		}

	return retval;
}
// writes the name of the Item this Task is responsible for into the parameter: ostream
void Task::validate(std::ostream& out)
{
	out << this->getName() << " --> ";
	if (m_pNextTask == nullptr)
		out << "END OF LINE";
	else
		out << m_pNextTask->getName();
	out << std::endl;
}
// Moves the parameter onto the front of the CustomerOrder queue.
Task& Task::operator+=(CustomerOrder&& newItem)
{
	m_orders.push_front(std::move(newItem));
	return *this;
}
