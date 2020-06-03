#include <iostream>
#include <vector>
using namespace std;

struct Arac
{
	int plaka;
	char model[10];
	char renk[10];
	int ucret;
	bool musait;

} a;

struct Musteri
{
	char ad[10];
	char soyad[10];
	int no;
} m;

struct Kirala
{
	int plaka;
	int no;
	char alinanT[10];
	char iadeT[10];
} k;

vector < Arac > araclar;
vector < Musteri > musteriler;
vector < Kirala > kiralamalar;


void karsilama()
{
	cout << "\nArac islemleri icin     >> 1" << endl;
	cout << "\nMusteri islemleri icin  >> 2" << endl;
	cout << "\nKiralama islemleri icin >> 3" << endl;
	cout << "\nCikmak icin             >> 4\n" << endl;
}

void aracislem()
{
	cout << "\n\tArac ekleme >> 1" << endl;
	cout << "\n\tArac cikarma>> 2" << endl;
	cout << "\n\tArac gosterme >> 3" << endl;
	int aislem;
	cout << "\n\nYapacagin islemi sec: ";
	cin >> aislem;
	if (aislem == 1)
	{
		cout << "\nArac plakasi: ";
		cin >> a.plaka;
		cout << "\nModeli: ";
		cin >> a.model;
		cout << "\nRenk: ";
		cin >> a.renk;
		cout << "\nUcreti: ";
		cin >> a.ucret;
		a.musait = true;
		araclar.push_back(a);
		cout << "\n\nArac kaydi yapildi." << endl;
	}
	else if (aislem == 2)
	{
		int cplaka;
		cout << "\nCikarmak istedigin aracin  plakasi: ";
		for (int i = 0; i < araclar.size(); i++)
		{
			cout << araclar[i].plaka << endl;
		}
		cin >> cplaka;
		for (int i = 0; i < araclar.size(); i++)
		{
			if (araclar[i].plaka == cplaka)
			{
				araclar.erase(araclar.begin() + i);
				cout << cplaka << " plakali arac cikarildi.\n";
				break;
			}
		}
	}
	else if (aislem == 3)
	{
		for (int i = 0; i < araclar.size(); i++)
		{
			cout << i + 1 << ". arac: " << endl;
			cout << "\tPlakasi >> " << araclar[i].plaka << endl;
			cout << "\tModel   >> " << araclar[i].model << endl;
			cout << "\tRenk    >> " << araclar[i].renk << endl;
			cout << "\tUcret   >> " << araclar[i].ucret << endl;
			cout << "\tDurum    >> " << araclar[i].musait << endl;
		}
	}
}

void musteriislem()
{
	int mislem;
	cout << "\n\tMusteri ekleme >> 1" << endl;
	cout << "\n\tMusteri cikarma>> 2" << endl;
	cout << "\n\tMusteri gosterme>> 3" << endl;
	cout << "\n\nislem secin: ";
	cin >> mislem;
	if (mislem == 1)
	{
		cout << "\nAdi: ";
		cin >> m.ad;
		cout << "\nSoyadi: ";
		cin >> m.soyad;
		cout << "\nNosu: ";
		cin >> m.no;
		musteriler.push_back(m);
		cout << "\nMusteri kaydi yapildi." << endl;
	}
	else if (mislem == 2)
	{
		int mno;
		cout << "\nCikarmak istedigin musterinin nosu: ";
		for (int i = 0; i < musteriler.size(); i++)
		{
			cout << "\t" << musteriler[i].no << endl;
		}
		cin >> mno;
		for (int i = 0; i < musteriler.size(); i++)
		{
			if (musteriler[i].no == mno)
			{
				musteriler.erase(musteriler.begin() + i);
				cout << mno << " nolu musteri cikarildi.\n";
				break;
			}
		}
	}
	else if (mislem == 3)
	{
		for (int i = 0; i < musteriler.size(); i++)
		{
			cout << i << ". Musteri: " << endl;
			cout << "\tAd    >> " << musteriler[i].ad << endl;
			cout << "\tSoyad >> " << musteriler[i].soyad << endl;
			cout << "\tNo    >> " << musteriler[i].no << endl;
		}
	}
}

void kiralama()
{
	for (int i = 0; i < araclar.size(); i++)
	{
		cout << araclar[i].plaka << endl;
	}
	int kplaka;
	cout << "\nKiralamak istedigin aracin plakasi: ";
	cin >> kplaka;
	for (int i = 0; i < araclar.size(); i++)
	{
		if (araclar[i].plaka == kplaka)
		{
			if (araclar[i].musait == 1)
			{
				cout << "\nArac kiralamadadir zaten." << endl;
			}
			else
			{
				araclar[i].musait = true;
			}
		}
	}
	cout << "\nNo: ";
	cin >> k.no;
	cout << "\nKiralama tarihi: ";
	cin >> k.alinanT;
	cout << "\nİade tarihi: ";
	cin >> k.iadeT;
	kiralamalar.push_back(k);
	cout << kplaka << " plakali arac kiralandi." << endl;
}

int main()
{
	while (1)
	{
		int islem;
		karsilama();
		cout << "\nYapacaginiz islemi secin: ";
		cin >> islem;
		switch (islem)
		{
		case 1:
			aracislem();
			break;
		case 2:
			musteriislem();
			break;
		case 3:
			kiralama();
			break;
		case 4:
			exit(1);
			break;
		}
	}
}