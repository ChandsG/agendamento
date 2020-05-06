//---------------------------------------------------------------------------

#ifndef UnitTarefaH
#define UnitTarefaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TLabel *Label2;
	TDateEdit *DateEditData;
	TLabel *Label3;
	TMemo *MemoDescricao;
	TTimeEdit *TimeEditHora;
	TLabel *Label4;
	TButton *ButtonAlterar;
	TText *Text1;
	TEdit *EditLocal;
	TLabel *Label5;
	TLabel *Label6;
	TTrackBar *TrackBarLocal;
	TCornerButton *CornerButton1;
	void __fastcall ButtonAlterarClick(TObject *Sender);
	void __fastcall CornerButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
