// -------------------------------------------------------------------

#include <ctype.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <windows.h>

#include "kansaku.h"

// -------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    //HWND hwnd;
    WNDCLASSEX winc;
    MSG msg;

    winc.cbSize         = sizeof(winc);
    winc.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    winc.lpfnWndProc    = WndProc;
    winc.cbClsExtra     = 0;
    winc.cbWndExtra     = 0;
    winc.hInstance      = hInstance;
    winc.hIcon          = LoadIcon(hInstance, "kansaku");
    winc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    winc.hbrBackground  = CreateSolidBrush(COL_BG);
    winc.lpszMenuName   = NULL;
    winc.lpszClassName  = TEXT("kansaku");
    winc.hIconSm        = LoadIcon(hInstance, "kansakum");

    if (RegisterClassEx(&winc) == 0) { return 0; }

    hwnd = CreateWindow(TEXT("kansaku"), TEXT("������"),
                        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        ENT_W, ENT_H,
                        NULL, NULL,
                        hInstance, NULL);
    if (hwnd == NULL) { return 0; }

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// -------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (msg) {
    case WM_CREATE:
        handleCreate(hwnd);
        return 0;

    case WM_DESTROY:
        handleDestroy(hwnd);
        PostQuitMessage(0);
        return 0;

    case WM_LBUTTONDBLCLK:
        handleClick(hwnd, FALSE);
        return 0;

    case WM_RBUTTONUP:
        handleClick(hwnd, TRUE);
        return 0;

    case WM_KEYDOWN:
        switch (wp) {
        case VK_RETURN:
            handleClick(hwnd, FALSE);
            return 0;
        case VK_SPACE:
            handleClick(hwnd, TRUE);
            return 0;
        default:
        return 0;
        }

    case WM_PAINT:
        handlePaint(hwnd);
        return 0;

    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }
}

// -------------------------------------------------------------------

int handleCreate(HWND hwnd) {
    // �O�g�̑傫�����擾
    RECT winRect;
    GetWindowRect(hwnd, &winRect);

    // ���g�̑傫�����擾
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);

    // ����̍��W���擾
    int sX = winRect.left;
    int sY = winRect.top;

    // �O�g�ƒ��g�̍����擾
    int dX = (winRect.right - winRect.left)
        - (clientRect.right - clientRect.left);
    int dY = (winRect.bottom - winRect.top)
        - (clientRect.bottom - clientRect.top);
    // �傫�����X�V
    //if (tc->OPT_xLoc != -1) { sX = tc->OPT_xLoc; }
    //if (tc->OPT_yLoc != -1) { sY = tc->OPT_yLoc; }
    MoveWindow(hwnd, sX, sY, ENT_W + dX, ENT_H + dY, TRUE);

    // �t�H���g��ݒ�
    LOGFONT lf;
    lf.lfHeight = CHAR_SIZE;
    lf.lfWidth = 0;
    lf.lfEscapement = 0;
    lf.lfOrientation = 0;
    lf.lfWeight = 0;
    lf.lfItalic = 0;
    lf.lfUnderline = 0;
    lf.lfStrikeOut = 0;
    lf.lfCharSet = SHIFTJIS_CHARSET;
    lf.lfOutPrecision = 0;
    lf.lfClipPrecision = 0;
    lf.lfQuality = 0;
    lf.lfPitchAndFamily = 0;
    strcpy(lf.lfFaceName, "�l�r �S�V�b�N");
    hFont = CreateFontIndirect(&lf);
    //<multishift>
    // �e�[�u�����\����L���p�̕���
    lf.lfHeight = PREF_SIZE;
    hFont2 = CreateFontIndirect(&lf);
    //</multishift>

    // �I�v�V�����̓ǂ݂��݂Ƌt�����e�[�u���̍쐬
    initialize(hwnd);

    {
        char str[512];
        //<multishift2>
        //sprintf(str, "������ - %s", OPT_tableFile);
        //if (OPT_certain[0] != 0) {
        //    strcat(str, " (");
        //    strcat(str, OPT_certain);
        //    strcat(str, ")");
        //}
        sprintf(str, "������");
        if (dirTable[DIR_table_name]) {
            strcat(str, " ");
            strcat(str, dirTable[DIR_table_name]);
        }
        //</multishift2>
        SetWindowText(hwnd, str);
    }

    // �N������ - ��̑Ō��}
    clipboardStr = new char[1];
    clipboardStr[0] = 0;

    updateEntData(hwnd, FALSE);

    return 0;
}

