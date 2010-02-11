
#include <windows.h>
#include <imm.h>

#include "kanchar.h"

static const char VERSION[] = "kanchar.dll 2010/02/11";

UINT WM_KANCHOKU_CHAR=0;
UINT WM_KANCHOKU_UNICHAR=0;
UINT WM_KANCHOKU_NOTIFYVKPROCESSKEY=0;
UINT WM_KANCHOKU_NOTIFYIMESTATUS=0;
UINT WM_KANCHOKU_SETIMESTATUS=0;

HINSTANCE hInst;
HHOOK hMsgHook=0;
HHOOK hCWPHook=0;
HWND hwKanchoku;

int inKanChar=0;


int WINAPI DllMain(HINSTANCE hInstance, DWORD fdReason, PVOID pvReserved)
{
    hInst = hInstance;
    switch (fdReason) {
    case DLL_PROCESS_ATTACH:
        hInst = hInstance;
        WM_KANCHOKU_CHAR = RegisterWindowMessage("WM_KANCHOKU_CHAR");
        WM_KANCHOKU_UNICHAR = RegisterWindowMessage("WM_KANCHOKU_UNICHAR");
        WM_KANCHOKU_NOTIFYVKPROCESSKEY = RegisterWindowMessage("WM_KANCHOKU_NOTIFYVKPROCESSKEY");
        WM_KANCHOKU_NOTIFYIMESTATUS = RegisterWindowMessage("WM_KANCHOKU_NOTIFYIMESTATUS");
        WM_KANCHOKU_SETIMESTATUS = RegisterWindowMessage("WM_KANCHOKU_SETIMESTATUS");
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


EXPORT BOOL IsHooking()
{
    if (hMsgHook || hCWPHook)
        return TRUE;
    else
        return FALSE;
}

EXPORT void MySetHook(HHOOK *hmh, HHOOK *hch)
{
    if (!hMsgHook) {
        hMsgHook = SetWindowsHookEx(WH_GETMESSAGE, (HOOKPROC)msgHookProc, hInst, NULL);
    }
    if (!hCWPHook) {
        hCWPHook = SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)cwpHookProc, hInst, NULL);
    }
    if (hmh) *hmh = hMsgHook;
    if (hch) *hch = hCWPHook;
    return ;
}

EXPORT int MyEndHook()
{
    if (hMsgHook) {
        if (UnhookWindowsHookEx(hMsgHook)) hMsgHook = NULL;
    }
    if (hCWPHook) {
        if (UnhookWindowsHookEx(hCWPHook)) hCWPHook = NULL;
    }
    return IsHooking();
}


BOOL CALLBACK FindWindowProc(HWND hw, LPARAM lp)
{
    HANDLE h = GetProp(hw, "KanchokuWin_KanCharDLL_NextMsgHook");
    if (h) {
        hwKanchoku = hw;
        hMsgHook = (HHOOK)h;
        HANDLE h2 = GetProp(hw, "KanchokuWin_KanCharDLL_NextCWPHook");
        if (h2) hCWPHook = (HHOOK)h2;
        return FALSE;
    }
    return TRUE;
}

