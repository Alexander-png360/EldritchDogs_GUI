#include "MainFrame.h"
#include "eldritchdogs.h"
#include <cstdlib>
#include <ctime>
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Age button
    ageButton = new wxButton(panel, wxID_ANY, "Generate Age", wxPoint(50, 20), wxSize(120, 30));
    ageButton->Bind(wxEVT_BUTTON, &MainFrame::OnGenerateAge, this);

    // Age result label
    ageResultLabel = new wxStaticText(panel, wxID_ANY, "", wxPoint(200, 25), wxSize(150, 30));

    // Name inputs
    new wxStaticText(panel, wxID_ANY, "First Letter:", wxPoint(50, 70));
    firstLetterInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 65), wxSize(50, 25));

    new wxStaticText(panel, wxID_ANY, "Length:", wxPoint(50, 110));
    lettersInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 105), wxSize(50, 25));

    // Name button
    nameButton = new wxButton(panel, wxID_ANY, "Generate Name", wxPoint(50, 150), wxSize(120, 30));
    nameButton->Bind(wxEVT_BUTTON, &MainFrame::OnGenerateName, this);

    // Name result label
    nameResultLabel = new wxStaticText(panel, wxID_ANY, "", wxPoint(200, 155), wxSize(200, 30));
}

// Calls age_generator.cpp
void MainFrame::OnGenerateAge(wxCommandEvent& event)
{
    int age = generate_age();  // delegate to age_generator.cpp
    wxString ageStr = wxString::Format("Dog's Age: %d", age);
    ageResultLabel->SetLabel(ageStr);
}

// Calls name_generator.cpp
void MainFrame::OnGenerateName(wxCommandEvent& event)
{
    wxString firstLetterStr = firstLetterInput->GetValue();
    wxString lettersStr = lettersInput->GetValue();

    if (firstLetterStr.IsEmpty() || lettersStr.IsEmpty())
    {
        nameResultLabel->SetLabel("Please enter a letter and length!");
        return;
    }

    char firstLetter = firstLetterStr.ToStdString()[0];

    int letters = 0;
    if (!lettersStr.ToLong((long*)&letters) || letters < 1)
    {
        nameResultLabel->SetLabel("Invalid length!");
        return;
    }

    // Delegate to name_generator.cpp
    std::string name = generateName(firstLetter, letters);

    nameResultLabel->SetLabel("Generated Name: " + name);
}
