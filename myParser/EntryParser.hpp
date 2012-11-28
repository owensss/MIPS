#pragma once

#include "Parser.hpp"
#include "GList.hpp"
#include <string>
#include <ostream>

template <typename Me, typename T = Token_iter>
class EntryParser : public Parser<T> {
	public:

	typedef T Iter;
	typedef bool (*Action) (Iter& iter, Iter& end, Me&); // action funtion called after a match

	struct Tuple { // tuple structure of the GList
		std::string entry;
		Action action;
		// end of member decalaration
		bool operator==(const std::string& _entry) {return entry==_entry;}
		bool operator==(const EntryParser::Tuple& _entry) {return entry==_entry.entry;}
		Tuple(const std::string& ent, Action act) :entry(ent), action(act) {}
		Tuple() {}
		friend std::ostream& operator << (std::ostream& os, const Tuple& tp) {
			os << tp.entry << "#";
			if (tp.action==nullptr) os << "null";
			else os << (int) (tp.action);
			return os;
		}
	};

	public:
		virtual ~EntryParser() {}
		// set entry statement
		// if the statement is blank, do nothing
		bool setStatement(T& iter, T end) {
			if (iter==end) return true; // nothing to parse

			entries.head();
			cerr << entries.value().entry << endl;
			while (1) {
				if (! findFirst(entries, iter->tk)) { // not found, error
					std::string desc = ListAllCandidate();
					this->setErr("", "statement err, cadidate tokens are \""+desc+'\"');
					return false;
				}
				if (++iter==end) return true;

				entries.child();
			}
#ifdef _DEBUG_
			cerr << "setstatement over" << endl;
#endif
			// entries.value().action(*this);
			return true;
		}
		// add an entry.
		// this function addes the token to entry.
		// only the last token is set to the action
		// action is a function pointer which will be called if the input matches
		virtual EntryParser& add(const Tokens& tk, Action act) {
			size_t end = tk.size(); // the index we shall put the entry
			if (end==0) { // empty entry
				entries.rootValue().action=act;
				return *this; 
			}

			entries.head();
			for (size_t i = 0; i < end; ++i) {
				if (! findFirst(entries, tk[i])) { // not found
					for (size_t j = i; j < end; ++j) {
						entries.insert(Tuple(tk[i], nullptr));
					}
					// associate the last entry to the action
					entries.value().action = act;
					return *this; // match end
				}
				// if found, then
				// loop into its child
				entries.child();
			}
			this->setErr("", "[EntryParser]adding existing tokens, not set");
			return *this;
		}

		virtual EntryParser& add(const Token& tk, Action act) {
			entries.head();
			if (! findFirst(entries, tk)) { // not found
				entries.insert(Tuple(tk, act));
			} else {
				if (entries.current()->child()!=nullptr) { // action not set
					entries.value().action = act;
				} else {
					this->setErr("", "[EntryParser]adding existing token, not set");
				}
			}
			return *this;
		}

	protected:
		// find in current's successes
		bool findFirst(GList<Tuple>& entires, const std::string& Entry) {
			entries.save_current();
			while (1) {
				if (entries.current() != nullptr) {
					if (entries.value().entry==Entry) {
						// do not load the last state. 
						// the pointer now points to the found item
						return true;
					}
				} else break; // loop reaches the end
				entries.next();
			}
			entries.load_current(); // load to last state
			return false;
		}
		std::string ListAllCandidate(void) {
			std::string res;
			entries.save_current();

			while (entries.current() != nullptr) {
				res += entries.value().entry+" ";
				entries.next();
			}

			entries.load_current();
			return res;
		}
	protected:
		GList<Tuple> entries;
};

