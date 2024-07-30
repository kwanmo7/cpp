#ifndef CALCULATORFRAME_H
#define CALCULATORFRAME_H

#include <wx/wx.h>
#include "Calculator.h"

class CalculatorFrame : public wxFrame {
public:
    CalculatorFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnAdd(wxCommandEvent& event);
    void OnSubtract(wxCommandEvent& event);
    void OnMultiply(wxCommandEvent& event);
    void OnDivide(wxCommandEvent& event);
    void OnSine(wxCommandEvent& event);
    void OnCosine(wxCommandEvent& event);
    void OnTangent(wxCommandEvent& event);
    void OnLogarithm(wxCommandEvent& event);
    void OnNaturalLogarithm(wxCommandEvent& event);
    void OnPower(wxCommandEvent& event);
    void OnSquareRoot(wxCommandEvent& event);

    wxTextCtrl* firstNumberTextCtrl;
    wxTextCtrl* secondNumberTextCtrl;
    wxStaticText* resultLabel;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Add = 1,
    ID_Subtract,
    ID_Multiply,
    ID_Divide,
    ID_Sine,
    ID_Cosine,
    ID_Tangent,
    ID_Logarithm,
    ID_NaturalLogarithm,
    ID_Power,
    ID_SquareRoot
};

#endif // CALCULATORFRAME_H
