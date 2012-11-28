#include "CodeAsm.hpp"
#include "SyntaxFilter.hpp"

/*
 * always assume the comments are removed
 */
bool CodeAsm::setStatement(iter_para) {
	SyntaxFilter sf;
	if (iter==end) {
		setErr(iter, "End reached", err_eof);
		return false;
	}
	
	string first = iter->tk;
	// the last char of the string
	if (first.at(first.size()-1) == ':') { // a label 
		// remove the last ':'
		insertLabel(first.substr(0, first.size()-1));
	} else {
		processInstruction(iter, end);
	}
	adv_iter(iter, end);

	sf.GetInput(first);
}
