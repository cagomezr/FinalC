// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 29/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"

LineManager::LineManager(const std::string filename, std::vector<Task*>& taskBuilder, std::vector<CustomerOrder>& Customerorders)
{
	std::move(Customerorders.begin(), Customerorders.end(), std::back_inserter(ToBeFilled));
	std::copy(taskBuilder.begin(), taskBuilder.end(), std::back_inserter(AssemblyLine));
	std::ifstream file(filename);
	m_cntCustomerOrder = ToBeFilled.size();
	Linestart = nullptr;
	
	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";
	std::string record;
	Utilities pointersmanager;
	while (!file.eof())
	{
		std::getline(file, record);
		Task* begin;
		Task* end;
		std::string findstr;
		size_t startCode = 0u;
		bool moreContent = true;
		auto lambdafind = [&](const Task* data) {
			return (data->getName().compare(findstr) == 0);
		};
		findstr = pointersmanager.extractToken(record, startCode, moreContent);		
		begin = *(std::find_if(AssemblyLine.begin(), AssemblyLine.end(), lambdafind));
		if (Linestart== nullptr)
			Linestart = begin;

		if (moreContent) {
			findstr = pointersmanager.extractToken(record, startCode, moreContent);
			begin->setNextTask(**(std::find_if(AssemblyLine.begin(), AssemblyLine.end(), lambdafind)));
		}
	}

}

bool LineManager::run(std::ostream& out)
{
	auto runforeach = [&](Task* current) {
		current->runProcess(out);
	};
	auto moveforeach = [&](Task* current) {
		CustomerOrder possiblecomplete;
		current->getCompleted(possiblecomplete);
		if (!possiblecomplete.empty())
			Completed.push_back(std::move(possiblecomplete));
		else
			current->moveTask();
	};
	if (Linestart != nullptr) {
		Task* current = Linestart;
		if (ToBeFilled.size() != 0) {
			*(Linestart) += std::move(ToBeFilled.front());
			ToBeFilled.pop_front();
		}
		
		std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runforeach);
		std::for_each(AssemblyLine.begin(), AssemblyLine.end(), moveforeach);
		
	}
	return(Completed.size() == m_cntCustomerOrder);
}

void LineManager::displayCompleted(std::ostream& out) const
{
	auto runfunc = [&](const CustomerOrder& single) {
		single.display(out);
	};
	std::for_each(Completed.begin(), Completed.end(), runfunc);
}

void LineManager::validateTasks()
{
	auto runfunc = [&](Task* single) {
		single->validate(std::cout);
	};
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runfunc);
}
