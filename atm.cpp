#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

class Banka {
	public:
		struct Person {
			long long int hno;
			std::string name,surname;
			std::string adres;
			std::string tur;
			int cash;
		}p;

		std::vector<Person>kisiler;

		void Search(std::string a) {
			for(int i=0;i<kisiler.size();i++) {
				if(kisiler[i].name == a) {
					std::cout<<"\nİsim  >> "<<kisiler[i].name<<std::endl;
					std::cout<<"\nSoyisim >> "<<kisiler[i].surname<<std::endl;
					std::cout<<"\nHesap no >> "<<kisiler[i].hno<<std::endl;
					std::cout<<"\nHesap tur >> "<<kisiler[i].tur<<std::endl;
					std::cout<<"\nAdres      >> "<<kisiler[i].adres<<std::endl;
					std::cout<<"\nBakiye      >> "<<kisiler[i].cash<<std::endl;
				}
				else {
					std::cout<<"\nKisi bulunamadi.\n";
					break;
				}
			}
		}

		void Delete(std::string a) {
			for(int i=0;i<kisiler.size();i++) {
				if(kisiler[i].name == a) {
					kisiler.erase(kisiler.begin());
				}
				else {
					std::cout<<"\nKisi bulunamadi.\n";
					break;
				}
			}
			std::cout<<"\nKayit silindi.\n";
		}

		void Puts() {
			std::cout<<"\nİsim: ";
			std::cin>>p.name;
			std::cout<<"\nSpyisim: ";
			std::cin>>p.surname;
			std::cout<<"\nHesap no: ";
			std::cin>>p.hno;
			std::cout<<"\nAdres: ";
			std::cin>>p.adres;
			std::cout<<"\nBakiye: ";
			std::cin>>p.cash;

			kisiler.push_back(p);
			std::cout<<"\nKayit eklendi.\n";
		}


		Banka() {
			std::cout<<"\n\n\tBANKAMİZA HOSGELDİNİZ.\n\n";
		}

		~Banka() {
			std::cout<<"\n\n\tTEKRAR BEKLERİZ. :))\n\n";
		}


		void mainMenu() {
			std::cout<<"\nMusteri ekleme   > 1";
			std::cout<<"\nMusteri silme    > 2";
			std::cout<<"\nMusteri gosterme > 3";
			std::cout<<"\nPara cekme       > 4";
			std::cout<<"\nPara yatirma     > 5";
			std::cout<<"\nCikis            > 6\n";
		}

};

class Opera : public Banka {
	public:
		std::vector<Person> Parayatir(std::vector<Person>&kisiler, std::string a) {
			int c;
			for(int i=0;i<kisiler.size();i++) {
				if(kisiler[i].name==a) {
					std::cout<<"\nMiktar: ";
					std::cin>>c;
					kisiler[i].cash += c;
				}
				else {
					std::cout<<"\nKisi bulunamadi.\n";
					//return false;
					break;
				}
			}
			std::cout<<"\nPara yatirma tamamlandi.\n";
			return kisiler;
		}

		std::vector<Person> Paracek(std::vector<Person>&kisiler, std::string a) {
			int c;
			for(int i=0;i<kisiler.size();i++) {
				if(kisiler[i].name == a) {
					std::cout<<"\nMiktar: ";
					std::cin>>c;
					kisiler[i].cash = (kisiler[i].cash - c);
				}
				else {
					std::cout<<"\nKisi bulunamadi.\n";
					//return false;
					break;
				}
			}
			std::cout<<"\nPara cekme tamamlandi.\n";
			return kisiler;
		}
};

int main(int argc, char *argv[]) {
	Banka a;
	Opera b;
	while(1) {
		//system("cls | clear");
		int islem;
		std::string isim;
		a.mainMenu();
		std::cout<<"\nİslem sec: ";
		std::cin>>islem;
		switch(islem) {
			case 1:
				a.Puts();
				break;
			case 2:
				std::cout<<"\nSilmek istedigin isim: ";
				std::cin>>isim;
				a.Delete(isim);
				break;
			case 3:
				std::cout<<"\nAramak istedigin isim: ";
				std::cin>>isim;
				a.Search(isim);
				break;
			case 4:
				std::cout<<"\nİsim: ";
				std::cin>>isim;
				b.Paracek(a.kisiler, isim);
				break;
			case 5:
				std::cout<<"\nİsim: ";
				std::cin>>isim;
				b.Parayatir(a.kisiler, isim);
				break;
			case 6:
				a.~Banka();
				exit(1);
				break;
			default:
				std::cout<<"\nİslem yok.\n";
				break;
		}
	}
}



