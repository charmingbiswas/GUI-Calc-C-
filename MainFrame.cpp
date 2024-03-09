#include "MainFrame.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <queue>

enum ButtonID {
    btn_0 = 10,
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
    btn_div,
    btn_equal,
    btn_reset
};

std::vector<wxButton*> buttons(10, nullptr);
std::vector<int> selectedNumbers;
std::string selectedOperator = "";


MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{ 
    const int WIDTH = FromDIP(50);
    const int HEIGHT = FromDIP(50);
    const int ROWS = 4;
    const int COLUMNS = 4;

    auto verticalSizer = new wxBoxSizer(wxVERTICAL);
    this->display = new wxTextCtrl(this, 1000, "", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    auto buttonsGrid = new wxGridSizer(ROWS, COLUMNS, 0, 0);

    for(int i = 0; i <= 9; i++) {
        auto label = wxString::Format("%d", i);
        auto btn = new wxButton(this, ButtonID(i + 10), label, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
        btn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
        buttons[i] = btn;
    }

    // first row
    for(int i = 7; i <=9; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }
    auto addBtn = new wxButton(this, btn_add, "+", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    addBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    buttonsGrid->Add(addBtn);

    // second row
    for(int i = 4; i <=6; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }
    auto subBtn = new wxButton(this, btn_sub, "-", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    subBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    buttonsGrid->Add(subBtn);

    // third row
    for(int i = 1; i <=3; i++) {
        auto btn = buttons[i];
        buttonsGrid->Add(btn, 0, wxALL, 0);
    }
    auto mulBtn = new wxButton(this, btn_mul, "*", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    mulBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    buttonsGrid->Add(mulBtn);

    auto resetBtn = new wxButton(this, btn_reset, "CLR", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    auto equalBtn = new wxButton(this, btn_equal, "=", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    resetBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    equalBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    auto zeroBtn = buttons[0];
    buttonsGrid->Add(resetBtn, 0, wxALL, 0);
    buttonsGrid->Add(zeroBtn, 0, wxALL, 0);
    buttonsGrid->Add(equalBtn, 0, wxALL, 0);
    auto divBtn = new wxButton(this, btn_div, "/", wxDefaultPosition, wxSize(WIDTH, HEIGHT));
    divBtn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    buttonsGrid->Add(divBtn);

    verticalSizer->Add(display, 0, wxEXPAND);
    verticalSizer->Add(buttonsGrid, 0, wxEXPAND);
    this->SetSizerAndFit(verticalSizer);
};


void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    int id = event.GetId();
    switch (id)
    {
    case btn_0:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_1:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_2:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_3:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_4:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_5:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_6:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_7:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_8:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_9:
        if((int)selectedNumbers.size() < 2) {
            selectedNumbers.push_back(id - 10);
        } else {
            selectedNumbers[0] = selectedNumbers[1];
            selectedNumbers[1] = id - 10;
        }
        break;
    case btn_equal:
        if((int)selectedNumbers.size() == 2 && selectedOperator != "") {
            if(selectedOperator == "+") {
                int value = selectedNumbers[0] + selectedNumbers[1];
                std::cout << value;
                display->ChangeValue(wxString::Format("%d", value));
            } else if(selectedOperator == "-") {
                int value = selectedNumbers[0] - selectedNumbers[1];
                display->ChangeValue(wxString::Format("%d", value));
            } else if(selectedOperator == "*") {
                int value = selectedNumbers[0] * selectedNumbers[1];
                display->ChangeValue(wxString::Format("%d", value));
            } else if(selectedOperator == "/") {
                int value = selectedNumbers[0] / selectedNumbers[1];
                display->ChangeValue(wxString::Format("%d", value));
            }
        }
        break;
    case btn_add:
        selectedOperator = "+";
        break;
    case btn_sub:
        selectedOperator = "-";
        break;
    case btn_mul:
        selectedOperator = "*";
        break;
    case btn_div:
        selectedOperator = "/";
        break;
    case btn_reset:
        std::cout << "Reset\n";
        selectedOperator = "";
        selectedNumbers.resize(0);
        this->display->ChangeValue("");
        break;
    default:
        break;
    }
}

