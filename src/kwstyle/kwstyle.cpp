// kwstyle.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "kwstyle.h"

#define MAX_LOADSTRING 100

// �O���[�o���ϐ�:
HINSTANCE hInst;								// ���݂̃C���^�[�t�F�C�X
TCHAR szTitle[MAX_LOADSTRING];					// �^�C�g�� �o�[�̃e�L�X�g
TCHAR szWindowClass[MAX_LOADSTRING];			// ���C�� �E�B���h�E �N���X��
HWND hWndMain;

// ���̃R�[�h ���W���[���Ɋ܂܂��֐��̐錾��]�����܂�:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �����ɃR�[�h��}�����Ă��������B
	MSG msg;
	HACCEL hAccelTable;

	// �O���[�o������������������Ă��܂��B
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_KWSTYLE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// �A�v���P�[�V�����̏����������s���܂�:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KWSTYLE));

	// ���C�� ���b�Z�[�W ���[�v:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
        if(!IsDialogMessage(hWndMain,&msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
		}
	}

	return (int) msg.wParam;
}



//
//  �֐�: MyRegisterClass()
//
//  �ړI: �E�B���h�E �N���X��o�^���܂��B
//
//  �R�����g:
//
//    ���̊֐�����юg�����́A'RegisterClassEx' �֐����ǉ����ꂽ
//    Windows 95 ���O�� Win32 �V�X�e���ƌ݊�������ꍇ�ɂ̂ݕK�v�ł��B
//    �A�v���P�[�V�������A�֘A�t����ꂽ
//    �������`���̏������A�C�R�����擾�ł���悤�ɂ���ɂ́A
//    ���̊֐����Ăяo���Ă��������B
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= DLGWINDOWEXTRA;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KWSTYLE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_KWSTYLE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �֐�: InitInstance(HINSTANCE, int)
//
//   �ړI: �C���X�^���X �n���h����ۑ����āA���C�� �E�B���h�E���쐬���܂��B
//
//   �R�����g:
//
//        ���̊֐��ŁA�O���[�o���ϐ��ŃC���X�^���X �n���h����ۑ����A
//        ���C�� �v���O���� �E�B���h�E���쐬����ѕ\�����܂��B
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // �O���[�o���ϐ��ɃC���X�^���X�������i�[���܂��B

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VSCROLL,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   hWndMain = hWnd;

   return TRUE;
}

#define GRAYTONE(x) RGB((x), (x), (x))
#define COLORDEF(r, g, b) RGB((r), (g), (b))

struct {
    char *nam_func;
    char *nam_visu;
    COLORREF col;
} allentry[] = {
    {"off_BtnFrame", "COL_OFF_LN", GRAYTONE(0x60)},
    {"off_BtnFace", "COL_OFF_K1", GRAYTONE(0xf8)},
    {"off_Window", "COL_OFF_M1", GRAYTONE(0xe8)},
    {"on_BtnFrame", "COL_ON_LN", GRAYTONE(0x00)},
    {"on_BtnFace", "COL_ON_K1", GRAYTONE(0xf0)},
    {"on_BtnShadow", "COL_ON_K2", GRAYTONE(0xc0)},
    {"on_BtnHilight", "COL_ON_K3", GRAYTONE(0xff)},
    {"on_Window", "COL_ON_M1", GRAYTONE(0xe0)},
    {"on_WndShadow", "COL_ON_M2", GRAYTONE(0xb0)},
    {"on_WndHilight", "COL_ON_M3", GRAYTONE(0xff)},
    {"BG_ST1", "COL_LT_RED",      (COLORDEF(0xff, 0xc0, 0xc0))},
    {"BG_ST2(norm)", "COL_LT_GREEN",    (COLORDEF(0xc0, 0xff, 0xc0))},
    {"BG_ST3(help)", "COL_LT_YELLOW",   (COLORDEF(0xff, 0xff, 0xc0))},
    {"BG_STF", "COL_LT_GRAY",     (COLORDEF(0xc0, 0xc0, 0xc0))},
    {"BG_STW(cand)", "COL_LT_BLUE",     (COLORDEF(0xc0, 0xc0, 0xff))},
    {"BG_STX(Hilight)", "COL_LT_CYAN",     (COLORDEF(0xc0, 0xff, 0xff))},
    {"SpecialText", "COL_DK_CYAN",     (COLORDEF(0x00, 0x80, 0x80))},
    {"GuideText", "COL_DK_MAGENTA",  (COLORDEF(0x80, 0x00, 0x80))},
    {"Text", "COL_BLACK",       (COLORDEF(0x00, 0x00, 0x00))},
    {"HilightText", "COL_RED",         (COLORDEF(0xff, 0x00, 0x00))},
    {NULL, NULL, (COLORREF)-1},
};

