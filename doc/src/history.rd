=begin

== �ύX����

:ver 1.27g (2009-10-18�`)
  * �V�t�g�Ō���p������͕����ɑΉ�:
  * �e�[�u���t�@�C���̏������g��:
  * �O�����͕⏕�@�\:
  * �������K���[�h:
  * �V�t�g�Ō��ɂ��X�g���[�N���b�N�@�\:
  * ����Win��OFF�ɂ����Ƃ��Ɋe�탂�[�h��������ԂɃ��Z�b�g����: (({offResetModes=((|nnn...|))})) �I�v�V����
    (�،����� [offResetModes])
  * (({offHide=2})) �̏�Ԃ���ꎞ�I�ɃE�B���h�E��\������@�\: (({@w})) �����`
    (�،����� [tmpshowwin])
  * ((%BackSpace%)) �ŃX�g���[�N�P�ʂ̏���: (({weakBS=1})) �I�v�V����
  * ���Ō������L�[����͂���: (({@w})) �����`
  * ���z���Ղ̔z�F�E�t�H���g�̃J�X�^�}�C�Y�@�\: kwstyle.exe
  * (({useCtrlKey=1})) �̏ꍇ�� XKeymacs �Ƃ̓����g�p���̖����C��:
  * C-h ���� XKeymacs �Ɠ��l�̕��@�ŏ�������B���I�v�V����: (({useCtrlKey=2})) �I�v�V����
    ([�����X��4:253])
  * ((%BackSpace%)) ���� @v �̃L�[���o�� keybd_event() ��p����: (({outputVKeyMethod=1})) �I�v�V����
  * �������o���@�� WM_UNICHAR ��ǉ�:
  * Unicode �����ւ̑Ή��̃e�X�g�R�[�h(���ړ��͂̂݁AU+0080�`U+3FFF����): (({outputUnicode=1})) �I�v�V����
  * �n��K�C�h�Ɂu���A���A���v�Ȃǂ���͂��܂�n���o�^���Ă�
    ���������\������Ȃ��o�O��fix: ([�����X��4:132])
  * �n��K�C�h��L���ɂ��Ȃ��� defguide�iphoenix �z��̔z���ē����j��
    �\������Ȃ������C��:
  * (({@v})) �� ((%Tab%)) ���g����"h"����͂����Ƃ��ɓ����o�b�t�@��
    �Ԉ���Ĉꕶ���폜����Ă��܂������C��:
  * Visual Studio 2008 �ŃR���p�C�����ʂ�悤�ɏC��:

:ver 1.27f-20060325 (2006-03-25)
  * Word �̐}�\�ԍ��}���_�C�A���O�ŕ�����������o�O�̏C��:
    (�،����� [tcode-ml:2665])

