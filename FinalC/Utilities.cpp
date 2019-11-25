// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 16/11/2019
// Modified for milestone 2 and clarity:  23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
char Utilities::m_delimiter;
//sets the field  width
void Utilities::setFieldWidth(size_t fieldwidth)
{
	m_widthField = fieldwidth;
}
// gets the  current  field width
size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}
//extracts an item from  str sets start position, and  if there is more items  with flag more
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string returntoken = "";
	more = false;
	size_t dats = str.find(this->getDelimiter(), next_pos);		
	if (dats != std::string::npos) {
		returntoken = str.substr(next_pos , dats-next_pos);
		more = true;
	}
	else
		returntoken = str.substr(next_pos);
	next_pos = dats+1;
	if (returntoken.length() == 0)
		throw "no token";
	else if ((m_widthField < returntoken.length()))
		setFieldWidth(returntoken.length());
	return returntoken;
}
//sets m_delimiter
 void Utilities::setDelimiter(const char delim)
{
	  m_delimiter = char(delim);
}
 // gets the current delimiter
const char Utilities::getDelimiter() const
{
	return m_delimiter;
}