/*
  WM_KANCHOKU_CHAR: ����Win���t�H�[�J�X�̂���E�B���h�E
    wParam: ���͂����������iDBCS�A���P�[���ˑ��H�j
    lParam: =0�ł���Γ��͂��s����
            >0�ł����-1���Ď������g�Ƀ|�X�g�iTranslateMessage()��WM_CHAR���|�X�g���闬����j
    wParam=0�̏ꍇ�AIME�ɕϊ����̕����񂪂�������m��(CPS_COMPLETE)���邾��
  WM_KANCHOKU_UNICHAR: wParam��UTF-32�ł��邱�ƈȊOWM_KANCHOKU_CHAR�Ɠ��l
  WM_KANCHOKU_NOTIFYVKPROCESSKEY: �t�H�[�J�X�̂���E�B���h�E������Win
    wParam: ImmGetVirtualKey�Ŏ擾�������z�L�[�R�[�h
    lParam: ����`(�Ƃ肠����WM_KEYDOWN��lParam)
  WM_KANCHOKU_NOTIFYIMESTATUS: �t�H�[�J�X�̂���E�B���h�E������Win
    wParam: 0-7 GCS_COMPREADSTR�̒���
            8-15 GCS_COMPSTR�̒���
            16-19 ImmGetConversionStatus�̑�2�����̖߂�l(����4�r�b�g)
            24 IME��ON���ǂ���(ImmGetOpenStatus)
            25 (ImmGetContext)
            26 (ImmIsIme)
            27-29 ���� 0:WM_SETFOCUS 1:KeyboardLayout��IME�̕ύX(������)
                       2:IMN_SETOPENSTATUS 3:IMN_SETCONVERSIONMODE
    lParam: ���M����hWnd
  WM_KANCHOKU_SETIMESTATUS: ����Win���t�H�[�J�X�̂���E�B���h�E
    wParam: (WM_IME_NOTIFY��wParam�Ɏw�肷����̂𗬗p)
            IMN_SETOPENSTATUS: ImmSetOpenStatus(lParam)�����s
            IMN_SETCONVERSIONMODE: ImmSetConversionStatus(, lParam, )�����s(����4�r�b�g�̂ݍX�V)
 */

EXPORT LRESULT CALLBACK cwpHookProc(int nCode, WPARAM wp, LPARAM lp)
{
    CWPSTRUCT *pcwp;
    if (!hMsgHook) {
        EnumWindows(&FindWindowProc, NULL);
    }
    if (!hCWPHook) return 0;
    if (nCode == HC_ACTION) {
        pcwp = (CWPSTRUCT *)lp;
        if (pcwp->hwnd == hwKanchoku) return CallNextHookEx(hCWPHook, nCode, wp, lp);
        // WM_KANCHOKU_NOTIFYIMESTATUS
        if (pcwp->message == WM_SETFOCUS
            || pcwp->message == WM_IME_NOTIFY && !inKanChar
               && (pcwp->wParam == IMN_SETOPENSTATUS
                   || pcwp->wParam == IMN_SETCONVERSIONMODE)) {
            if (!hwKanchoku) return CallNextHookEx(hCWPHook, nCode, wp, lp);
            HWND activeWin = pcwp->hwnd;
            WPARAM wpRet = 0;
            HKL hKL;
            HIMC hImc;
            int bIME;
            DWORD dwConv, dwSent;
            LONG lCompLen, lReadLen;
            if (pcwp->message == WM_SETFOCUS) ;
            else if (pcwp->message == WM_IME_NOTIFY) {
                if (pcwp->wParam == IMN_SETOPENSTATUS) wpRet |= 2 << 27;
                else if (pcwp->wParam == IMN_SETCONVERSIONMODE) wpRet |= 3 << 27;
            }
            hKL = GetKeyboardLayout(0);
            wpRet |= !!ImmIsIME(hKL) << 26;
            hImc = ImmGetContext(activeWin);
            if (hImc) {
                wpRet |= 1 << 25;
                bIME = ImmGetOpenStatus(hImc);
                wpRet |= !!bIME << 24;
                if (ImmGetConversionStatus(hImc, &dwConv, &dwSent)) {
                    wpRet |= (dwConv && 0x000f) << 16;
                }
                lReadLen = ImmGetCompositionString(hImc, GCS_COMPREADSTR, NULL, 0);
                if (lReadLen >= 0) wpRet |= (lReadLen && 0xff) << 8;
                lCompLen = ImmGetCompositionString(hImc, GCS_COMPSTR, NULL, 0);
                if (lCompLen >= 0) wpRet |= (lCompLen && 0xff);
                ImmReleaseContext(activeWin, hImc);
            }
            PostMessage(hwKanchoku, WM_KANCHOKU_NOTIFYIMESTATUS, wpRet, (LPARAM)pcwp->hwnd);
            return CallNextHookEx(hCWPHook, nCode, wp, lp);
        }
    }
    return CallNextHookEx(hCWPHook, nCode, wp, lp);
}

