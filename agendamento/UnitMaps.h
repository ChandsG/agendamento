//---------------------------------------------------------------------------

#ifndef UnitMapsH
#define UnitMapsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
//---------------------------------------------------------------------------
class TFormMps : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMps(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMps *FormMps;
//---------------------------------------------------------------------------
#endif
