#include "MainParser.hpp"

bool MainParser::setStatement(iter_para) {
	EntryParser<MainParser>::setStatement(iter, end);
	entries.value().action(iter, end, *this);
}
