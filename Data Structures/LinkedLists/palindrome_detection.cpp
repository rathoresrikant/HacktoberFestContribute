#include <iostream>
#include <memory>
#include <stack>


using namespace std;


template <class T>
class _list_el;

template <class T>
class linked_list {
	
public:
	bool is_palindrome() const;
	void insert(const T& val);
	void remove_at(const size_t& index);
	void print() const;
	inline const size_t& length() const { return _length; }
private:
	unique_ptr<_list_el<T>> _head;
	_list_el<T>* _tail = nullptr;
	size_t _length = 0;
};

template <class T>
class _list_el{
template <class _T>
friend class linked_list;
public:
	_list_el(const T& val) : _val(val) {}
	inline const T& get_value() const { return _val; }
	inline void set_value(const T& val) { _val = val; }
	inline _list_el<T>* get_next() const { return _next.get(); }
	inline void set_next(const T& val) { _next = make_unique<_list_el<T>>(val); }
private:
	T _val;
	unique_ptr<_list_el<T>> _next;
};

template <class T>
void linked_list<T>::print() const {
	_list_el<T>* tmp_el = _head.get();
	while(tmp_el != nullptr){
		cout << tmp_el->get_value() << endl;
		tmp_el = tmp_el->get_next();
	}
}

template <class T>
bool linked_list<T>::is_palindrome() const {
	stack<T> value_stack;
	_list_el<T>* tmp_el = _head.get();
	int i = 0;
	while(i != _length/2){
		value_stack.push(tmp_el->get_value());
		tmp_el = tmp_el->get_next();
		++i;
	}
	if(_length % 2 == 1)
		tmp_el = tmp_el->get_next();
	while(tmp_el != nullptr){
		if(value_stack.top() != tmp_el->get_value())
			return false;
		value_stack.pop();
		tmp_el = tmp_el->get_next();
	}
	return true;
}

template <class T>
void linked_list<T>::insert(const T& val){
	if(_tail == nullptr){
		_head = make_unique<_list_el<T>>(val);
		_tail = _head.get();
		++_length;
		return;
	}
	_tail->set_next(val);
	_tail = _tail->get_next();
	++_length;
}

template <class T>
void linked_list<T>::remove_at(const size_t& index){
	if(index >= _length)
		throw -1;
	if(index == 0){
		_head = move(_head->_next);
		--_length;
		return;
	}
	int i = 0;
	_list_el<T>* tmp_el = _head.get();
	while(i++ != index-1)
		tmp_el = tmp_el->get_next();
	tmp_el->_next = move(tmp_el->_next->_next);
	--_length;
}