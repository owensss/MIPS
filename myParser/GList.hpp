#pragma once
#include <cstddef>
#include <queue>
#define _DEBUG_

#ifdef _DEBUG_
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#endif
// π„“Â±Ì

template <typename T> class GList;

template <typename T>
class GNode {
	// elements are not assessible
	GNode<T>* Next;
	GNode<T>* Child;
	T value;
	public:
		friend class GList<T>;
		// default constructer
		GNode<T> () :Next(nullptr), Child(nullptr) {}
		GNode<T> (const T& val) :value(val) {Child=nullptr; Next=nullptr;}
		const GNode<T>* next(void) const {return Next;}
		const GNode<T>* child(void) const {return Child;}
		operator T&() {return value;}
};

template <typename T>
class GList {
	public:
		GList(void) {
			root = new GNode<T>();
			father = root;
			cur = father->Child;
			bk_cur = cur;
			bk_father = father;
		}
		~GList() {
			clear();
			delete root;
		}
	// accessing the current pointer
	// the current pointer points to a pointer accessible by the user.
	// note: current CAN be a nullptr
	public:
		const T& value(void) const {return cur->value;}
		T& value(void) {return cur->value;}
		const T& rootValue(void) const {return root->value;}
		T& rootValue(void) {return root->value;}
		// returns the current position of the GList
		GNode<T>* current() {return cur;}
		// iterate current to its next position
		GNode<T>* next(void) {father = cur; cur=cur->Next; return current();}
		// iterate the previous position
		// note that this takes O(N) time
		// GNode<T>* previous(void) ;
		// iterator current to its child position
		GNode<T>* child() {father = cur; cur=cur->Child; return current();}
		// to root->child
		GNode<T>* head(void) {father = root; cur = father->Child; return current();}
		/* all below performs a breath first search */
		// found in current's children
		// if current == nullptr, return false
		// place the current pointer to the found item
		// otherwise do not change the position
		// if current==
		bool find(const T& value) {
#ifdef _DEBUG_
			cerr << "------------------------" << endl;
#endif
			if (cur==nullptr) return false;
			GNode<T>* p = cur; 	// current
			GNode<T>* tp = father; 	// parent queue

			using std::queue;
			queue<GNode<T>*> q;		// queue
			queue<GNode<T>*> qp;	// parent queue

			if (father==root) { // special case
				tp = root;
				p = tp->Child;
				while (p!=nullptr) {
					q.push(p);
					qp.push(tp);
					tp = p;
					p = tp->Next;
				}
			} else {
				q.push(p);
				qp.push(tp);
			}

			while (! q.empty()) {
				p=q.front();
				q.pop();
				tp = qp.front();
				qp.pop();
#ifdef _DEBUG_
				cerr << "iterating:" << p->value << "#Children:";
#endif
				if (p->value==value) { // test t
					cur = p; 
					father = tp; // pop parent
#ifdef _DEBUG_
					cerr << "[res]" << father->value << "#" << cur->value << endl;
					cerr << "------------------------" << endl;
#endif
					return true;
				}
				
				// push all childs
				tp = p;
				p = p->Child;
				while (p != nullptr) {
#ifdef _DEBUG_
					cerr << p->value << "#";
#endif
					q.push(p);
					qp.push(tp);
					tp = p;
					p = tp->Next;
				}
#ifdef _DEBUG_
				cerr << endl;
#endif
			}

#ifdef _DEBUG_
			cerr << "------------------------" << endl;
#endif
			return false; // not found
		}
		// these all finally calls the find(value);
		bool search(const T& value) {return find(value); }
		// begin the search from root
		bool findRoot(const T& value) {head(); find(value); return cur;}
		bool searchRoot(const T& value) {return findRoot(value);}
	// telling the state of current position
	public:
		bool isFirst(void) const {return father->Child==cur;}
		bool isLast(void) const {if (current==nullptr)return false; return cur->next==nullptr;}
		// has no child
		bool isLeaf(void) const {if (current==nullptr)return false; return cur->child==nullptr;}
	// accessing the GList using the current pointer
	// all returns the current pointer
	public:
		// erase the current pointer.
		// the behaviour is just what you think
		GNode<T>* erase(void) {
			if (cur==nullptr) {
				return cur;
			}

			if (isFirst()) { // the first item of the list
				father->Child = cur->Next;
				cur->Next = nullptr;
				clear_children(cur);
				cur = father->Child;

				return cur;
			} else {
				father->Next = cur->Next;
				cur->Next = nullptr;
				clear_children(cur);
				cur = father->Next;

				return cur;
			}

			return cur;
		}
		// insert after, current will move to the inserted item
		GNode<T>* insert(const T& value) {
			if (cur==nullptr) {
#ifdef _DEBUG_
				cerr << "pushing fisrt#" << value << endl;
#endif
				if (father==root) {
					father->Child = new GNode<T>(value);
					cur = father->Child;
					return cur;
				} else {
					if (father->Next==cur) { // father can be the parent or the previous item of current
						father->Next = new GNode<T>(value);
						cur = father->Next;
						return cur;
					} else {
						father->Child = new GNode<T>(value);
						cur = father->Child;
						return cur;
					}
				}
			} else {
				/* let f, c, n donates father, current and next
				 * they are linked like this: f->c->n
				 * note that whether father->Child=current or father->Next=current doesn't matter
				 * now we are to insert i between c and n
				 */
				// move father and current forward
				// f, c->n
				father = cur;
				// oldf->f->c, n
				cur = father->Next;
				// allocate new node
				// f->i c->n
				father->Next = new GNode<T>(value);
				// f->i->c->n
				father->Next->Next = cur;
				// f->i, c->n
				cur = father->Next;
#ifdef _DEBUG_
				cerr << "pushing next#" << value << endl;
#endif
			}

			return cur;
		}
		// insert before, current will move to the inserted item
		GNode<T>* insert_before(const T& value) {
			if (father->Next == cur) {
				// father can not be null
				father->Next = new GNode<T>(value);
				father->Next->Next = cur;
				cur = father->Next;
			} else { // father->Childe == current
				father->Child = new GNode<T>(value);
				father->Child->Next = cur;
				cur = father->Child;
			}

			return cur;
		}
		// insert to current's child
		GNode<T>* insert_child(const T& value) {
			if (cur==nullptr) {
				cur = new GNode<T>(value);
			} else {
				father = cur;
				cur = father->Child;
				father->Child = new GNode<T>(value);
				father->Child->Child = cur;
				cur = father->Child;
			}

			return cur;
		}
		// this will cause the current travels to the end of the list
		GNode<T>* push_back(const T& value) {
			while (cur != nullptr) {
				cur = cur->Next;
			}
			return insert(value);
		}

		void clear(void) {
#ifdef _DEBUG_
			cerr << "clear" << endl;
#endif
			clear_children(root->Child);
			father = root;
			root->Child = nullptr;
			cur = root->Child;
		}
			
		// clear all its children and 'next' nodes
		void clear_children(GNode<T>* ptr) {
			if (ptr->Child != nullptr)
				clear_children(ptr->Child);
			if (ptr->Next != nullptr)
				clear_children(ptr->Next);

			delete ptr;
		}

		GNode<T>* save_current(void) {bk_cur = cur; bk_father=father; return cur;}
		GNode<T>* load_current(void) {cur = bk_cur; father=bk_father; return cur;}
	private:
		GNode<T>* root;
		GNode<T>* father; // the pointer points to cur
		GNode<T>* cur; // the 'current' pointer
		GNode<T>* bk_cur; // backup current
		GNode<T>* bk_father; // backup father
};
