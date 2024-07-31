#include <wx/wx.h>
#include "../include/CalendarApp.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    CalendarApp* frame = new CalendarApp("Calendar Application");
    frame->Show(true);
    return true;
}
