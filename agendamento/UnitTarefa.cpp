//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitTarefa.h"
#include "uMain.h"
#include "UnitMaps.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TForm1::ButtonAlterarClick(TObject *Sender)
{
	AnsiString SQL;
    FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskName")->AsAnsiString = Text1->Text;
	FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskDescricao")->AsAnsiString = MemoDescricao->Lines->Text;
	FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskHora")->AsDateTime = TimeEditHora->Time;
	FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskData")->AsDate = DateEditData->Date;
	FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskLocal")->AsAnsiString = EditLocal->Text;
	FireDAC_SQLiteForm->FDQueryModificar->ParamByName("TaskDuracao")->AsInteger = TrackBarLocal->Value;
	try {
		SQL = FireDAC_SQLiteForm->FDQueryModificar->SQL->Text;
		FireDAC_SQLiteForm->FDQueryModificar->ExecSQL();
	FireDAC_SQLiteForm->FDTableTask->Refresh();

	} 		catch (Exception &exception)
		{
			ShowMessage(exception.Message+" - "+SQL);
		}

	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CornerButton1Click(TObject *Sender)
{
    FormMps->Show();
}
//---------------------------------------------------------------------------

