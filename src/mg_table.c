#ifdef _MSC_VER //<OKA>
#pragma warning(disable:4786)
#endif          //</OKA>
#include "mg_table.h"
#include "debug.h"

MgTable::MgTable(HWND h) {
    hwnd = h;
    mgMap = new MgMap();
    cand = 0;
}

MgTable::~MgTable() {
    delete(mgMap);
}

void MgTable::readFile(ifstream *is) {
    // buffer �̈�m��
    char bufferS[2048];
    char bufferD1[2048];
    char bufferD2[2048];
    int line = 1;

    while (!(is->eof())) {
        // 1 �s�ǂ݂���
        is->getline(bufferS, 2048);
        if (sscanf(bufferS, "%s /%s\n", bufferD1, bufferD2) == 2) {
            // �p�^�[���ɍ����s�Ȃ�o�^
            // �L�[
            char *key = new char[strlen(bufferD1) + 1];
            strcpy(key, bufferD1);

            // ���e
            int length = strlen(bufferD2) + 1;
            char *contents = new char[length + 2]; // ���e

            // ���e�Ɋւ��ẮA'/' �� 0 (����) �ɂ��Ă����B
            // ����ɁA�{���̖����ɂ� '/' ���B
            for (int i = 0; i < length; i++) {
                if (bufferD2[i] == '/') {
                    contents[i] = 0;
                } else {
                    contents[i] = bufferD2[i];
                }
            }
            contents[length] = '/';
            contents[length + 1] = 0; // �\��

            // map �ɓo�^
            (*mgMap)[key] = contents;
        }
        line++;
    }
}

int MgTable::setCand(char *key) {
    // �}�b�v���ɂ��邩�`�F�b�N
    if (mgMap->find(key) == mgMap->end()) {
        return 0;
    }

    // ��������o��
    char *str = (*mgMap)[key];

    // vector ������
    delete(cand);
    cand = new std::vector<char *>();

    // ����ς�
    int mode = 1;
    while (*str != '/') {
        if (*str == 0) {
            mode = 1;
        } else {
            if (mode == 1) {
                cand->push_back(str);
                mode = 0;
            }
        }
        str++;
    }

    return 1;
}

int MgTable::setCand(char *key, int OPT_conjugationalMaze) {
    if (OPT_conjugationalMaze == 0) { return setCand(key); }

    char *key2 = new char[strlen(key) + 3];
    sprintf(key2, "%s�\", key);

    // �}�b�v���ɂ��邩�`�F�b�N
    int check1 = (mgMap->find(key) != mgMap->end());
    int check2 = (mgMap->find(key2) != mgMap->end());
    if (check1 == 0 && check2 == 0) {
        delete [] key2;
        return 0;
    }

    // vector ������
    delete(cand);
    cand = new std::vector<char *>();

    // ����������o������ς�
    if (check1 != 0) {
        char *str = (*mgMap)[key];
        int mode = 1;
        while (*str != '/') {
            if (*str == 0) {
                mode = 1;
            } else {
                if (mode == 1) {
                    cand->push_back(str);
                    mode = 0;
                }
            }
            str++;
        }
    }
    if (check2 != 0) {
        char *str = (*mgMap)[key2];
        int mode = 1;
        while (*str != '/') {
            if (*str == 0) {
                mode = 1;
            } else {
                if (mode == 1) {
                    // XXX
                    int i;
                    for (i = 0; i < cand->size(); i++) {
                        if (strcmp(str, (*cand)[i]) == 0) { break; }
                    }
                    if (i == cand->size()) { cand->push_back(str); }
                    mode = 0;
                }
            }
            str++;
        }
    }

    delete [] key2;
    return 1;
}

int MgTable::setCand(char *key, int OPT_conjugationalMaze, int len) {
    if (OPT_conjugationalMaze != 2) {
        return setCand(key, OPT_conjugationalMaze);
    }
    if (len == 0) {
        return setCand(key, 1);
    }
    char *key2 = new char[strlen(key) + 3];
    sprintf(key2, "%s", key);
    sprintf(key2 + strlen(key) - len, "�\");
    int ret = setCand(key2);
    delete [] key2;
    return ret;
}
// -------------------------------------------------------------------

