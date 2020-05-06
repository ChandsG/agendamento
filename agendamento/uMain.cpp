//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "uMain.h"
#include "UnitTarefa.h"
#include "UnitSobre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.SmXhdpiPh.fmx", _PLAT_ANDROID)

TFireDAC_SQLiteForm *FireDAC_SQLiteForm;
//---------------------------------------------------------------------------
__fastcall TFireDAC_SQLiteForm::TFireDAC_SQLiteForm(TComponent* Owner)
	: TForm(Owner)
{
	Layout1->Visible = false;

	try {
		// For unidirectional dataset, don't refill automatically when dataset is activated
		// because dataset is reactivated everytime use DataSet.First.
		LinkFillControlToField1->AutoActivate = false;
		LinkFillControlToField1->AutoFill = false;
		Application->OnIdle = OnIdle;
		FireTaskList->Connected = true;
		FDTableTask->Active = true;
		LinkFillControlToField1->BindList->FillList();
	} catch (Exception &e) {
		ShowMessage(e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFireDAC_SQLiteForm::btnAddClick(TObject *Sender)
{
	Layout1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFireDAC_SQLiteForm::btnDeleteClick(TObject *Sender)
{
	String TaskName;
	TaskName = ListBox1->Selected->Text;
	try {
		FDQueryDelete->ParamByName("TaskName")->AsString = TaskName;
		FDQueryDelete->ExecSQL();
		FDTableTask->Refresh();
		LinkFillControlToField1->BindList->FillList();
		if ((ListBox1->Selected) && (ListBox1->Count > 0)) {
			ListBox1->ItemIndex = ListBox1->Count - 1;
		}
	} catch (Exception &e) {
		ShowMessage(e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFireDAC_SQLiteForm::OnIdle(TObject* Sender, bool &Done)
{
	btnDelete->Visible = ListBox1->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TFireDAC_SQLiteForm::FireTaskListAfterConnect(TObject *Sender)
{
	FireTaskList->ExecSQL("CREATE TABLE IF NOT EXISTS Task (IdTarefa INT  PRIMARY KEY,TaskName TEXT NOT NULL,"
	"TaskHora DATETIME, TaskDescricao TEXT, TaskDuracao INT, TaskLocal TEXT, TaskData Date)");
}
//---------------------------------------------------------------------------

void __fastcall TFireDAC_SQLiteForm::FireTaskListBeforeConnect(TObject *Sender)
{
#if defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(__ANDROID__)
	FireTaskList->Params->Values["Database"] = IncludeTrailingPathDelimiter(
		System::Ioutils::TPath::GetDocumentsPath()) + "tasks.s3db";
#else
	FireTaskList->Params->Values["Database"] = "tasks.s3db";
#endif
}
//---------------------------------------------------------------------------



void __fastcall TFireDAC_SQLiteForm::ListBox1ItemClick(TCustomListBox * const Sender,
	TListBoxItem * const Item)
{   FDQueryProcurar->Active = false;
	FDQueryProcurar->ParamByName("TaskName")->AsAnsiString =  Item->Text;
	FDQueryProcurar->Active = true;
	Form1->Text1->Text = FDQueryProcurar->FieldByName("TaskName")->AsString;
	Form1->MemoDescricao->Lines->Clear();
	Form1->MemoDescricao->Lines->Add(FDQueryProcurar->FieldByName("TaskDescricao")->AsString);
	Form1->TimeEditHora->Time = FDQueryProcurar->FieldByName("TaskHora")->AsDateTime;
	Form1->DateEditData->Date = FDQueryProcurar->FieldByName("TaskData")->AsDateTime;
	Form1->EditLocal->Text = FDQueryProcurar->FieldByName("TaskLocal")->AsString;
	int hora = FDQueryProcurar->FieldByName("TaskDuracao")->AsInteger;
	Form1->TrackBarLocal->Value = hora;
	Form1->Label6->Text = "Tempo: "+IntToStr(hora)+" Horas";
	Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFireDAC_SQLiteForm::Button1Click(TObject *Sender)
{
	FormSobre->Show();


}
//---------------------------------------------------------------------------


void __fastcall TFireDAC_SQLiteForm::Button2Click(TObject *Sender)
{
  	String TaskName;
	TaskName = Edit1->Text;
	Edit1->Text = "";
	try {
		if (!(Trim(TaskName) == "")) {
			FDQueryInsert->ParamByName("TaskName")->AsString = TaskName;
			FDQueryInsert->ExecSQL();
			FDTableTask->Refresh();
			LinkFillControlToField1->BindList->FillList();
		}
	}
	catch(Exception &e)
	{
		ShowMessage(e.Message);
	}
	Layout1->Visible = false;
}
//---------------------------------------------------------------------------

