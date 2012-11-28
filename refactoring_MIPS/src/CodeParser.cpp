#include "CodeParser.hpp"

bool CodeParser::setStatement(iter_para) {
	if (iter==end) return true;

	// test comment
	CommentParser cp;
	cp.setStatement(iter, end);
	if (iter==end) return true;
}
