//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include "ObrazekBMP.h"

const int R = 5;
//---------------------------------------------------------------------------
class TOkno : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
    TPaintBox *ObszarObrazu;
    TComboBox *CBOsrodkiN1;
    TComboBox *CBOsrodkiN2;
    TTimer *TimerStart;
    TTrackBar *TBZmianaPozycjiX;
    TTrackBar *TBZmianaPozycjiY;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *EDKatPadania;
    TEdit *EDKatZalamania;
    void __fastcall TimerStartTimer(TObject *Sender);
    void __fastcall CBOsrodkiN1Change(TObject *Sender);
    void __fastcall CBOsrodkiN2Change(TObject *Sender);
    void __fastcall TBZmianaPozycjiXChange(TObject *Sender);
    void __fastcall TBZmianaPozycjiYChange(TObject *Sender);
    






private:	// User declarations
    double grubosc;
    double xs, ys, x, y, alfa, a, zalamanie, yz;
    double n1, n2;
    void RysujStart();
    void Rysuj();
    TObrazekBMP obrazek;
public:		// User declarations
        __fastcall TOkno(TComponent* Owner);
        
};
//---------------------------------------------------------------------------
extern PACKAGE TOkno *Okno;
//---------------------------------------------------------------------------
#endif
