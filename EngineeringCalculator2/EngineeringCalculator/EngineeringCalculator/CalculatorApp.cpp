#include "CalculatorApp.h"

bool CalculatorApp::OnInit() {
    CalculatorFrame* frame = new CalculatorFrame("Engineering Calculator", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