int handleDestroy(HWND hwnd) {
    if (stTable) { delete stTable; }
    if (certainMoji) { delete certainMoji; }
    if (OPT_tableFile) { delete OPT_tableFile; }
    if (OPT_certain) { delete OPT_certain; }
    return 0;
}

int handleClick(HWND hwnd, bool ifappend) {
    readFromClipboard(hwnd);
    updateEntData(hwnd, ifappend);
    InvalidateRect(hwnd, NULL, TRUE);
    return 0;
}

int handlePaint(HWND hwnd) {
    HDC hdc;
    PAINTSTRUCT ps;

    hdc = BeginPaint(hwnd, &ps);
    BitBlt(hdc, 0, 0, bmW, bmH, hBuffer, 0, 0, SRCCOPY);
    EndPaint(hwnd, &ps);

    return 0;
}

// -------------------------------------------------------------------

void initialize(HWND hwnd) {
    // �ݒ�t�@�C�����J��
    char iniFile[MAX_PATH + 1];
    GetCurrentDirectory(sizeof(iniFile), iniFile);
    strcat(iniFile, "\\kanchoku.ini");

    // table file �� useTTCode
    //<multishift>
    // !!! `useTTCode=1' option in "kanchoku.ini" is now obsolete.
    // !!! Use `#define prefix /*/*/*/*/' directive 
    // !!! in table file ("*.tbl") instead.
    //</multishift>
    // �܂� [kansaku] �Z�N�V���������āA�Ȃ���� [kanchoku] �Z�N�V����������
    char tableFile[255];    // �e�[�u���t�@�C����
    GetPrivateProfileString("kansaku", "tablefile", "",
                            tableFile, sizeof(tableFile), iniFile);
    OPT_useTTCode = GetPrivateProfileInt("kansaku", "usettcode", 0, iniFile);
    if (tableFile[0] == 0) {
        GetPrivateProfileString("kanchoku", "tablefile", "t.tbl",
                                tableFile, sizeof(tableFile), iniFile);
        OPT_useTTCode = GetPrivateProfileInt("kanchoku", "usettcode", 0,
                                             iniFile);
    }
    if (tableFile[0] == 0) {
        error(hwnd, "�utablefile=(�t�@�C����)�v�̐ݒ肪�܂������Ă���悤�ł�");
    }

    // certain
    char certainFile[255];  // CERTAIN �t�@�C����
    GetPrivateProfileString("kansaku", "certain", "",
                            certainFile, sizeof(certainFile), iniFile);

    // dotStyle
    OPT_dotStyle = GetPrivateProfileInt("kansaku", "dotstyle", 0, iniFile);

    //<skipOutset>
    // nonUniq
    OPT_nonUniq = GetPrivateProfileInt("kansaku", "nonUniq", 0, iniFile);

    // skipOutset
    OPT_skipOutset = GetPrivateProfileInt("kansaku", "skipOutset", 0, iniFile);
    //</skipOutset>

    // �e�[�u���t�@�C���̓ǂݍ���
    ifstream *is = new ifstream();
    is->open(tableFile/*, is->nocreate*/);
    if (is->fail()) { error(hwnd, "�e�[�u���t�@�C�����J���܂���"); }
    // �p�[�Y����
    Parser *parser = new Parser(is, hwnd);
    ControlBlock *table = parser->parse();
    is->close();
    delete(parser);

    // �t�����e�[�u���̍쐬
    stTable = new StTable(table);
    delete(table);

    //<multishift>
    // (���i�V�t�g) prefix �ƃw���v�p�̕���
    {
        is->open(tableFile/*, is->nocreate*/);
        if (!is->fail()) {
            TCode::readDir(&dirTable, is);
            is->close();
        }
    }
    stTable->setupPref(dirTable[DIR_prefix]);
    if (OPT_useTTCode) {
        stTable->setupPref("/��/26,23/����/��/:/��/23,26/����/��/");
    }
    //</multishift>

    // CERTAIN ����
    certainMoji = new std::vector<MOJI>();
    if (certainFile[0] != 0) {
        is->open(certainFile/*, is->nocreate*/);
        if (is->fail()) {
            warn(hwnd, "CERTAIN �t�@�C�����J���܂���");
            certainFile[0] = 0;
        } else {
            char buf[4096];
            while (!(is->eof())) {
                is->getline(buf, sizeof(buf));
                char *p = buf;
                MOJI m;
                for (p = buf; *p; ) {
                    m = str2moji(p, &p);
                    if (isspace(m & 0xff)) { continue; } // XXX
                    certainMoji->push_back(m);
                }
            }
            is->close();
        }
    }

#define STRDUP(dst, src) do {               \
        dst = new char[strlen(src) + 1];    \
        strcpy(dst, src);                   \
    } while (0)
    STRDUP(OPT_tableFile, tableFile);
    STRDUP(OPT_certain, certainFile);
