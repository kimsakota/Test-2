//Nguyen Kim Linh
//20233495
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

node* make_node(int data) {
	node* p = new node;
	p->data = data;
	p->next = NULL;
	return p;
}

struct list {
	node* head;
	node* tail;
};

list* make_list() {
	list* L = new list;
	L->head = L->tail = 0;
	return L;
}

bool is_list_empty(list* L) {
	return L->head == NULL;
}

void add_first(list* L, int data) {
	node* p = make_node(data);
	if (is_list_empty(L))
		L->tail = p;
	else p->next = L->head;
	L->head = p;
}

void add_last(list* L, int data) {
	node* p = make_node(data);
	if (is_list_empty(L))
		L->head = p;
	else L->tail->next = p;
	L->tail = p;
}

list* copy_list(const list* L) {
	list* tmp = make_list();
	node* p = L->head;
	while (p) {
		add_last(tmp, p->data);
		p = p->next;
	}
	return tmp;
}

list* merge_L2_after_L1(const list* L1, const list* L2) {
	list* tmp = copy_list(L1);
	node* p = tmp->head;
	while (p->next != NULL) p = p->next;
	p->next = L2->head;
	return tmp;
}


void prinf(const list* L) {
	node* p = L->head;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
int main() {
	list* L = make_list(), *L1 = make_list(), * L2 = make_list(), * L3 = make_list();
	add_last(L1, 1); add_last(L1, 1); add_last(L1, 1); add_last(L1, 1);
	add_last(L2, 2); add_last(L2, 2); add_last(L2, 2);
	add_last(L3, 3); add_last(L3, 3); add_last(L3, 3);
	
	cout << "L1: "; prinf(L1);
	cout << "L2: "; prinf(L2);
	cout << "L3: "; prinf(L3);
	//Ghép L2 vào sau L1 
	L = merge_L2_after_L1(L1, L2);
	cout << "L1 + L2: "; prinf(L);

	list* tmp = make_list();
	tmp = merge_L2_after_L1(L3, L2); //L3 vào trước L2
	tmp = merge_L2_after_L1(tmp, L1); // L1 vào sau L2 
	cout << "L3 + L2 + L1: "; prinf(tmp);
}
