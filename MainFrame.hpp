#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame {
    private:
        wxTextCtrl* display;
    public:
        MainFrame(const wxString& appTitle);
        void OnButtonClicked(wxCommandEvent& event);
};