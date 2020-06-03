#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hesap {
	public:
		int miktar,n;
		string isim;
		struct account {
			int no;
			int bakiye=0;
			long long int iban;
			string name;
		}j;

		vector<account>hesaplar;

		void newAccount() {
			cout<<"\nAdiniz: ";
			cin>>j.name;
			cout<<"\nHesap numaraniz: ";
			cin>>j.iban;
			cout<<"\nNo: ";
			cin>>j.no;
			cout<<"\nİlk bakiye: ";
			cin>>j.bakiye;
			hesaplar.push_back(j);

		}

		void delAccount() {
			cout<<"\nİsminiz: ";
			cin>>isim;
			for(int i=0;i<hesaplar.size();i++) {
				if(hesaplar[i].name==isim) {
					hesaplar.erase(hesaplar.begin());
					break;
				}
			}
		}

		void deposit() {
			cout<<"\nYatirmak istediginiz hesab no su: ";
			cin>>n;
			for(int i=0;i<hesaplar.size();i++) {
				if(hesaplar[i].no==n) {
						cout<<"\nMiktar: ";
						cin>>miktar;
						hesaplar[i].bakiye += miktar;
						break;
				}
				else {
					cout<<"\nHesap yok.\n";
					break;
				}
			}
		}

		void withdraw() {
			cout<<"\nHesap no gir: ";
			cin>>n;
			for(int i=0;i<hesaplar.size();i++) {
				if(hesaplar[i].no==n) {
					cout<<"\nMiktar: ";
					cin>>miktar;
					if(miktar>hesaplar[i].bakiye) {
						cout<<"\nBu kadar para yok.\n";
						break;
					}
					else {
						hesaplar[i].bakiye -= miktar;
						cout<<"\nPara cekme basarili.\n";
						break;
					}
				}
			}
		}

		void getBalance() {
			cout<<"\nHesap nosu gir: ";
			cin>>n;
			for(int i=0;i<hesaplar.size();i++) {
				if(hesaplar[i].no==n) {
					cout<<"\nHesabin Bakiyesi: "<<hesaplar[i].bakiye<<endl;
					break;
				}
				else {
					cout<<"\nHesap yok.\n";
					break;
				}
			}
		}

		void getId() {
			cout<<"\nİsminiz: ";
			cin>>isim;
			for(int i=0;i<hesaplar.size();i++) {
				if(hesaplar[i].name==isim) {
					cout<<"\nHesap numarasi: "<<hesaplar[i].iban<<endl;
					break;
				}
				else {
					cout<<"\nHesap yok.\n";
				}
			}
		}


//		void benefit();

};

class Bank : public Hesap {
	public:

		void getAccount() {
			for(int i=0;i<hesaplar.size();i++) {
				cout<<i+1<<". Hesap >> "<<endl;
				cout<<"\n\tİsim > "<<hesaplar[i].name;
				cout<<"\n\tHesap no > "<<hesaplar[i].iban;
				cout<<"\n\tNo       > "<<hesaplar[i].no;
				cout<<"\n\tBakiye   > "<<hesaplar[i].bakiye;
				cout<<endl;
			}
		}
};

void mainMenu() {
	cout<<"\nHesap acma > 1";
	cout<<"\nHesap kapatma > 2";
	cout<<"\nPara cekme    > 3";
	cout<<"\nPara yatirma  > 4";
	cout<<"\nHesap listele > 5";
	cout<<"\nBakiye goster > 6";
	cout<<"\nCikis         > 7";
	cout<<endl;
}


int main() {
	Hesap h;
	Bank b;
	while(1) {
		mainMenu();
		int islem;
		cout<<"\nİslem sec: ";
		cin>>islem;
		switch(islem) {
			case 1:
				h.newAccount();
				cout<<"\nHesap acma basarili.\n";
				break;
			case 2:
				h.delAccount();
				cout<<"\nHesap silme basarili.\n";
				break;
			case 3:
				h.withdraw();
				break;
			case 4:
				h.deposit();
				break;
			case 5:
				b.getAccount();
				break;
			case 6:
				h.getBalance();
				break;
			case 7:
				exit(1);
				break;
			default:
				cout<<"\nislem yok.\n";
		}
	}
}

