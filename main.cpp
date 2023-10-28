//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <iostream>
#pragma hdrstop

#include "main.h"
#include "ObrazekBMP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TOkno *Okno;
//---------------------------------------------------------------------------
__fastcall TOkno::TOkno(TComponent* Owner)
        : TForm(Owner)
{
    TimerStart->Enabled = true;
    n1 = 1.0003;
    n2 = 1.33;
    x = 1;
    y = 0;
}
//---------------------------------------------------------------------------

void TOkno::RysujStart()
{

    obrazek.kanwa->Pen->Color = clBlack;
    obrazek.kanwa->Pen->Width = 0.1;
    obrazek.kanwa->Brush->Color = clBlack;
    obrazek.kanwa->MoveTo(0, ys);
    obrazek.kanwa->LineTo(ObszarObrazu->Width, ys);

    obrazek.kanwa->MoveTo(xs, 0);
    obrazek.kanwa->LineTo(xs, ObszarObrazu->Height);

    obrazek.Rysuj(ObszarObrazu->Canvas);

}

//---------------------------------------------------------------------------

void TOkno::Rysuj()
{
    obrazek.Czysc(ObszarObrazu->Width, ObszarObrazu->Height);


    double tangens, a, katzalamanie, sinb, temp;

    if ( yz == ys) {
        return;

    } else
        tangens = (xs-x)/(ys-yz);

    alfa = atan(tangens) * (180/M_PI);
    a = atan(tangens);

    //Ustawienia rysowania
    obrazek.kanwa->Pen->Color = clRed;
    obrazek.kanwa->Pen->Width = 2;
    obrazek.kanwa->Brush->Color = clRed;


    // cwiartka 2
    obrazek.kanwa->MoveTo(xs, ys);
    obrazek.kanwa->LineTo(x, yz);

    // cwiartka 1

    obrazek.kanwa->MoveTo(xs, ys);
    obrazek.kanwa->LineTo(fabs(x-ObszarObrazu->Width), yz);




    //cwiartka 4 oraz wyliczanie katow

    sinb = (n1*sin(a))/n2;

    if(sinb <= 1)
    {
        katzalamanie = asin((n1*sin(a))/n2);
        zalamanie = katzalamanie * 180/M_PI;
        temp = tan(katzalamanie)*ys;
        obrazek.kanwa->MoveTo(xs, ys);
        obrazek.kanwa->LineTo(temp+xs, ObszarObrazu->Height);
    }

    if( n1 > n2 )
    {
        if( a >= asin(n2/n1))
        {
            obrazek.kanwa->MoveTo(xs, ys);
            obrazek.kanwa->LineTo(ObszarObrazu->Width, ys);
            zalamanie = 0;
        }
    }
    EDKatPadania->Text = alfa;
    EDKatZalamania->Text = zalamanie;


    obrazek.Rysuj(ObszarObrazu->Canvas);
    RysujStart();

}

void __fastcall TOkno::TimerStartTimer(TObject *Sender)
{
    TimerStart->Enabled = false;
    xs = ObszarObrazu->Width/2;
    ys = ObszarObrazu->Height/2;
    yz = 0;
    TBZmianaPozycjiX->Max = xs;
    TBZmianaPozycjiY->Max = ys;
    EDKatPadania->Text = alfa;
    EDKatZalamania->Text = zalamanie;
    Rysuj();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TOkno::CBOsrodkiN1Change(TObject *Sender)
{
    switch(CBOsrodkiN1->ItemIndex)
    {
        case 0:
            n1 = 1.0003;
            break;
        case 1:
            n1 = 1.33;
            break;
        case 2:
            n1 = 1.5;
            break;
        case 3:
            n1 = 2.42;
            break;
    }
    if(CBOsrodkiN1->ItemIndex == CBOsrodkiN2->ItemIndex)
    {
        Application->MessageBox("Wybrano te same osrodki, powrot do domyslnych ustawien", "Uwaga", MB_OK);
        CBOsrodkiN1->ItemIndex = 0;
        n1 = 1.0003;
        CBOsrodkiN2->ItemIndex = 1;
        n2 = 1.33;
    }
    Rysuj();
    EDKatPadania->Text = alfa;
    EDKatZalamania->Text = zalamanie;
}
//---------------------------------------------------------------------------

void __fastcall TOkno::CBOsrodkiN2Change(TObject *Sender)
{
    switch(CBOsrodkiN2->ItemIndex)
    {
        case 0:
            n2 = 1.0003;
            break;
        case 1:
            n2 = 1.33;
            break;
        case 2:
            n2 = 1.5;
            break;
        case 3:
            n2 = 2.42;
            break;
    }
    if(CBOsrodkiN2->ItemIndex == CBOsrodkiN1->ItemIndex)
    {
        Application->MessageBox("Wybrano te same osrodki, powrot do domyslnych ustawien", "Uwaga", MB_OK);
        CBOsrodkiN1->ItemIndex = 0;
        n1 = 1.0003;
        CBOsrodkiN2->ItemIndex = 1;
        n2 = 1.33;
    }
    Rysuj();
    EDKatPadania->Text = alfa;
    EDKatZalamania->Text = zalamanie;
}
//---------------------------------------------------------------------------


void __fastcall TOkno::TBZmianaPozycjiXChange(TObject *Sender)
{

    x = TBZmianaPozycjiX->Position;

    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TOkno::TBZmianaPozycjiYChange(TObject *Sender)
{
    yz = TBZmianaPozycjiY->Position;

    Rysuj();
}
//---------------------------------------------------------------------------

