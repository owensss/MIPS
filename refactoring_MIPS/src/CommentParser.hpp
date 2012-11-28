#ifndef _COMMENT_PARSER_HPP
#define _COMMENT_PARSER_HPP
#include "Parser.hpp"
#define _PARSER_CLASS_FAMILY

/*
 * note: this parser assume that end is the end of the line
 * note: this special parser does not modify the iter, however, it may
 * 			change end into the last valid instruction;
 */
class CommentParser : public Parser {
	public:
	   bool setStatement(iter_para);

};

#undef _PARSER_CLASS_FAMILY
#endif
