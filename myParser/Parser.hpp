/* by owensss */
#ifndef _PARSER_HPP
#define _PARSER_HPP

#include "Token.hpp"
#include <string>
#include <vector>

/* note: classes inherit from Parser shall use the namespace PARSER
 * 		to gain the convenience provided by the predefined marcos
 */
namespace PARSER {

#include "../misc.hpp"

#define adv_iter(iter,end)                         \
if (! advance_iterator(iter, end)) {               \
	setErr(*(--iter), "statement not finished");   \
	return false;                                  \
}

// expect_token micro expect the token appears inthat place
// otherwise set the error code and returns false
#define expect_token(iter, token)                  \
if (misc::toLower(iter->tk) != token) {            \
	setErr(*iter,                                  \
		std::string("expect \"")+token+"\" here"); \
	return false;                                  \
}

// assert_keyword micro test if the name is a keyword
// if it is, then set the error code and returns false
#define assert_keyword(token)                      \
if (isKeyword(misc::toLower(token))) {             \
	setErr(token, "is a keyword");                 \
	return false;                                  \
}                                                  \

// this micro check if the token is a valid word:
// '_' + 'A'-'Z' + 'a'+'z'
#define assert_word(token)                         \
if (! misc::isToken(token)) {                       \
	setErr(token, "not a valid word");             \
	return false;                                  \
}

// this micro appears in the end of the expression
// where expect to be equal to end, otherwise it 
// shall be ';'
#define expect_end(iter)                           \
while (++iter!=end) expect_token(iter, ";");           

#define optional_bracket(statement)                \
if (iter->tk == "(") {                             \
	adv_iter(iter, end);                           \
	{statement}                                    \
	adv_iter(iter, end);                           \
	expect_token(iter, ")");                       \
}                                                  \
else {statement}                                   \

/* expect enclosed bracket */
#define enclosed_bracket(statement)                \
expect_token(iter, ")")                            \
adv_iter(iter, end)                                \
{statement}                                        \
adv_iter(iter, end);                               \
expect_token(iter, ")")                            

}; // end of namespace PARSER;
/*
 * error handling :
 *    use what() to fetch error information
 *    use clrerr() to clear current error state
 *    use fail() to test if there is an error
 *    if an error ocurrs, the content of the result is not defined
 *    while setting statement, I will automatically clear the error state
 * parsing:
 *    children shall overload setStatement to finish the parsing steps
 * note:
 *    没事就不要把这个包含进去了...
 */
template <typename T = Token_iter>
class Parser {
	public:
		/*
		 * note: the iter always points to the current 
		 * 		 token shall be processed.
		 * 		 end always points to the past-end end
		 */
		virtual bool setStatement(T& iter, T& end) = 0;
	public:
		Parser() {clrerr();}
		virtual ~Parser() {}
		virtual void clear() {clrerr();}
	// error handling functions
	public:
		// return the error message string
		const std::string& what(void) const {return errdesc;}
		// return the wrong token
		const Token& where(void) const {return err;}
		// clear err state
		void clrerr(void) {haserror = false; err.tk=""; err.col=-1;}
		// return true if there is error
		bool fail(void) {return haserror;}
		// pass error message to another Parser
		void passErrTo(Parser& p) {if(fail()) p.setErr(err, errdesc); else clrerr();}
		// return true if it is a keyword
		bool isKeyword(const Token& tk) {
			for (const auto& keyword : keywords)
				if (keyword==tk)
					return true;
			return false;
		}
	// error descriptor and error set functions
	protected:
		void setErr(Token tk, const std::string& des="syntax error") {err = tk; haserror = true; errdesc=des;}
		bool advance_iterator(T& iter, T end) {
			if (++iter==end) return false;
			else return true;
		}
	private:
		Token err;
		bool haserror;
		std::string errdesc;
		// inherited classes shall initialize the keyword variable
		static Tokens keywords;
};

#endif
