#pragma once
#include "Token.hpp"
template <typename T> class Parser;
template <typename M, typename T> class EntryParser;
typedef Token_iter Iter;
typedef Parser<Iter> IParser;
// typedef EntryParser<MainParser, Iter> EntryParser;
#ifdef _PARSER_CLASS_FAMILY
#define iter_para Iter& iter, Iter& end
#endif
