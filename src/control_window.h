#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H
// -------------------------------------------------------------------

#include "table_window.h"

class ControlWindow {
 public:
    // TableWindow �� instance
    TableWindow *tableWindow;

    // window procedure
    int wndProc(HWND, UINT, WPARAM, LPARAM);

    // ���b�Z�[�W�̈������i�[
    HWND hwnd;
    WPARAM wParam;
    LPARAM lParam;

    // �R���X�g���N�^
    ControlWindow(TableWindow *t) {
        tableWindow = t;
    }
};

// -------------------------------------------------------------------
#endif // CONTROL_WINDOW_H

