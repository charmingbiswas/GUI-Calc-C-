#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame {
    public:
        MainFrame(const wxString& appTitle);
        void OnButtonClicked(wxCommandEvent& event);
};