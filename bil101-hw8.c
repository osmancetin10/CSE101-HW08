						/***************************/
						/*                         */
						/*      Osman Çetin        */
						/*       161044069         */
						/*          HW-8           */
						/*                         */
						/***************************/
#include <stdio.h>
/* Bu kodumuz taylor dizisi ile math.h kütüphanesini kullanmadan sinüs hesaplamamızı sağlar. Kullanıcıdan sinüsü hesaplanacak açı istenir. Daha sonra işlemin ne kadar detaylı sonuçlar vereceğini sağlayan kademe sayısı istenir. Ardından girilen açının sinüsü ekrana yazdırılır.*/ 
double sinus (int kademe,int radyan);/* sin fonksiyonumuzun prototipi*/
int power(int adim, int radyan);/* pow fonksiyonumuzun prototipi*/
double bolum(double pay,int adim);/* bolum fonksiyonumuzun prototipi*/				
int factorial(int adim);/* factorial fonksiyonumuzun prototipi*/
int main(){
	int derece,kademe,radyan;
	double sonuc;
	printf("Lütfen sinüsünün hesaplanmasını istediğiniz dereceyi giriniz\n");/*kullanıcıdan derece istenr ve çekilir*/
	scanf("%d",&derece);
	printf("işlemin kaç kademede yapılacağını giriniz\n");/*kullanıcıdan kademe istenir ve çekilir*/
	scanf("%d",&kademe);
	if(derece>360){/*eğer girdiğimiz açı 360 dereceden büyükse 360 dereceye göre mod alır ve hesaplama yapar*/
		derece=derece%360;
	}
	radyan=(derece*3.14/180)*1000;/*açımızı radyana çevrilir*/ /*1000 ile çarpmamızın sebebi değerimizi integer olarak kullanmayı istemek*/
	sonuc=sinus(kademe,radyan);/* radyanımız için sinüs hesaplayan fonskyon başlatılır ve geri döndürülecek sonuç sonuc integerine atanır*/
	printf("Girdiğiniz açının sinüsü==>");/*ve sonuç yazdırılır*/
	printf("%lf\n",sonuc);	
	return 0;
}

double sinus(int kademe,int radyan){/*Bu fonskiyonun amacı gerekli değerleri main fonksyonundan alıp sinüs hesaplaması yapmaktır.*/
	int adim;
	double pay,pay1,payda,pozitif=0,negatif=0,sonuc,toplam;
	int	a=1;
	for(adim=1;adim<=kademe;adim=adim+2){/*öncelikle hangi adımın yapılacağını belirleyen döngümüzü başlatırız*/
		pay=power(adim,radyan);/*pay kısmımızı verecek radyanımızın adıma göre kuvvetini alacak fonskyonumuzu başlatırız*/
		pay1=bolum(pay,adim);/*main fonskiyonunda radyanımızı 1000 değeri ile çarpmıştık. Bu fonksiyonun amacı 1000'e bölüp doğru değeri elde etmek*/
		payda=factorial(adim);/*burada ise adım sayısına göre faktöriyel hesabı yapacak fonksiyon başlatılır.*/
		sonuc=pay1/payda;/*pay ve payda değerleri birbirine bölünür*/
		if(a%2!=0){/*işlem adedimiz tek değil ise pozitif havuzda toplanır*/
			pozitif=sonuc+pozitif;
		}	
		else{/*değilse negatif havuzda toplanır*/
			negatif=sonuc+negatif;
		}
		a++;
	}
	toplam=pozitif-negatif;/*pozitif değerlerden negatif değerler çıkarılır, toplam adlı double'a atanır*/
	return toplam;/*ve sonucumuz main fonksiyonuna geri döndürülür*/
}

int power(int adim, int radyan){/*Bu fonksiyonun amacı radyanın adım sayımıza göre üssünü almak*/
	int i,power=1;
	for(i=0;i<adim;i++){/*adim sayımız kere radyanımız kendi ile çarpılır*/
		power=power*radyan;
	}
	return power;/*çıkan sonuç sinüs fonksiyonumuza geri döndürülür*/
}

double bolum(double pay,int adim){/*bu fonksyonun amacı integer değer elde etmek için çarptığımız 1000 sayılarından kurtulmak*/
	int j;
	for(j=0;j<adim;j++){/*adım sayısı kere 1000'e bölüm yapılır*/
		pay=pay/1000;
	}
	return pay;/*sinüs fonksiyonumuza geri döndürülür*/
}

int factorial (int adim){/*Bu fonksiyonun amacı paydadaki faktöriyel hesabını yapmaktır*/
	int j;
	double func=1;
	for(j=0;adim>j;adim--){/*döngümüzün içinde adim sayımız her seferinde bir eksiltilerek bir önceki değeri ile çarpılır*/
		func=func*adim;
	}
	return func;/*sinüs fonksiyonuna geri döndürülür*/
}					
