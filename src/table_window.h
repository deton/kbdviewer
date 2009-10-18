#ifndef TABLE_WINDOW_H
#define TABLE_WINDOW_H
// -------------------------------------------------------------------
// class TableWindow
// ���C���̃E�B���h�E�֘A�̏���

#include <iostream>
#include <fstream>
#include <windows.h>
#include <imm.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "block.h"
#include "bushu_dic.h"
#include "mg_table.h"
#include "moji.h"
//<v127a - gg>
#include "gg_dic.h"
//</v127a - gg>
#include "st_table.h"
#include "parser.h"
#include "tcode.h"
#include "version.h"

using namespace std;

/* -------------------------------------------------------------------
 * ���b�Z�[�W
 */
#define KANCHOKU_ICONCLK 0x1001

/* -------------------------------------------------------------------
 * ����肷��L�[
 *
 * �L�[�ԍ� 0 �` 97 (== TC_NKEYS * 2 - 1) ���������͂ɗp����L�[�B
 * 0x100�ȍ~���@�\�L�[�ƂȂ��Ă���B
 * �Փ˂��Ȃ��悤�ɋC�����邱�ƁB
 */
#define ACTIVE_KEY (0x100 + 1) // ON/OFF �̐؂�ւ��L�[
//<OKA> support unmodified hot key
#define ACTIVE2_KEY (0x100 + 2) // ON/OFF �̐؂�ւ��L�[�A����2
//</OKA>

#define ESC_KEY    (0x100 + 11) // ESC
#define CG_KEY     (0x100 + 12) // C-g

#define BS_KEY     (0x100 + 21) // BS
#define CH_KEY     (0x100 + 22) // C-h

#define RET_KEY    (0x100 + 31) // RET
#define CM_KEY     (0x100 + 32) // C-m
#define CJ_KEY     (0x100 + 33) // C-j

#define TAB_KEY    (0x100 + 41) // TAB
#define CI_KEY     (0x100 + 42) // C-i

#define LT_KEY     (0x100 + 51) // "<"
#define GT_KEY     (0x100 + 52) // ">"


/* -------------------------------------------------------------------
 * ���z���� (1) - �t�H���g�ƃE�B���h�E�̑傫��
 *
 *   MARGIN                   ���� BLOCK
 * �F���d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d ��
 * �F�����������������������������������������������F ��
 * �F��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ���F ��
 * �F����������������������  �����������������������F ��
 * �F��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ���F ��
 * �F����������������������  �����������������������F ��
 * �F��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ���F �� HEIGHT
 * �F����������������������  �����������������������F ��
 * �F��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ���F ��
 * �F�����������������������������������������������F ��
 * �F  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �F ��
 * �F  ������������������������������������������  �F ��
 * �F�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�d�F ��
 * ���������������������� WIDTH  ��������������������
 */
#define CHAR_SIZE (12)          // �����̑傫��
#define LARGE_CHAR_SIZE (16)    // �傫�������̑傫��
#define BLOCK_SIZE (18)         // ���z���Ղ̃L�[�̑傫��
#define MARGIN_SIZE (4)         // ���z���Ղ̓V�n���E�̗]��
#define WIDTH  (MARGIN_SIZE * 2 + BLOCK_SIZE * 11 + 1)  // ���z���Ղ̉���
#define HEIGHT (MARGIN_SIZE * 2 + BLOCK_SIZE * 5 + 1)   // ���z���Ղ̏c��

/* -------------------------------------------------------------------
 * ���z���� (2) - �F
 */
