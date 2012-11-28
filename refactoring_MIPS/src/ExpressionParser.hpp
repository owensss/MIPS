#pragma once
/*
 * note: this parser do not accept variables
 */
#include "Parser.hpp"
#include "Token.hpp"
#define _PARSER_CLASS_FAMILY

class ExpressionParser : public Parser {
	public:
		bool setStatement(iter_para);
};

#undef _PARSER_CLASS_FAMILY
