#include <windows.h>
#include <string.h>

#include "control_window.h"
#include "table_window.h"

TableWindow *tableWindow;
std::vector<TableWindow::WEH> TableWindow::weh_map;
ControlWindow *controlWindow;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//BOOL CALLBACK CtlProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance,
                   PSTR cmdLine, int cmdShow) {
    static char *appName = "kanchoku";

    // �E�B���h�E�̃X�^�C����o�^
    WNDCLASSEX wndclass;
    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = instance;
    wndclass.hIcon = LoadIcon(instance, "kanchoku");
    wndclass.hIcon = NULL;
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = appName;
    ////wndclass.hIconSm = LoadIcon(instance, "kanmini");
    wndclass.hIconSm = LoadIcon(instance, "kanmini0");
                                // ���A�C�R��
                                // ON/OFF �ŕύX����\��
                                // ���ύX����
    RegisterClassEx(&wndclass);

    // ���C���̃E�B���h�E����������N���X
    tableWindow = new TableWindow(instance);

    // �_�C�A���O�{�b�N�X����������N���X
    controlWindow = new ControlWindow(tableWindow);

    // �E�B���h�E�����
    HWND hwnd;
    hwnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
                          appName,
                          "������",
                          WS_DLGFRAME | WS_SYSMENU,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          176, 100,
                          NULL,
                          NULL,
                          instance,
                          NULL);

    // �E�B���h�E��\��
    //<hideOnStartup>
    //ShowWindow(hwnd, cmdShow);
    ShowWindow(hwnd, SW_SHOWNOACTIVATE);
    //</hideOnStartup>
    UpdateWindow(hwnd);
    //<hideOnStartup>
    // �V���[�g�J�b�g�̃v���p�e�B�̎��s���̑傫���ōŏ������w�肳��Ă�ꍇ
    if (cmdShow == SW_SHOWMINNOACTIVE)
        ShowWindow(hwnd, SW_HIDE);
    //</hideOnStartup>

    // ���b�Z�[�W���[�v
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // �I��
    return msg.wParam;
}

// window procedure
// �P�� table window �ɏ������񂷂���
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    return tableWindow->wndProc(hwnd, msg, wParam, lParam);
}

// window procedure - �_�C�A���O
// �P�� dialog window �ɏ������񂷂���
//BOOL CALLBACK CtlProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//    return controlWindow->wndProc(hwnd, msg, wParam, lParam);
//}

// -------------------------------------------------------------------
