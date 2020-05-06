//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMaps.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormMps *FormMps;
//---------------------------------------------------------------------------
__fastcall TFormMps::TFormMps(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMps::Button1Click(TObject *Sender)
{
	WebBrowser1->GoBack();
}
//---------------------------------------------------------------------------
void __fastcall TFormMps::FormShow(TObject *Sender)
{
	WebBrowser1->Navigate("https://www.google.com/maps/");
}
//---------------------------------------------------------------------------
