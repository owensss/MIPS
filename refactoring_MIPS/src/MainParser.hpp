#ifndef _MAIN_PARSER_HPP
#define _MAIN_PARSER_HPP

#define _PARSER_CLASS_FAMILY
#include "EntryParser.hpp"
#include "ParserCommon.hpp"
#include "CodeParser.hpp"

class MainParser;

bool codeParser(iter_para, MainParser& mp);

const Tokens CODE_START = {"code", "segment"};
const Tokens DATA_START = {"data", "segment"};
const Tokens CODE_END = {"end", "segment"};
const Tokens DATA_END  = {"end", "segment"};

class MainParser : public EntryParser<MainParser> {
	public:
		bool setStatement(iter_para);

		MainParser() {
			add(CODE_START, codeParser);
			// add(DATA_START, dataParser);
		}
	private:
		
};

#ifdef _PARSER_CLASS_FAMILY
#define AutoFunction(func_name, parser_name) \
bool func_name(iter_para, MainParser& mp) { \
	parser_name p; \
	p.setStatement(iter, end); \
	p.parseResult(mp); \
	p.passErrTo(mp); \
	return p.fail()==false; \
             \
}
#endif

AutoFunction(codeParser, CodeParser);
// AutoFunction(dataParser, DataParser);
#undef _PARSER_CLASS_FAMILY
#endif
