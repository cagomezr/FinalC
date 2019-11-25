#include <string>
#include <ostream>
#include "Utilities.h"

int main() {
	Utilities deltatesto;
	Utilities::setDelimiter(',');
	std::string data1 = "wing,1992,xwg1";
	size_t  dat1 = 0;
	bool more1 = false;
	std::string gundam = deltatesto.extractToken(data1, dat1, more1);
	std::string year = deltatesto.extractToken(data1, dat1, more1);
	std::string code = deltatesto.extractToken(data1, dat1, more1);
	
	dat1 = 0;
	more1 = false;
	Utilities::setDelimiter('|');
	std::string data2 = "g|1991|gghma";
	std::string gundam2 = deltatesto.extractToken(data2, dat1, more1);
	std::string year2 = deltatesto.extractToken(data2, dat1, more1);
	std::string code2 = deltatesto.extractToken(data2, dat1, more1);


};