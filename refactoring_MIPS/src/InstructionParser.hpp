#ifndef _INSTRUCTION_PARSER_HPP_
#define _INSTRUCTION_PARSER_HPP_
#include "Parser.hpp"
#define _PARSER_CLASS_FAMILY

class InstructionParser : public Parser { 
	bool setStatement(iter_para);
};

#undef _PARSER_CLASS_FAMILY
#endif

