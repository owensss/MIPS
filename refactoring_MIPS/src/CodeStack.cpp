#include "CodeStack.hpp"
#include "Code.hpp"
#include <algorithm>

void CodeStack::setAddress(uint32_t address) {
	addr = address;
}

bool CodeStack::insert(const Code& code) {
#ifdef _DEBUG_
	clog << "[InsertCode]" << code.name << ":" << code.rs << ":"
		<< code.rd << ": " << code.rt << ":" << code.Imd() << endl;
	clog << "[InsertCode]" << code.lb << ":" << code.Dirt() << endl;
#endif
	if (! validate(code))
	{
		// ÃÓø”
		std::cerr << "[debug][codeformat]" << cf << endl;
		return false;
	}

	origin.push_back(code);
	return true;
}

bool CodeStack::insert(const std::string& label, const Code& code) {
	if (! insert(code) ) return false;
	if (! insertLabel(label)) return false;
	return true;
}

bool insertLabel(const std::string& label) {
	// label name exist
	if (labels.find(label)) {
		setErr("label name "+label+" exist");
		return false;
	}
	// size-1 = index of current
	labels.insert(pair<string, int>(label, origin.size()-1));
}

bool CodeStack::validate(const Code& cf)
{
	TypeFilter tf;
	// returns r, i, or j
	switch (tf.Get(cf.name))
	{
		// r requires 
		// rs, rd, rt
		case 'r':
			if (cf.rs!="" && cf.rd!="" && cf.rt!="")
				return true;
			setErr("rs or rt or rd not set");
			return false;
		// i requires
		// rs, rt, imd(or lb)
		case 'i':
			if (cf.rs!="" && cf.rt!="" && cf.dirt())
				return true;
			setErr("rs or rt or immediate not set");
			return false;
		// j requires
		// imd
		case 'j':
			if (cf.dirt())
				return true;
			setErr("immediate not set");
			return false;
		default:
			// ’‚ «…∂
			return false;
	}
	return true;
}


bool CodeStack::generate(void) {
	TypeFilter tf;
	SyntaxFilter sf;

	// always be one-to-one map to origin
	binary.clear();
	for (auto& code : origin)
	{
		switch (tf.Get(code.name))
		{
			case 'r':
				binary.push_back(
					bitset<6>(sf.GetOutput(code.name)[0]).to_ulong()<<26
					+code.rs << 21
					+code.rt << 16
					+code.rd << 11
					+0       << 6  // shamt
					+bitset<6>(sf.GetOutput(code.name)[5]).to_ulong()
				);
				break;
			case 'i':
				binary.push_back(
					bitset<6>(sf.GetOutput(code.name)[0]).to_ulong()<<26
					+code.rs << 21
					+code.rt << 16
					+bitset<16>(
						code.label()!="" ? // label is a string? map it : the set immediate number
							code.setLabelAddress(labels[code.label()])
						  	:code.Imd()
					).to_ulong()
				);
				break;
			case 'j':
				binary.push_back(
					bitset<6>(sf.GetOutput(code.name)[0]).to_ulong()<<26
					+bitset<26>(
						code.Imd()
					).to_ulong()
				);
				break;
		}
#ifdef _DEBUG_
		cerr << "[GenerateCode]" << code.code << endl;
#endif
	}
}