EXPORT LRESULT CALLBACK msgHookProc(int nCode, WPARAM wp, LPARAM lp)
{
    MSG *pcwp;
    if (!hMsgHook) {
        EnumWindows(&FindWindowProc, NULL);
    }
    if (nCode == HC_ACTION && wp == PM_REMOVE) {
        pcwp = (MSG *)lp;
        if (pcwp->hwnd == hwKanchoku) return CallNextHookEx(hMsgHook, nCode, wp, lp);
        // WM_KANCHOKU_NOTIFYVKPROCESSKEY
        if (pcwp->message == WM_KEYDOWN && pcwp->wParam == VK_PROCESSKEY) {
            if (hwKanchoku) PostMessage(hwKanchoku, WM_KANCHOKU_NOTIFYVKPROCESSKEY, ImmGetVirtualKey(pcwp->hwnd), pcwp->lParam);
            return CallNextHookEx(hMsgHook, nCode, wp, lp);
        }
        // WM_KANCHOKU_SETIMESTATUS
        if (pcwp->message == WM_KANCHOKU_SETIMESTATUS) {
            HWND activeWin = pcwp->hwnd;
            HKL hKL;
            HIMC hImc;
            int bIME;
            DWORD dwConv, dwSent;
            LONG lCompLen, lReadLen;
            hKL = GetKeyboardLayout(0);
            if (!ImmIsIME(hKL)) {
                return 0;
            }
            hImc = ImmGetContext(activeWin);
            if(hImc == NULL) {
              return(0);
            }
            inKanChar = 1;
            if (pcwp->wParam == IMN_SETOPENSTATUS) {
                ImmSetOpenStatus(hImc, !!pcwp->lParam);
            } else if (pcwp->wParam == IMN_SETCONVERSIONMODE) {
                if (ImmGetConversionStatus(hImc, &dwConv, &dwSent)) {
                    ImmSetConversionStatus(hImc, (dwConv & ~0x000fL) | (pcwp->lParam & 0x000fL), dwSent);
                }
            }
            ImmReleaseContext(activeWin, hImc);
            inKanChar = 0;
            return CallNextHookEx(hMsgHook, nCode, wp, lp);
        }
        // WM_KANCHOKU_CHAR or WM_KANCHOKU_UNICHAR
        if (pcwp->message == WM_KANCHOKU_CHAR || pcwp->message == WM_KANCHOKU_UNICHAR) {
            if (pcwp->lParam & 0xFF > 0) {
                //���b�Z�[�W�L���[�ɕ��тȂ����iWord�ł�BS�\���΍�j
                //VK_BACK�̎���WM_KEYDOWN/KEYUP��PostMessage����Ȃ�
                //����ɑg�ݍ��킹��ɂ�lParam=1��PostMessage
                PostMessage(pcwp->hwnd, pcwp->message, pcwp->wParam, pcwp->lParam-1);
                pcwp->message = WM_NULL;
                return CallNextHookEx(hMsgHook, nCode, wp, lp);
            }
        }
        if (pcwp->message == WM_KANCHOKU_CHAR) {
            HWND activeWin = pcwp->hwnd;
            char mbc[4];
            HKL hKL;
            HIMC hImc;
            int bIME;
            DWORD dwConv, dwSent;
            if ((pcwp->wParam >> 8) & 0xff) {
                mbc[0] = (pcwp->wParam >> 8) & 0xff;
                mbc[1] = pcwp->wParam & 0xff;
                mbc[2] = 0;
            } else {
                mbc[0] = pcwp->wParam & 0xff;
                mbc[1] = 0;
            }
            hKL = GetKeyboardLayout(0);
            if (!ImmIsIME(hKL)) {
                return 0;
            }
            hImc = ImmGetContext(activeWin);
            if(hImc == NULL) {
              return(0);
            }
            bIME = ImmGetOpenStatus(hImc);
            if (!mbc[0]) {
                if (bIME) {
                    inKanChar = 1;
                    ImmNotifyIME(hImc, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
                    ImmReleaseContext(activeWin, hImc);
                    inKanChar = 0;
                }
                return 0;
            }
            inKanChar = 1;
            if (!bIME) {
                ImmSetOpenStatus(hImc, TRUE);
            }
            ImmGetConversionStatus(hImc, &dwConv, &dwSent);
            /*if (0xa1 <= pcwp->wParam && pcwp->wParam <= 0xdf) {
                ImmSetConversionStatus(hImc, IME_CMODE_NATIVE | IME_CMODE_KATAKANA, IME_SMODE_NONE);
            } else if (0x829f <= pcwp->wParam && pcwp->wParam <= 0x82f1) {
                ImmSetConversionStatus(hImc, IME_CMODE_NATIVE | IME_CMODE_FULLSHAPE, IME_SMODE_NONE);
            } else*/ if (0x8340 <= pcwp->wParam && pcwp->wParam <= 0x8396) {
                //�S�p�J�^�J�i�͂������Ȃ��ƂЂ炪�Ȃ�@MSIME2k
                ImmSetConversionStatus(hImc, IME_CMODE_NATIVE | IME_CMODE_KATAKANA | IME_CMODE_FULLSHAPE, IME_SMODE_NONE);
            } else {
                ImmSetConversionStatus(hImc, (((pcwp->wParam >> 8) & 0xff) ? IME_CMODE_FULLSHAPE : 0), IME_SMODE_NONE);
            }
            ImmSetCompositionString(hImc, SCS_SETSTR, (LPVOID)mbc, strlen(mbc), (LPVOID)mbc, strlen(mbc));
            ImmNotifyIME(hImc, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
            ImmSetConversionStatus(hImc, dwConv, dwSent);
            if (!bIME) {
                ImmSetOpenStatus(hImc, FALSE);
            }
            ImmReleaseContext(activeWin, hImc);
            inKanChar = 0;
            pcwp->message = WM_NULL;
        }
        if (pcwp->message == WM_KANCHOKU_UNICHAR) {
            HWND activeWin = pcwp->hwnd;
            WCHAR wc[4];
            HKL hKL;
            HIMC hImc;
            int bIME;
            DWORD dwConv, dwSent;
            wc[0] = pcwp->wParam;
            wc[1] = 0;
            hKL = GetKeyboardLayout(0);
            if (!ImmIsIME(hKL)) {
                return 0;
            }
            hImc = ImmGetContext(activeWin);
            if(hImc == NULL) {
              return(0);
            }
            bIME = ImmGetOpenStatus(hImc);
            if (!wc[0]) {
                if (bIME) {
                    inKanChar = 1;
                    ImmNotifyIME(hImc, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
                    inKanChar = 0;
                }
                return 0;
            }
            inKanChar = 1;
            if (!bIME) {
                ImmSetOpenStatus(hImc, TRUE);
            }
            ImmGetConversionStatus(hImc, &dwConv, &dwSent);
            {
                ImmSetConversionStatus(hImc, IME_CMODE_FULLSHAPE, IME_SMODE_NONE);
            }
            ImmSetCompositionStringW(hImc, SCS_SETSTR, (LPVOID)wc, wcslen(wc)*sizeof(WCHAR), (LPVOID)wc, wcslen(wc)*sizeof(WCHAR));
            ImmNotifyIME(hImc, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
            ImmSetConversionStatus(hImc, dwConv, dwSent);
            if (!bIME) {
                ImmSetOpenStatus(hImc, FALSE);
            }
            ImmReleaseContext(activeWin, hImc);
            inKanChar = 0;
            pcwp->message = WM_NULL;
        }
    }
    return CallNextHookEx(hMsgHook, nCode, wp, lp);
}


