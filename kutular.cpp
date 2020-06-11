#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _node {
	string _data;
	int data;
	_node *next;
}node;


void pushs(node *a,int b) {
	string c;
	for(int i=0;i<b;i++) {
		a->next = (node*)malloc(sizeof(node));
		cout<<"\nVeri gir: ";
		cin>>c;
		a->_data = c;
		a = a->next;
	}
	cout<<"\nEkleme basarili.\n";
}

void push(node *a, int b) {
	int c;
	for(int i=0;i<b;i++) {
		a->next = (node*)malloc(sizeof(node));
		cout<<"\nVeri gir: ";
		cin>>c;
		a->data = c;
		a = a->next;
	}
	cout<<"\nEkleme basarili.\n";
}



void prints(node *a) {
	int i=1;
	while(a->next != NULL) {
		cout<<i<<". veri > "<<a->_data<<endl;
		a = a->next;
		i++;
	}
}


void print(node *a) {
	int i=1;
	while(a->next != NULL) {
		cout<<i<<". veri > "<<a->data<<endl;
		a = a->next;
		i++;
	}
}


node *dels(node *a, string b) {
	node *temp;
	node *iter = a;
	while(iter->next != NULL && iter->next->_data != b) {
		iter = iter->next;
	}
	if(iter->next==NULL) {
		cout<<"\nKelime yok.\n";
		return a;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	cout<<"\nBasariyla silindi.\n";
	return a;
}

node *del(node *a, int b) {
	node *temp;
	node *iter = a;
	while(iter->next != NULL && iter->next->data != b) {
		iter = iter->next;
	}

	if(iter->next==NULL) {
		cout<<"\nBu sayi yok.\n";
		return a;
	}

	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	cout<<"\nBasariyla silindi.\n";
	return a;
}




int main() {

	node *root;
	node *sroot;
	root = (node*)malloc(sizeof(node));
	sroot = (node*)malloc(sizeof(node));
	node *iter;
	node *iters;
	iter = root;
	iters = sroot;

	int choice;
	string delets;
	int delet;
	int much;
	go:
	while(1) {
		cout<<"\nSayilarla islem icin   1";
		cout<<"\nKelimelerle islem icin 2\n";
		cout<<"\nİslem sec: ";
		cin>>choice;
		if(choice==1) {
			while(1) {
				cout<<"\nEleman eklemek icin    1";
				cout<<"\nEleman silmek icin     2";
				cout<<"\nEkranda gostermek icin 3";
				cout<<"\nBi once menu icin      4\n";

				int cho;
				cout<<"\nİslem sec: ";
				cin>>cho;

				switch(cho) {
					case 1:
						cout<<"\nKac eleman olsun: ";
						cin>>much;
						push(iter, much);
						break;
					case 2:
						print(root);
						cout<<"\nSilmek istedigin sayiyi yaz: ";
						cin>>delet;
						del(iter, delet);
						break;
					case 3:
						print(root);
						break;
					case 4:
						goto go;
						break;
					default:
						cout<<"\nİslem bulunamadi.\n";
						break;
				}
			}
		}

		else if(choice==2) {
			while(1) {
	                        cout<<"\nEleman eklemek icin    1";
        	                cout<<"\nEleman silmek icin     2";
                	        cout<<"\nEkranda gostermek icin 3";
                    	        cout<<"\nBi once menu icin      4\n";

				int cho;
				cout<<"\nİslem sec: ";
				cin>>cho;

				switch(cho) {
        	                        case 1:
						cout<<"\nKac eleman olsun: ";
						cin>>much;
						pushs(iters, much);
                         	                break;
                                	case 2:
						prints(sroot);
						cout<<"\nSilmek istedigin elemani yaz: ";
						cin>>delets;
						dels(iters,delets);
                                	        break;
                                	case 3:
						prints(sroot);
                                	        break;
                                	case 4:
						goto go;
                                        	break;
                                	default:
                                       		cout<<"\nİslem bulunamadi.\n";
                                        	break;
                        	}
                	}
		}
		else {
			cout<<"\nCikis yapiliyo.\n";
			exit(1);
		}
	}
	return 0;
}


