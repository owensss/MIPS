#ifndef _CODE_ASM_HPP
#define _CODE_ASM_HPP
#include "Token.hpp"
#include "Parser.hpp"

#define _PARSER_CLASS_FAMILY
/*
 * this class deals with the assembly of code
 * including:
 * 		CodeStack => Generated code
 * 		instruction
 * 		pesudo instruction
 * 		ends while retrieves an error
 */
class CodeAsm {
	public:
		bool setStatement(iter_para);
		
		
};

#undef _PARSER_CLASS_FAMILY
#endif