:ver 1.27f (2006-03-03)
  * ���񍇐��ϊ��̉��ǃA���S���Y��:
    (({bushuAlgo=YAMANOBE})) �I�v�V����
    (�R�ӂ��� [tcode-ml:2652,2662])
  * ���p�`�̌��������ϊ�:
    (({conjugationalMaze=2})) �I�v�V����
    (�R�ӂ��� [tcode-ml:2644--2645])
  * �t�b�N�� ImmSetCompositionString �̑g�ݍ��킹�ɂ�镶�����o�A�����
    �E�B���h�E�N���X���ƂɈقȂ镶���̑��o���@�̃T�|�[�g:
    (�،�����A����юR�ӂ��� [tcode-ml:2625--2634])
  * �I�v�V�������ύX: (({useWMIMECHAR})) �� (({outputMethod}))
  * Firefox 1.5 �� BackSpace �� 2 ������������Ă��܂����̑Ώ�:
    (�،����� [tcode-ml:2625])
  * ���p���ȕϊ�: (({enableHankakuKana=1})) �I�v�V����
  * ���͂̓��v: 
    (({record=((|file|))})), (({stat=((|file|))})) �I�v�V����

:ver 1.27e (2004-12-12)
  * phoenix �z��̔z���ē� (�R�ӂ��� [tcode-ml:2580,2583]):
    �u(({defg="..."}))�v�I�v�V�����V�݁B
  * �n��K�C�h�����̏����g�� (�R�ӂ��� [tcode-ml:2580,2583]):
    ��s�Ń}�b�`�Ώۃp�^�[���𕡐��w��B
  * �N���� (�I�t���) �ɃE�B���h�E���B�� (�،����� [tcode-ml:2579]):
    �V���[�g�J�b�g�̃v���p�e�B�́u���s���̑傫���v��
    �ŏ������w�肵�A�u(({offHide=1}))�v�I�v�V�������w��B
  * phoenix.tbl: �p�����E�L���Ɣz���ē��ݒ���܂ށBGPL �K�p�B
  * tt.tbl: prefix �w����܂ށBGPL �K�p�B
  * �e�[�u���t�@�C���̏����g�� (�b��):
    �u(({#define {table-name,prefix,defguide} ((|arg|))}))�v
  * ���p/�S�p �̘A�z�e�[�u���̌����C��

:ver 1.27d (2004-08-10)
  * ���r�s����ɂ��ȉ��̕ύX [tcode-ml:2572]
    * VC6 �̃v���W�F�N�g�t�@�C�� (kanchoku.dsw, kanchoku.dsp)
    * VC6 �ŃR���p�C�����ʂ� (no error, no warning)
    * ON/OFF �̃z�b�g�L�[�Ƃ��āACTRL�Ȃǂ̏C���L�[�Ȃ����g����
      (�u(({unmodifiedHotKey=((|xx|))}))�v�I�v�V�����V��)
    * �q�X�g���֌W�̖��������ȂǁA�������̃o�O�t�B�b�N�X
  * �}�j���A���X�V

:ver 1.27c (2003-12-28)
  * �O�u�^�ϊ����̌�u�^�ϊ� (�u�A�K�X��2�v99�� [590-591])
  * �e��o�O�t�B�b�N�X (�u�A�K�X��2�v99 ��)
    * �L�[���s�[�g���̓���̉��P ([517])
    * 256 �F���ł̕\���̉��P ([522,537-538])
    * IE �� 1 �s���̓t�H�[���̒��� - �Ƃ� \ �Ƃ��̒��ړ��� ([616])
  * �u(({offHide=2}))�v�I�v�V����:
    ���[�h ON �������z���Ղ��\��
    (���b��@�\�Anews.txt ��}�j���A���ɂ͖��L��)�B
    (�u�A�K�X��2�v[614,619])

:ver 1.27b (2003-12-09)
  * tut.tbl: �u(({als})) (({@B}))�v�̒�`�̒E���̏C�� 
    (�،��p�l���� [tcode-ml:2450])
  * src/moji.c (tblHandaku): ��������`�́u��/���v�u��/���v�u��/���v��
    �E�����C���B
  * phoenix.tbl: 
    ���J�m������� 
    ((<phoenix �z��|URL:http://www.h5.dion.ne.jp/~y_hagiya/hairetsu.html>))
    �̃e�[�u���t�@�C���ǉ��B
  * �g�p�R���p�C��: Borland C++ 5.5 -> 5.5.1

:ver 1.27a (2003-10-04)
  * �n��K�C�h�@�\�ǉ� (�u�A�K�X��2�v99 �� [102-106,208-209,211-212,240-241])
  * �V�݃I�v�V�����u(({outputSleep=((|n|))}))�v
    (�u�A�K�X��2�v[99?])
  * �u(({shiftKana=1}))�v���̃V�t�g�Ō��̈����̉��P
    (�،��p�l���� [tcode-ml:2438])
  * ���񍇐����� kwbushu.rev �̔��p/�S�p�����̓�����`�̌��̏C��
  * �}���j�A�����X�V

:ver 1.27 (2003-08-28)
  * 1.26eb �ł����ƂɊg�� ([tcode-ml:2437])
    * �ċA�I�ȑO�u�^�ϊ�
    * �q�X�g�����͋@�\
    * ���p��̌��������ϊ�
    * �V�t�g�Ō��ɂ�邩�����ȓ���
    * �L�����b�g�Ǐ]�@�\ (�u�A�K�X���v816 ��)
    * ���o���b�Z�[�W�Ƃ��� WM_CHAR ���f�t�H���g��
    * �f�U�C���ύX
    * �u�����v�̃N���[���\�t�g�u�������v��t��
    * �V�����@�\�ɑΉ������}�j���A��

:(ver 1.26eb) (2002-05-05) (�k���� [tcode-ml:2207])
  * ((<kw126eb-20020505.zip|URL:http://openlab.jp/tcode/soft.html>)) �Ƃ���
    �p�b�P�[�W��

:ver 1.26eb (2002-04-25) (�،��p�l [tcode-ml:2151])
  * ���񍇐��ϊ��@�\ (�O�u�^�E��u�^) �̒ǉ�
  * ��u�ϊ��Ɋւ���o�O�̏C��

:ver 1.26e (2002-01-15) (�䂹�悵�Ђ� [tcode-ml:2054])
  * �L�[���́E�}�E�X����̕ύX
  * ��u�^���������ϊ��@�\ (�������w��) �̒ǉ�
  * �����w���v�@�\�̒ǉ�

:ver 1.26 (2000-06-10) (�����G��)
  * ((<"�u����Win�v�̃I���W�i����"|URL:http://t.pos.to/tc/kanchoku.html>))
  * (�o�[�W���� 1.26 �ȑO�̗����́A�I���W�i���ł̃h�L�������g
    kanchoku.txt ���Q��)

=end
