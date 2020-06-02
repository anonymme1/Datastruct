#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct n {
	int data;
	n * next;
}node;



void push(node *a,int b) {
	int c;
	for(int i=0;i<b;i++) {
		a->next = (node*)malloc(sizeof(node));
		cout<<"\nSayi gir: ";
		cin>>c;
		a->data = c;
		a = a->next;
	}
}

void pop(node *a, int b,int c) {
	while(a->next!=NULL && a->next->data!=b) {
		a = a->next;
	}

	for(int i=0;i<c;i++) {
		if(a->next->data==b) {
			a->next = a->next->next;
			free(a->next);
		}
	}
}


void print(node *x) {
	int i=1;
	while(x->next != NULL) {
		cout<<i<<". kutu > "<<x->data<<endl;
		x = x->next;
		i++;
	}
}

int main() {
	node * root;
	root = (node*)malloc(sizeof(node));
	node *iter;
	iter = root;
	int inp;
	cout<<"\nKac kutu olcak: ";
	cin>>inp;
	push(root,inp);
	print(root);
	cout<<"\nSilmek istedigin eleman: ";
	int sil;
	cin>>sil;
	pop(root,sil,inp);
	print(root);
}
