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

int average(const list* L) {
	node* p = L->head;
	int sum = 0; 
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum / L->count;
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
	list* L = make_list();
	for (int i = 1; i <= 12; i++)
		add_last(L, i);
	prinf(L);
	int aver = average(L);
	cout << "Trung binh: " << aver;
}
