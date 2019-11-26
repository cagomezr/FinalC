#include "Task.h"

Task::Task(const std::string record):Item(record)
{
	m_pNextTask =nullptr;
}

void Task::runProcess(std::ostream& out)
{
	if (m_orders.size() == 0u)
		if (!(m_orders.back().getItemFillState(this->getName())))
			m_orders.back().fillItem(*this, out);
}

bool Task::moveTask()
{	
	if ((m_orders.back().getItemFillState(this->getName())) and (m_pNextTask != nullptr)) {
		CustomerOrder send;
		getCompleted(send);
		*m_pNextTask += std::move(send);
	}
	bool retval = (m_orders.size() == 0u) ? false : true;
	return retval;
}

void Task::setNextTask(Task& nexttask)
{
	m_pNextTask = &nexttask;
}

bool Task::getCompleted(CustomerOrder& sending)
{	
	sending = std::move(m_orders.back());
	bool returnvalue = false;
	m_orders.pop_back();
	if (m_orders.size() == 0u)
		returnvalue = true;
	return returnvalue;
}

void Task::validate(std::ostream& out)
{
	out << this->getName() << " --> ";
	if (m_pNextTask == nullptr)
		out << "END OF LINE";
	else
		out << m_pNextTask->getName();
}

Task& Task::operator+=(CustomerOrder&& newItem)
{
	m_orders.push_front(std::move(newItem));
	return *this;
}
