#include "LineManager.h"

Linemanager::Linemanager(const std::string filename, std::vector<Task*>& taskBuilder, std::vector<CustomerOrder>& Customerorders)
{
	
}

bool Linemanager::run(std::ostream&)
{
	return false;
}

void Linemanager::displayCompleted(std::ostream& out) const
{
	auto runfunc = [&](CustomerOrder& single) {
		single.display(out);
	};
	std::for_each(Completed.begin(), Completed.end(), runfunc);
}

void Linemanager::validateTasks() const
{
}
