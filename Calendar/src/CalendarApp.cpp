#include "../include/CalendarApp.h"

wxBEGIN_EVENT_TABLE(CalendarApp, wxFrame)
    EVT_CALENDAR_SEL_CHANGED(ID_Calendar, CalendarApp::OnDateChanged)
    EVT_BUTTON(ID_SaveButton, CalendarApp::OnSaveClicked)
wxEND_EVENT_TABLE()

CalendarApp::CalendarApp(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400,300)){
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    calendar = new wxCalendarCtrl(this, ID_Calendar, wxDefaultDateTime,
                                    wxDefaultPosition,wxDefaultSize,wxCAL_SHOW_HOLIDAYS);
    vbox->Add(calendar, 1, wxEXPAND | wxALL, 5);

    eventText = new wxTextCtrl(this, wxID_ANY, "",
                                wxDefaultPosition, wxSize(300, 100),wxTE_MULTILINE);
    vbox->Add(eventText, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

    saveButton = new wxButton(this, ID_SaveButton, "Save Event");
    vbox->Add(saveButton, 0, wxALIGN_CENTER | wxALL, 5);

    SetSizer(vbox);
}

void CalendarApp::OnDateChanged(wxCalendarEvent &event) {
    eventText->Clear();
    eventText->SetHint(wxString::Format("Add event for %s", event.GetDate().FormatISODate()));

}

void CalendarApp::OnSaveClicked(wxCommandEvent &event) {
    wxString eventDetails = eventText->GetValue();
    if(!eventDetails.IsEmpty()) {
        wxLogMessage("Event saved: %s", eventDetails);
    }
}

