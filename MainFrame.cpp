#include "MainFrame.hpp"

#include <vector>
#include <iostream>


enum ButtonID {
    btn_0 = 0,
    btn_1,
    btn_2,
    btn_3,
    btn_4,
    btn_5,
    btn_6,
    btn_7,
    btn_8,
    btn_9,
    btn_add,
    btn_sub,
    btn_mul,
    btn_div
};

std::vector<wxButton*> buttons(10, nullptr);

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{ 
    const int WIDTH = FromDIP(50);
    const int HEIGHT = FromDIP(50);
    const int ROWS = 4;
    const int COLUMNS = 3;

    auto buttonsGrid = new wxGridSizer(ROWS, COLUMNS, wxSize(0, 0));

    for(int i = 0; i <= 9; i++) {
        auto label = wxString::Format("%d", i);
        auto btn = new wxButton(this, ButtonID(i), label, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
        btn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
        buttons[i] = btn;
    }

    // first row
    for(int i = 7; i <=9; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }

    // second row
    for(int i = 4; i <=6; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }

    // third row
    // second row
    for(int i = 1; i <=3; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }

    auto emptyBtnOne = new wxButton(this, wxID_ANY, "", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    auto emptyBtnTwo = new wxButton(this, wxID_ANY, "", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    auto zeroBtn = buttons[0];
    buttonsGrid->Add(emptyBtnOne, 0, wxALL, 0);
    buttonsGrid->Add(zeroBtn, 0, wxALL, 0);
    buttonsGrid->Add(emptyBtnTwo, 0, wxALL, 0);


    CreateStatusBar();
    this->SetSizerAndFit(buttonsGrid);
};


void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    std::cout << "Clicked\n"; 
    auto id = event.GetString();
    wxLogStatus(id);
}
