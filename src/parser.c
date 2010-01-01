#include "parser.h"
#include "moji.h"
#include "tc.h"
#include "debug.h"

// ���[�h�ЂƂ��ǂ�
//����������̓t�@�C�������܂œ������[�h�Ƃ݂Ȃ��Ă���
ControlBlock *Parser::parse() {
	ControlBlock *node = new ControlBlock();
    setNextToken();
    while (currentToken) {
        switch(currentToken) {
        case LBRACE:
            parseControl(node);
            break;
        case ARROW:
            parseRoute(node);
            break;
        default:
            parseError();
        }
        setNextToken();
    }
    return node;
}

// control block ���ЂƂǂ�
void Parser::parseControl(ControlBlock *node) {
    checkToken(LBRACE);         // �ŏ��� '{'
    setNextToken();

    for (int i = 0; i < TC_NKEYS; i++) {
      for (int j = 0; j < 2; j++) {
        int k = (j?TC_SHIFT(i):i);
        if (currentToken == LBRACE || currentToken == ARROW) {
            if (!node->block[k]) node->block[k] = new ControlBlock();
            if (node->block[k]->kind() != CONTROL_BLOCK) {
                delete(node->block[k]);
                node->block[k] = new ControlBlock();
            }
        }
        switch(currentToken) {
        case LBRACE:            // '{' : �l�X�g���� control block
            parseControl((ControlBlock *)node->block[k]);
            setNextToken();
            if (currentToken != ARROW) break;
        case ARROW:             // '-n>' : control block �̎w��ʒu�Ɉړ�
            while (currentToken == ARROW) {
                parseRoute((ControlBlock *)node->block[k]);
                setNextToken();
            }
            break;
        case RBRACE:            // '}' ��������u�����N
        case COMMA:             // ',' �����Ă��u�����N
		case SLASH:             // '/' �����Ă��u�����N
            break;
        case STRING:            // "str" : ������u���b�N
            if (node->block[k]) delete(node->block[k]);
            node->block[k] = new StringBlock(buffer);
            setNextToken();
            break;
        case SPECIAL:           // @c : ����u���b�N
            if (node->block[k]) delete(node->block[k]);
            node->block[k] = new SpecialBlock(buffer[0]);
            setNextToken();
            break;
        case 0:                 // �r���Ńt�@�C�����I������ꍇ : �G���[
            parseError();
            break;
        }
        if (currentToken == SLASH) {
            setNextToken();
            continue;
        }
        break;
      }

        if (i != (TC_NKEYS - 1)) {
            // control �u���b�N�̍Ō�̂ЂƂłȂ�����A���ɂ̓R���}���K�v
            checkToken(COMMA);
            setNextToken();
        }
    }

    checkToken(RBRACE);         // �ŏ��� '}'
    return ;
}

// control block �̒��Ɉړ�
void Parser::parseRoute(ControlBlock *node) {
    checkToken(ARROW);
    int k = buffer[0];
    setNextToken();

        if (currentToken == LBRACE || currentToken == ARROW) {
            if (!node->block[k]) node->block[k] = new ControlBlock();
            if (node->block[k]->kind() != CONTROL_BLOCK) {
                delete(node->block[k]);
                node->block[k] = new ControlBlock();
            }
        }
        switch(currentToken) {
        case LBRACE:            // '{' : �l�X�g���� control block
            parseControl((ControlBlock *)node->block[k]);
            break;
        case ARROW:             // -n> : control block �̎w��ʒu�Ɉړ�
            parseRoute((ControlBlock *)node->block[k]);
            break;
        case STRING:            // "str" : ������u���b�N
            if (node->block[k]) delete(node->block[k]);
            node->block[k] = new StringBlock(buffer);
            break;
        case SPECIAL:           // @c : ����u���b�N
            if (node->block[k]) delete(node->block[k]);
            node->block[k] = new SpecialBlock(buffer[0]);
            break;
        case RBRACE:            // '}' ��������G���[
        case COMMA:             // ',' �����Ă��G���[
        case SLASH:             // '/' �����Ă��G���[
        case 0:                 // �r���Ńt�@�C�����I������ꍇ : �G���[
            parseError();
            break;
        }

    return ;
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
    if (is->eof()) return NULL;

    // '#' �܂��� ';' �ȍ~�A�s���܂ŃR�����g
    if (c == '#' || c == ';') {
        do {
            is ->get(c);
        } while (!is->eof() && c != 0 && c != '\n' && c != '\r');
        if (is->eof()) return NULL;
    }

    // �ꕶ���̃g�[�N���V���[�Y
    switch (c) {
    case '{': return LBRACE;
    case '}': return RBRACE;
    case ',': return COMMA;
    case '/': return SLASH;

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

    // ���
    if (c == '-') {
        is->get(c);
        int count = 0;
        while (!is->eof() && count < BUFFER_SIZE && c != '>') {
            if (is->eof() || c == 0) {
                parseError();
            }
            buffer[count] = c;
            count++;
            is->get(c);
        }
        buffer[count] = 0;
        int k;
        if (1 <= sscanf(buffer, "%d", &k)) ;
        else if (1 <= sscanf(buffer, "S%d", &k)) k = TC_SHIFT(k);
        else parseError();
        buffer[0] = k;
        return ARROW;
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
    while (!is->eof() && count < BUFFER_SIZE && c != '"') {
        if (is->eof() || c == 0) {
            parseError();
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
