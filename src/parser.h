// -------------------------------------------------------------------
// class Parser
// �����e�[�u�����t�@�C������ǂރN���X

#ifndef PARSER_H
#define PARSER_H
// -------------------------------------------------------------------

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include "block.h"

using namespace std;

// �g�[�N���̎��
#define LBRACE  (1)             // {
#define RBRACE  (2)             // }
#define COMMA   (3)             // ,
#define STRING  (4)             // "str"
#define SPECIAL (5)             // @c
#define SLASH   (6)             // /
#define ARROW   (7)             // -n>

// �o�b�t�@�̑傫��
#define BUFFER_SIZE 8192

// Parser �N���X (�e�[�u���t�@�C����ǂ݂���)
class Parser {
 public:
    HWND hwnd;                  // window handle
    istream *is;                // ���̓X�g���[��
    char *buffer;               // ������o�b�t�@
    int currentToken;           // �Ō�ɓǂ񂾃g�[�N��
    int lineNumber;             // ���ǂ�ł�s��

    // �R���X�g���N�^
    Parser(istream *i, HWND h) {
        is = i;
        buffer = new char[BUFFER_SIZE];
        lineNumber = 1;
        hwnd = h;
    }

    // �f�X�g���N�^
    ~Parser() {
        delete(buffer);
    }

    ControlBlock *parse();      // ���[�h�ЂƂ��ǂ�
    void parseControl(ControlBlock *); // control block ���ЂƂǂ�
    void parseRoute(ControlBlock *); // control block �̒��Ɉړ�

    int getToken();             // �g�[�N���ЂƂǂ�
    void setNextToken();        // �g�[�N���ЂƂǂ�� currentToken �ɃZ�b�g
    void checkToken(int);       // �g�[�N�����ߑł��A�������G���[
    void parseError();          // ���b�Z�[�W�{�b�N�X�ŃG���[���o���ďI��
};

// -------------------------------------------------------------------
#endif // PARSER_H
