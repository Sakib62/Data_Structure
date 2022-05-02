#include <iostream>
#include <cstdarg>
#include <list>
#include <algorithm>
using namespace std;

void m(int* a) {
	(*a)++;
	// void fun(int* a) {
	// 	(*a)++;
	// }
	// fun(&a);
}

//ellipsis in c++ (Variable Arguments)
void hlw(...) {
	
	va_list list;
	//va_start(list, 5);
	int sum = 0;
	for(int i = 0; i < 4; i++) {
		sum += va_arg(list, int);
	}
	va_end(list);
	cout << sum << "\n";
}

void showList(list<int>lt) {
	for(auto hi : lt) 
		cout << hi << " ";
	cout << "\n";
}

int main() {
	int a = 10;
	m(&a);
	cout << a << "\n";
	//hlw(4, 3, 2, 5, 6);

	list<int>list1 = {2, 3, 4, 5};
	list<int>::iterator it;

	for(it = list1.begin(); it != list1.end(); it++) 
		cout << *it << " ";
	cout << "\n";

	list1.sort();
	showList(list1);

	list1.reverse();
	showList(list1);

	list1.pop_back();
	showList(list1);

	list1.pop_front();
	showList(list1);

	list1.push_back(100);
	showList(list1);

	list1.push_front(500);
	showList(list1);

	cout << list1.size() << "\n";
	cout << list1.front() << "\n";
	cout << list1.back() << "\n";
	cout << list1.empty() << "\n";
	cout << list1.max_size() << "\n";


	string s = "sakib";
	cout << s.front() << " " << s.back() << "\n";

	// for(it = list1.cbegin(); it != list1.cend(); it++) 
	// 	cout << *it << " ";
	// cout << "\n";

	it = list1.begin();
	list1.erase(it);
	showList(list1);

	//list1.assign(6, 4); //6 size, all are 4.
	//showList(list1);

	list1.remove(4); //remove all 4 from list
	showList(list1);

	list1.resize(5);//empty cell filled with 0's
	showList(list1);

	list1.push_back(3);
	list1.push_front(3);

	list1.unique(); //removes duplicate if they are in consecutive order. Only one remains.
	showList(list1);

	list1.emplace_front(54); //push_front
	showList(list1);

	list1.emplace_back(59); //push_back
	showList(list1);

	list<int>list2(6, 5); //this way or assign
	showList(list2);

	swap(list1, list2); //Must be of same type and size.
	cout << "List1: "; showList(list1);
	cout << "List2: "; showList(list2);

	list1.emplace(it, 54); //insert at a specified position.
	showList(list1);

	list1.insert(--it, 53);//same as emplace
	showList(list1);

	list1.merge(list2);//list2 becomes empty.
	showList(list1);
	showList(list2);

	list1.remove(5);
	showList(list1);

}
