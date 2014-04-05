//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SZD.h"
#include <math.h>
#include <math.hpp>
#include <vector.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "Series"
#pragma resource "*.dfm"
TForm1 *Form1;
  
class AbonentK  {
public:
	TPoint pozycja;
	enum trybType {AUTOSTRADA, STATYCZNY};
	trybType tryb;
	int stan;
	int czasRozmowy;
	int aktualnaKomorka;
	bool przydzielony;
	int kierunek;
	float predkosc;
	void konstruktor(bool trybZycia,TPoint poz)  {
		if(trybZycia==true)tryb=AUTOSTRADA; else tryb=STATYCZNY;
		stan=0;
		czasRozmowy=0;
		przydzielony=false;
		kierunek=92;
		predkosc=random(100)*0.1;
		pozycja=poz;
	}

};

class KomorkaK  {
public:
	TPoint centrumK;
	float promien;
	int liczbaKanalow;
	double wykorzystaneKanaly;
	void konstruktor(TPoint cen, float prom, int lk) {
		centrumK=cen;
		promien=prom;
		liczbaKanalow=lk;
		wykorzystaneKanaly=0.0;
	}

};

AbonentK *abonent;
KomorkaK *komorka;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RozmiarSieciCBKeyPress(TObject *Sender, char &Key)
{
Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IloscIteracjiEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IloscIteracjiNaSekundeEKeyPress(TObject *Sender,
      char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IloscKanalowEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LiczbaAbonentowEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrawdRozpRozmEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MaxRozmowyEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SzerAutostradyEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ZiarnoEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OdchylenieEKeyPress(TObject *Sender, char &Key)
{
if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SredniaEKeyPress(TObject *Sender, char &Key)
{
                 if(!(((int)Key >= 48 && (int)Key<=57)|| Key=='\b'))
	 {
			Key = 0 ;
		 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ZakladkiMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{

if (Zakladki->TabIndex != 0) PostepPB->Visible = false;
else  PostepPB->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

Timer->Enabled = false;
ZiarnoE->Enabled = false;
zdarzenia = 0;
aboTest = false;
stala = false;
Image1->Canvas->Pen->Color = clRed ;
Image1->Canvas->Brush->Color = clRed ;
Image1->Canvas->Rectangle(0, 0,Image1->Width , Image1->Width);
Image2->Canvas->Pen->Color = clMenuHighlight ;
Image2->Canvas->Brush->Color = clMenuHighlight ;
Image2->Canvas->Rectangle(0, 0,Image2->Width , Image2->Width);
Image3->Canvas->Pen->Color = clBlack ;
Image3->Canvas->Brush->Color = clLime;
Image3->Canvas->Rectangle(0, 0,Image3->Width , Image3->Width);
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::StartBClick(TObject *Sender)
{
Wykres->Series[0]->Clear();
Wynik->Clear();
Wynik2->Clear();
Timer->Enabled = true;
ZiarnoE->Enabled = false;
if (StalaCB->State == cbChecked) {
   stala = true;
} else {
   stala = false;
}
rozmiarSieci = RozmiarSieciCB->ItemIndex+2;
if (rozmiarSieci < 9) {
    dodatek = 5;
} else {
	dodatek = 3;
}
iteracje = IloscIteracjiE->Text.ToInt();
if (iteracje > 1000) {
	iteracje = 1000;
	IloscIteracjiE->Text = 1000;
}
Label23->Caption=AnsiString(0)+"/"+AnsiString(iteracje);
PostepPB->Max = iteracje;
kanaly = IloscKanalowE->Text.ToInt();
if (LiczbaAbonentowE->Text.ToInt() < 10 && aboTest == false) {
	LiczbaAbonentowE->Text = 10;
} else
abonenci = LiczbaAbonentowE->Text.ToInt();
abonenci = LiczbaAbonentowE->Text.ToInt();
for (int i = 0; i < abonenci; i++) {
		doRozmowy.push_back(0);
		poissonV.push_back(0);
}
doRozmowy.clear();
poissonV.clear();
zdarzenia = 0;
szerokosc = SzerAutostradyE->Text.ToInt();
if (szerokosc > Image->Width) {
    SzerAutostradyE->Text = Image->Height;
	szerokosc = SzerAutostradyE->Text.ToInt();
}
prawdRozmowy = PrawdRozpRozmE->Text.ToDouble();
if (prawdRozmowy > 0.99) {
	prawdRozmowy = 0.99;
	PrawdRozpRozmE->Text = 0.99;
}
aboStatyczny = (abonenci*ProporcjaTB->Position)/100;
aboAutostrada = abonenci - aboStatyczny;
ileKomorki = rozmiarSieci*rozmiarSieci;
odchylenie = OdchylenieE->Text.ToDouble();
srednia = SredniaE->Text.ToDouble();
ziarno = ZiarnoE->Text.ToInt();
abonent = new AbonentK[abonenci];
komorka = new KomorkaK[ileKomorki];
Wykres->Series[0]->AddX(zdarzenia);
if (CBBZ->Checked == true) {
	srand(time(0));
	randomize();
} else {
	srand (ziarno);
	randomize();
}
temp = 0;

if (stala == true) {
	wylosowanyKierunek = 92;
} else {
	wylosowanyKierunek = random(45)+50;
}
while (temp<aboAutostrada)	{
		start.x=random(100);
		start.y=random(szerokosc)+((Image->Height-szerokosc)/2);
		abonent[temp].konstruktor(false,start);
		abonent[temp].kierunek=wylosowanyKierunek;
		abonent[temp].predkosc=random(100)*0.1+3;
		temp++;
}

while (temp<abonenci) {
		start2.x=random(Image->Width);
		start2.y=random(Image->Height);
		abonent[temp].konstruktor(false,start2);
		abonent[temp].kierunek=0;
		abonent[temp].predkosc=0;
		temp++;
}
               
  Timer->Enabled=true;
  Image->Canvas->Brush->Color = clWhite;
  Image->Canvas->FillRect(Rect(0,0,Image->Width,Image->Height));
  Image->Canvas->Refresh();
  RysowanieSiatki ( Image->Width, Image->Height ,rozmiarSieci);
}
//---------------------------------------------------------------------------

void TForm1::RysowanieSiatki (double SZER, double WYS, int ROZMIAR ){
   TPoint points[5];
   TPoint centrum;
   int nrKomorki = 0;
   Image->Canvas->Pen->Color = clSilver ;
   Image->Canvas->Brush->Color = clWhite ;
   Image->Canvas->Rectangle(0, 0,SZER , WYS);
   Image->Canvas->Pen->Color = clBlack;
   Image->Canvas->Brush->Color = cl3DLight ;
   double a,b;
   if (ROZMIAR < 3) {
	   b = (SZER/ROZMIAR);
	   a = b;
   } else if (ROZMIAR < 10 && ROZMIAR > 2) {
	   b = (SZER/ROZMIAR)+(sin((30*M_PI)/180.0f)*(SZER/ROZMIAR)/2,8);
	   a = (WYS/ROZMIAR)-(cos((30*M_PI)/180.0f)*(WYS/ROZMIAR)/1,5);
   } else if (ROZMIAR ==20) {
	 {
	   b = (SZER/ROZMIAR)+(sin((30*M_PI)/180.0f)*(SZER/ROZMIAR)/2);
	   a = (WYS/ROZMIAR);//+(cos((30*M_PI)/180.0f)*(WYS/ROZMIAR)/2);
   }
   } else {
	   b = (SZER/ROZMIAR)+(sin((30*M_PI)/180.0f)*(SZER/ROZMIAR)/2);
	   a = b;
   }

   double s =b/2;
   double h = (sin((30*M_PI)/180.0f)*s);
   double r = (cos((30*M_PI)/180.0f)*s);
   double k = ( ((a - (a/2))+r) - ((a - (a/2))-r));
   int i, przekatnaB, przekatnaA;
   int u =0;
   int y =(2*s)-h;
   for (int p = 0; p < ROZMIAR; p++) {
	 if (p%2 == 0) {
		i = 0;
	 for (int j = 0; j < ROZMIAR; j++) {
		points[0] = Point(u, a - (a/2)+i);
		points[1] = Point(u+ h, (a - (a/2))-r+i);
		points[2] = Point(u+ h+s, (a - (a/2))-r+i);
		points[3] = Point(u+b,a- (a/2)+i);
		points[4] = Point(u+ h+s, (a - (a/2))+r+i);
		points[5] = Point(u + h, (a - (a/2))+r+i);
		Image->Canvas->Polygon(points, 5);
		if(zdarzenia==0 ) {
			//x = d³u¿sza przek¹tna-h-(bok/2)
			//y = krótsza przekatna/2;
			//bok = points[2].x - points[1].x;
			przekatnaB = points[3].x - points[0].x;
			przekatnaA = points[5].y - points[1].y;
			//wysokosc = (przekatnaB-bok)/2;
			centrum = Point(points[0].x+(przekatnaB/2),points[1].y+(przekatnaA/2));
			float promien = przekatnaA/2;
			komorka[nrKomorki].konstruktor(centrum, promien, kanaly);
			nrKomorki++;
		}
		i = i +(k);
   }
   u = u +3*s;
  } else {
	i = k/2;
	for (int j = 0; j < ROZMIAR; j++) {
		points[0] = Point(y, a - (a/2)+i);
		points[1] = Point(y + h, (a - (a/2))-r+i);
		points[2] = Point(y+h+s, (a - (a/2))-r+i);
		points[3] = Point(y+b ,a- (a/2)+i);
		points[4] = Point(y+h+s, (a - (a/2))+r+i);
		points[5] = Point(y+h, (a - (a/2))+r+i);
		Image->Canvas->Polygon(points, 5);
		if(zdarzenia==0 ) {
			//bok = points[2].x - points[1].x;
			przekatnaB = points[3].x - points[0].x;
			przekatnaA = points[5].y - points[1].y;
			//wysokosc = (przekatnaB-bok)/2;
			centrum = Point(points[0].x+(przekatnaB/2),points[1].y+(przekatnaA/2));
            float promien = przekatnaA/2;
			komorka[nrKomorki].konstruktor(centrum, promien, kanaly);
			nrKomorki++;
		}
		i = i +(k);
   } //koniec 2 petli wew.
   y = y +3*s;
  } //koniec else
 }

 }

void TForm1::RysowaniePkt (){

int i=0;
Image->Canvas->Pen->Color=clRed;
Image->Canvas->Brush->Color=clRed;

while (i<abonenci) {
		if(abonent[i].czasRozmowy > 0 && abonent[i].przydzielony == true)	{
				Image->Canvas->Brush->Color=clRed;
				Image->Canvas->Pen->Color=clRed;
		} else if (abonent[i].przydzielony==true) {
				Image->Canvas->Brush->Color=clMenuHighlight;
				Image->Canvas->Pen->Color=clMenuHighlight;
		} else {
				Image->Canvas->Brush->Color=clLime;
				Image->Canvas->Pen->Color=clBlack;
        }
		Image->Canvas->Ellipse(abonent[i].pozycja.x-2,abonent[i].pozycja.y-2,abonent[i].pozycja.x+2,abonent[i].pozycja.y+2);
		abonent[i].przydzielony=false;
		i++;
 }
}

void TForm1::Ruch(){
int i=0;
int maxX = Image->Width;
int maxY = Image->Height;
while (i<abonenci)  {
		abonent[i].pozycja.x=abonent[i].pozycja.x+1.0*abonent[i].predkosc*sin(2.0*M_PI*wylosowanyKierunek/360.0);
		abonent[i].pozycja.y=abonent[i].pozycja.y-1.0*abonent[i].predkosc*cos(2.0*M_PI*wylosowanyKierunek/360.0);
		if(abonent[i].pozycja.x<0)abonent[i].pozycja.x=maxX;
		if(abonent[i].pozycja.x>maxX)abonent[i].pozycja.x=0;
		if(abonent[i].pozycja.y<0)abonent[i].pozycja.y=maxY;
		if(abonent[i].pozycja.y>maxY)abonent[i].pozycja.y=0;
		i++;
		}
}

double TForm1::Silnia(int n) {
		double liczba = n;
		double nowa = 1;
		double wynik = 1;

		for(int i = n; i > 0; i--) {
		  wynik = wynik * liczba;
		  liczba = liczba - nowa;
		}
		return wynik;
	}

 /*
double TForm1::Poisson(int k, double lambda) {
	double sil = Silnia(k);
	double lambda_do_k = pow(lambda, k);
	double exp_do_minus_lambda = exp((-1) * lambda);
	double licznik = lambda_do_k * exp_do_minus_lambda;
	double wynik = licznik / sil;
	return wynik;
}
 /*
double TForm1::Normalny(int k, double oczekiwana, double odchylenie) {
	double mianownik =odchylenie*sqrt(2*M_PI);
	double licznik =exp((-1.0*pow(k-oczekiwana,2))/(2*odchylenie*odchylenie));
	double wynik = licznik / mianownik;
	return wynik;
}
  */

void TForm1::Zaznacz(){
int i=0;
int j=0;
int rozmawiajacy;
int dzwoniacy;
int zaczynajacyRozmowe;
double wykorzystanie=0.0;
int nierozmawiajacy;
double lambda;
doRozmowy.clear();
wykorzystanie=0;
while (i<ileKomorki) {
		 j=0;
		 nierozmawiajacy=0;
		 rozmawiajacy=0;
		 zaczynajacyRozmowe=0;
		 while (j<abonenci) {
				if(abonent[j].przydzielony==false) {
					//jezeli abonent znajduje sie w zasiegu komorki
					if(sqrt(pow((komorka[i].centrumK.x-abonent[j].pozycja.x),2)+pow((komorka[i].centrumK.y-abonent[j].pozycja.y),2))<=komorka[i].promien+dodatek)  {
						abonent[j].przydzielony=true; //to znaczy, ¿e jest przydzielony
						abonent[j].aktualnaKomorka=i; //do konkretnej komorki
						Wynik->Lines->Add("Komórka "+AnsiString(i)+" -> abonent "+AnsiString(j));
						if(abonent[j].czasRozmowy==0) {
							doRozmowy[nierozmawiajacy]=j;
							nierozmawiajacy++;
						} else if (rozmawiajacy == kanaly){
								abonent[j].czasRozmowy=0;
								doRozmowy[nierozmawiajacy]=j;
								nierozmawiajacy++;
						}  else {
								rozmawiajacy++;
						}
					}
				}
				j++;
		 }
		 if (rozmawiajacy > 0) {
			 Wynik3->Lines->Add("Komórka nr. "+AnsiString(i)+" -> "+AnsiString(rozmawiajacy));
         }
		 lambda=prawdRozmowy*nierozmawiajacy;
		 if(nierozmawiajacy>0) {
				zaczynajacyRozmowe = Poisson(lambda);
				int index=0;

				//jezeli liczba zaczyanajacych rozmowe jest > od liczby dostepnych kanalow
				if(zaczynajacyRozmowe > (komorka[i].liczbaKanalow-rozmawiajacy)) {
					if((komorka[i].liczbaKanalow-rozmawiajacy)>0)
						zaczynajacyRozmowe = komorka[i].liczbaKanalow-rozmawiajacy;
					else
						zaczynajacyRozmowe = 0;
				}
				while(index < zaczynajacyRozmowe) {
					abonent[doRozmowy[index]].stan=1;
					abonent[doRozmowy[index]].czasRozmowy = Normal(srednia,odchylenie);
					index++;
				}
		  }
		 if ((rozmawiajacy+zaczynajacyRozmowe)> 0) {
			komorka[i].wykorzystaneKanaly=(double)(rozmawiajacy+zaczynajacyRozmowe)/kanaly;
		 } else {
			komorka[i].wykorzystaneKanaly=0;
		 }
		 wykorzystanie=wykorzystanie+komorka[i].wykorzystaneKanaly;
		 komorka[i].wykorzystaneKanaly=0;
		 i++;
		}

Wynik3->Lines->Add("Wykorzystanie kana³ów -> "+AnsiString(wykorzystanie/ileKomorki));
Wykres->Series[0]->AddY((wykorzystanie/ileKomorki)*100);
wykorzystanie=0;
}

void TForm1::Czas() {
	int j=0;
	while (j<abonenci) {
		if(abonent[j].czasRozmowy>0) {
			abonent[j].czasRozmowy--;
			Wynik2->Lines->Add("Rozmawia abonent nr. "+AnsiString(j));
		}
		j++;
	}
}

void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
if (Key == 't') {
	aboTest=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ProporcjaTBChange(TObject *Sender)
{
Label9->Caption = IntToStr(100-ProporcjaTB->Position) + "/" + IntToStr(ProporcjaTB->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBBZContextPopup(TObject *Sender, TPoint &MousePos,
      bool &Handled)
{
if (CBBZ->Checked == true) {
	CBZZ->Checked = false;
} else if (CBZZ->Checked == true) {
			CBBZ->Checked = false;
	   }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::CBBZMouseActivate(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y, int HitTest,
      TMouseActivate &MouseActivate)
{
	CBZZ->Checked = false;
	ZiarnoE->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBZZMouseActivate(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y, int HitTest,
      TMouseActivate &MouseActivate)
{
	CBBZ->Checked = false;
	ZiarnoE->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTimer(TObject *Sender)
{
	RysowanieSiatki ( Image->Width, Image->Height ,rozmiarSieci);
	RysowaniePkt();
	Zaznacz();
	Ruch();
	Czas();
	zdarzenia++;
	Wynik->Lines->Add("--------ITERACJA "+AnsiString(zdarzenia)+"--------");
	Wynik2->Lines->Add("--------ITERACJA "+AnsiString(zdarzenia)+"--------");
	Wynik3->Lines->Add("--------------------ITERACJA "+AnsiString(zdarzenia)+"--------------------");
	Label23->Caption=AnsiString(zdarzenia)+"/"+AnsiString(iteracje);
	PostepPB->Position = zdarzenia;
	if(zdarzenia==iteracje)  {
		Timer->Enabled=false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZakladkiChange(TObject *Sender)
{
if (Zakladki->TabIndex != 0) {
	PostepPB->Visible = false;
	Image->Visible = false;
	GroupBox3->Visible = false;
	Label22->Visible = false;
} else {
	PostepPB->Visible = true;
	Image->Visible = true;
	GroupBox3->Visible = true;
	Label22->Visible = true;
}

if (Zakladki->TabIndex != 2) {
	Wynik->Visible = false;
	Wynik2->Visible = false;
	Wynik3->Visible = false;
	Label16->Visible = false;
	Label17->Visible = false;
	Label18->Visible = false;
} else {
	Wynik->Visible = true;
	Wynik2->Visible = true;
	Wynik3->Visible = true;
	Label16->Visible = true;
	Label17->Visible = true;
	Label18->Visible = true;
}

if (Zakladki->TabIndex != 1) {
	Wykres->Visible = false;

} else {
	Wykres->Visible = true;
}

}
//---------------------------------------------------------------------------





void __fastcall TForm1::IloscIteracjiUDClick(TObject *Sender, TUDBtnType Button)
{
if (Button == btNext) {
	IloscIteracjiE->Text = IloscIteracjiE->Text.ToInt() +1;
} else {
    IloscIteracjiE->Text = IloscIteracjiE->Text.ToInt() -1;	
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IloscIteracjiEChange(TObject *Sender)
{
if (IloscIteracjiE->Text.ToInt() <= 10000 && IloscIteracjiE->Text.ToInt() >=1  ) {
	IloscIteracjiUD->Position = IloscIteracjiE->Text.ToInt();
} else {
	IloscIteracjiE->Text = 100;
	IloscIteracjiUD->Position = 100;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LiczbaKanalowUDClick(TObject *Sender, TUDBtnType Button)
{
if (Button == btNext) {
	IloscKanalowE->Text = IloscKanalowE->Text.ToInt() +1;
} else {
	IloscKanalowE->Text = IloscKanalowE->Text.ToInt() -1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IloscKanalowEChange(TObject *Sender)
{
if (IloscKanalowE->Text.ToInt() <= 999 && IloscKanalowE->Text.ToInt() >=1  ) {
	IloscKanalowUD->Position = IloscKanalowE->Text.ToInt();
} else {
	IloscKanalowE->Text = 10;
	IloscKanalowUD->Position = 10;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LiczbaAbonentowEChange(TObject *Sender)
{
if (LiczbaAbonentowE->Text.ToInt() <= 10000 && LiczbaAbonentowE->Text.ToInt() >=1  ) {
	LiczbaAbonentowUD->Position = LiczbaAbonentowE->Text.ToInt();
} else {
	LiczbaAbonentowE->Text = 200;
	LiczbaAbonentowUD->Position = 200;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LiczbaAbonentowUDClick(TObject *Sender,
      TUDBtnType Button)
{
if (Button == btNext) {
	LiczbaAbonentowE->Text = LiczbaAbonentowE->Text.ToInt() +1;
} else {
	LiczbaAbonentowE->Text = LiczbaAbonentowE->Text.ToInt() -1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SzerAutostradyEChange(TObject *Sender)
{
if (SzerAutostradyE->Text.ToInt() <= 460 && SzerAutostradyE->Text.ToInt() >=10  ) {
	SzerAutostradyUD->Position = SzerAutostradyE->Text.ToInt();
} else {
	SzerAutostradyE->Text = 100;
	SzerAutostradyUD->Position = 100;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SzerAutostradyUDClick(TObject *Sender,
      TUDBtnType Button)
{
if (Button == btNext) {
	SzerAutostradyE->Text = SzerAutostradyE->Text.ToInt() +1;
} else {
	SzerAutostradyE->Text = SzerAutostradyE->Text.ToInt() -1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrawdRozpRozmUDClick(TObject *Sender, TUDBtnType Button)
{
if (Button == btNext) {
	PrawdRozpRozmE->Text = PrawdRozpRozmE->Text.ToDouble() +0.1;
} else {
	PrawdRozpRozmE->Text = PrawdRozpRozmE->Text.ToDouble() -0.1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrawdRozpRozmEChange(TObject *Sender)
{
if (PrawdRozpRozmE->Text.ToDouble() <= 1 && PrawdRozpRozmE->Text.ToDouble() >=0.00009 ) {
	PrawdRozpRozmUD->Position = PrawdRozpRozmE->Text.ToDouble()*10;
} else {
	PrawdRozpRozmE->Text = 0.1;
	PrawdRozpRozmUD->Position = 1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZamknijBClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszwykres1Click(TObject *Sender)
{
Wykres->SaveToBitmapFile(AnsiString(time(0))+"wykres.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszdane1Click(TObject *Sender)
{
Wynik->Lines->SaveToFile(AnsiString(time(0))+"przydzial.txt");
Wynik2->Lines->SaveToFile(AnsiString(time(0))+"rozmawiajacy.txt");
Wynik3->Lines->SaveToFile(AnsiString(time(0))+"zajete.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::About1Click(TObject *Sender)
{
Application->MessageBox("Projekt 8 \n" "Symulator zdarzeñ dyskretnych \n"
			"Autor: Kamil Jagie³³o", "About Projekt 8", MB_ICONASTERISK);

}
//---------------------------------------------------------------------------

