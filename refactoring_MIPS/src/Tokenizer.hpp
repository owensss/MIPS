#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_

/*
 * author: 	owensss
 * date:	20121101
 * version:	01
 */

#include "Token.hpp"
#include <vector>
#include <string>

class UnterminatedQuote {
	public:
		UnterminatedQuote(const std::string& _what, std::string::const_iterator _where) :err(_what), here(_where){}
		const Token& what() const {return err;}
		const std::string::const_iterator& where(void) const {return here;}
	private:
		Token err;
		std::string::const_iterator	here;
};

/*
 * this class split the input string into tokens
 * skips whitespace, tabs, '\n'. etc
 * it does nothing more than that
 */
class Tokenizer { // exception save
	public:
		// set the pure string
		void set(const std::string& input);
		// get the result 
		const Tokens& get(void) const {return output;}
		// get the result's beginning iterator
		Token_iter begin(void) {return output.begin();}
		// get the result's ending iterator
		Token_iter end(void) {return output.end();}
		// combination of set() and get()
		const Tokens& tokenize(const std::string& input);
	// error handling
	public:
		bool fail(void) const {return failcode!=0;}
		const Token& what(void) const {return err;}
		void clrerr(void) {failcode=0; err="";}
	public:
		Tokenizer() {failcode=0;}
		~Tokenizer() {}
	private:
		// the main loop, this one does nothing but call gaoWord until it reaches
		// the end of the input
		void gao(const std::string& input);
		/* this is the main function that grabs tokens from word
		 * params: beginning iter & end iter
		 * return: parsed string, the new beginning-iter
		 * note: that means, iter will be modified
		 */
		std::string gaoWord(std::string::const_iterator& iter, std::string::const_iterator end);
	private:
		Tokens output;
	// error handling
	private:
		//
		Token err;
		// currently, there is only one fail code indicating the unterminated quoatation
		unsigned failcode;
};

#endif
