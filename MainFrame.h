#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    void OnGenerateAge(wxCommandEvent& event);
    void OnGenerateName(wxCommandEvent& event);

    wxTextCtrl* firstLetterInput;
    wxTextCtrl* lettersInput;
    wxButton* ageButton;
    wxButton* nameButton;

    wxStaticText* ageResultLabel;
    wxStaticText* nameResultLabel;
};
