/* by owensss */
#ifndef _MISC_HPP_
#define _MISC_HPP_
/*
 * this file comes from another work of mine
 */

#include <string>
 
namespace misc {
	bool isExp(const char* word);
	bool isDigit(char a);
	bool isWord(const char* word);
	inline bool isWord(const std::string& word) {return isWord(word.c_str());}
	bool isToken(const std::string& word);
	bool isNumber(const char* word);
	bool isBlank(char c);
	bool isAllBlank(const char* word);
	std::string toLower(const std::string& str);
	// remove leading blanks only
	void removeBlank(std::string& str);
	std::string toHex(const std::string&);
	std::string toHex(unsigned num);
	// hex to binary
	int h2b(const char* word);
	// oct to binary
	int o2b(const char* word);
	// dec to binary
	int d2b(const char* word);
	// binary to dec
	unsigned b2d(const std::string& word);
	int Calc(const char* word);
	std::string toBinary(const std::string&);
	// no '_'
	bool isLetter(char c);
};

#endif
