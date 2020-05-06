//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitSobre.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormSobre *FormSobre;
//---------------------------------------------------------------------------
__fastcall TFormSobre::TFormSobre(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormSobre::FormShow(TObject *Sender)
{
	Layout1->Visible = false;
	Text3->Text = "Francisco Manuel Kunanga Caianga."
	"\nClemente Tchissingue Fayenda."
	"\nAlexandra Monica Bravo Mendes."
	"\nSonia Noemia Lopes Narciso.";

}
//---------------------------------------------------------------------------

void __fastcall TFormSobre::Button2Click(TObject *Sender)
{

	String TaskName;
	TaskName = Edit1->Text;
	if (TaskName == "28256")
	{
		Form2->Show();
	}
	Close();
}
//---------------------------------------------------------------------------



void __fastcall TFormSobre::Button1Click(TObject *Sender)
{
  Layout1->Visible = true;
}
//---------------------------------------------------------------------------

