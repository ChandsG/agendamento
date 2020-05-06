//---------------------------------------------------------------------------

#ifndef UnitSobreH
#define UnitSobreH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSobre : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TText *Text1;
	TText *Text3;
	TLayout *Layout1;
	TButton *Button2;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSobre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSobre *FormSobre;
//---------------------------------------------------------------------------
#endif
