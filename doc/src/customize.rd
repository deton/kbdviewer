=begin

== �J�X�^�}�C�Y

�u����Win�v�̃J�X�^�}�C�Y�Ɋ֘A����t�@�C���́A
���� 3 ��ł��B

* ((<�����ݒ�t�@�C��>)) (kanchoku.ini)
* ((<�L�[�{�[�h�t�@�C��>)) (106.key, 101.key �Ȃ�)
* ((<�e�[�u���t�@�C��>)) (t.tbl, tut.tbl �Ȃ�)

((<�����ݒ�t�@�C��>)) (kanchoku.ini) �́A
�u����Win�v�̓����ݒ肷��ݒ�t�@�C���ł��B
�ʏ�́A���̃t�@�C����ҏW���邾���ł悢�ł��傤�B

((<�L�[�{�[�h�t�@�C��>)) (*.key) �́A
�u����Win�v�Ŏg�p����L�[��ݒ肷��ݒ�t�@�C���ł��B
�ʏ�́A���̃t�@�C����ύX����K�v�͂���܂��񂪁A
����ȃL�[�{�[�h���g�p������A�L�[���C�A�E�g��ύX�����肵�Ă���ꍇ�́A
�L�[�{�[�h�t�@�C����ҏW������A
�V�����쐬�����肷��K�v�����邩���m��܂���B

((<�e�[�u���t�@�C��>)) (*.tbl) �́A
T-Code �� TUT-Code �Ȃǂ̓��͕����́A
�����ƃX�g���[�N�̑Ή����`����ݒ�t�@�C���ł��B
���񍇐�����������ϊ��A�������ȃ��[�h�Ȃǂ̋@�\�L�[�̊��蓖�Ă��A
���̃t�@�C���Őݒ肵�܂��B
�܂��A�Ǝ��̃R�[�h���쐬����ꍇ�́A
�e�[�u���t�@�C����V�����쐬���邱�ƂɂȂ�܂��B

=== �����ݒ�t�@�C��

�����ݒ�t�@�C�� kanchoku.ini �́A
�u����Win�v�̓����ݒ肷��ݒ�t�@�C���ł��B

�g�p������͕��� (T-Code, TUT-Code �Ȃ�) ��
�L�[�{�[�h���w�肷��ɂ́A���̐ݒ�t�@�C����ҏW���܂��B

* kanchoku.ini �̏����́AWindows �ň�ʓI�ɗp������ INI �`���ł��B
* �Z�~�R���� ((({;}))) ����s���܂ł́A�R�����g�Ƃ��ēǂ݂Ƃ΂���܂��B
* �u����Win�v�̐ݒ�I�v�V�����́A
  (({[kanchoku]})) �Z�N�V�����ɋL�q���܂��B

  ��(({[kansaku]})) �Z�N�V�����ɂ́A
  ((<������>)) �̐ݒ�I�v�V�������L�q����ꏊ�Ȃ̂ŁA�����ɂ�
  �u����Win�v�̐ݒ�������Ȃ��悤�ɂ��܂��傤�B��

==== �u����Win�v�̋N��
�u����Win�v�̋N���Ɋւ���I�v�V�����ł��B
:(({hotKey=((|xx|))}))
  [kanchoku.ini �̃f�t�H���g: dc (���Ȃ킿�A((%Ctrl%))+((%\%))); �ȗ���: dc]

  ((|xx|)) �ɁA�z�b�g�L�[ (ON/OFF �̃g�O���Ɏg�p����L�[) ���A
  16 �i�\�L�� ((<���z�L�[�R�[�h>)) �Ŏw�肵�܂��B
  �����Ŏw�肵���L�[�ƁA((%Ctrl%)) �𓯎��ɉ������ƂŁAON/OFF ���g�O�����܂��B

  ���Ƃ��΁A((%Ctrl%))+((%Space%)) ���z�b�g�L�[�ɂ���ɂ́A
  ���̂悤�ɋL�q���܂��B
    hotKey=20

:(({unmodifiedHotKey=((|xx|))}))
  [kanchoku.ini �̃f�t�H���g: (�Ȃ�); �ȗ���: (�Ȃ�)]

  [^[((<ver1.27d|�ύX����>))]^]
  (({hotKey=((|xx|))})) �Ɠ��l�ł����A
  �����Őݒ肵���z�b�g�L�[�͒P�Ƃœ����A((%Ctrl%)) �������K�v������܂���B

  ���Ƃ��΁A((%�ϊ�%)) �L�[���z�b�g�L�[�ɂ���ɂ́A
  ���̂悤�ɋL�q���܂��B
    unmodifiedHotKey=1c

(({hotKey=((|xx|))})) �� (({unmodifiedHotKey=((|xx|))})) �̎w��͗������܂��B
���Ƃ��΁A
  hotKey=1c
  unmodifiedHotKey=1c
�ƋL�q����΁A((%�ϊ�%)) �� ((%Ctrl%))+((%�ϊ�%)) �̗�����
�z�b�g�L�[�ɂȂ�܂��B

�z�b�g�L�[�ɐݒ肵���L�[ (((%Ctrl%))+((%\%)) �� ((%�ϊ�%)) �Ȃ�) �́A
�˂Ɂu����Win�v������Ă��܂��̂ŁA
(�u����Win�v���I�����Ȃ������) �\�t�g�ɓn�����Ƃ͂ł��Ȃ��Ȃ�܂��B
((*((*�L�[�͐T�d�ɑI��ł��������B*))*))

==== ���͕���
���͕����֘A�̃I�v�V�����ł��B
:(({keyboard=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: 106.key; �ȗ���: 106.key]

  ((|file|)) �ɁA((<�L�[�{�[�h�t�@�C��>)) ���w�肵�܂��B
  * 106.key �c ���{��z��̃L�[�{�[�h (106 �z��A109 �z��)
  * 101.key �c �p��z��̃L�[�{�[�h (101 �z��A104 �z��)
  * dvorak.key �c Dvorak �z��̃L�[�{�[�h
:(({tableFile=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: t.tbl; �ȗ���: t.tbl]

  ((|file|)) �ɁA((<�e�[�u���t�@�C��>)) ���w�肵�܂��B
  * t.tbl �c T-Code
  * tut.tbl �c TUT-Code
  * g.tbl �c G-Code

==== �⏕����
�⏕���͊֘A�̃I�v�V�����ł��B
:(({bushu=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: kwbushu.rev; �ȗ���: (�Ȃ�)]

  ((|file|)) �ɁA���񍇐��ϊ��̎����t�@�C�����w�肵�܂��B
  �w�肵�Ȃ��ꍇ�́A���񍇐��ϊ����g�p���Ȃ��ݒ�ɂȂ�܂��B
:(({bushuAlgo=[OKA | YAMANOBE]}))
  [kanchoku.ini �̃f�t�H���g: YAMANOBE; �ȗ���: OKA]
  
  [^[((<ver1.27f|�ύX����>))]^]
  ���񍇐��ϊ��̃A���S���Y�����w�肵�܂��B
  * (({bushuAlgo=OKA})) 
    �c ������ɂ��A���S���Y�����g�p���܂��B
  * (({bushuAlgo=YAMANOBE})) 
    �c �R�ӂ���ɂ��A���S���Y�� [tcode-ml:2652] ���g�p���܂��B
  ������̃A���S���Y���́A����Win �̏]���̃A���S���Y���ł��B
  �R�ӂ���̃A���S���Y���́A���������ׂ����������č������s�����̂ŁA
  ���Ƃ��΁A�u�� + �V�v�́u�`�v�ł͂Ȃ��u���v�ƂȂ�܂��B
  ������̃A���S���Y���́A
  tc.el �� 
  ((<T-Code for Macintosh|URL:http://openlab.jp/tcode/soft.html">)) �Ȃǂɋ߂��A
  �R�ӂ���̃A���S���Y���́A((<tc2|"���ړ��̓\�t�g">)) 
  (���Ƀo�[�W���� 2.2 �ȍ~?) �ɋ߂��Ǝv���܂��B
  
  �w�肵�Ȃ��ꍇ�́A������ɂ��A���S���Y����p���܂��B
:(({mazegaki=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: kwmaze.dic; �ȗ���: (�Ȃ�)]

  ((|file|)) �ɁA���������ϊ��̎����t�@�C�����w�肵�܂��B
  �w�肵�Ȃ��ꍇ�́A���������ϊ����g�p���Ȃ��ݒ�ɂȂ�܂��B
:(({conjugationalMaze=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 2; �ȗ���: 1]

  ���p������������ϊ�����ۂ́A�ǂ݂̓��͂̂��������w�肵�܂��B
  ���Ƃ��΁A
  ((<���������ϊ�����>))�� (({�͂ȁ\ /�b/})) �Ƃ����G���g��������Ƃ��āA
  �u�b�v�ƕϊ����悤�Ƃ����Ƃ��A
  * (({conjugationalMaze=0})) 
    �c �u�͂ȁ\�v(�����ɏ����Ă��邻�̂܂܂̌`) �ł̂݁A�ϊ��\�B
  * (({conjugationalMaze=1})) 
    �c �u�͂ȁ\�v�A�u�͂ȁv(�ꊲ) �ł̂݁A�ϊ��\
  * (({conjugationalMaze=2})) 
    �c �u�͂Ȃ��v�u�͂Ȃ��Ȃ��v�u�͂Ȃ��܂��v�Ȃǂ̊��p�`�ŕϊ��\[^[((<ver1.27f|�ύX����>))]^]
  �ƂȂ�܂��B

:(({gg=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: (�Ȃ�); �ȗ���: (�Ȃ�)]

  [^[((<ver1.27a|�ύX����>))]^]
  ((|file|)) �� ((<�n��K�C�h>)) �̎����t�@�C�����w�肵�܂��B
  �w�肵�Ȃ��ꍇ�́A�n��K�C�h���g�p���Ȃ��ݒ�ɂȂ�܂��B

:(({defg=((|string|))}))
  [kanchoku.ini �̃f�t�H���g: (�Ȃ�); �ȗ���: (�Ȃ�)]

  [^[((<ver1.27e|�ύX����>))]^]
  ((<�n��K�C�h>)) �g�p���ɁA�f�t�H���g�̏�� (�K�C�h���ׂ��������Ȃ��ꍇ)
  �ŕ\�����镶������ׂĎw�肵�܂��B

:(({prefixautoassign=((|string|))}))
  [kanchoku.ini �̃f�t�H���g: (�Ȃ�); �ȗ���: (�Ȃ�)]

  [^[((<ver1.27g|�ύX����>))]^]
  ((<�n��K�C�h>)) �g�p���ɁA�O���Ɉꎞ�I�ɃX�g���[�N������U��@�\�ŗp����
  �X�g���[�N�����`�`���Ŏw�肵�܂��B

:(({record=((|file|))}))
:(({stat=((|file|))}))
  [kanchoku.ini �̃f�t�H���g: kwrecord.txt, kwstat.txt; �ȗ���: (�Ȃ�)]

  [^[((<ver1.27f|�ύX����>))]^]
  ((<���͂̓��v>))���L�^����t�@�C�������w�肵�܂��B

==== ��������
�������͂Ɋւ���I�v�V�����ł��B
:(({shiftKana=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  ((|n|)) �� 1 ���w�肷��ƁA�V�t�g�Ō��ŁA
  �Ђ炪�Ȃ��������Ȃɕϊ����ē��͂��܂��B
  [:del:]�������A
  �{���V�t�g��p���ē��͂��镶�� (�啶����L���Ȃ�) �͓��͂ł��Ȃ��Ȃ�܂��B
  [:/del:]
  �Ȃ��A
  �V�t�g�Ō��́A���ȕ����̓��͂Ɏg���L�[�������u����Win�v���Ŏ��A
  ����ȊO�̃L�[�̃V�t�g�Ō��́A
  �ʏ�̑Ō��Ƃ��Ĉ����܂�[^[((<ver1.27a|�ύX����>))]^]�B

:(({enableHankakuKana=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ��l: 0]

  [^[((<ver1.27f|�ύX����>))]^]
  ((|n|)) �� 1 ���w�肷��ƁA((<�S�p���[�h>)) ���ɁA
  �������Ȃ𔼊p���Ȃɕϊ����܂��B

==== ���o���b�Z�[�W
���o���b�Z�[�W�Ɋւ���I�v�V�����ł��B
:(({outputMethod=((|n|))}))
:(({useWMIMECHAR=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  �u����Win�v���A�v���P�[�V�����ɕ����𑗏o����Ƃ��ɗp����
  ���o���b�Z�[�W���w�肵�܂��B�w��ł���l�́A
  * 0 (WM_CHAR)
  * 1 (WM_IME_CHAR)
  * 2 (WM_KANCHOKU_CHAR; �t�b�N�� ImmSetCompositionString ��g�ݍ��킹��
    ���͂��邽�߂̓Ǝ��̃��b�Z�[�W
    [^[((<ver1.27f|�ύX����>))]^])
  �ł��B

  WindowsNT/2000/XP �ł� 0 ���A
  Windows95/98/Me �ł� 1 ���w�肵�Ă��������������悤�ł��B
  
  ����̃A�v���P�[�V�����Łu����Win�v���g���Ȃ��ꍇ�́A
  ��q�� ((<�E�B���h�E�N���X���Ƃɑ��o���b�Z�[�W���w��>)) �̕��@��
  �����Ă݂Ă�������[^[((<ver1.27f|�ύX����>))]^]�B
:(({enableWMKANCHOKUCHAR=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 1; �ȗ���: 0]

  [^[((<ver1.27f|�ύX����>))]^]
  (({outputMethod=2})) ���g�p����ꍇ�́A((|n|)) �� 1 ���w�肵�Ă����܂��B

:(({outputSleep=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 1; �ȗ���: 0]

  [^[((<ver1.27a,f|�ύX����>))]^]
  �L�[���o���� Sleep() ����҂����� (�P�ʂ̓~���b) ���w�肵�܂��B
  �f�t�H���g�� 1 �ł����A
  ���̂悤�ȏꍇ�ɂ́A�K���ɒl�𑝂₵�Ďw�肵�Ă݂Ă��������B
  * ((<��u�^�̕ϊ�>)) �ŁA
    �ϊ��������������܂��u���������Ȃ��ꍇ
  * ���͂̎�肱�ڂ�������ꍇ
  * ((%BackSpace%)) �� ((%Enter%)) ���d�����ē��͂���Ă��܂��ꍇ

==== �E�B���h�E�N���X���Ƃɑ��o���b�Z�[�W���w��
[^[((<ver1.27f|�ύX����>))]^] 
���o���b�Z�[�W (({outputMethod})) �́A
�A�v���P�[�V�������Ƃ� (���m�ɂ́A�E�B���h�E�N���X���Ƃ�) 
�w�肷�邱�Ƃ��ł��܂��B

�w�肵�����A�v���P�[�V�������ƂɁA���̂悤�ȋL�q��K�X�ǉ����Ă��������B
  [<���ʎq>]
  className=<�E�B���h�E�N���X��>
  outputMethod=<���o���b�Z�[�W>

(({<���ʎq>})) �́A���ł��悢�̂ł����A
�ΏۃA�v���P�[�V�����̖��O���p���ŏ����̂��悢�ł��傤�B
���̂��̂ƂԂ���Ȃ��悤�ɓK���ɖ������܂��B

(({<�E�B���h�E�N���X��>})) �́A�ݒ���s�������E�B���h�E�N���X�����w�肵�܂��B
�E�B���h�E�N���X���́A�t���̃c�[�� wininfo.exe �Œ��ׂ邱�Ƃ��ł��܂��B
wininfo.exe ���N���� (�u����Win�v�͏I�����Ă����܂�)�A
���ׂ����E�B���h�E���A�N�e�B�u�ɂ��āA((%Ctrl%))+((%\%)) �L�[�������ƁA
���̓t�H�[�J�X�����E�B���h�E�̃N���X�����擾�����̂ŁA
����������Ă����܂��B

(({<���o���b�Z�[�W>})) �ɂ́A0, 1, 2 �̂����ꂩ���w�肵�܂��B
�O�q�̑S�ʓI�� ((<���o���b�Z�[�W>)) ��
(({outputMethod=0})) ���w�肵���ꍇ�́A
�����ł�(({outputMethod=1})) ���A
�t�ɑS�ʓI�Ȏw�肪 1 �������Ƃ��́A�����ł� 0 ���w�肵�Ă݂Ă��������B

����ł��߂Ȃ�A(({outputMethod=2})) �������Ă݂Ă��������B
(({outputMethod=2})) �ł����͂ł��Ȃ��ꍇ���A
�u�ڍׂȃe�L�X�g�T�[�r�X���I�t�ɂ���v�Ƀ`�F�b�N������ƁA
���͂ł���悤�ɂȂ邱�Ƃ�����܂�
(�R���g���[���p�l����
�u�n��ƌ���̃I�v�V�����v���u����v�^�u���u�ڍׁv���u�ڍאݒ�v�^�u)�B
�܂��AIME �Ƃ̑���������悤�ł��B


�t���� kanchoku.ini �ɁA�������ݒ�Ⴊ����܂��̂ŁA�Q�l�ɂ��Ă݂Ă��������B

==== �\��
�\���Ɋւ���I�v�V�����ł��B
:(({xLoc=((|n|))}))
:(({yLoc=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: -1, -1; �ȗ���: -1, -1]

  �N�����́u����Win�v�̃E�B���h�E�̏����ʒu�� x ���W�� y ���W���A
  ���ꂼ��s�N�Z���P�ʂŎw�肵�܂��B
  -1 �Ƃ���ƁA���Ɏw�肵�Ȃ��ݒ�ɂȂ�܂��B
:(({offHide=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  ((|n|)) �� 1 ���w�肷��ƁAOFF ���Ɂu����Win�v�̃E�B���h�E���\���ɂ��܂��B

  �܂� 2 ���w�肷��ƁAON ���ɂ��E�B���h�E���\���ɂ��܂��B
  ���̏ꍇ�́A�⏕�ϊ��E���I���E�����w���v�E�q�X�g�����͎��̂݁A
  �E�B���h�E��\�����܂��B
:(({followCaret=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  ((|n|)) �� 1 ���w�肷��ƁA
  �u����Win�v�̃E�B���h�E���L�����b�g (�J�[�\��) ��
  �Ǐ]���ē����悤�ɂȂ�܂��B
  �������A�Ώۃ\�t�g�ɂ���Ă͓��삵�Ȃ����Ƃ�����܂��B

==== ���̑�
�ȉ��́A�p�b�`�쐬�҂̍D�݂ŉ�����ꂽ�I�v�V�����ł��B
�ʏ�͎w�肷��K�v�͂Ȃ��ł��傤�B
:(({hardBS=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  �� 2 �Ō��Ƃ��ĉ����ꂽ ((%BackSpace%)) �L�[�́A�ʏ�A
  �� 1 �Ō��̎������ł����A
  ((|n|)) �� 1 ���w�肷��ƁA�u�� 1 �Ō��̎����� + �����폜�v�ɂȂ�܂��B
:(({useCtrlKey=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  ((|n|)) �� 1 ���w�肷��ƁA
  �u((%Ctrl%))+ �p���v���@�\�L�[�Ɠ��l�Ɉ����܂��B��̓I�ɂ́A
  * ((%C-g%)) �� ((%Esc%)) ��
  * ((%C-h%)) �� ((%BackSpace%)) ��
  * ((%C-m%)) �� ((%C-j%)) �� ((%Enter%)) ��
  * ((%C-i%)) �� ((%Tab%)) ��
  ���ꂼ��A���l�Ɉ����܂��B
:(({win95=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  Windows95 �ŉ��z���Ղ̃t�H���g�� 1 �h�b�g�����悤�Ȃ̂ŁA���̕␳�ł��B
=end
:(({useTTCode=((|n|))}))
  [kanchoku.ini �̃f�t�H���g: 0; �ȗ���: 0]

  �����w���v���A�O���\ T-Code �X�^�C���ɂ��܂��B
  ���Ȃ킿�A
  �O���\ T-Code �̉E�\ (((%j%))((%f%)) ���v���t�B�b�N�X�Ƃ��� 4 �X�g���[�N) ��
  �΂��Ă͑� 3 �Ō��Ƒ� 4 �Ō��݂̂��u���v�Ɓu���v�ŁA
  ���\ (((%f%))((%j%)) ���v���t�B�b�N�X�Ƃ��� 4 �X�g���[�N) �ɑ΂��Ă�
  �� 3 �Ō��Ƒ� 4 �Ō��݂̂��u���v�Ɓu���v�ŕ\�����܂��B

  [^[((<ver1.27e|�ύX����>))]^] ���̃I�v�V������ OBSOLETE �ɂȂ�܂����B
  �����ɁA((<�e�[�u���t�@�C��>)) ��
  ((<(({#define prefix ((|spec|))}))>)) ���g���Ă��������B
=begin




=== �L�[�{�[�h�t�@�C��

�L�[�{�[�h�t�@�C�� *.key �́A�L�[�{�[�h��̎��ۂ̃L�[�ƁA
�u����Win�v�̓����Ŏg�p���� ((*�L�[�ԍ�*)) �̑Ή����L�q�����t�@�C���ł��B

�g�p����L�[�{�[�h�ɍ��킹�����̂�I�сA�����ݒ�t�@�C�� kanchoku.ini ��
(({keyboard})) �I�v�V�����Ŏw�肵�܂��B
�u����Win�v�̃p�b�P�[�W�Ɋ܂܂�Ă���L�[�{�[�h�t�@�C���́A���̂Ƃ���ł��B

* ((<106.key>)) �c ���{��z�� (106 �z��A109 �z��)
* ((<101.key>)) �c �p��z�� (101 �z��A104 �z��)
* ((<dvorak.key>)) �c Dvorak �z��

�ʏ�́A��L�̂����ꂩ����I�ԂƂ悢�ł��傤�B

����ȃL�[�{�[�h���g�p���Ă������A�L�[���C�A�E�g��ύX���Ă�����́A
�ȉ��� ((<�L�[�{�[�h�t�@�C���̏���>)) ���Q�l�ɁA
�L�[�{�[�h�t�@�C�����L�q���Ă��g�����������B

==== �L�[�{�[�h�t�@�C���̏���

�L�[�{�[�h�t�@�C���ɂ́A
�u����Win�v�ŗp���� 49 �̃L�[�� ((<���z�L�[�R�[�h>)) ���A16 �i�\�L�ŁA
�L�[�ԍ� (0 �` 48) �̏��ɋL�q���܂��B
�e���z�L�[�R�[�h�̌��ɂ́A�R���} ((({,}))) �������܂��B
���z�L�[�R�[�h��R���}�̊Ԃɂ́A�󔒂���s�����Ă��悢�悤�ł��B
�R�����g���������Ƃ͂ł��܂���B

==== �L�[�ԍ�

�L�[�ԍ��́A�u����Win�v�̓����ŁA�e�L�[�����ʂ���̂ɗp������ԍ��ł��B
T-Code �ŗp������ 40 �̃L�[�ɂ��ẮA
�L�[�{�[�h�̍��ォ�珇�� 0 �` 39 ���A
�܂�����ȊO�̃L�[�ɂ� 40 �` 48 �̔ԍ������蓖�ĂĂ��܂��B

�e�L�[�ԍ��̃L�[�̔z�u���A
���ۂ̃L�[�{�[�h��̔z�u (�}��)�A�����
�u����Win�v�̉��z���Տ�̔z�u (�}�E) �Ɏ����܂��B
�Ȃ��A�p��L�[�{�[�h�ł́A48 �Ԃɑ�������L�[�͑��݂����A
���p�ł��Ȃ��悤�ł��B

=end
=begin html
<table class="figure" summary="�L�[�ԍ��̑Ή��̐}��">
<caption>�L�[�ԍ��̑Ή��\�\���z���� (��) �Ǝ��ۂ̃L�[�{�[�h (�E)</caption>
<tr>
<td>
<img src="img/tkeys_vkb.png" alt="���z����" title="���z����" />
</td>
<td>
<img src="img/tkeys_kb.png" alt="�L�[�{�[�h" title="�L�[�{�[�h" />
</td>
</tr>
</table>
=end
=begin

==== ���z�L�[�R�[�h

���z�L�[�R�[�h�́AWindows �̓����ŁA�e�L�[�����ʂ���̂ɗp�����鐔�l�ł��B

��ȃL�[�̉��z�L�[�R�[�h���A���̕\�Ɏ����܂��B

��((%�J�i%))�A((%����%))�A((%Win%)) �ȂǁA�ꕔ�̃L�[��
�u����Win�v�ł͗��p�ł��Ȃ��悤�ł��B��
=end


  ����������������������������������������������������������������������
  vkey  key       ��vkey  key       ��vkey  key       ��vkey  key
  ����������������������������������������������������������������������
   30    0        �� 41    A        �� 4b    K        �� 55    U
   31    1        �� 42    B        �� 4c    L        �� 56    V
   32    2        �� 43    C        �� 4d    M        �� 57    W
   33    3        �� 44    D        �� 4e    N        �� 58    X
   34    4        �� 45    E        �� 4f    O        �� 59    Y
   35    5        �� 46    F        �� 50    P        �� 5a    Z
   36    6        �� 47    G        �� 51    Q        ��
   37    7        �� 48    H        �� 52    R        ��
   38    8        �� 49    I        �� 53    S        ��
   39    9        �� 4a    J        �� 54    T        ��
  ����������������������������������������������������������������������
   ba   : * (; :) �� c0   @ ` (` ~) �� 08   BS        �� 15   �J�i
   bb   ; + (= +) �� db   [ {       �� 09   TAB       �� 19   ����
   bc   , <       �� dc   \ |       �� 0d   RET       �� 1c   �ϊ�
   bd   - = (- _) �� dd   ] }       �� 1b   ESC       �� 1d   ���ϊ�
   be   . >       �� de   ^ ~ (' ") �� 20   SPC       ��
   bf   / ?       �� e2   \ _ (�Ȃ�)��                ��
  ����������������������������������������������������������������������
   21   PageUp    �� 25   ��        �� 2d   Insert    �� 5b   ��Win
   22   PageDown  �� 26   ��        �� 2e   Delete    �� 5c   �EWin
   23   End       �� 27   ��        ��                �� 5d   �A�v��
   24   Home      �� 28   ��        ��                ��
  ����������������������������������������������������������������������
                 vkey: ���z�L�[�R�[�h; key: ���ۂ̃L�[; ( ) ���͉p��z��



=begin html
<div class="table">
<table class="vkeytbl0" rules="cols" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<caption>���z�L�[�R�[�h (vkey) �Ǝ��ۂ̃L�[ (key) �̑Ή� (���������͉p��z��)</caption>
<tr valign="top">
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>30</code></td><td><kbd>0</kbd></td></tr>
<tr><td><code>31</code></td><td><kbd>1</kbd></td></tr>
<tr><td><code>32</code></td><td><kbd>2</kbd></td></tr>
<tr><td><code>33</code></td><td><kbd>3</kbd></td></tr>
<tr><td><code>34</code></td><td><kbd>4</kbd></td></tr>
<tr><td><code>35</code></td><td><kbd>5</kbd></td></tr>
<tr><td><code>36</code></td><td><kbd>6</kbd></td></tr>
<tr><td><code>37</code></td><td><kbd>7</kbd></td></tr>
<tr><td><code>38</code></td><td><kbd>8</kbd></td></tr>
<tr><td><code>39</code></td><td><kbd>9</kbd></td></tr>
</tbody>
</table>
</td>
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>41</code></td><td><kbd>A</kbd></td></tr>
<tr><td><code>42</code></td><td><kbd>B</kbd></td></tr>
<tr><td><code>43</code></td><td><kbd>C</kbd></td></tr>
<tr><td><code>44</code></td><td><kbd>D</kbd></td></tr>
<tr><td><code>45</code></td><td><kbd>E</kbd></td></tr>
<tr><td><code>46</code></td><td><kbd>F</kbd></td></tr>
<tr><td><code>47</code></td><td><kbd>G</kbd></td></tr>
<tr><td><code>48</code></td><td><kbd>H</kbd></td></tr>
<tr><td><code>49</code></td><td><kbd>I</kbd></td></tr>
<tr><td><code>4a</code></td><td><kbd>J</kbd></td></tr>
<tr><td><code>4b</code></td><td><kbd>K</kbd></td></tr>
<tr><td><code>4c</code></td><td><kbd>L</kbd></td></tr>
<tr><td><code>4d</code></td><td><kbd>M</kbd></td></tr>
</tbody>
</table>
</td>
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>4e</code></td><td><kbd>N</kbd></td></tr>
<tr><td><code>4f</code></td><td><kbd>O</kbd></td></tr>
<tr><td><code>50</code></td><td><kbd>P</kbd></td></tr>
<tr><td><code>51</code></td><td><kbd>Q</kbd></td></tr>
<tr><td><code>52</code></td><td><kbd>R</kbd></td></tr>
<tr><td><code>53</code></td><td><kbd>S</kbd></td></tr>
<tr><td><code>54</code></td><td><kbd>T</kbd></td></tr>
<tr><td><code>55</code></td><td><kbd>U</kbd></td></tr>
<tr><td><code>56</code></td><td><kbd>V</kbd></td></tr>
<tr><td><code>57</code></td><td><kbd>W</kbd></td></tr>
<tr><td><code>58</code></td><td><kbd>X</kbd></td></tr>
<tr><td><code>59</code></td><td><kbd>Y</kbd></td></tr>
<tr><td><code>5a</code></td><td><kbd>Z</kbd></td></tr>
</tbody>
</table>
</td>
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>ba</code></td><td><kbd>:*</kbd> (<kbd>;:</kbd>)</td></tr>
<tr><td><code>bb</code></td><td><kbd>;+</kbd> (<kbd>=+</kbd>)</td></tr>
<tr><td><code>bc</code></td><td><kbd>,&lt;</kbd></td></tr>
<tr><td><code>bd</code></td><td><kbd>-=</kbd> (<kbd>-_</kbd>)</td></tr>
<tr><td><code>be</code></td><td><kbd>.&gt;</kbd></td></tr>
<tr><td><code>bf</code></td><td><kbd>/?</kbd></td></tr>
<tr><td><code>c0</code></td><td><kbd>@`</kbd> (<kbd>`~</kbd>)</td></tr>
<tr><td><code>db</code></td><td><kbd>[{</kbd></td></tr>
<tr><td><code>dc</code></td><td><kbd>\|</kbd></td></tr>
<tr><td><code>dd</code></td><td><kbd>]}</kbd></td></tr>
<tr><td><code>de</code></td><td><kbd>^~</kbd> (<kbd>'&quot;</kbd>)</td></tr>
<tr><td><code>e2</code></td><td><kbd>\_</kbd> (�Ȃ�)</td></tr>
</tbody>
</table>
</td>
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>08</code></td><td><kbd>BS</kbd></td></tr>
<tr><td><code>09</code></td><td><kbd>TAB</kbd></td></tr>
<tr><td><code>0d</code></td><td><kbd>Enter</kbd></td></tr>
<tr><td><code>15</code></td><td><kbd>�J�i</kbd></td></tr>
<tr><td><code>19</code></td><td><kbd>����</kbd></td></tr>
<tr><td><code>1b</code></td><td><kbd>ESC</kbd></td></tr>
<tr><td><code>1c</code></td><td><kbd>�ϊ�</kbd></td></tr>
<tr><td><code>1d</code></td><td><kbd>���ϊ�</kbd></td></tr>
<tr><td><code>20</code></td><td><kbd>SPC</kbd></td></tr>
</tbody>
</table>
</td>
<td>
<table class="vkeytbl" summary="���z�L�[�R�[�h�Ǝ��ۂ̃L�[�̑Ή�">
<colgroup><col align="right" /><col align="left" /></colgroup>
<thead><tr><th>vkey</th><th>key</th></tr></thead>
<tbody>
<tr><td><code>21</code></td><td><kbd>PageUp</kbd></td></tr>
<tr><td><code>22</code></td><td><kbd>PageDown</kbd></td></tr>
<tr><td><code>23</code></td><td><kbd>End</kbd></td></tr>
<tr><td><code>24</code></td><td><kbd>Home</kbd></td></tr>
<tr><td><code>25</code></td><td><kbd>��</kbd></td></tr>
<tr><td><code>26</code></td><td><kbd>��</kbd></td></tr>
<tr><td><code>27</code></td><td><kbd>��</kbd></td></tr>
<tr><td><code>28</code></td><td><kbd>��</kbd></td></tr>
<tr><td><code>2d</code></td><td><kbd>Insert</kbd></td></tr>
<tr><td><code>2e</code></td><td><kbd>Delete</kbd></td></tr>
<tr><td><code>5b</code></td><td>��<kbd>Win</kbd></td></tr>
<tr><td><code>5c</code></td><td>�E<kbd>Win</kbd></td></tr>
<tr><td><code>5d</code></td><td><kbd>Appl</kbd></td></tr>
</tbody>
</table>
</td>
</tr>
</table>
</div>
=end
=begin

==== �t���̃L�[�{�[�h�t�@�C��

+ 106.key

  31, 32, 33, 34, 35, 36, 37, 38, 39, 30,
  51, 57, 45, 52, 54, 59, 55, 49, 4f, 50,
  41, 53, 44, 46, 47, 48, 4a, 4b, 4c, bb,
  5a, 58, 43, 56, 42, 4e, 4d, bc, be, bf,
  20, bd, de, dc, c0, db, ba, dd, e2,
=end
=begin html
<table class="figure" summary="106.key �̑Ή��̐}��">
<tr>
<td>
<img src="img/keys_106_vkb.png" alt="���z����" title="���z����" />
</td>
<td>
<img src="img/keys_106_kb.png" alt="�L�[�{�[�h" title="�L�[�{�[�h" />
</td>
</tr>
</table>
=end
=begin
+ 101.key

  31, 32, 33, 34, 35, 36, 37, 38, 39, 30,
  51, 57, 45, 52, 54, 59, 55, 49, 4f, 50,
  41, 53, 44, 46, 47, 48, 4a, 4b, 4c, ba,
  5a, 58, 43, 56, 42, 4e, 4d, bc, be, bf,
  20, bd, bb, dc, db, dd, de, c0, 00,
=end
=begin html
<table class="figure" summary="101.key �̑Ή��̐}��">
<tr>
<td>
<img src="img/keys_101_vkb.png" alt="���z����" title="���z����" />
</td>
<td>
<img src="img/keys_101_kb.png" alt="�L�[�{�[�h" title="�L�[�{�[�h" />
</td>
</tr>
</table>
=end html
=begin

+ dvorak.key

  31, 32, 33, 34, 35, 36, 37, 38, 39, 30,
  de, bc, be, 50, 59, 46, 47, 43, 52, 4c,
  41, 4f, 45, 55, 49, 44, 48, 54, 4e, 53,
  ba, 51, 4a, 4b, 58, 42, 4d, 57, 56, 5a,
  20, db, dd, dc, bf, bb, bd, c0, e2,
=end

<table class="figure" summary="dvorak.key �̑Ή��̐}��">
<tr>
<td>
<img src="img/keys_dvorakj_vkb.png" alt="���z����" title="���z����" />
</td>
<td>
<img src="img/keys_dvorakj_kb.png" alt="�L�[�{�[�h" title="�L�[�{�[�h" />
</td>
</tr>
</table>

=begin html
<table class="figure" summary="dvorak.key �̑Ή��̐}��">
<tr>
<td>
<img src="img/keys_dvorake_vkb.png" alt="���z����" title="���z����" />
</td>
<td>
<img src="img/keys_dvorake_kb.png" alt="�L�[�{�[�h" title="�L�[�{�[�h" />
</td>
</tr>
</table>
=end
=begin




=== �e�[�u���t�@�C��

�e�[�u���t�@�C���́A���͕��� (T-Code �� TUT-Code �Ȃ�) �̒�`
���L�q�����t�@�C���ł��B

�g�p������͕����ɍ��킹�����̂�I�сA�����ݒ�t�@�C�� kanchoku.ini ��
(({tableFile})) �I�v�V�����Ŏw�肵�܂��B
�u����Win�v�̃p�b�P�[�W�Ɋ܂܂�Ă���e�[�u���t�@�C���́A���̂Ƃ���ł��B

* t.tbl �c T-Code
* tut.tbl �c TUT-Code
* g.tbl �c G-Code

�e�[�u���t�@�C�����J�X�^�}�C�Y����������A�Ǝ��̓��͕��������g���̕��́A
�ȉ��� ((<�e�[�u���t�@�C���̏���>)) ���Q�l�ɁA
�e�[�u���t�@�C�����L�q���Ă��g�����������B

==== �e�[�u���t�@�C���̏���

�ȉ��ɁA�e�[�u���t�@�C���̏��� (����) ��������܂��B

�e�[�u���t�@�C���́A��܂��Ɉȉ��̂悤�Ȍ`�����Ă��܂��B

  {
     <0> ,  <1> ,  <2> ,  <3> ,  <4> ,  <5> ,  <6> ,  <7> ,  <8> ,  <9> ,
    <10> , <11> , <12> , <13> , <14> , <15> , <16> , <17> , <18> , <19> ,
    <20> , <21> , <22> , <23> , <24> , <25> , <26> , <27> , <28> , <29> ,
    <30> , <31> , <32> , <33> , <34> , <35> , <36> , <37> , <38> , <39> ,
    <40> , <41> , <42> , <43> , <44> , <45> , <46> , <47> , <48>
  }

���Ȃ킿�A(({<0>})) �` (({<48>})) �� 49 �́u�Ȃ�炩�̗v�f�v���A
�R���} ((({,}))) �ŋ�؂��ĕ��ׁA
���̑S�̂𒆂����� ((({{})) �� (({(('}'))}))) �ň͂������̂ł��B
������A�Ȍ�A�u���b�N�ƌĂт܂��B

* �u�Ȃ�炩�̗v�f�v�́A��ʂɁA�ʂ̃u���b�N�܂��͓����`�ł��B
* �ł��O���̃u���b�N�̂��Ƃ��A((*���[�h�u���b�N*)) �ƌĂт܂��B
* [^[((<ver1.27g|�ύX����>))]^]((*���[�h�u���b�N*)) �́A������J��Ԃ����Ƃ��ł��A
  �g��������@�\�L�[��`�𕪗����ċL�q���邱�Ƃ��ł��܂��B
* �e�v�f�ƃR���}�A���������̊Ԃɂ́A�󔒂���s�����Ă��悢�悤�ł��B
* (({;})) �܂��� (({#})) ����s���܂ł́A�R�����g�Ƃ��ēǂ݂Ƃ΂���܂��B

�u���b�N�̒��̊e�v�f (({<n>})) ���A
���ꂼ��� ((<�L�[�ԍ�>)) �̃L�[�ɑΉ����Ă���A
���̕����ɁA�e�L�[�̋������L�q���܂��B

[^[((<ver1.27g|�ύX����>))]^]
�V�t�g�Ō���p������͕����̏ꍇ�A�e�v�f��
���ۂɂ� (�`(({,}))(({<n> / <Sn>}))(({,}))�`) �Ƃ����`����
2�̗v�f���w�肷��悤�ɂȂ��Ă���A(({<n>})) �Œʏ�Ō����́A(({<Sn>})) ��
�V�t�g�Ō����̋������L�q���܂��B(({/})) �ȍ~���ȗ����邱�Ƃ��ł��A�ȗ�����
�`���̂��̂��]���̃e�[�u���t�@�C���Ɠ����ɂȂ�܂��B

�e�L�[�̋����Ƃ��Ďw�肷��v�f�́A���̂����ꂩ�ł��B

:���`
  ���������Ȃ������ꍇ�́A���`�ƂȂ�܂��B

  ���̏ꍇ�A�Y���L�[�������Ă������N���炸�A�������͂���܂���
  (�����ɂ́A������Ԃ����Z�b�g����A�� 1 �Ō��҂��̏�ԂɂȂ�܂�)�B
  ��������`����Ă��Ȃ��L�[�ɂ́A���`���w�肵�܂��B

  �Ȃ��A���`���w�肷��ꍇ�ł��A��؂�̃R���}�͏ȗ��ł��܂���B

  [^[((<ver1.27g|�ύX����>))]^]���[�h�u���b�N�𕡐���J��Ԃ��ꍇ�A
  ���̃u���b�N�Œ�`�܂��͏㏑�������������ȊO�͋��`�ɂ��Ă��������B

:�u���b�N
  49 �̗v�f���R���} ((({,}))) �ŋ�؂��ĕ��ׁA
  �S�̂𒆂����� ((({{})) �� (({(('}'))}))) �ň͂������̂ł��B

  ���̑Ō��ɑ����悤�ȃL�[�ɂ̓u���b�N���w�肵�A
  ���̃u���b�N�̓����̊e�v�f�ɁA���̊e�Ō��̋������L�q���܂��B

:������
  (({"��"})) ���邢�� (({"��"})) �Ȃǂ̂悤�ɁA
  �_�u���N�H�[�g ((({"}))) �ň͂���
  ���� (�̗L���̕���) �ł��B
  ���̏ꍇ�A�Y������L�[��Ō�����ƁA�w�肵�����������͂���܂��B

  �Ȃ��A�������`���́u(({\}))�v�́A���� 1 �������G�X�P�[�v���܂��B
  �����u"�v���`����ɂ́u(({"\""}))�v�A
  �u\�v���`����ɂ́u(({"\\"}))�v�Ǝw�肵�Ă��������B

  ���݂̎d�l�ł́A
  �u(({\}))�v�͒P�Ȃ�G�X�P�[�v�ł���A�u(({\n}))�v��u(({\t}))�v��
  ���s��^�u�ɂ͂Ȃ�܂���B

:�����`
  ���񍇐��ϊ�����������ϊ��ȂǁA
  �e��̋@�\�ɑΉ������`�ł��B
  (({@b})) �� (({@m})) �Ȃǂ̂悤�ɁA(({@<����>})) �Ƃ����`�������Ă��܂��B

  ��q�� ((<�����`�̈ꗗ>)) ���Q�Ƃ��Ă��������B

:����`[^[((<ver1.27g|�ύX����>))]^]
  (({"-26>"})) �� (({"-S12>"})) �Ȃǂ̂悤�ɁA�}�C�i�X ((({-}))) ��
  �s���� ((({>}))) �ŃL�[�ԍ����͂������̂ł��B����`�̌��ɁA�L�[�ԍ���
  �w�肵���Ō��̋������w�肵�܂��B

  �V�t�g�Ō��� (({"S12"})) �̂悤�� (({"S"})) �����Ďw�肵�܂��B

���Ƃ��� T-Code �̏ꍇ�ł́A
���[�h�u���b�N�� 0 �` 39 �Ԃ̗v�f (�� 1 �Ō��ɑΉ�) �Ƀu���b�N���w�肵�A
���̊e�u���b�N�̒��� 0 �` 39 �Ԃ̗v�f (�� 2 �Ō��ɑΉ�) �ɕ������
�w�肷�邱�ƂɂȂ�܂��B
���ɁA
���[�h�u���b�N�̒��� 26 �Ԃ̃u���b�N�̒��� 23 �Ԃ̗v�f�ɂ�
���񍇐��ϊ� (({@b})) ���A
�܂� 23 �Ԃ̃u���b�N�̒��� 26 �Ԃ̗v�f�ɂ�
���������ϊ� (({@m})) ���w�肷�邱�Ƃ�
�Ȃ�܂��B

TUT-Code �� T-Code �̏ꍇ�Ɠ��l�ł����A
3 �X�g���[�N�� 4 �X�g���[�N�̕����ɑ΂��ẮA
���[�h�u���b�N���̊Y������v�f�ɁA2 �d���邢�� 3 �d�̓���q�̃u���b�N��
�w�肷�邱�ƂɂȂ�ł��傤�B



==== �����`�̈ꗗ

�����`�Ɏw��ł�����̂��A�ȉ��ɗ񋓂��܂��B
[ ] ���͉��z���Ղł̕\�����A
( ) ���́u����Win�v�̓����ł̖��O��\���Ă��܂��B

+ ���[�h�ނ̓����`
:(({@Z})) [((%�S%))] (((|F_HANZEN|)))
  ((<�S�p���[�h>)) �̐؂�ւ��ł��B
  �S�p���[�h�ł́A
  �e�[�u���Œ�`���ꂽ�����̂����A
  ���p���� (ASCII ����) �ƑΉ�����S�p���������ݕϊ�����ē��͂���܂��B
  [:del:]�Ȃ��A���p���Ȃɂ͑Ή����Ă��܂���B[:/del:]
  ((<�����ݒ�t�@�C��>)) �� (({enableHankakuKana=1})) �I�v�V�������w�肷��ƁA
  ���p���Ȃɂ��Ή����܂��B[^[((<ver1.27f|�ύX����>))]^]
:(({@K})) [((%�A%))] (((|F_HIRAKATA|)))
  ((<�������ȃ��[�h>)) �̐؂�ւ��ł��B
  �������ȃ��[�h�ł́A
  �e�[�u���Œ�`���ꂽ�����̂����A
  �Ђ炪�ȂƂ������Ȃ����ݕϊ�����ē��͂���܂��B
:(({@s})) [((%��%))] (((|F_SWITCH_MODE|)))
  (({@K})) �Ɠ����Ӗ��ɂȂ�܂��B
:(({@p})) [((%��%))] (((|F_PUNCT|)))
  ((<��Ǔ_�̐؂�ւ�>)) �ł��B
  �e�[�u���Œ�`���ꂽ�����̂����A�u�A�B�v�Ɓu�C�D�v��
  ���ݕϊ�����ē��͂���܂��B

+ �O�u�^�̕ϊ��̓����`
:(({@b})) [((%��%))] (((|F_BUSHU_PRE|)))
  �O�u�^�� ((<���񍇐��ϊ�>)) ���J�n���܂��B
:(({@m})) [((%��%))] (((|F_MAZE_PRE|)))
  �O�u�^�� ((<���������ϊ�>)) ���J�n���܂��B
:(({@!})) [((%��%))] (((|F_HIST|)))
  ((<�q�X�g������>)) ���[�h�ɓ���܂��B

+ ����̓����`
:(({@q})) [((%�~%))] (((|F_QUIT|)))
  ���񍇐��ϊ����[�h����������ϊ����[�h�𒆒f���A
  �ʏ�̓��̓��[�h�ɖ߂�܂�

+ ��u�^�̕ϊ��̓����`
:(({@B})) [((%��%))] (((|F_BUSHU_POST|)))
  ((<��u�^�̕��񍇐��ϊ�>)) �ł��B
:(({@1})) �` (({@9})) [((%��%))] (((|F_MAZE_POST1|)) �` ((|F_MAZE_POST9|)))
  ���ꂼ��A�ǂ݂̒����� 1 ���� �` 9 ������ ((<��u�^�̌��������ϊ�>)) �ł��B
:(({@D})) [((%�J%))] (((|F_DAKUTEN|)))
  ��u�^�̑��_�ł��B
:(({@P})) [((%�K%))] (((|F_HANDAKUTEN|)))
  ��u�^�̔����_�ł��B

+ �����w���v�̓����`
:(({@h})) [((%��%))] (((|F_HELP_BACKW|)))
  ���O�� ((<�����w���v>)) ���ĕ\�����܂��B
  �����Ď��s����ƁA�w���v�����������̂ڂ��ĕ\�����܂��B
:(({@H})) [((%��%))] (((|F_HELP_FORW|)))
  ���O�� ((<�����w���v>)) ���ĕ\�����܂��B
  �����Ď��s����ƁA(({@h})) �̋t�����ɕ\�����܂��B

+ �L�[���͂̓����`
:(({@v})) [((%�E%))] (((|F_VERB_FIRST|)))
  �ŏ��̃X�g���[�N�̃L�[����͂��܂��B
  T-Code �̑� 2 �Ō��� ((%Space%)) �Ɏw�肷��Ƃ悢�ł��傤�B
  �Ȃ��A�� 1 �Ō��Ƃ��Ďw�肳�ꂽ�ꍇ�́A���̑Ō����̂��̂���͂��܂��B



==== ���͕����ɌŗL�̐ݒ�

[^[((<ver1.27e|�ύX����>))]^]
�u(({#define ((|...|))}))�v�̌`���̍s�w��ŁA
���͕����ɌŗL�̐ݒ���s�����Ƃ��ł��܂��B
���݁A�ȉ��̃I�v�V�������ݒ�\�ł��B

:(({#define table-name "((|name|))"}))
  ���͕����̖��O���A
  (({"T"})), (({"TUT"})), (({"G"}))�Ȃǂ̂悤�Ɏw�肵�܂��B
  �w�肵�����O�́A�u����Win�v�̃^�C�g���o�[�ɕ\������܂��B

:(({#define prefix ((|spec|))}))
  Try-Code �� TT-Code �Ȃǂ́A�v���t�B�b�N�X�g���^�̓��͕����ɂ�����A
  �����w���v�̕\���w��ł��B
  * Try-Code �̏ꍇ
      #define prefix /��/40/����/��/
  * TT-Code �̏ꍇ
      #define prefix /��/26,23/����/��/:/��/23,26/����/��/
  �u�g���\���\���镶�� (�������ŗ��p�����)�v
  �u�g���v���t�B�b�N�X�̃L�[�ԍ� (�R���}��؂�)�v
  �u((*base stroke*))
  (�g���v���t�B�b�N�X�������������̊e�Ō�) ��\������ (���ł��珇�ɕ��ׂ�)�v
  �ubase stroke �ł̓�d�Ō��� (���������) �O�d�Ō���\������ (���ׂ�)�v
  ���A�X���b�V���ŋ�؂��Ďw�肵�܂��B
  �w�肪��������ꍇ�́A�R�����ŋ�؂��ĕ��ׂ܂��B

  [^[((<ver1.27g|�ύX����>))]^]�V�t�g�Ō��� (({"S12"})) �̂悤�� (({"S"})) �����Ďw�肵�܂��B


:(({#define defguide "((|string|))"}))
  ((<�����ݒ�t�@�C��>)) �� ((<(({defg=((|string|))}))>)) �Ɠ��l�ł��B
  ���Ƃ��΁Aphoenix �z���((*�z���ē�*))�͎��̂悤�Ɏw�肵�܂��B
    #define defguide "����t���M���ۋU����|������G���֏Y����y�őW�������Փw���J�������ʖj���B����"
  (({defg=((|string|))})) �Ɠ����Ɏw�肳�ꂽ�ꍇ�́A
  (({defg=((|string|))})) �̐ݒ肪�D�悳��܂��B


=end