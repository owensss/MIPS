/* by owensss */
#include "misc.hpp"
#include <cstring>
#include <string>
#include <bitset>

using std::string;
using std::bitset;

namespace {
	char GetHexCharacter(const std::string& str);
	std::string GetBinaryChar(char ch);
};

bool misc::isNumber(const char* word)
{
	if (strlen(word)==0) return false;
	bool splited = false;
	const char* p = word;
	while (isBlank(*p)) ++p;
	for (; *p != '\0'; ++p)
		if (!isDigit(*p)) {
			if (isBlank(*p)) {
				// 123 23 form returns false
				if (splited) return false;
				else {
					splited = true;
					do ++p; while (isBlank(*p));
					--p; // for loop will automaticaly add it
				}
			}
			else return false;
		} else if (splited) return false;

	return true;
}

bool misc::isLetter(char c) {
	return ( (c>='a'&&c<='z') || (c>='A'&&c<='Z') );
}

bool misc::isBlank(char c) {
	return (c==' '||c=='\n'||c=='\0'||c=='\t');
}

// including dec & oct and hex
inline bool misc::isDigit(char w)
{
	return (w>='0'&&w<='9')||w=='x'||w=='X';
}

bool misc::isExp(const char* word)
{
	for (const char* p = word; *p != '\0' ;++p)
	{
		char a = *p;
		if ( !(isDigit(a)||a=='*'||a=='%'||a=='/'||a=='('||a==')'))
			return false;
	}

	return true;
}

// only contains _, a-Z
bool misc::isWord(const char* word)
{
	if (word==NULL) return false;
	if (word[0]=='\0') return false; // \0 is not a word
	for (const char* p = word; *p != '\0'; ++p)
	{
		char a = *p;
		if ( !(a=='_'||(a>='a'&&a<='z')||(a>='A'&&a<='Z')))
			return false;
	}

	return true;
}

int misc::h2b(const char* word) {
	return -1;
}

int misc::d2b(const char* word) {
	unsigned len = strlen(word);
	int result=0;
	for (unsigned i = 0; i < len; ++i)
	{
		if (word[i]>='0'&&word[i]<='9') {
			result *= 10;
			result += word[i]-'0';
		}
	}

	return result;
}
int misc::o2b(const char* word) { return 0; }
int misc::Calc(const char* word) { return 0; }

string misc::toBinary(const string& input)
{
	string tmp = "";

	for (unsigned i = 0; i < input.length(); ++i)
		tmp += GetBinaryChar(input[i]);

	return tmp;
}

namespace {

char GetHexCharacter(const std::string& str)
{
	if(str.compare("1111") == 0) return 'F';
	else if(str.compare("1110") == 0) return 'E';
	else if(str.compare("1101")== 0) return 'D';
	else if(str.compare("1100")== 0) return 'C';
	else if(str.compare("1011")== 0) return 'B';
	else if(str.compare("1010")== 0) return 'A';
	else if(str.compare("1001")== 0) return '9';
	else if(str.compare("1000")== 0) return '8';
	else if(str.compare("0111")== 0) return '7';
	else if(str.compare("0110")== 0) return '6';
	else if(str.compare("0101")== 0) return '5';
	else if(str.compare("0100")== 0) return '4';
	else if(str.compare("0011")== 0) return '3';
	else if(str.compare("0010")== 0) return '2';
	else if(str.compare("0001")== 0) return '1';
	else if(str.compare("0000")== 0) return '0';
	else if(str.compare("111")== 0) return '7';
	else if(str.compare("110")== 0) return '6';
	else if(str.compare("101")== 0) return '5';
	else if(str.compare("100")== 0) return '4';
	else if(str.compare("011")== 0) return '3';
	else if(str.compare("010")== 0) return '2';
	else if(str.compare("001")== 0) return '1';
	else if(str.compare("000")== 0) return '0';
	else if(str.compare("11")== 0) return '3';
	else if(str.compare("10")== 0) return '2';
	else if(str.compare("01")== 0) return '1';
	else if(str.compare("00")== 0) return '0';
	else if(str.compare("1")== 0) return '1';
	else if(str.compare("0")== 0) return '0';
	else return 'x';
}


std::string GetBinaryChar(char ch)
{
	switch (ch)
	{
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': 
		case 'a': return "1010";
		case 'B':
		case 'b': return "1011";
		case 'c': 
		case 'C': return "1100";
		case 'D': 
		case 'd': return "1101";
		case 'e': 
		case 'E': return "1110";
		case 'F': 
		case 'f': return "1111";
	}

	return "xxxx";
}
}

string misc::toHex(const std::string& rowresult)
{
	std::string endresult = "";
	if (rowresult.length()-4 < 0) 
		endresult += GetHexCharacter(rowresult);
	else {
		for(unsigned i = rowresult.size()-4; (int)(i) >= 0; i = i-4)
		{
			char c = GetHexCharacter(rowresult.substr(i,4));
			endresult = c+endresult;
		}
	}

	unsigned unzero=endresult.size()-1;
	// remove leading zeros
	for (unsigned i = 0; i < endresult.size(); ++i) {
		if (endresult[i]!='0') {
			unzero = i;
			break;
		}
	}

	endresult=endresult.substr(unzero);
	if (endresult=="") endresult="0";
	return endresult;
}

string misc::toHex(unsigned num) {
	return toHex(std::bitset<32>(num).to_string());
}

unsigned misc::b2d(const string& word) {
	return bitset<32>(word).to_ulong();
}

void misc::removeBlank(string& str) {
	for (unsigned i = 0; i<str.size(); ++i) 
		if (!isBlank(str[i])) { str = str.substr(i); return ;}
}

bool misc::isAllBlank(const char* word) {
	unsigned len = strlen(word);
	for (unsigned i = 0; i < len; ++i)
		if (! isBlank(word[i])) return false;
	return true;
}

string misc::toLower(const string& str) {
	string tmp="";
	for (auto c : str) {
		if (c>='A'&&c<='Z') {
			c=c-'A'+'a';
		}
		tmp+=c;
	}

	return tmp;
}

bool misc::isToken(const std::string& word) {
	if (word.size()==0) return false;
	if (! ( isLetter(word[0])||word[0]=='_') )
		return false;

	for (unsigned i = 1; i < word.size(); ++i) {
		if (! (isLetter(word[i])||isDigit(word[i])||word[i]=='_') )
			return false;
	}

	return true;
}
