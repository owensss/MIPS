#include "CommentParser.hpp"
#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
using std::cerr;
using std::endl;
#endif

bool CommentParser::setStatement(iter_para) {
	if (iter == end) return true;

	size_t pos;

	// does not modify iter;
	auto _iter = iter;
	while (1) {
		if (_iter->tk[0] == '\'' || _iter->tk[0] == '\"') // make sure it's not quoted
			goto adv;

		pos = _iter->tk.find(";");
		if (pos != std::string::npos) { // if found single line comment
			_iter->tk = _iter->tk.substr(0, pos);
			if (_iter->tk.size()==0) end = _iter;
			else end = ++_iter;

			break;
		}
adv:
		if (++_iter==end) return true;
	}

	return true;
}