char fontname[LF_FACESIZE] = "�l�r �S�V�b�N";
int fontsize = 12;

enum {
    IDC_MYSTART = 4000,
    IDC_FONTNAME = 5000,
    IDC_FONTSIZE = 5001,
    IDC_FONT = 5002,
    IDC_APPLY = 5099
};

int clientsizeX = 126;
int clientsizeY = 20*12+2;
RECT rcC;
SCROLLINFO si = {sizeof(SCROLLINFO)};

void ReadSetting()
{
    char iniFile[MAX_PATH + 1];
    GetCurrentDirectory(sizeof(iniFile), iniFile);
    strcat(iniFile, "\\kanchoku.ini");

    char style[255];
    GetPrivateProfileString("kanchoku", "style_base", "",
                            style, sizeof(style), iniFile);
    if (*style) {
        int i;
        char work[10];
        for (i=0; i < 10; i++) {
            *work = 0;
            strncat(work, style+i*8, 8);
            if (lstrlen(work) < 8) break;
            allentry[i+0].col = strtoul(work, NULL, 16);
        }
    }
    GetPrivateProfileString("kanchoku", "style_info", "",
                            style, sizeof(style), iniFile);
    if (*style) {
        int i;
        char work[10];
        for (i=0; i < 10; i++) {
            *work = 0;
            strncat(work, style+i*8, 8);
            if (lstrlen(work) < 8) break;
            allentry[i+10].col = strtoul(work, NULL, 16);
        }
    }
    GetPrivateProfileString("kanchoku", "style_fontname", "",
                            style, sizeof(style), iniFile);
    if (*style) {
        *fontname = 0;
        strncat(fontname, style, LF_FACESIZE-1);
    }
    int fs = GetPrivateProfileInt("kanchoku", "style_fontsize", 0,
                            iniFile);
    if (fs) {
        fontsize = fs;
    }
}

void WriteSetting()
{
    char iniFile[MAX_PATH + 1];
    GetCurrentDirectory(sizeof(iniFile), iniFile);
    strcat(iniFile, "\\kanchoku.ini");

    char style[255];
    {
        *style = 0;
        int i;
        char work[10];
        for (i=0; i < 10; i++) {
            wsprintf(work, "%08x", allentry[i+0].col);
            strcat(style, work);
        }
    }
    WritePrivateProfileString("kanchoku", "style_base", style, iniFile);
    {
        *style = 0;
        int i;
        char work[10];
        for (i=0; i < 10; i++) {
            wsprintf(work, "%08x", allentry[i+10].col);
            strcat(style, work);
        }
    }
    WritePrivateProfileString("kanchoku", "style_info", style, iniFile);
    WritePrivateProfileString("kanchoku", "style_fontname", fontname,
                            iniFile);
    wsprintf(style, "%d", fontsize);
    WritePrivateProfileString("kanchoku", "style_fontsize", style,
                            iniFile);
}

void notifyToKW()
{
    HWND target = FindWindow("kanchoku", NULL);
    if (target) PostMessage(target, WM_SYSCOLORCHANGE, 0, 0);
}

