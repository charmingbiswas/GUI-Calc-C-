// #include "MyFrame.hpp"

// #include <vector>
// #include <unordered_map>
// #include <string>
// #include <iostream>



// MyFrame::MyFrame(const wxString& title)
//     : wxFrame(nullptr, wxID_ANY, title)
// {

//     std::unordered_map<int, std::string> charMap = {
//         {1, "+"},
//         {2, "-"},
//         {3, "*"},
//         {4, "/"},
//     };

//     const int HEIGHT = FromDIP(100);
//     const int WIDTH = FromDIP(100);

//     const int ROWS = 3;
//     const int COLS = 3;

//     auto verticalBox = new wxBoxSizer(wxVERTICAL);
//     auto horizontalBox = new wxBoxSizer(wxHORIZONTAL);
//     auto panelTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 50));
//     // auto panelBottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));

//     panelTop->SetBackgroundColour(wxColor(100, 200, 100));

//     verticalBox->Add(panelTop, 0, wxEXPAND | wxALL, 5);
//     // verticalBox->Add(panelBottom, 1, wxEXPAND | wxALL, 5);
//     auto gridNumbers = new wxGridSizer(ROWS, COLS, 5, 5);
//     auto gridOperators = new wxGridSizer(4, 1, 5, 5);

//     for(int i = 1; i <= 9; i++) {
//         wxButton *my_button1 = new wxButton(this, wxID_ANY, wxString::Format("Button %d", i));

//         wxBitmap changedBMP(wxSize(1, 1));// = wxNullBitmap;// = unchangedBitmap;
//         wxMemoryDC memDC;
//         memDC.SelectObject(changedBMP);

//         wxColour bgcolour = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);//m_colourDefaultBackground;

//         memDC.SetBackground(bgcolour);
//         memDC.Clear();
//         memDC.SelectObject(wxNullBitmap);
        
//         my_button1->SetBitmap(changedBMP);
//         gridNumbers->Add(my_button1, 1, wxEXPAND);
//     }

//     for(int i = 1; i <= 4; i++) {
//         auto label = wxString::Format("%s", charMap[i]);
//         std::cout << label << std::endl;
//         wxButton *my_button1 = new wxButton(this, wxID_ANY, label);

//         wxBitmap changedBMP(wxSize(1, 1));// = wxNullBitmap;// = unchangedBitmap;
//         wxMemoryDC memDC;
//         memDC.SelectObject(changedBMP);

//         wxColour bgcolour = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);//m_colourDefaultBackground;

//         memDC.SetBackground(bgcolour);
//         memDC.Clear();
//         memDC.SelectObject(wxNullBitmap);
        
//         my_button1->SetBitmap(changedBMP);
//         gridOperators->Add(my_button1, 1, wxEXPAND);
//     } 

//     horizontalBox->Add(gridNumbers, 1, wxEXPAND | wxTOP | wxRight , 5);
//     horizontalBox->Add(gridOperators, 1, wxEXPAND | wxTOP | wxLEFT, 5);
//     verticalBox->Add(horizontalBox, 1, wxEXPAND);

    

    

    


//     // auto grid = new wxGridSizer(ROWS, COLS, 0, 0);

//     // for(int i = 0; i < ROWS; i++) {
//     //     for(int j = 0; j < COLS; j++) {
//     //         auto square = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(WIDTH, HEIGHT));
//     //         auto btn = new wxButton(square, wxID_ANY, wxString::Format("Button %d", i), wxDefaultPosition, wxSize(WIDTH, HEIGHT));
//     //         bool isDark = (i + j) % 2 == 0;
//     //         square->SetBackgroundColour(isDark ? wxColor(80, 80, 80) : *wxWHITE);

//     //         grid->Add(square, 0, wxEXPAND);
//     //     }
//     // }

//     this->SetSizerAndFit(verticalBox);
// };