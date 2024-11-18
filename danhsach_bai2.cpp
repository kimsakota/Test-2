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
	int count;
};

list* make_list() {
	list* L = new list;
	L->head = L->tail = 0;
	L->count = 0;
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
	L->count++;
}

void add_last(list* L, int data) {
	node* p = make_node(data);
	if (is_list_empty(L))
		L->head = p;
	else L->tail->next = p;
	L->tail = p;
	L->count++;
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

void prinf(const list* L) {
	node* p = L->head;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

void tach_danh_sach(const list* L, int pos) {
	list* p = make_list(), * q = make_list();
	node* tmp = L->head;
	pos--;
	while (pos--) {
		add_last(p, tmp->data);
		tmp = tmp->next;
	}
	while (tmp) {
		add_last(q, tmp->data);
		tmp = tmp->next;
	}
	prinf(p);
	prinf(q);
}

int main() {
	list* L = make_list();
	for (int i = 1; i <= 12; i++)
		add_last(L, i);
	prinf(L);
	int pos = 5;
	tach_danh_sach(L, pos);
}
