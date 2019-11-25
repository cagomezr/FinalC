#include "Task.h"

Task::Task(const std::string record):Item(record)
{
	m_pNextTask=nullptr;
}

void Task::runProcess(std::ostream&)
{
	
}

bool Task::moveTask()
{
	return false;
}

void Task::setNextTask(Task& nexttask)
{
	m_pNextTask = &nexttask;
}

bool Task::getCompleted(CustomerOrder& sending)
{
	CustomerOrder* dats = nullptr;
	dats = &m_orders.back();
	sending = &dats;
	bool returnvalue = false;
	m_orders.pop_back();
	if (m_orders.size() == 0u)
		returnvalue = true;
	return returnvalue;
}

void Task::validate(std::ostream&)
{

}

Task& Task::operator+=(CustomerOrder&&)
{
	// TODO: insert return statement here
}
