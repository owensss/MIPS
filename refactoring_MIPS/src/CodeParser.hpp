#pragma once
#define _PARSER_CLASS_FAMILY
#include "Parser.hpp"
#include "ParserCommon.hpp"
#include <cstddef>

class MainParser;

/*
 * note that this parser parse single line assembly code
 */
class CodeParser : public IParser {
	public:
		CodeParser(size_t start_address=0);
		bool setStatement(iter_para);
		bool parseResult(MainParser&);
	private:
		
};
