#include "InstructionParser.hpp"
#include "SyntaxFilter.hpp"

bool InstructionParser::setStatement(iter_para) {
	SyntaxFilter sf;
	try {
		// first one is the instruction
		auto cur_ins = sf.GetInput(iter->tk);
		
		for (auto i = cur_ins.begin(); i != cur_ins.end(); ++i) {
			adv_iter(iter, end);
			auto word = *iter;
			switch(i->[0]) {
				// maybe have the form imd($reg);
				// or the same form as 'i';
				case 'a':
					if (word[0]=='$') {
						gaoReg(iter, end);
						adv_iter(iter, end);
						gaoImd(iter, end);
					}
					else {
						gaoImd(iter, end);
						adv_iter(iter, end);
						expect_token(iter, "(");
						adv_iter(iter, end);
						gaoReg(iter, end);
						adv_iter(iter, end);
						expect_Token(iter, ")");
					}
					break;
					
			}
		}
	} catch (const ExceptionSyntaxNotFound& e) {
		setErr(iter, "instruction not found");
		return false;
	}
}
