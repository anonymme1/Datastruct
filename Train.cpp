#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct n{
	string name;
	int data;
	n * next;
}node;


void Banner() {
	cout<<"\nBilet alim  > 1";
	cout<<"\nBilet iptal > 2";
	cout<<"\nTrendekiler > 3";
	cout<<"\nCikis       > 4\n";
}


bool get(node *a) {
	string temp;
	cout<<"\nAdiniz: ";
	cin>>temp;
	while(a->next != NULL && a->data != 0) {
		a = a->next;
	}
	if(a->data == 0) {
		a->name = temp;
		a->data = 3;
		return true;
	}
	else {
		cout<<"\nYer dolu.\n";
		return false;
	}

}


node* del(node *a, string b) {
	while(a->next != NULL && a->next->name != b) {
		a = a->next;
	}
	node *temp = a;
	for(int i=0;i<10;i++) {
		if(temp->next->name==b) {
			temp->next = temp->next->next;
			free(a->next);
			return temp;
		}
	}
}


void print(node *a) {
	int i=0;
	while(a->next != NULL) {
		for(int j=0;j<5;j++) {
			cout<<i+1<<". kisi > "<<a->name<<"  "<<a->data<<endl;
			a = a->next;
			i++;
		}
	}
}

int main() {
	node *root;
	root = (node*)malloc(sizeof(node));
	node *iter;
	iter = root;
	for(int i=0;i<10;i++) {
		iter->next = (node*)malloc(sizeof(node));
		iter->data = 0;
		iter = iter->next;
	}

	while(1) {
		Banner();
		int choice;
		cout<<"\nİslem sec: ";
		cin>>choice;
		if(choice==1) {
			iter = root;
			get(iter);
		}
		else if(choice==2) {
			string a;
			cout<<"\nİsminiz: ";
			cin>>a;
			iter = root;
			del(iter,a);
		}
		else if(choice==3) {
			iter = root;
			print(iter);
		}
		else if(choice==4) {
			cout<<"\nYine bekleriz :)\n";
			exit(1);
		}
		else {
			cout<<"\nTekrar dene.\n";
		}
	}
}


