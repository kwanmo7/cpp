#include "CalculatorFrame.h"

wxBEGIN_EVENT_TABLE(CalculatorFrame, wxFrame)
    EVT_MENU(wxID_EXIT, CalculatorFrame::OnExit)
    EVT_MENU(wxID_ABOUT, CalculatorFrame::OnAbout)
    EVT_BUTTON(ID_Add, CalculatorFrame::OnAdd)
    EVT_BUTTON(ID_Subtract, CalculatorFrame::OnSubtract)
    EVT_BUTTON(ID_Multiply, CalculatorFrame::OnMultiply)
    EVT_BUTTON(ID_Divide, CalculatorFrame::OnDivide)
    EVT_BUTTON(ID_Sine, CalculatorFrame::OnSine)
    EVT_BUTTON(ID_Cosine, CalculatorFrame::OnCosine)
    EVT_BUTTON(ID_Tangent, CalculatorFrame::OnTangent)
    EVT_BUTTON(ID_Logarithm, CalculatorFrame::OnLogarithm)
    EVT_BUTTON(ID_NaturalLogarithm, CalculatorFrame::OnNaturalLogarithm)
    EVT_BUTTON(ID_Power, CalculatorFrame::OnPower)
    EVT_BUTTON(ID_SquareRoot, CalculatorFrame::OnSquareRoot)
wxEND_EVENT_TABLE()

CalculatorFrame::CalculatorFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    firstNumberTextCtrl = new wxTextCtrl(this, wxID_ANY);
    sizer->Add(firstNumberTextCtrl, 0, wxEXPAND | wxALL, 5);

    secondNumberTextCtrl = new wxTextCtrl(this, wxID_ANY);
    sizer->Add(secondNumberTextCtrl, 0, wxEXPAND | wxALL, 5);

    wxGridSizer* gridSizer = new wxGridSizer(4, 3, 3, 3);

    gridSizer->Add(new wxButton(this, ID_Add, "Add"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Subtract, "Subtract"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Multiply, "Multiply"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Divide, "Divide"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Sine, "Sine"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Cosine, "Cosine"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Tangent, "Tangent"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Logarithm, "Logarithm"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_NaturalLogarithm, "Natural Log"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_Power, "Power"), 0, wxEXPAND);
    gridSizer->Add(new wxButton(this, ID_SquareRoot, "Square Root"), 0, wxEXPAND);

    sizer->Add(gridSizer, 1, wxEXPAND);

    resultLabel = new wxStaticText(this, wxID_ANY, "");
    sizer->Add(resultLabel, 0, wxEXPAND | wxALL, 5);

    SetSizer(sizer);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}

void CalculatorFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void CalculatorFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a wxWidgets' based scientific calculator",
        "About Calculator", wxOK | wxICON_INFORMATION);
}

void CalculatorFrame::OnAdd(wxCommandEvent& event) {
    double a = wxAtof(firstNumberTextCtrl->GetValue());
    double b = wxAtof(secondNumberTextCtrl->GetValue());
    double result = Calculator::add(a, b);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnSubtract(wxCommandEvent& event) {
    double a = wxAtof(firstNumberTextCtrl->GetValue());
    double b = wxAtof(secondNumberTextCtrl->GetValue());
    double result = Calculator::subtract(a, b);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnMultiply(wxCommandEvent& event) {
    double a = wxAtof(firstNumberTextCtrl->GetValue());
    double b = wxAtof(secondNumberTextCtrl->GetValue());
    double result = Calculator::multiply(a, b);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnDivide(wxCommandEvent& event) {
    double a = wxAtof(firstNumberTextCtrl->GetValue());
    double b = wxAtof(secondNumberTextCtrl->GetValue());
    bool ok;
    double result = Calculator::divide(a, b, ok);
    if (!ok) {
        wxMessageBox("Division by zero is undefined.", "Error", wxOK | wxICON_ERROR);
    }
    else {
        resultLabel->SetLabelText(wxString::Format("%f", result));
    }
}

void CalculatorFrame::OnSine(wxCommandEvent& event) {
    double angle = wxAtof(firstNumberTextCtrl->GetValue());
    double result = Calculator::sine(angle);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnCosine(wxCommandEvent& event) {
    double angle = wxAtof(firstNumberTextCtrl->GetValue());
    double result = Calculator::cosine(angle);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnTangent(wxCommandEvent& event) {
    double angle = wxAtof(firstNumberTextCtrl->GetValue());
    double result = Calculator::tangent(angle);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnLogarithm(wxCommandEvent& event) {
    double value = wxAtof(firstNumberTextCtrl->GetValue());
    bool ok;
    double result = Calculator::logarithm(value, ok);
    if (!ok) {
        wxMessageBox("Logarithm of non-positive number is undefined.", "Error", wxOK | wxICON_ERROR);
    }
    else {
        resultLabel->SetLabelText(wxString::Format("%f", result));
    }
}

void CalculatorFrame::OnNaturalLogarithm(wxCommandEvent& event) {
    double value = wxAtof(firstNumberTextCtrl->GetValue());
    bool ok;
    double result = Calculator::naturalLogarithm(value, ok);
    if (!ok) {
        wxMessageBox("Natural logarithm of non-positive number is undefined.", "Error", wxOK | wxICON_ERROR);
    }
    else {
        resultLabel->SetLabelText(wxString::Format("%f", result));
    }
}

void CalculatorFrame::OnPower(wxCommandEvent& event) {
    double base = wxAtof(firstNumberTextCtrl->GetValue());
    double exponent = wxAtof(secondNumberTextCtrl->GetValue());
    double result = Calculator::power(base, exponent);
    resultLabel->SetLabelText(wxString::Format("%f", result));
}

void CalculatorFrame::OnSquareRoot(wxCommandEvent& event) {
    double value = wxAtof(firstNumberTextCtrl->GetValue());
    bool ok;
    double result = Calculator::squareRoot(value, ok);
    if (!ok) {
        wxMessageBox("Square root of negative number is undefined.", "Error", wxOK | wxICON_ERROR);
    }
    else {
        resultLabel->SetLabelText(wxString::Format("%f", result));
    }
}