//<v127c>
// [�A�K�X��2:522] 256 �F���ł̖��
// !!! see also table_window.c--handleCreate()--palent
//#define GRAYTONE(x) RGB((x), (x), (x))
#define GRAYTONE(x) PALETTERGB((x), (x), (x))
//</v127c>
// ���[�h ON ���̉��z����
#define COL_ON_LN GRAYTONE(0x00) // �g
#define COL_ON_K1 GRAYTONE(0xf0) // �L�[
#define COL_ON_K2 GRAYTONE(0xc0) // �L�[ (�e)
#define COL_ON_M1 GRAYTONE(0xe0) // �]��
#define COL_ON_M2 GRAYTONE(0xb0) // �]�� (�e)
// ���[�h OFF ���̉��z����
#define COL_OFF_LN GRAYTONE(0x60) // �g
#define COL_OFF_K1 GRAYTONE(0xf8) // �L�[
#define COL_OFF_M1 GRAYTONE(0xe8) // �]��
//<v127c>
// �����F�Ɣw�i�F
//#define COL_BLACK       (RGB(0x00, 0x00, 0x00)) // ��
//#define COL_WHITE       (RGB(0xff, 0xff, 0xff)) // ��
//#define COL_GRAY        (RGB(0x80, 0x80, 0x80)) // �D
//#define COL_LT_GRAY     (RGB(0xc0, 0xc0, 0xc0)) // ���D
//#define COL_LT_RED      (RGB(0xff, 0xc0, 0xc0)) // ����
//#define COL_LT_GREEN    (RGB(0xc0, 0xff, 0xc0)) // ����
//#define COL_LT_BLUE     (RGB(0xc0, 0xc0, 0xff)) // ����
//#define COL_LT_YELLOW   (RGB(0xff, 0xff, 0xc0)) // ����
//#define COL_LT_CYAN     (RGB(0xc0, 0xff, 0xff)) // ����
//#define COL_RED         (RGB(0xff, 0x00, 0x00)) // ��
//#define COL_DK_CYAN     (RGB(0x00, 0x80, 0x80)) // �[��
////<v127a - gg>
//#define COL_DK_MAGENTA  (RGB(0x80, 0x00, 0x80)) // �[��
////</v127a - gg>
//#define COLORDEF(r, g, b) RGB((r), (g), (b))
#define COLORDEF(r, g, b) PALETTERGB((r), (g), (b))
#define COL_BLACK       (COLORDEF(0x00, 0x00, 0x00)) // ��
#define COL_WHITE       (COLORDEF(0xff, 0xff, 0xff)) // ��
#define COL_GRAY        (COLORDEF(0x80, 0x80, 0x80)) // �D
#define COL_LT_GRAY     (COLORDEF(0xc0, 0xc0, 0xc0)) // ���D
#define COL_LT_RED      (COLORDEF(0xff, 0xc0, 0xc0)) // ����
#define COL_LT_GREEN    (COLORDEF(0xc0, 0xff, 0xc0)) // ����
#define COL_LT_BLUE     (COLORDEF(0xc0, 0xc0, 0xff)) // ����
#define COL_LT_YELLOW   (COLORDEF(0xff, 0xff, 0xc0)) // ����
#define COL_LT_CYAN     (COLORDEF(0xc0, 0xff, 0xff)) // ����
#define COL_RED         (COLORDEF(0xff, 0x00, 0x00)) // ��
#define COL_DK_CYAN     (COLORDEF(0x00, 0x80, 0x80)) // �[��
#define COL_DK_MAGENTA  (COLORDEF(0x80, 0x00, 0x80)) // �[��
// !!! see also table_window.c--handleCreate()--palent
//</v127c>

/* -------------------------------------------------------------------
 * TableWindow �N���X
 */
class TableWindow {
private:
    // T-Code �ϊ���
    TCode *tc;

    // �C���X�^���X�n���h��
    HINSTANCE instance;
    // �t�H���g
    HFONT hFont;
    HFONT hLFont;
    //<v127c>
    // �p���b�g
    HPALETTE hPalette;
    //</v127c>
    // ���b�Z�[�W�̈������i�[
    HWND hwnd;
    WPARAM wParam;
    WPARAM lParam;

    // �^�X�N�g���C�ɓo�^
    NOTIFYICONDATA nid;

    // WM_KANCHOKU_CHAR�֘A
    HINSTANCE hKanCharDLL;
    HHOOK (*lpfnMySetHook)(void);
    int (*lpfnMyEndHook)(void);
    HHOOK hNextHook;
    UINT WM_KANCHOKU_CHAR;

    enum HOTKEYMODE { OFF, NORMAL, EDITCLAUSE };
    HOTKEYMODE hotKeyMode;
    // �ꊲ�L�΂��k�ߗp�L�[
    // T-Code�L�[�Ƃ��Ԃ��Ă���ꍇ�̂ݎg�p
    int tc_lt_key;
    int tc_gt_key;

    bool isShift;

public:
    // �R���X�g���N�^
    TableWindow(HINSTANCE i);
    // �f�X�g���N�^
    ~TableWindow();
    // window procedure
    int wndProc(HWND, UINT, WPARAM, LPARAM);

private:
    // �N��/�ҋ@
    void activate();            // �N�� (HotKey �̊��t)
    void inactivate();          // �ҋ@ (HotKey �̉��)
    //void setSpecialHotKey();    // ���� HotKey �̊m�ۂƉ��
    void setMazeHotKey(int);
    void setTitleText();        // �^�C�g���o�[�̕�����ݒ�

    // ���b�Z�[�W�n���h��
    int handleCreate();         // WM_CREATE
    int handleDestroy();        // WM_DESTROY
    int handleLButtonDown();    // WM_LBUTTONDOWN
    int handlePaint();          // WM_PAINT
    int handleHotKey();         // WM_HOTKEY

    // T-Code �֘A
    void initTC();              // T-Code �ϊ���̏�����
    void output();              // T-Code �ϊ����ʂ̏o��

    // ���z���Ղ̕`��
    void drawFrameOFF(HDC hdc); // OFF ���̉��z���Ղ̘g
    void drawFrame50(HDC hdc);  // �ʏ펞�̉��z���Ղ̘g
    void drawFrame10(HDC hdc);  // �������I�����̉��z���Ղ̘g
    void drawVKB50(HDC hdc, bool isWithBothSide = false);        // �ʏ펞�̉��z����
    void drawVKB10(HDC);        // �������I�����̉��z����
    void drawMiniBuffer(HDC, int, COLORREF, MojiBuffer *);
                                // �~�j�o�b�t�@

    // �G���[����
    void error(char *);         // �G���[��\�����A�I��
    void warn(char *);          // �x����\�����邪�A�p��

    void readTargetWindowSetting(char *); // �o�͐�E�B���h�E���Ƃ̐ݒ�̓Ǎ�
    int getOutputMethod(HWND);  // �w�肵���E�B���h�E�ɑ΂���outputMethod���擾
};

// -------------------------------------------------------------------
#endif // TABLE_WINDOW_H
