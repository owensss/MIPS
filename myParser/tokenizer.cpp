/*
 * author: 	owensss
 * date:	20121101
 * version:	01
 */
#include "tokenizer.hpp"
#include "misc.hpp"
#include <string>
#include <vector>

// #define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
using std::endl;
using std::cerr;
#endif

using std::string;
using std::vector;

namespace {
	// if the tokens shall be take out alone
	inline bool seperate(char c) {return (c=='('||c==')'||c==','||c==';'||c=='=');}
}

void Tokenizer::set(const string& input) {
	clrerr();
	output.clear();
	gao(input);
}

void Tokenizer::gao(const string& input) {
	string token;
	auto iter = input.begin();
	auto end = input.end();
	try { // catch the Unterminated Quotation error
		while (iter != input.end()) { // calls gaoWord while end not reached
			token = gaoWord(iter, end);
			if (token != "") // note: the string, and the string's position
				output.push_back(Token(token, std::distance(input.begin(), iter)-token.size()+1));
		}
	} catch (const UnterminatedQuote& e) {
		err = e.what();
		err.col = std::distance(input.begin(), e.where());
		failcode = 1;
	}
}

const Tokens& Tokenizer::tokenize(const string& input) {
	set(input);
	return get();
}

string Tokenizer::gaoWord(string::const_iterator& iter, string::const_iterator end) {
	// true if began adding chars to result word
	bool adding =false;
	// escape ; ( ) , in "" or ''
	char escape = 0;
	using misc::isBlank;
	string result;
	for (; iter != end; ++iter) {
		char c = *iter;
		if (adding) { // if adding chars into word
			// if in " or ' closure
			if (escape != 0) {
				if (c==escape) {
					result += c;
					++iter;
					escape = 0;
					break;
				} else result += c;
			}
			// these characters are treated as a single token
			else if (seperate(c)||c=='\"'||c=='\'') {
					break;
			} else if (isBlank(c)) {
					break;
			} else result += c;
		}
		else { // if processing blank
			if (seperate(c)) { // (, ), ','
				++iter;
				result = c;
				break; // break from for each char
			} else if (! isBlank(c)) {
				if (c=='\''||c=='\"') escape = c;
				adding = true;
				result = c;
			}
		}
	}
	// unterminated quotation
	if (escape) throw UnterminatedQuote(result, iter);
	return result;
}

/*
#include <iostream>
using namespace std;

int main() {
	Tokenizer tk;
	string str;
	while (1) {
		getline(cin, str);
		if (str=="quit") break;
		else {
			tk.set(str);
			if (tk.fail()) {
				cerr << "unterminate quotation " << tk.what().tk << endl;
			} else {
				for (unsigned i = 0; i < tk.get().size(); ++i) {
					cout << tk.get()[i].col << " " << tk.get()[i].tk << endl;
				}
				cout << endl;
			}
		}
	}
}
*/
