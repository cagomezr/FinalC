// Name:Carlos Antonio Gomez
// Seneca Student ID: 032936056
// Seneca email:cagomez@myseneca.ca
// Date of completion: 16/11/2019
// Modified for milestone 2 and clarity:  23/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#ifndef SDDS_UTILITIES
#define SDDS_UTILITIES
class Utilities {
	size_t m_widthField = 1;// sets utilites widthfield
	static char m_delimiter;// delimiter  static so it can be called at will and changed at wull
public:
	void setFieldWidth(size_t); //sets the field  width
	size_t getFieldWidth() const;// gets the  current  field width
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);//extracts an item from  str sets start position, and  if there is more items  with flag more
	static void setDelimiter(const char);//sets m_delimiter
	const char getDelimiter() const; // gets the current delimiter
};
#endif
