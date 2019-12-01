// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 29/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"
//Custom constructor with the following arguments:

//a reference to an unmodifiable std::string.This string contains the filename specified by the user to be used for linking the assembly line objects(example: AssemblyLine.dat)
//a reference to a std::vector<Task*> that contains the addresses of all the Task objects created for the assembly line
//a reference to a std::vector<CustomerOrder> that contains all the CustomerOrder objects to be filled
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
		else
			Lineend = begin;
	}

}
// this function performs one cycle of operations on the assembly line
bool LineManager::run(std::ostream& out)
{
	auto runforeach = [&](Task* current) {
		current->runProcess(out);
	};
	auto moveforeach = [](Task* current) {		
			current->moveTask();
	};
	if (Linestart != nullptr) {
		if (ToBeFilled.size() != 0) {
			*(Linestart) += std::move(ToBeFilled.front());
			ToBeFilled.pop_front();
		}
		
		std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runforeach);
		std::for_each(AssemblyLine.begin(), AssemblyLine.end(), moveforeach);
		CustomerOrder possiblecomplete;		
		if (Lineend->getCompleted(possiblecomplete))
			Completed.push_back(std::move(possiblecomplete));
	}
	return(Completed.size() == m_cntCustomerOrder);
}
//displays all the orders that were completed
void LineManager::displayCompleted(std::ostream& out) const
{
	auto runfunc = [&](const CustomerOrder& single) {
		single.display(out);
	};
	std::for_each(Completed.begin(), Completed.end(), runfunc);
}
//validates each task on the assembly line
void LineManager::validateTasks()
{
	auto runfunc = [&](Task* single) {
		single->validate(std::cout);
	};
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), runfunc);
}
