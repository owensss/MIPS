#include <iostream>
#include <string>
#include "CommentParser.hpp"
#include "tokenizer.hpp"

int main() {
	using namespace std;
	string str;
	CommentParser cp;
	Tokenizer tk;
	while (1) {
		getline(cin, str);
		tk.set(str);
		auto begin = tk.begin();
		auto end = tk.end();
		for (auto iter=begin; iter != end; ++iter) {
			cout << iter->tk << " ";
		}
		cout << endl;

		cp.setStatement(begin, end);
		
		for (auto iter=begin; iter != end; ++iter) {
			cout << iter->tk << " ";
		}
		cout << endl;
	}
}
