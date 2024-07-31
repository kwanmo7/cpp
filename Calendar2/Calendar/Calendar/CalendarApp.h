#ifndef CALENDARAPP_H
#define CALENDARAPP_H

#include <wx/wx.h>
#include <wx/calctrl.h>

class CalendarApp : public wxFrame {
public:
    CalendarApp(const wxString& title);

private:
    void OnDateChanged(wxCalendarEvent& event);
    void OnSaveClicked(wxCommandEvent& event);

    wxCalendarCtrl* calendar;
    wxTextCtrl* eventText;
    wxButton* saveButton;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Calendar = wxID_HIGHEST + 1,
    ID_SaveButton
};

#endif //CALENDARAPP_H
