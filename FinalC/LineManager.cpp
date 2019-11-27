#include "LineManager.h"

Linemanager::Linemanager(const std::string filename, std::vector<Task*>& taskBuilder, std::vector<CustomerOrder>& Customerorders)
{
	std::move(Customerorders.begin(), Customerorders.end(), std::back_inserter(ToBeFilled));
	std::copy(taskBuilder.begin(), taskBuilder.end(), std::back_inserter(AssemblyLine));
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";
	string record;
	Utilities pointersmanager
	while (!file.eof())
	{
		std::getline(file, record);
		Task* begin;
		Task* end;
		size_t startCode = 0u;
		bool moreContent = true;
		auto lambdafind = [&](string dats) {
			//add search logic			
			// returns the task data address;
		};
		
		std::string return1 = pointersmanager.extractToken(record, startCode, moreContent);
		if (morecontent) {
			std::string return2 = pointersmanager.extractToken(record, startCode, moreContent);
			begin = lambdafind(return1);
			end = lambdafind(return2);
			begin->setNextTask(end);
		}
	}

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
	auto runfunc = [&](Task& single) {
		single.validate(std::cout);
	};
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runfunc);
}