#undef STRDUP

    // ���̑�
    nEnt = 0;
}

// -------------------------------------------------------------------

void readFromClipboard(HWND hwnd) {
    // get string from clipboard
    if (OpenClipboard(hwnd) == 0) { return; }
    HGLOBAL hg = GetClipboardData(CF_TEXT);
    if (hg == 0) { CloseClipboard(); return; }
    clipboardStr = new char[GlobalSize(hg)];
    lstrcpy(clipboardStr, (PTSTR)GlobalLock(hg));
    GlobalUnlock(hg);
    CloseClipboard();
}

void updateEntData(HWND hwnd, bool ifappend) {
    // ifappend �� TRUE �Ȃ疖���ɒǉ�
    // FALSE �Ȃ�㏑��

    // make ent
    lookSt(clipboardStr, ifappend);
    delete [] clipboardStr;

    // draw bitmap
    HDC hdc = GetDC(hwnd);

    // nEnt == 0 �̏ꍇ - �󔒂̑Ō��}
    if (nEnt == 0) {
        ent[0].s[0] = 0;
        ent[0].st[0] = EOST;
        nEnt = 1;
    }

    bmW = ENT_W * ((nEnt - 1) / ENT_ROWS + 1);
    bmH = (nEnt < ENT_ROWS) ? (ENT_H * nEnt) : (ENT_H * ENT_ROWS);
    if (hBitmap) {
        DeleteDC(hBuffer); hBuffer = 0;
        DeleteObject(hBitmap); hBitmap = 0;
    }
    hBitmap = CreateCompatibleBitmap(hdc, bmW, bmH);
    hBuffer = CreateCompatibleDC(hdc);
    SelectObject(hBuffer, hBitmap);
    SelectObject(hBuffer, GetStockObject(NULL_PEN));
    {
        RECT r;
        r.left = r.top = 0; r.right = bmW; r.bottom = bmH;
        HBRUSH brBG = CreateSolidBrush(COL_BG);
        FillRect(hBuffer, &r, brBG);
        DeleteObject(brBG);
    }

    for (int i = 0; i < nEnt; i++) {
        int entX = ENT_W * (i / ENT_ROWS);
        int entY = ENT_H * (i % ENT_ROWS);
        if (OPT_dotStyle) {
            drawVKB4Ent1(hwnd, hBuffer, entX, entY, &(ent[i]));
        } else {
            drawVKB4Ent0(hwnd, hBuffer, entX, entY, &(ent[i]));
        }
    }

    // �{�� nEnt == 0 �������ꍇ�͌��ɖ߂��Ă���
    if (nEnt == 1 && ent[0].s[0] == 0 && ent[0].st[0] == EOST) { nEnt = 0; }

    ReleaseDC(hwnd, hdc);

    // �O�g�̑傫�����擾
    RECT winRect;
    GetWindowRect(hwnd, &winRect);
    // ���g�̑傫�����擾
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    // ����̍��W���擾
    int sX = winRect.left;
    int sY = winRect.top;
    // �O�g�ƒ��g�̍����擾
    int dX = (winRect.right - winRect.left)
        - (clientRect.right - clientRect.left);
    int dY = (winRect.bottom - winRect.top)
        - (clientRect.bottom - clientRect.top);
    // �傫�����X�V
    //if (tc->OPT_xLoc != -1) { sX = tc->OPT_xLoc; }
    //if (tc->OPT_yLoc != -1) { sY = tc->OPT_yLoc; }
    if (bmW && bmH) { MoveWindow(hwnd, sX, sY, bmW + dX, bmH + dY, TRUE); }
}

