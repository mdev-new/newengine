#include <glad/glad.h>

#include "engine/Engine.hpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

#include <memory>
#include <wx/notebook.h>
#include <wx/glcanvas.h>

#ifdef _WIN32
	#include <uxtheme.h>
#endif

// this file is a fucking mess

Engine *engine = nullptr;

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnNew(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExport(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};


class TriangleCanvas : public wxGLCanvas  {
    public:
        TriangleCanvas(wxWindow* parent, wxWindowID id = wxID_ANY, 
            const int* attribList = 0,
            const wxPoint& pos = wxDefaultPosition, 
            const wxSize& size = wxDefaultSize, long style = 0L, 
            const wxString& name = L"GLCanvas", 
            const wxPalette& palette = wxNullPalette);
        ~TriangleCanvas();
        TriangleCanvas(const TriangleCanvas& tc) = delete;
        TriangleCanvas(TriangleCanvas&& tc) = delete;
        TriangleCanvas& operator=(const TriangleCanvas& tc) = delete; 
        TriangleCanvas& operator=(TriangleCanvas&& tc) = delete; 
    private:
            void OnPaint(wxPaintEvent& event);
			void Resize(wxSizeEvent& event);

          	wxGLContext* m_context;
			wxGLContextAttrs *ctx_attr;
};

std::queue<int> pressedKeys;
std::unordered_set<int> heldKeys;
InputManager::MouseStatus status;

TriangleCanvas::TriangleCanvas(wxWindow* parent, wxWindowID id, 
        const int* attribList, const wxPoint& pos, const wxSize& size,
        long style, const wxString& name, const wxPalette& palette)
	: wxGLCanvas(parent, id, attribList, pos, size, style, name, palette)
{
	ctx_attr = new wxGLContextAttrs;
	ctx_attr->CompatibilityProfile().OGLVersion(4, 3).EndList();
	m_context = new wxGLContext(this, NULL, ctx_attr);
	SetCurrent(*m_context);

	engine = new Engine(new InputManager(&pressedKeys, &heldKeys, &status), { 0, 0 }); // 0, 0 because GetClientSize will return 20, 20 anyway

	Bind(wxEVT_PAINT, &TriangleCanvas::OnPaint, this);
	Bind(wxEVT_SIZE, &TriangleCanvas::Resize, this);
}

TriangleCanvas::~TriangleCanvas()
{
	delete engine;
}

void TriangleCanvas::Resize(wxSizeEvent& event) {
    event.Skip();
    if(engine != nullptr) engine->setSize({event.GetSize().x, event.GetSize().y});
}

void TriangleCanvas::OnPaint(wxPaintEvent& event)
{
	SetCurrent(*m_context);
	engine->render();
	SwapBuffers();
}

enum
{
    ID_New = 1,
	ID_Save,
	ID_Export,
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_New,   MyFrame::OnNew)
    EVT_MENU(ID_Save,   MyFrame::OnSave)
	EVT_MENU(ID_Export,   MyFrame::OnExport)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame("NewEngine Rewritten Editor", wxPoint(50, 50), wxSize(800, 600));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenuBar *menuBar = new wxMenuBar;
	wxMenu *menuFile = new wxMenu;
    wxMenu *menuHelp = new wxMenu;

    menuFile->Append(ID_New, "&New...\tCtrl-N", "Create new project");
    menuFile->Append(ID_Save, "&Save...\tCtrl-S", "Save this project");
    menuFile->Append(ID_Export, "&Export...\tCtrl-E", "Export playable version");
	menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

	menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Ready.");

	wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxNotebook* notebook = new wxNotebook(panel, wxID_ANY);

	wxTextCtrl* textCtrl2 = new wxTextCtrl(notebook, wxID_ANY, L"Project options");
    notebook->AddPage(textCtrl2, L"Project");

    wxTextCtrl* textCtrl1 = new wxTextCtrl(notebook, wxID_ANY, L"Scene");
    notebook->AddPage(textCtrl1, L"Scene");

    notebook->AddPage(new TriangleCanvas(notebook), L"Game");

    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(notebook, 1, wxEXPAND);
    panel->SetSizer(panelSizer);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "NewEngine Rewrite v0.0.0", "About NewEngine Rewrite", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnNew(wxCommandEvent& event)
{
    wxLogMessage("New invoked");
}

void MyFrame::OnSave(wxCommandEvent& event)
{
    wxLogMessage("Save invoked");
}

void MyFrame::OnExport(wxCommandEvent& event)
{
    wxLogMessage("Export invoked");
}
