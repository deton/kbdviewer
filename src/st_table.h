#ifndef ST_TABLE_H
#define ST_TABLE_H
// -------------------------------------------------------------------
// class StTable
//
// �X�g���[�N��̋t�����\

//<multishift>
#include <iostream>
#include <fstream>
#include <windows.h>
//</multishift>
#include <map>

#include "block.h"
#include "moji.h"

// -------------------------------------------------------------------
// �X�g���[�N�� : EOST �I�[�̕�����ŕ\��

typedef char STROKE;

#define EOST (STROKE)(0xff) // End Of STroke
#define STROKE_MAX (4)

int strokelen(const STROKE *);  // �X�g���[�N��
void strokecpy(STROKE *, const STROKE *); // �X�g���[�N�̃R�s�[

//<multishift>
// -------------------------------------------------------------------
// ���i�V�t�g

#define MAXPREFS    8           // (���i�V�t�g) prefix �̌��̏��
#define MAXPREFLEN  4           // (���i�V�t�g) prefix �̒����̏��

struct PREF {
    char mkTbl[3];              // �e�[�u�����\���镶�� (�w���x�w���x�Ȃ�
    int stlen;                  // prefix �̒���
    STROKE st[MAXPREFLEN];      // prefix
    char mkSt[6][3];            // �X�g���[�N��\������ (�w���x�w���x�Ȃ�)
};
//</multishift>

// -------------------------------------------------------------------
// StMap : STroke Map

typedef std::map<MOJI, STROKE *> StMap;

// -------------------------------------------------------------------
// StTable : STroke Table

class StTable {
public:
    STROKE *stroke;

    StMap *stMap;

    //<multishift>
    char defmkSt[6][3];         // �����w���v�̋L��
    char (*mkSt)[3];
    char defmkTbl[3];           // �e�[�u�����\���镶��
    char *mkTbl;
    int nprefs;                 // (���i�V�t�g) prefix �̌�
    struct PREF pref[MAXPREFS]; // (���i�V�t�g) prefix ��`
    STROKE *baseStroke;         // prefix ����菜���� strokes
    //</multishift>

    StTable(Block *);
    ~StTable();

    void init(Block *);
    void initSub(Block *, STROKE *);
    int look(MOJI);

    //<multishift>
    /* readFile()  : �u*.tbl�v���� prefix ��`��ǂ݂��ށB
     * setupPref() : "/��/26,23/����/��/:/��/23,26/����/��/" �̂悤�Ȉ�������
     *               prefix ��`��ݒ�B
     * matchPref() : �X�g���[�N��� prefix �̃}�b�`���O�B
     */
    void setupPref(const char *);
    //<127e>
    //void matchPref(STROKE *, STROKE **, char **, char (**)[]);
    void matchPref(STROKE *, STROKE **, char **, char (**)[3]);
    //</127e>
    //</multishift>
};

// -------------------------------------------------------------------
#endif // ST_TABLE_H