// -------------------------------------------------------------------

void lookSt(char *s, bool ifappend) {
    // ifappend �� TRUE �Ȃ疖���ɒǉ�
    // FALSE �Ȃ�㏑��

    int check;
    STROKE *st;
    nEnt = ifappend ? nEnt : 0;
    for ( ; nEnt < ENT_MAX && *s; ) {
        MOJI m = str2moji(s, &s);

        // �󔒗ނ͏��O
        int h = MOJI2H(m);
        int l = MOJI2L(m);
        if (h == 0 && isspace(l)) { continue; } // XXX

        // CERTAIN �����O (�����c�c�_���_���ȃA���S���Y��)
        for (int i = 0; i < certainMoji->size(); i++) {
            if (m == certainMoji->at(i)) { goto CONTINUE; }
        }

        // non-adjacent help - ���ꕶ����A�����ē���Ȃ�
        if (0 < nEnt && ent[nEnt - 1].m == m) { goto CONTINUE; }

        //<skipOutset>
        // uniq help - ���ꕶ���𕡐�����Ȃ�
        if (!OPT_nonUniq) {
            for (int i = 0; i < nEnt; i++) {
                if (m == ent[i].m) { goto CONTINUE; }
            }
        }
        //</skipOutset>

        // �X�g���[�N���ׂĒǉ�
        check = stTable->look(m);

        //<skipOutset>
        //if (check == 0) { continue; }
        if (check == 0) {
            if (OPT_skipOutset) { continue; }
            ent[nEnt].m = m;
            ent[nEnt].s[0] = 0; moji2strcat(ent[nEnt].s, m);
            ent[nEnt].st[0] = EOST;
            ent[nEnt].sTbl[0] = '\0';
            nEnt++;
            goto CONTINUE;
        }
        //</skipOutset>
        //<multishift>
        //st = stTable->stroke;
        st = stTable->baseStroke;
        //</multishift>
        if (STROKE_MAX < strokelen(st)) { continue; } // XXX
        ent[nEnt].m = m;
        ent[nEnt].s[0] = 0; moji2strcat(ent[nEnt].s, m);
        strokecpy(ent[nEnt].st, st);
        //<multishift>
        strcpy(ent[nEnt].sTbl, stTable->mkTbl);
        //</multishift>
        nEnt++;
     CONTINUE: ;
    }
}

// -------------------------------------------------------------------

