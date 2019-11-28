#include "LineManager.h"

Linemanager::Linemanager(const std::string filename, std::vector<Task*>& taskBuilder, std::vector<CustomerOrder>& Customerorders)
{
	std::move(Customerorders.begin(), Customerorders.end(), std::back_inserter(ToBeFilled));
	std::copy(taskBuilder.begin(), taskBuilder.end(), std::back_inserter(AssemblyLine));
	std::ifstream file(filename);
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
		if (firstexec) {
			Linestart = begin;
			firstexec = false;
		}

		if (moreContent) {
			findstr = pointersmanager.extractToken(record, startCode, moreContent);
			end = (std::find_if(AssemblyLine.begin(), AssemblyLine.end(), lambdafind))[0];
			begin->setNextTask(*end);
		}
	}

}

bool Linemanager::run(std::ostream&)
{
	// while pointer  is not  null  run  run and  validate  so tis a linked list 
	//run the entire  que from strart (begin) once you run an entire  cycle

	//check if order is completed, if order is completed move  order to  completed.


	return (ToBeFilled.size() ==0);
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
