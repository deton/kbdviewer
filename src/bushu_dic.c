/* $Id: bushu_dic.c,v 1.6 2006/03/25 10:22:17 yuse Exp $ */

/* comp.c from tserv-0.2 <http://www.tcp-ip.or.jp/~tagawa/archive/>.
 * modified for ����Win.
 */

/*
 *                    Copyright (C) Shingo NISHIOKA, 1992
 *                       nishioka@sanken.osaka-u.ac.jp
 *            Everyone is permitted to do anything on this program
 *         including copying, transplanting, debugging, and modifying.
 */

/*
  ���̃v���O�����̌��^��, tc.el �������܂���.  tc.el �� Copyright
  �͈ȉ��̒ʂ�ł�.
;;
;; T-Code frontend for Nemacs.
;; Author : Yasushi Saito (yasushi@is.s.u-tokyo.ac.jp)
;;          Kaoru Maeda   (kaoru@is.s.u-tokyo.ac.jp)
;;
;; Department of Information Science
;; Faculty of Science, University of Tokyo
;; 7-3-1 Hongo, Bunkyo-ku, 113 Tokyo, Japan
;;
;; Copyright (C) 1989, 1990, 1991 Yasushi Saito and Kaoru Maeda.
;;

;; This program is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License version 1
;; as published by the Free Software Foundation.
;;
;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with this program; if not, write to the Free Software
;; Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "bushu_dic.h"
#include "debug.h"

#define MOJI_BUSHU_NL B2MOJI('N', 'L')
//#define MOJI_BUSHU_NL 0

BushuDic::BushuDic() {
    nent = 0;
}

BushuDic::~BushuDic() {
    for (int i = 0; i < nent; i++) { delete(ent[i]); }
}

void BushuDic::readFile(ifstream *is) {
    // ��Ɨ̈�
    char buffer[2048];
    //int line = 1;

    for (nent = 0; !(is->eof()) && nent < BUSHUDIC_MAXENT; // XXX
         nent++) {
        // get one line
        is->getline(buffer, sizeof(buffer));
        if (*buffer == 0) { break; } // XXX; ?
        char *s = buffer;
        // "CAB" �� C := A + B
        MOJI c = str2moji(s, &s);
        MOJI a = str2moji(s, &s);
        MOJI b = str2moji(s, &s);
        // "BC" �� B �� C
        // ���ԈႦ���c�c��������
        // "CB" �� B �� C
#ifdef _MSC_VER //<OKA>
        if (b == MOJI('\r') || b == MOJI('\n') || b == 0) { // XXX
#else
        if (b == MOJI(0, '\r') || b == MOJI(0, '\n') || b == 0) { // XXX
#endif          //</OKA>
            b = c;
            c = a;
            a = MOJI_BUSHU_NL;
        }
        ent[nent] = new BushuEnt;
        ent[nent]->a = a;
        ent[nent]->b = b;
        ent[nent]->c = c;
    }
}

// kanji �� 2 �̕��i�ɕ�������
// ���������� 1 ���A���s������ 0 ��Ԃ�
int BushuDic::decompose(MOJI kanji, MOJI &c1, MOJI &c2) {
    for (int i = 0; i < nent; i++) {
        if (ent[i]->c == kanji) {
            c1 = ent[i]->a;
            c2 = ent[i]->b;
            return 1;
        }
    }
    // not found
    //c1 = c2 = 0;
    c1 = c2 = MOJI_BUSHU_NL;
    return 0;
}

// c �Ɠ����ȕ��� eqc ��Ԃ��B���ɂȂ���� c ���g��Ԃ��B
// �����ł���Ƃ� c := NL + eqc �ƒ�`����Ă��邱�Ƃł���B
MOJI BushuDic::alternative(MOJI c) {
    MOJI a, b;

    if (decompose(c, a, b) != 0 && a == MOJI_BUSHU_NL) {
        return b;
    }
    return c;
}

// a �� b �𒼐ڑg�ݍ��킹�Ăł���O����T���B
// ������Ȃ������ꍇ�� 0 ��Ԃ��BXXX
MOJI BushuDic::lookSub(MOJI a, MOJI b) {
    for (int i = 0; i < nent; i++) {
        if (ent[i]->a == a && ent[i]->b == b) {
            // ������ a �� b ����ꊷ���č����\��
            // ent[i]->a == b && ent[i]->b == a
            // �Ƃ����󋵂͍l���Ȃ�
            return ent[i]->c;
        }
    }
    return 0;
}

// a �� b ��g�ݍ��킹�Ăł���O����T���B
// ������Ȃ������ꍇ�� 0 ��Ԃ��BXXX
//
// �ȉ��̃R�[�h�́A
// �� �r�s (OKA Toshiyuki) <oka@nova.co.jp>
// ����ɂ��A���S���Y����p�������́B
MOJI BushuDic::look(MOJI ca, MOJI cb) {
    return look(ca, cb, TC_BUSHU_ALGO_OKA);
}

MOJI BushuDic::look(MOJI ca, MOJI cb, int bushu_algo) {
    // ���̃��[�`���ł́A������̕��������̕����ɖ߂�Ȃ��悤
    // ���ӂ��Ȃ���΂Ȃ�Ȃ�
#define RETURN(x) if (x != ca && x != cb) return x

    // �S�p�����Ŕ��p�ɒ����镶���͔��p�ɂ��Ă���
    // XXX (���̂��������\��)
    // �c�c�Ǝv�������Abushu.rev ��
    // > 3�R
    // �̂悤�ȓ�����`�������đΏ����Ă��炤���Ƃɂ����B

    // �����ȕ��i��p�ӂ��Ă���
    MOJI a = alternative(ca);
    MOJI b = alternative(cb);
    // ����ɁA�������Ă���
    MOJI a1, a2, b1, b2;
    decompose(a, a1, a2);       // a := a1 + a2
    decompose(b, b1, b2);       // b := b1 + b2

    // NL �͔�����
    if (a1 == MOJI_BUSHU_NL) { a1 = 0; }
    if (a2 == MOJI_BUSHU_NL) { a2 = 0; }
    if (b1 == MOJI_BUSHU_NL) { b1 = 0; }
    if (b2 == MOJI_BUSHU_NL) { b2 = 0; }

    MOJI a11, a12, a21, a22;

    for (int i = 0; i < 2; i++) {
        MOJI r;
        // �܂��A�����Z
        if ((r = lookSub(ca, cb)) != 0) RETURN(r);

        // �����������m�ő����Z
        if ((r = lookSub(a, b)) != 0) RETURN(r);
#define lookSub_L2R(x, y, z) ((r = lookSub(x, y)) != 0 && (r = lookSub(r, z)) != 0)
#define lookSub_R2L(x, y, z) ((r = lookSub(y, z)) != 0 && (r = lookSub(x, r)) != 0)
        // YAMANOBE algorithm
        if (bushu_algo == TC_BUSHU_ALGO_YAMANOBE) {
            if (a1 && a2) {
                if (lookSub_L2R(a1, b, a2)) RETURN(r);
                if (lookSub_R2L(a1, a2, b)) RETURN(r);
            }
            if (b1 && b2) {
                if (lookSub_L2R(a, b1, b2)) RETURN(r);
                if (lookSub_R2L(b1, a, b2)) RETURN(r);
            }
        }

        // ���́A�����Z
        if (a2 && a1 && a2 == b) RETURN(a1);
        if (a1 && a2 && a1 == b) RETURN(a2);
        // YAMANOBE algorithm
        if (bushu_algo == TC_BUSHU_ALGO_YAMANOBE) {
            a11 = a12 = a21 = a22 = 0;
            if (a1) decompose(a1, a11, a12);
            if (a2) decompose(a2, a21, a22);
            if (a11 == MOJI_BUSHU_NL) { a11 = 0; }
            if (a12 == MOJI_BUSHU_NL) { a12 = 0; }
            if (a21 == MOJI_BUSHU_NL) { a21 = 0; }
            if (a22 == MOJI_BUSHU_NL) { a22 = 0; }

            if (a2 && a11 && a12) {
                if (a12 == b && (r = lookSub(a11, a2)) != 0) RETURN(r);
                if (a11 == b && (r = lookSub(a12, a2)) != 0) RETURN(r);
            }
            if (a1 && a21 && a22) {
                if (a22 == b && (r = lookSub(a1, a21)) != 0) RETURN(r);
                if (a21 == b && (r = lookSub(a1, a22)) != 0) RETURN(r);
            }
        }

        // ��������i�ɂ�鑫���Z
        if (a && b1 && (r = lookSub(a, b1)) != 0) RETURN(r);
        if (a && b2 && (r = lookSub(a, b2)) != 0) RETURN(r);
        if (a1 && b && (r = lookSub(a1, b)) != 0) RETURN(r);
        if (a2 && b && (r = lookSub(a2, b)) != 0) RETURN(r);
        // YAMANOBE algorithm
        if (bushu_algo == TC_BUSHU_ALGO_YAMANOBE) {
            if (a1 && a2 && b1) {
                if (lookSub_L2R(a1, b1, a2)) RETURN(r);
                if (lookSub_R2L(a1, a2, b1)) RETURN(r);
            }
            if (a1 && a2 && b2) {
                if (lookSub_L2R(a1, b2, a2)) RETURN(r);
                if (lookSub_R2L(a1, a2, b2)) RETURN(r);
            }
            if (a1 && b1 && b2) {
                if (lookSub_L2R(a1, b1, b2)) RETURN(r);
                if (lookSub_R2L(b1, a1, b2)) RETURN(r);
            }
            if (a2 && b1 && b2) {
                if (lookSub_L2R(a2, b1, b2)) RETURN(r);
                if (lookSub_R2L(b1, a2, b2)) RETURN(r);
            }
        }

        // ���������i�ɂ�鑫���Z
        if (a1 && b1 && (r = lookSub(a1, b1)) != 0) RETURN(r);
        if (a1 && b2 && (r = lookSub(a1, b2)) != 0) RETURN(r);
        if (a2 && b1 && (r = lookSub(a2, b1)) != 0) RETURN(r);
        if (a2 && b2 && (r = lookSub(a2, b2)) != 0) RETURN(r);

        // ���i�ɂ������Z
        if (a2 && b1 && a2 == b1) RETURN(a1);
        if (a2 && b2 && a2 == b2) RETURN(a1);
        if (a1 && b1 && a1 == b1) RETURN(a2);
        if (a1 && b2 && a1 == b2) RETURN(a2);
        if (bushu_algo == TC_BUSHU_ALGO_YAMANOBE) {
            if (a2 && a11 && a12) {
                if ((a12 == b1 || a12 == b2) && (r = lookSub(a11, a2)) != 0) RETURN(r);
                if ((a11 == b1 || a11 == b2) && (r = lookSub(a12, a2)) != 0) RETURN(r);
            }
            if (a1 && a21 && a22) {
                if ((a22 == b1 || a22 == b2) && (r = lookSub(a1, a21)) != 0) RETURN(r);
                if ((a21 == b1 || a21 == b2) && (r = lookSub(a1, a22)) != 0) RETURN(r);
            }
        }

        // �����̏������t�ɂ��Ă݂�
        MOJI t = ca; ca = cb, cb = t;
        t = a, a = b, b = t;
        t = a1, a1 = b1, b1 = t;
        t = a2, a2 = b2, b2 = t;
    }
    return 0;
}
#undef RETURN
#undef MOJI_BUSHU_NL