void makeVKB(STROKE *st) {
    // ������
    for (int i = 0; i < TC_NKEYS; i++) { // XXX
        vkb[i] = TC_BG_NIL;
    }

    int stlen = strokelen(st);

    //<multishift>
    //// �O���\ T-Code �̉E�\�E���\
    //// - prefix �� 2 �Ō�����菜���A������ 2 �Ō���������
    //if (OPT_useTTCode && stlen == 4) {
    //    if (st[0] == 26 && st[1] == 23) {
    //        if (st[2] == st[3]) {
    //            vkb[st[2]] = TC_BG_STWR;
    //        } else {
    //            vkb[st[2]] = TC_BG_ST1R;
    //            vkb[st[3]] = TC_BG_ST2R;
    //        }
    //        return;
    //    } else if (st[0] == 23 && st[1] == 26) {
    //        if (st[2] == st[3]) {
    //            vkb[st[2]] = TC_BG_STWL;
    //        } else {
    //            vkb[st[2]] = TC_BG_ST1L;
    //            vkb[st[3]] = TC_BG_ST2L;
    //        }
    //        return;
    //    }
    //}
    //</multishift>

    // �ʏ�̃X�g���[�N
    int needX = 0;
    for (int th = 0; th < stlen; th++) {
        int k = TC_UNSHIFT(st[th]);
        switch (th) {
        case 0:                 // 1st stroke
            vkb[k] = TC_BG_ST1;
            break;

        case 1:                 // 2nd stroke
            if (vkb[k] != TC_BG_NIL) {
                vkb[k] = TC_BG_STW;
                needX = 1;
            } else {
                vkb[k] = TC_BG_ST2;
            }
            break;

        case 2:                 // 3rd stroke
            if (vkb[k] != TC_BG_NIL) {
                if (needX) { vkb[k] = TC_BG_STX; }
                else {
                    vkb[k] = TC_BG_STW;
                    needX = 1;
                }
            } else {
                vkb[k] = TC_BG_ST3;
            }
            break;

        default:                // forth stroke(s)
            if (vkb[k] != TC_BG_NIL) {
                if (needX) { vkb[k] = TC_BG_STX; }
                else {
                    vkb[k] = TC_BG_STW;
                    needX = 1;
                }
            } else {
                vkb[k] = TC_BG_STF;
            }
            break;
        } // switch th
    } // for th
}

// -------------------------------------------------------------------
// �Ō��} (�����X�^�C��)

