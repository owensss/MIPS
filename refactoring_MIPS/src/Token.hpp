/* by owensss */
#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <string>
#include <vector>

/*
 * a simple token struct with a simple constructor
 * col is the column of the token
 */
struct Token {
	public:
		Token(const std::string& _tk, unsigned _col=0) :tk(_tk), col(_col) {}
		Token(const char* _tk, unsigned _col=0) :tk(_tk), col(_col) {}
		Token() :tk("#unknown", 0){}
		~Token() {}
	// ±ãÃñº¯Êý
	public:
		operator std::string&() {return tk;}
		operator const std::string&() const {return tk;}
		bool operator==(const Token& rhs) const { return tk==rhs.tk;}
		// bool operator==(const char* rhs) const { return tk==rhs;}
		Token& operator=(const Token& rhs) {tk=rhs.tk; col=rhs.col; return *this;}
	public:
		std::string tk;
		unsigned col;
};

typedef std::vector<Token> Tokens;
typedef Tokens::iterator Token_iter;

#endif
