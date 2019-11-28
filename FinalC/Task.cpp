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
	if ((m_orders.back().getItemFillState(this->getName())) && (m_pNextTask != nullptr)) {

		*m_pNextTask += std::move(m_orders.back());
		m_orders.pop_back();
	}
	return (m_orders.size() == 0u) ? false : true;;
}

void Task::setNextTask(Task& nexttask)
{
	m_pNextTask = &nexttask;
}

Task* Task::getnextTask()
{
	return m_pNextTask;
}

bool Task::getCompleted(CustomerOrder& sending)
{	
	if (m_orders.back().getOrderFillState()) {
		sending = std::move(m_orders.back());		
		m_orders.pop_back();
	}
	return (m_orders.size() == 0u);
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