void drawVKB4Ent0(HWND hwnd, HDC hdc, int x0, int y0, struct ENT *e) {
    HBRUSH brVKB    = CreateSolidBrush(COL_VKB);
    HBRUSH brK1B    = CreateSolidBrush(COL_K1B);
    HBRUSH brK0B    = CreateSolidBrush(COL_K0B);

    HPEN pnK1P      = CreatePen(PS_SOLID, 1, COL_K1P);
    HPEN pnK0P      = CreatePen(PS_SOLID, 1, COL_K0P);
    HPEN pnBlack    = CreatePen(PS_SOLID, 1, COL_BLACK);

    HBRUSH brRed    = CreateSolidBrush(COL_RED);
    HBRUSH brGreen  = CreateSolidBrush(COL_GREEN);
    HBRUSH brYellow = CreateSolidBrush(COL_YELLOW);
    HBRUSH brGray   = CreateSolidBrush(COL_GRAY);
    HBRUSH brBlue   = CreateSolidBrush(COL_BLUE);
    HBRUSH brCyan   = CreateSolidBrush(COL_CYAN);
    HBRUSH brYR     = CreateSolidBrush(COL_YR);
    HBRUSH brRP     = CreateSolidBrush(COL_RP);

    HGDIOBJ brSave = SelectObject(hdc, GetStockObject(NULL_BRUSH));
    HGDIOBJ pnSave = SelectObject(hdc, GetStockObject(NULL_PEN));
    HGDIOBJ fnSave = SelectObject(hdc, hFont);

    // �O�g
    SelectObject(hdc, pnBlack);
    SelectObject(hdc, brVKB);
    Rectangle(hdc, x0 + FRAME_X, y0 + FRAME_Y,
              x0 + FRAME_X + FRAME_W, y0 + FRAME_Y + FRAME_H);

    //<multishift>
    // ���i�V�t�g
    SelectObject(hdc, hFont2);
    SetTextColor(hdc, PREF_COL);
    SetBkMode(hdc, TRANSPARENT);
    if (*(e->sTbl)) {
        TextOut(hdc, x0 + PREF_X, y0 + PREF_Y, e->sTbl, strlen(e->sTbl));
    }
    //</multishift>

    // ����
    SelectObject(hdc, hFont);
    SetTextColor(hdc, COL_BLACK);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, x0 + CHAR_X, y0 + CHAR_Y, e->s, strlen(e->s));

    // �Ō��}
    makeVKB(e->st);
    for (int y = 0; y < 4; y++) {
        int py = y0 + VKB_Y + VKB_S * y;
        for (int x = 0; x < 10; x++) {
            int k = y * 10 + x;
            int px = x0 + VKB_X + VKB_S * x;
            if (5 <= x) { px += VKB_S; }

            switch (vkb[k]) {
            case TC_BG_ST1:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brRed); break;
            case TC_BG_ST2:
            //<multishift>
            //case TC_BG_ST2R:
            //case TC_BG_ST2L:
            //</multishift>
                SelectObject(hdc, pnBlack); SelectObject(hdc, brGreen); break;
            case TC_BG_ST3:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brYellow); break;
            case TC_BG_STF:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brGray); break;
            case TC_BG_STW:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brBlue); break;
            case TC_BG_STX:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brCyan); break;
            //<multishift>
            //case TC_BG_ST1R:
            //case TC_BG_STWR:
            //    SelectObject(hdc, pnBlack); SelectObject(hdc, brRP); break;
            //case TC_BG_ST1L:
            //case TC_BG_STWL:
            //    SelectObject(hdc, pnBlack); SelectObject(hdc, brYR); break;
            //</multishift>
            default:
                if (y == 0 || x == 4 || x == 5) {
                    SelectObject(hdc, pnK0P); SelectObject(hdc, brK0B);
                } else {
                    SelectObject(hdc, pnK1P); SelectObject(hdc, brK1B);
                }
                break;
            } // switch vkb[k]
            Rectangle(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
        } // for x
    } // for y

 END:
    SelectObject(hdc, brSave);
    SelectObject(hdc, pnSave);
    SelectObject(hdc, fnSave);

    DeleteObject(brVKB);
    DeleteObject(brK1B);
    DeleteObject(brK0B);
    DeleteObject(pnK1P);
    DeleteObject(pnK0P);
    DeleteObject(pnBlack);

    DeleteObject(brRed);
    DeleteObject(brGreen);
    DeleteObject(brYellow);
    DeleteObject(brGray);
    DeleteObject(brBlue);
    DeleteObject(brCyan);
    DeleteObject(brYR);
    DeleteObject(brRP);
}

// -------------------------------------------------------------------
// �Ō��} (�h�b�g�X�^�C��)