//
//  �֐�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �ړI:  ���C�� �E�B���h�E�̃��b�Z�[�W���������܂��B
//
//  WM_COMMAND	- �A�v���P�[�V���� ���j���[�̏���
//  WM_PAINT	- ���C�� �E�B���h�E�̕`��
//  WM_DESTROY	- ���~���b�Z�[�W��\�����Ė߂�
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
    int i;
    static char rgbBkup[10];

	switch (message)
	{
    case WM_CREATE:{
        ReadSetting();
        /*HFONT hFont = CreateFont(9, 0, 0, 0, FW_REGULAR, 0, 0, 0,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
            FIXED_PITCH | FF_DONTCARE, "Courier New");*/
        int HU = LOWORD(GetDialogBaseUnits())/2;  // templateunitX��2�{���ۂ�����
        int VU = LOWORD(GetDialogBaseUnits())/4;  // templateunitY��2�{���ۂ�����
        rcC.left = rcC.top = 0;
        rcC.right = HU * clientsizeX;
        rcC.bottom = VU * clientsizeY;
        for (i=0; allentry[i].nam_func; i++) {
            CreateWindow("Static", allentry[i].nam_func,
                WS_CHILD | WS_VISIBLE | SS_LEFTNOWORDWRAP, 
                HU*2, VU*(2+12*i), HU*30, VU*10, hWnd, (HMENU)(IDC_MYSTART+i*10),
                hInst, NULL);
            HWND hEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
                "Edit", "",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT,
                HU*34, VU*(2+12*i), HU*16, VU*10, hWnd, (HMENU)(IDC_MYSTART+i*10+1),
                hInst, NULL);
            //SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, 0);
            SendMessage(hEdit, EM_LIMITTEXT, 6, 0);
            char work[10];
            wsprintf(work, "%06x", allentry[i].col & 0x00ffffff);
            SetWindowText(hEdit, work);
            CreateWindowEx(WS_EX_CLIENTEDGE,
                "Button", "",
                WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, 
                HU*52, VU*(2+12*i), HU*10, VU*10, hWnd, (HMENU)(IDC_MYSTART+i*10+2),
                hInst, NULL);
        }
        //DeleteObject(hFont);
        HWND hFN = CreateWindowEx(WS_EX_CLIENTEDGE,
            "Edit", "",
            WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            HU*64, VU*2, HU*30, VU*10, hWnd, (HMENU)IDC_FONTNAME,
            hInst, NULL);
        SendMessage(hFN, EM_LIMITTEXT, 31, 0);
        SetWindowText(hFN, fontname);
        HWND hFS = CreateWindowEx(WS_EX_CLIENTEDGE,
            "Edit", "",
            WS_CHILD | WS_VISIBLE,
            HU*96, VU*2, HU*10, VU*10, hWnd, (HMENU)IDC_FONTSIZE,
            hInst, NULL);
        char work[10];
        wsprintf(work, "%d", fontsize);
        SetWindowText(hFS, work);
        CreateWindow("Button", "Font...",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            HU*108, VU*2, HU*16, VU*10, hWnd, (HMENU)IDC_FONT,
            hInst, NULL);
        CreateWindow("Button", "OK",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            HU*72, VU*50, HU*16, VU*10, hWnd, (HMENU)IDOK,
            hInst, NULL);
        CreateWindow("Button", "Cancel",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            HU*90, VU*50, HU*16, VU*10, hWnd, (HMENU)IDCANCEL,
            hInst, NULL);
        CreateWindow("Button", "Apply",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            HU*108, VU*50, HU*16, VU*10, hWnd, (HMENU)IDC_APPLY,
            hInst, NULL);
        break;}
    case WM_SIZE:{
        RECT rc;
        GetClientRect(hWnd, &rc);
        si.fMask = SIF_POS | SIF_RANGE | SIF_PAGE;
        si.nMin = 0;
        si.nMax = rcC.bottom-rcC.top;
        si.nPage = rc.bottom-rc.top;
        si.nPos = -rcC.top;
        SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
        break;}
    case WM_VSCROLL:{
        int HU = LOWORD(GetDialogBaseUnits())/2;  // templateunitX��2�{���ۂ�����
        int VU = LOWORD(GetDialogBaseUnits())/4;  // templateunitY��2�{���ۂ�����
        int dy;
        switch (LOWORD(wParam))
        {
        case SB_LINEUP:
            dy = -VU;
            break;
        case SB_LINEDOWN:
            dy = VU;
            break;
        case SB_PAGEUP:
            dy = -1 * si.nPage;
            break;
        case SB_PAGEDOWN:
            dy = si.nPage;
            break;
        case SB_THUMBTRACK:
            dy = HIWORD(wParam) - si.nPos;
            break;
        default:
            dy = 0;
        }
        dy = max(-1 * si.nPos, min(dy, si.nMax - (int)si.nPage - si.nPos + 1));
        if (dy != 0) {
            si.nPos += dy;
            OffsetRect(&rcC, 0, -dy);
            SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
            ScrollWindow(hWnd, 0, -dy, NULL, NULL);
            UpdateWindow(hWnd);
        }
        break;}
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �I�����ꂽ���j���[�̉��:
		switch (wmId)
		{
		case IDM_ABOUT:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
        case IDC_APPLY:
        case IDOK:
            WriteSetting();
            notifyToKW();
            if (wmId == IDC_APPLY) break;
        case IDCANCEL:
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
        case IDC_FONTNAME:
            switch (wmEvent)
            {
            case EN_KILLFOCUS:
                HWND hEdit = GetDlgItem(hWnd, wmId);
                GetWindowText(hEdit, fontname, LF_FACESIZE);
                break;
            }
            break;
        case IDC_FONTSIZE:
            switch (wmEvent)
            {
            case EN_KILLFOCUS:
                char work[10];
                char *p;
                HWND hEdit = GetDlgItem(hWnd, wmId);
                GetWindowText(hEdit, work, 9);
                int tmp = strtoul(work, &p, 10);
                if (p == work || *p) {
                    wsprintf(work, "%d", fontsize);
                    SetWindowText(hEdit, work);
                    break;
                }
                fontsize = tmp;
                break;
            }
            break;
        case IDC_FONT:{
            LOGFONT lf = {0};
            lf.lfHeight = -fontsize;
            lf.lfCharSet = SHIFTJIS_CHARSET;
            strcpy(lf.lfFaceName, fontname);
            CHOOSEFONT cf = {sizeof(CHOOSEFONT), hWnd};
            cf.lpLogFont = &lf;
            cf.Flags = CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT | CF_NOSCRIPTSEL;
            if (ChooseFont(&cf)) {
                strcpy(fontname, lf.lfFaceName);
                HWND hFN = GetDlgItem(hWnd, IDC_FONTNAME);
                SetWindowText(hFN, fontname);
                fontsize = lf.lfHeight;
                if (fontsize < 0) fontsize = -fontsize;
                HWND hFS = GetDlgItem(hWnd, IDC_FONTSIZE);
                char work[10];
                wsprintf(work, "%d", fontsize);
                SetWindowText(hFS, work);
            }
            break;}
		default:
            for (i=IDC_MYSTART; allentry[(i-IDC_MYSTART)/10].nam_func; i+=10) {
                if (wmId < i) break;
                if (wmId == i+1) {
                    HWND hEdit = GetDlgItem(hWnd, wmId);
                    switch (wmEvent)
                    {
                    case EN_SETFOCUS:
                        GetWindowText(hEdit, rgbBkup, 9);
                        //SendMessage((HWND)wmId, WM_GETTEXT, 9, (LPARAM)rgbBkup);
                        break;
                    case EN_KILLFOCUS:
                    case EN_UPDATE:
                        char work[10];
                        char *p;
                        GetWindowText(hEdit, work, 9);
                        COLORREF tmp = strtoul(work, &p, 16);
                        if (p != work+6 || *p) {
                            if (wmEvent == EN_UPDATE) break;
                            else {
                                SetWindowText(hEdit, rgbBkup);
                                tmp = strtoul(rgbBkup, &p, 16);
                            }
                        }
                        allentry[(wmId-IDC_MYSTART)/10].col = tmp;
                        InvalidateRect(hWnd, NULL, FALSE);
                        break;
                    }
                    break;
                } else if (wmId == i+2) {
                    HWND hButton = GetDlgItem(hWnd, wmId);
                    HWND hEdit = GetDlgItem(hWnd, wmId-1);
                    COLORREF dwCustColors[16];
                    CHOOSECOLOR cc = {
                        sizeof(CHOOSECOLOR), hWnd, NULL,
                        allentry[(i-IDC_MYSTART)/10].col, dwCustColors,
                        CC_RGBINIT, };
                    if (ChooseColor(&cc)) {
                        allentry[(i-IDC_MYSTART)/10].col = cc.rgbResult;
                        char work[10];
                        wsprintf(work, "%06x", cc.rgbResult & 0x00ffffff);
                        SendMessage(hEdit, WM_SETTEXT, 0, (LPARAM)work);
                    }
                    break;
                }
            }
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �`��R�[�h�������ɒǉ����Ă�������...
		EndPaint(hWnd, &ps);
		break;
    case WM_DRAWITEM:
        wmId = ((LPDRAWITEMSTRUCT)lParam)->CtlID;
        hdc = ((LPDRAWITEMSTRUCT)lParam)->hDC;
        {HBRUSH br = CreateSolidBrush(allentry[(wmId-IDC_MYSTART)/10].col);
        HGDIOBJ brSave = SelectObject(hdc, br);
        int HU = LOWORD(GetDialogBaseUnits())/2;  // templateunitX��2�{���ۂ�����
        int VU = LOWORD(GetDialogBaseUnits())/4;  // templateunitY��2�{���ۂ�����
        Rectangle(hdc, -1, -1, HU*10+1, VU*10+1);
        SelectObject(hdc, brSave);
        DeleteObject(br);}
        break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefDlgProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

