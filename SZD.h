//---------------------------------------------------------------------------

#ifndef SZDH
#define SZDH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <vector.h>
#include "Chart.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include "Series.hpp"
#include <Menus.hpp>
#include <losow.h>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{

__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TComboBox *RozmiarSieciCB;
	TEdit *IloscIteracjiE;
	TUpDown *IloscIteracjiUD;
	TUpDown *LiczbaAbonentowUD;
	TUpDown *PrawdRozpRozmUD;
	TEdit *IloscKanalowE;
	TEdit *LiczbaAbonentowE;
	TEdit *PrawdRozpRozmE;
	TEdit *SzerAutostradyE;
	TLabel *Label1;
	TEdit *ZiarnoE;
	TEdit *OdchylenieE;
	TEdit *SredniaE;
	TLabel *Label2;
	TCheckBox *StalaCB;
	TCheckBox *CBZZ;
	TCheckBox *CBBZ;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label8;
	TUpDown *SzerAutostradyUD;
	TGroupBox *GroupBox2;
	TTrackBar *ProporcjaTB;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TTabControl *Zakladki;
	TButton *StartB;
	TImage *Image;
	TLabel *Label14;
	TLabel *Label15;
	TTimer *Timer;
	TMemo *Wynik;
	TMemo *Wynik2;
	TChart *Wykres;
	TProgressBar *PostepPB;
	TLabel *Label16;
	TLabel *Label17;
	TMemo *Wynik3;
	TLabel *Label18;
	TGroupBox *GroupBox3;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TUpDown *IloscKanalowUD;
	TLabel *Label22;
	TLabel *Label23;
	TFastLineSeries *Wykorzystanie;
	TMainMenu *MainMenu1;
	TMenuItem *Symulator1;
	TMenuItem *Zakocz1;
	TMenuItem *Zapiszwykres1;
	TMenuItem *Zapiszdane1;
	TGroupBox *GroupBox4;
	TMenuItem *About1;
	void __fastcall RozmiarSieciCBKeyPress(TObject *Sender, char &Key);
	void __fastcall IloscIteracjiEKeyPress(TObject *Sender, char &Key);
	void __fastcall IloscIteracjiNaSekundeEKeyPress(TObject *Sender, char &Key);
	void __fastcall IloscKanalowEKeyPress(TObject *Sender, char &Key);
	void __fastcall LiczbaAbonentowEKeyPress(TObject *Sender, char &Key);
	void __fastcall PrawdRozpRozmEKeyPress(TObject *Sender, char &Key);
	void __fastcall MaxRozmowyEKeyPress(TObject *Sender, char &Key);
	void __fastcall SzerAutostradyEKeyPress(TObject *Sender, char &Key);
	void __fastcall ZiarnoEKeyPress(TObject *Sender, char &Key);
	void __fastcall OdchylenieEKeyPress(TObject *Sender, char &Key);
	void __fastcall SredniaEKeyPress(TObject *Sender, char &Key);
	void __fastcall ZakladkiMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StartBClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall ProporcjaTBChange(TObject *Sender);
	void __fastcall CBBZContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled);
	void __fastcall CBBZMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest,
          TMouseActivate &MouseActivate);
	void __fastcall CBZZMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest,
          TMouseActivate &MouseActivate);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall ZakladkiChange(TObject *Sender);
	void __fastcall IloscIteracjiUDClick(TObject *Sender, TUDBtnType Button);
	void __fastcall IloscIteracjiEChange(TObject *Sender);
	void __fastcall LiczbaKanalowUDClick(TObject *Sender, TUDBtnType Button);
	void __fastcall IloscKanalowEChange(TObject *Sender);
	void __fastcall LiczbaAbonentowEChange(TObject *Sender);
	void __fastcall LiczbaAbonentowUDClick(TObject *Sender, TUDBtnType Button);
	void __fastcall SzerAutostradyEChange(TObject *Sender);
	void __fastcall SzerAutostradyUDClick(TObject *Sender, TUDBtnType Button);
	void __fastcall PrawdRozpRozmUDClick(TObject *Sender, TUDBtnType Button);
	void __fastcall PrawdRozpRozmEChange(TObject *Sender);
	void __fastcall ZamknijBClick(TObject *Sender);
	void __fastcall Zakocz1Click(TObject *Sender);
	void __fastcall Zapiszwykres1Click(TObject *Sender);
	void __fastcall Zapiszdane1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	void RysowanieSiatki (double SZER, double DL, int ROZMIAR );
	void RysowaniePkt ();
	void Ruch();
	void Zaznacz();
	void Czas();
	double Silnia(int n);
   //	double Poisson(int k, double lambda);
	//double Normalny(int k, double oczekiwana, double odchylenie);

	vector<int> doRozmowy;
	vector<double> poissonV;
	int rozmiarSieci, iteracje, kanaly, abonenci, aboAutostrada, aboStatyczny, szerokosc, ileKomorki,
	odchylenie, srednia, ziarno, temp, zdarzenia, oczekiwana, wylosowanyKierunek, dodatek;
	double prawdRozmowy;
	bool aboTest, stala;
	TPoint start;
	TPoint start2;

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
