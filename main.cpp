#include "MainFrame.h"
#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit() override
    {
        MainFrame* frame = new MainFrame("Eldritch Dogs GUI");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
