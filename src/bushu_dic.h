#ifndef BUSHU_H
#define BUSHU_H
// -------------------------------------------------------------------

#include <iostream.h>
#include <fstream.h>
#include <windows.h>

#include "moji.h"
#include "tc.h"                 // TC_BUSHU_ALGO_{OKA,YAMANOBE}

// ���񍇐����� bushu.rev �̒��̍s�̈Ӗ�:
// * "CAB" �� C := A + B (��: "���T��")
// * "BC"  �� B �� C     (��: "�@�A")
// * ���ԈႦ���c�c��������
// * "CB" �� B �� C      (��: "�@�A")
struct BushuEnt {
    MOJI a;
    MOJI b;
    MOJI c;
};

#define BUSHUDIC_MAXENT 16000

class BushuDic {
public:
    BushuEnt *ent[BUSHUDIC_MAXENT];
    int nent;

    BushuDic();
    ~BushuDic();

    void readFile(ifstream *);
    MOJI look(MOJI, MOJI);
    MOJI look(MOJI, MOJI, int);
private:
    int decompose(MOJI, MOJI &, MOJI &);
    MOJI alternative(MOJI);
    MOJI lookSub(MOJI, MOJI);
};

// -------------------------------------------------------------------
#endif // BUSHU_H
