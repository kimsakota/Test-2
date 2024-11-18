//Nguyen Kim Linh
//20233495
#include <iostream>
using namespace std;

struct Node {
	int data;
	int pos;
	Node* next;
};

Node* make_node(int data, int pos) {
	Node* p = new Node;
	p->data = data;
	p->pos = pos;;
	p->next = NULL;
	return p;
}

struct DT {
	Node* head;
	Node* tail;
	int degree; 
};

DT* make_DT() {
	DT* P = new DT;
	P->head = P->tail = NULL;
	P->degree = -1;
	return P;
}

bool is_list_empty(DT* P) {
	return P->head == NULL;
}

void add_first(DT* P, int data, int pos) {
	Node* p = make_node(data, pos);
	if (is_list_empty(P))
		P->tail = p;
	else p->next = P->head;
	P->head = p;
	P->degree++;
}

void add_last(DT* P, int data, int pos) {
	Node* p = make_node(data, pos);
	if (is_list_empty(P))
		P->head = p;
	else P->tail->next = p;
	P->tail = p;
	P->degree++;
}

DT* copy_DT(const DT* dt) {
	DT* tmp = make_DT();
	Node* p = dt->head;
	while (p) {
		add_last(tmp, p->data, p->pos);
		p = p->next;
	}
	return tmp;
}

void create_DT(DT* P, int a[], int n) {
	for (int i = 0; i < n; i++)
		add_first(P, a[i], i);
}

DT* sum_DT(const DT* fx, const DT* gx) {
	DT* dt = fx->degree >= gx->degree ? copy_DT(fx) : copy_DT(gx);
	const DT* smaller = fx->degree < gx->degree ? fx : gx;

	Node* p = dt->head;
	Node* q = smaller->head;
	while (q) {
		while (p->pos > q->pos) 
			p = p->next; 
		p->data += q->data; 
		p = p->next;
		q = q->next;
	}
	return dt;
}
void prinf(const DT* P) {
	Node* node = P->head;
	if (node->data < 0) cout << '-';
	while (node != NULL) {
		if (node->data > 0) {
			if (node->data != 1)
				cout << node->data;
		}
		if (node->data < 0) {
			if (node->data != -1)
				cout << node->data * (-1);
		}
		if (node->pos > 0 && node->data != 0) {
			cout << 'x';
			if (node->pos > 1)
				cout << '^' << node->pos;
		}
		node = node->next;
		if (node != NULL && node->data != 0)
			cout << (node->data > 0 ? " + " : " - ");
	}
	cout << endl;
}

int main() {
	int f[] = { 10, 9, 0, -7, 6, 0, 4, -1, 2, -1 }; // f[i] tương ứng với hệ số của bậc x^i 
	int g[] = { -6, 0, 4, -3, 2, 6 };
	int nfx = sizeof(f) / sizeof(*f), ngx = sizeof(g) / sizeof(*g);
	DT* fx = make_DT(), * gx = make_DT();
	create_DT(fx, f, nfx);
	cout << "f(x) = "; prinf(fx);
	create_DT(gx, g, ngx);
	cout << "g(x) = "; prinf(gx);

	DT* fx_gx = sum_DT(fx, gx);
	cout << "f(x) + g(x) = "; prinf(fx_gx);
}