void drawVKB4Ent1(HWND hwnd, HDC hdc, int x0, int y0, struct ENT *e) {
    HBRUSH brVKB    = CreateSolidBrush(COL_VKB);
    HPEN pnBlack    = CreatePen(PS_SOLID, 1, COL_BLACK);

    HBRUSH brRed    = CreateSolidBrush(COL_RED);
    HBRUSH brGreen  = CreateSolidBrush(COL_GREEN);
    HBRUSH brYellow = CreateSolidBrush(COL_YELLOW);
    HBRUSH brGray   = CreateSolidBrush(COL_GRAY);
    HBRUSH brBlue   = CreateSolidBrush(COL_BLUE);
    HBRUSH brCyan   = CreateSolidBrush(COL_CYAN);
    HBRUSH brYR     = CreateSolidBrush(COL_YR);
    HBRUSH brRP     = CreateSolidBrush(COL_RP);

    HGDIOBJ brSave = SelectObject(hdc, GetStockObject(NULL_BRUSH));
    HGDIOBJ pnSave = SelectObject(hdc, GetStockObject(NULL_PEN));
    HGDIOBJ fnSave = SelectObject(hdc, hFont);

    // �O�g
    SelectObject(hdc, pnBlack);
    SelectObject(hdc, brVKB);
    Rectangle(hdc, x0 + FRAME_X, y0 + FRAME_Y,
              x0 + FRAME_X + FRAME_W, y0 + FRAME_Y + FRAME_H);

    //<multishift>
    // ���i�V�t�g
    SelectObject(hdc, hFont2);
    SetTextColor(hdc, PREF_COL);
    SetBkMode(hdc, TRANSPARENT);
    if (*(e->sTbl)) {
        TextOut(hdc, x0 + PREF_X, y0 + PREF_Y, e->sTbl, strlen(e->sTbl));
    }
    //</multishift>

    // ����
    SelectObject(hdc, hFont);
    SetTextColor(hdc, COL_BLACK);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, x0 + CHAR_X, y0 + CHAR_Y, e->s, strlen(e->s));

    // �Ō��}
    makeVKB(e->st);
    int dx = (VKB_S - 1) / 2;
    int dy = (VKB_S - 1) / 2;
    for (int y = 0; y < 4; y++) {
        int py = y0 + VKB_Y + VKB_S * y;
        for (int x = 0; x < 10; x++) {
            int k = y * 10 + x;
            int px = x0 + VKB_X + VKB_S * x;
            if (5 <= x) { px += VKB_S; }

            switch (vkb[k]) {
            case TC_BG_ST1:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brRed);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            case TC_BG_ST2:
            //<multishift>
            //case TC_BG_ST2R:
            //case TC_BG_ST2L:
            //</multishift>
                SelectObject(hdc, pnBlack); SelectObject(hdc, brGreen);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            case TC_BG_ST3:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brYellow);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            case TC_BG_STF:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brGray);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            case TC_BG_STW:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brBlue);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            case TC_BG_STX:
                SelectObject(hdc, pnBlack); SelectObject(hdc, brCyan);
                Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
                break;
            //<multishift>
            //case TC_BG_ST1R:
            //case TC_BG_STWR:
            //    SelectObject(hdc, pnBlack); SelectObject(hdc, brRP);
            //    Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
            //    break;
            //case TC_BG_ST1L:
            //case TC_BG_STWL:
            //    SelectObject(hdc, pnBlack); SelectObject(hdc, brYR);
            //    Ellipse(hdc, px, py, px + VKB_S - 1, py + VKB_S - 1);
            //    break;
            //</multishift>
            default:
                if (y != 0 && x != 4 && x != 5) {
                    SelectObject(hdc, pnBlack);
                    SelectObject(hdc, GetStockObject(NULL_BRUSH));
                    Rectangle(hdc, px + dx, py + dy,
                              px + dx + 2, py + dy + 2);
                }
                break;
            } // switch vkb[k]
        } // for x
    } // for y

 END:
    SelectObject(hdc, brSave);
    SelectObject(hdc, pnSave);
    SelectObject(hdc, fnSave);

    DeleteObject(brVKB);
    DeleteObject(pnBlack);

    DeleteObject(brRed);
    DeleteObject(brGreen);
    DeleteObject(brYellow);
    DeleteObject(brGray);
    DeleteObject(brBlue);
    DeleteObject(brCyan);
    DeleteObject(brYR);
    DeleteObject(brRP);
}

// -------------------------------------------------------------------
// �G���[��\�����A�I��
static void error(HWND hwnd, char *mes) {
    MessageBoxEx(hwnd, mes, "������ - �G���[",
                 MB_OK | MB_ICONERROR, LANG_JAPANESE);
    PostQuitMessage(0);
}

// -------------------------------------------------------------------
// �x����\�����邪�A�p������
static void warn(HWND hwnd, char *mes) {
    // �A�C�R���̑I���͐��������낤��?
    MessageBoxEx(hwnd, mes, "������ - �x��",
                 MB_OK | MB_ICONEXCLAMATION, LANG_JAPANESE);
}

// -------------------------------------------------------------------
