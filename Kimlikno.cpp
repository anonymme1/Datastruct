#include <iostream>

int main() {
        long long int tcno;
        std::cout<<"\nTc no gir: ";
        std::cin>>tcno;
        int dizi[11]={0};
        int basamak;
        int basamakSayisi=0;
        int j=10;
        int ctrl=0;
        while(tcno>0) {
                basamak = tcno%10;
                tcno /= 10;
                dizi[j] = basamak;
                j--;
                basamakSayisi++;
        }

        int tektoplam=0,cifttoplam=0;

        tektoplam = dizi[0]+dizi[2]+dizi[4]+dizi[6]+dizi[8];
        cifttoplam = dizi[1]+dizi[3]+dizi[5]+dizi[7];


        int onhane=0;

        for(int i=0;i<10;i++) {
                onhane += dizi[i];
        }

        if(onhane%10==dizi[10]) {
                ctrl++;
        }
        if(dizi[0]!=0) {
                ctrl++;
        }
        if(basamakSayisi==11) {
                ctrl++;
        }
        int toplam = (tektoplam*7)-cifttoplam;
        if(toplam%10==dizi[9]) {
                ctrl++;
        }

        std::cout<<"\nTek hane toplami  : "<<tektoplam<<std::endl;
        std::cout<<"\nCift hane toplami : "<<cifttoplam<<std::endl;
        std::cout<<"\n10 hane toplami   : "<<onhane<<std::endl;

        for(int i=0;i<11;i++) {
                std::cout<<dizi[i]<<"  ";
        }

        std::cout<<std::endl;
        if(ctrl==4) {
                std::cout<<"\nDogru.\n"<<std::endl;
        }
        else {
                std::cout<<"\nYanlis.\n"<<std::endl;
        }
}
