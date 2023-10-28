//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ObrazekBMP.h"

TObrazekBMP::TObrazekBMP()
{
    BMP = NULL;
    BMP = new Graphics::TBitmap();
    kanwa = BMP->Canvas;
    szerokosc = 100;
    wysokosc = 100;
    BMP->Width=szerokosc;
    BMP->Height = wysokosc;

}

//---------------------------------------------------------------------------
TObrazekBMP::~TObrazekBMP()
{
    if(BMP!=NULL)
        delete BMP;
}

//---------------------------------------------------------------------------

void TObrazekBMP::Czysc(int ASzerokosc, int AWysokosc, TColor AKolorTla)
{
    TRect prostokat;

    prostokat = TRect(0,0,ASzerokosc, AWysokosc);
    szerokosc = ASzerokosc;
    wysokosc = AWysokosc;
    BMP->Width = szerokosc;
    BMP->Height = wysokosc;
    kanwa->Brush->Color = AKolorTla;
    kanwa->FillRect(prostokat);


}
//---------------------------------------------------------------------------

void TObrazekBMP::Rysuj(TCanvas *AKanwa, int AX, int AY)
{
    AKanwa->Draw(AX, AY, BMP);


}
//---------------------------------------------------------------------------
#pragma package(smart_init)
