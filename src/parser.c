#include "parser.h"
#include "moji.h"
#include "tc.h"
#include "debug.h"

// ���[�h�ЂƂ��ǂ�
ControlBlock *Parser::parse() {
    setNextToken();
    return parseControl();      // ���[�h�� control block �ЂƂ���Ȃ�
}

// control block ���ЂƂǂ�
ControlBlock *Parser::parseControl() {
    checkToken(LBRACE);         // �ŏ��� '{'
    setNextToken();

    ControlBlock *node = new ControlBlock(); // control block ��p��
    for (int i = 0; i < TC_NKEYS; i++) {
        switch(currentToken) {
        case LBRACE:            // '{' : �l�X�g���� control block
            node->block[i] = parseControl();
            setNextToken();
            break;
        case RBRACE:            // '}' ��������u�����N
        case COMMA:             // ',' �����Ă��u�����N
            node->block[i] = 0;
            break;
        case STRING:            // "str" : ������u���b�N
            node->block[i] = new StringBlock(buffer);
            setNextToken();
            break;
        case SPECIAL:           // @c : ����u���b�N
            node->block[i] = new SpecialBlock(buffer[0]);
            setNextToken();
            break;
        case 0:                 // �r���Ńt�@�C�����I������ꍇ : �G���[
            parseError();
            break;
        }

        if (i != (TC_NKEYS - 1)) {
            // control �u���b�N�̍Ō�̂ЂƂłȂ�����A���ɂ̓R���}���K�v
            checkToken(COMMA);
            setNextToken();
        }
    }

    checkToken(RBRACE);         // �ŏ��� '}'
    return node;
}

// ���݂̃g�[�N�������ߑł�
void Parser::checkToken(int target) {
    if (currentToken != target) {
        parseError();           // �������G���[
    }
}

// �g�[�N���ЂƂǂ�� currentToken �ɃZ�b�g
void Parser::setNextToken() {
    currentToken = getToken();
}

// �g�[�N����ǂ�
int Parser::getToken() {
    char c;

    is->get(c);

    // '#' �܂��� ';' �ȍ~�A�s���܂ŃR�����g
    if (c == '#' || c == ';') {
        do {
            is ->get(c);
        } while (c != 0 && c != '\n' && c != '\r');
    }

    // �ꕶ���̃g�[�N���V���[�Y
    switch (c) {
    case '{': return LBRACE;
    case '}': return RBRACE;
    case ',': return COMMA;

    case '\n':                  // ^J  : �X�L�b�v�����Ǎs�ԍ��𑝂₷
        lineNumber++;
        // go down
    case ' ':                   // SPC : �X�L�b�v
    case '\t':                  // TAB : �X�L�b�v
    case '\r':                  // ^M  : �X�L�b�v
    case '\f':                  // ^L  : �X�L�b�v
        return getToken();

    case 0:
        return NULL;
    }

    // ����
    if (c == '@') {
        is->get(c);
        buffer[0] = c;
        return SPECIAL;
    }

    // ���̎��_�ŁA�c��͕�����̂݁B�������G���[�B
    if (c != '"') {
        parseError();
    }

    // '"' ������܂œǂ݂���ŁAbuffer �Ɋi�[�B
    // �u"�v���g�́u"\""�v�ƕ\�L���邱�ƂŎw��ł���B
    // �u\�v���g�́u"\\"�v�ƕ\�L����B
    // �u\�v�́A�P�Ɏ��̈ꕶ�����G�X�P�[�v���邾���ŁA
    // �u"\n"�v�u"\t"�v�u"\ooo"�v�͖��Ή��B
    is->get(c);
    int count = 0;
    while (c != '"') {
        if (c == 0) {
            exit(1);            // ��ł����ƃG���[��
        }
        if (IS_ZENKAKU(c)) {      // �擪�� 1 �o�C�g�����Ĕ��f
            // Shift-JIS �� 2 �o�C�g����
            buffer[count] = c; count++; is->get(c);
            buffer[count] = c; count++; is->get(c);
        } else {
            // 1 �o�C�g����
            if (c == '\\') {
                // �ŏ��́u\�v�́A�P�ɓǂ݂Ƃ΂�
                is->get(c);
            }
            buffer[count] = c; count++; is->get(c);
        }
    }
    buffer[count] = 0;

    return STRING;
}

// �ǂ݂��݂Ɏ��s�����ꍇ
void Parser::parseError() {
    sprintf(buffer, "�e�[�u���t�@�C���� %d �s�ڂ��܂������Ă���悤�ł�",
            lineNumber);
    MessageBoxEx(hwnd, buffer, "�G���[",
                 MB_OK | MB_ICONERROR, LANG_JAPANESE);
    exit(1);
}

// -------------------------------------------------------------------
