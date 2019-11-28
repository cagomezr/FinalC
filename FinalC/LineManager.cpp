#include "LineManager.h"

Linemanager::Linemanager(const std::string filename, std::vector<Task*>& taskBuilder, std::vector<CustomerOrder>& Customerorders)
{
	std::move(Customerorders.begin(), Customerorders.end(), std::back_inserter(ToBeFilled));
	std::copy(taskBuilder.begin(), taskBuilder.end(), std::back_inserter(AssemblyLine));
	std::ifstream file(filename);
	m_cntCustomerOrder = ToBeFilled.size();
	Linestart = nullptr;
	Lineend = nullptr;
	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";
	std::string record;
	Utilities pointersmanager;
	bool firstexec = true;
	while (!file.eof())
	{
		std::getline(file, record);
		Task* begin;
		Task* end;
		std::string findstr;
		size_t startCode = 0u;
		bool moreContent = true;
		auto lambdafind = [&](Task* data) {	
			return (data->getName().compare(findstr) == 0);				 
		};
		findstr = pointersmanager.extractToken(record, startCode, moreContent);
		begin = (std::find_if(AssemblyLine.begin(), AssemblyLine.end(), lambdafind))[0];
		if (Linestart== nullptr)
			Linestart = begin;
		

		if (moreContent) {
			findstr = pointersmanager.extractToken(record, startCode, moreContent);
			end = (std::find_if(AssemblyLine.begin(), AssemblyLine.end(), lambdafind))[0];
			begin->setNextTask(*end);
		}
		else {
			Lineend = begin;
		}
	}

}

bool Linemanager::run(std::ostream& out)
{
	// while pointer  is not  null  run  run and  validate  so tis a linked list 
	//run the entire  que from strart (begin) once you run an entire  cycle
	*(Linestart) += std::move(ToBeFilled.back());
	Task* current = Linestart;
	do  {
		current->runProcess(out);
		if (current->getnextTask() != nullptr)
		{
			current->moveTask();
			current = current->getnextTask();
		}
		else {//check if order is completed, if order is completed move  order to  completed.
			CustomerOrder possiblecomplete;
			current->getCompleted(possiblecomplete);
			if (!possiblecomplete.empty())
				Completed.push_back(std::move(possiblecomplete));
		}
	} while (current->getnextTask() != nullptr);

	return(Completed.size() == m_cntCustomerOrder);
}

void Linemanager::displayCompleted(std::ostream& out) const
{
	auto runfunc = [&](const CustomerOrder& single) {
		single.display(out);
	};
	std::for_each(Completed.begin(), Completed.end(), runfunc);
}

void Linemanager::validateTasks() 
{
	auto runfunc = [&](Task* single) {
		single->validate(std::cout);
	};
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runfunc);
}
