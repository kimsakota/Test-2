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
	p->pos = pos;
	p->next = NULL;
	return p;
}

bool is_list_empty(Node* node) {
	return node == NULL;
}

void add_first(Node*& node, int data, int pos) {
	Node* p = make_node(data, pos);
	if (is_list_empty(node))
		node = p;
	else {
		p->next = node;
		node = p;
	}
}

void create_da_thuc(Node*& node, int a[], int n) {
	for (int i = 0; i < n; i++) 
		add_first(node, a[i], i);
}

Node* sum_da_thuc(const Node* fx, const Node* gx) {
	Node* p = NULL; // chıa xong 
	while (fx != NULL && gx != NULL) {
		
	}
}

void prinf(const Node* node) {
	if (node->data < 0) cout << '-';
	while (node != NULL) {
		if (node->data > 0) {
			if (node->data != 1)
				cout << node->data;
		}
		if(node->data < 0) {
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
	int f[] = { 10, 9, 0, -7, 6, 0, 4, -1, 2, -1 };
	int g[] = { -6, 0, 4, -3, 2, 6 };
	int nfx = sizeof(f) / sizeof(*f), gfx = sizeof(g) / sizeof(*g);
	Node* fx = NULL, * gx = NULL;
	create_da_thuc(fx, f, nfx);
	create_da_thuc(gx, g, gfx);
	cout << "fx = "; prinf(fx);
	cout << "gx = "; prinf(gx);
}