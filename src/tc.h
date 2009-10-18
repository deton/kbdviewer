#ifndef TC_H
#define TC_H
/* -------------------------------------------------------------------
 * tc.h - T-Code �֘A�̒�`�̂�����r�I���ʂɎg������
 */

/* TC_NKEYS
 * --------
 * T-Code ���͂ŗp����L�[�̐��B
 *
 * TC_BUFFER_SIZE
 * --------------
 * �~�j�o�b�t�@�Ȃǂ́A�����o�b�t�@�̃T�C�Y (������)
 *
 * TC_NHIST
 * --------
 * �q�X�g���o�b�t�@�̃T�C�Y (��␔)�B
 * �q�X�g�����͂́A10 ��̃L�[�őI������d�l�Ȃ̂ŁA�ύX���Ȃ����ƁB
 */
#define TC_NKEYS 49
#define TC_BUFFER_SIZE 64
#define TC_NHIST 10

/* �V�t�g�Ō�
 * ----------
 * - TC_SHIFT(k)    : �L�[�ԍ� k �̃L�[�̃V�t�g�Ō����̃L�[�ԍ�
 * - TC_UNSHIFT(k)  : �L�[ k �̃A���V�t�g���̃L�[�ԍ�
 * - TC_ISSHIFTED(k): �L�[ k ���V�t�g�Ō����ǂ���
 */
#define TC_SHIFT(k) ((k) + ((k)<TC_NKEYS?TC_NKEYS:0))
#define TC_UNSHIFT(k) ((k) - ((k)>=TC_NKEYS&&(k)<TC_NKEYS*2?TC_NKEYS:0))
#define TC_ISSHIFTED(k) ((k)>=TC_NKEYS&&(k)<TC_NKEYS*2)

/* ���z���� (�̕`��) �Ɋւ���萔��
 * --------------------------------
 * ���z���Ղɕ\�����镶���̎�ނɉ������A�O�i�F (TC_FG_*) �Ɣw�i�F (TC_BG_*)�B
 * ��̓I�Ȕz�F�ɂ��ẮAtable_window.[ch] ���Q�ƁB
 */
/* �O�i�F (TCode::vkbFG[] �̂Ƃ�l)
 */
#define TC_FG_NIL       0       // �Ȃ�
#define TC_FG_NORMAL    1       // �ʏ�̕���
#define TC_FG_SPECIAL   2       // �@�\�L�[ (���񍇐��A���������ϊ��Ȃ�)
#define TC_FG_STROKE    3       // �����w���v�Ɏg������ (�������E�Ȃ�)
#define TC_FG_HISTREF   4       // �q�X�g�����͂ŁA�Q�ƃ}�[�N�̕t�������
//<v127a - gg>
#define TC_FG_GG        5       // �A�����K�C�h
//</v127a - gg>
/* �w�i�F (TCode::vkbBG[] �̂Ƃ�l)
 */
#define TC_BG_NIL       0       // �Ȃ�
#define TC_BG_ST1       1       // �� 1 �Ō�
#define TC_BG_ST2       2       // �� 2 �Ō�
#define TC_BG_ST3       3       // �� 3 �Ō�
#define TC_BG_STF       4       // �� 4 �Ō��A����т���ȍ~
#define TC_BG_STW       5       // ��d�Ō�
#define TC_BG_STX       6       // ��d�Ō� (���� 2)
//<multishift>
//#define TC_BG_ST1R      11      // �O���\ T-Code �̉E�\�̑� 1 �Ō�
//#define TC_BG_ST2R      12      // �O���\ T-Code �̉E�\�̑� 2 �Ō�
//#define TC_BG_STWR      13      // �O���\ T-Code �̉E�\�̓�d�Ō�
//#define TC_BG_ST1L      21      // �O���\ T-Code �̍��\�̑� 1 �Ō�
//#define TC_BG_ST2L      22      // �O���\ T-Code �̍��\�̑� 2 �Ō�
//#define TC_BG_STWL      23      // �O���\ T-Code �̍��\�̓�d�Ō�
//</multishift>
#define TC_BG_HISTPTR   40      // �q�X�g�����͂ŁA���O�ɒǉ����ꂽ���

//<multishift>
#define TC_MK_ST1       "��"    // �� 1 �Ō�
#define TC_MK_ST2       "��"    // �� 2 �Ō�
#define TC_MK_ST3       "��"    // �� 3 �Ō�
#define TC_MK_STF       "��"    // �� 4 �Ō�
#define TC_MK_STW       "��"    // ��d�Ō�
#define TC_MK_STX       "��"    // ��d�Ō� (���� 2)
//</multishift>

#define TC_MK_SH1       1
#define TC_MK_SH2       2
#define TC_MK_SH3       4


//<multishift2>
// -------------------------------------------------------------------
// directive
//
// �e�[�u���t�@�C�� (*.tbl) ���ɁA���͕����ŗL�̐ݒ���L�q�B
// �����́A���̂悤�Ȋ����B
//
// #define table-name "T"
// #define prefix /��/26,23/����/��/:/��/23,26/����/��/
// #define def-guide /����t���M���ۋU����|������G���֏Y���c/
//
// �u#�v�Ŏn�܂�s�́A�e�[�u����`��ǂ݂��ގ��_�ł̓R�����g�Ƃ���
// �����邱�Ƃɒ��ӁB
//</multishift2>

//<multishift2>
#define DIR_table_name      0
#define DIR_prefix          1
#define DIR_defguide        2

#define DIR_MAX_ENT         3

typedef char *DIR_TABLE[DIR_MAX_ENT];
//</multishift2>

// bushu conv algorithm
// -------------------------------------------------------------------
#define TC_BUSHU_ALGO_OKA      1 // ���A���S���Y�� (tc.el)
#define TC_BUSHU_ALGO_YAMANOBE 2 // �R�ӃA���S���Y�� [tcode-ml:2652]

// -------------------------------------------------------------------
#endif // TC_H
