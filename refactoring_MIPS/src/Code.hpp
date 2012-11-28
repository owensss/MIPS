#pragma once
#include <exception>
#include <string>

struct Code;

class duplicatedImmediateNum : public std::exception {
	public:
		duplicatedImmediateNum(Code& code) noexcept(true){

		}

		virtual ~duplicatedImmediateNum(void) noexcept(true) {}
	private:
		duplicatedImmediateNum(void) noexcept(true);
};


/*
 * note: this structure does not stores the address information
 * all necessary information except the label remapping result are stored
 */
struct Code
{
	std::string name; // original name
	unsigned rs;
	unsigned rd;
	unsigned rt;
	unsigned shamt;
	private:
	bool dirt; // set to true if either imd or lb_imd is set
	int imd;
	std::string lb_imd;
	public:
	Code(Code&& cf) {
		name=std::move(cf.name);
		rs=cf.rs;
		rd=cf.rd;
		rt=cf.rt;
		lb_imd=std::move(cf.lb_imd);
		dirt=cf.dirt;
		imd=cf.imd;
	}

	Code(const Code& cf) {
		operator=(cf);
	}

	Code& operator=(const Code& cf) {
		name=cf.name;
		rs=cf.rs;
		rd=cf.rd;
		rt=cf.rt;
		lb_imd=cf.lb_imd;
		dirt=cf.dirt;
		imd=cf.imd;

		return *this;
	}
	// set imd by int
	void Imd(int _imd) {if (dirt==true) throw duplicatedImmediateNum(*this); imd=_imd; dirt=true;}
	// set imd by label name
	void Imd(const std::string& _imd) {if (dirt==true) throw duplicatedImmediateNum(*this); lb_imd = _imd; dirt=true;}
	// map label imd to int only if label is set
	const int setLabelAddress(int _imd) {if (lb_imd!="") if (dirt()) imd = _imd; else Imd(_imd); return imd;}
	const std::string& label(void) const {return lb_imd;}
	const int Imd(void) const {return imd;}
	// return true if whether int imd or string imd is set
	bool dirt(void) const {return dirt;}
	Code(void) {dirt=false;}
	void clear(void) {name=""; rs=-1; rd=-1; rt=-1; shamt=-1; dirt=false; lb_imd="";}
	friend std::ostream& operator << (std::ostream& os, const Code& cf);
};

