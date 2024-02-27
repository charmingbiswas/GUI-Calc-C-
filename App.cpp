#include "App.hpp"
#include "MainFrame.hpp"

#include <wx/wx.h>

bool App::OnInit() {
    const wxString appTitle = "C++ GUI Calculator";
    MainFrame* frame = new MainFrame(appTitle);
    frame->SetClientSize(500, 300);
    frame->Center();
    frame->SetFocus();
    frame->Show();
    return true;
}


wxIMPLEMENT_APP_CONSOLE(App);