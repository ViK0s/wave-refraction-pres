//---------------------------------------------------------------------------

#ifndef ObrazekBMPH
#define ObrazekBMPH
//---------------------------------------------------------------------------

class TObrazekBMP
{
public:
    int szerokosc, wysokosc;
    Graphics::TBitmap *BMP;
    TCanvas *kanwa;

    void Czysc(int ASzerokosc, int AWysokosc, TColor kolorTla=clWhite);
    void Rysuj (TCanvas *AKanwa, int AX=0, int AY=0);

    TObrazekBMP();
    ~TObrazekBMP();

};


#endif
