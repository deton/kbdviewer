=begin

== �͂��߂�

=== �u����Win�v�Ƃ�

�u����Win�v�́AWindows ���((*�������ړ���*))���s�����߂̃c�[���ł��B
((<�����G��|URL:http://t.pos.to/tc/>)) ����ɂ���č쐻����A
���� T-Code ���[�����O���X�g�Ȃǂɂ����ĉ��ǂ��������Ă��܂��B

���̃h�L�������g�ł́A�u����Win�v�o�[�W���� 1.27 �ɂ��ĉ�����܂��B

�u����Win 1.27�v�̎�ȓ����́A���̂Ƃ���ł��B

* T-Code, TUT-Code, G-Code ���g���܂��B
* ((<���񍇐��ϊ�>))�A((<���������ϊ�>))�A((<�q�X�g������>))
  �Ȃǂ̕⏕���͂��g���܂��B�ċA�I�ɑg�ݍ��킹�邱�Ƃ��\�ł��B
* �⏕���͂��������̃R�[�h��\������((<�����w���v>))�����p�ł��܂��B
* ((<�n��K�C�h>))�̓��͕⏕�����p�ł��܂��B[^[((<ver1.27a|�ύX����>))]^]
* ((<���͂̓��v>))���L�^���邱�Ƃ��ł��܂��B[^[((<ver1.27f|�ύX����>))]^]

�Ȃ��A�����ł͊������ړ��͂��̂��̂ɂ��Ă͐G��܂���B
�������ړ��͂ɂ��ẮA((<�֘A URL>)) ���Q�Ƃ��Ă��������B

=== �����

Windows95 �ȍ~�� Windows �œ��삷����̂Ǝv���܂��B

=== ��������

�u����Win�v�́A�܂��Ƃ��� IME �ł͂Ȃ��A
WM_CHAR �Ȃǂ̃��b�Z�[�W�𑗂���邱�Ƃŕ�������͂���
�Ƃ������@���Ƃ��Ă��܂��B
���������āA���̂悤�ȃ��b�Z�[�W�ɑΉ����Ă��Ȃ��\�t�g�ł́A
�u����Win�v�𗘗p���邱�Ƃ͂ł��܂���B

���Ƃ��΁A�R�}���h�v�����v�g (MS-DOS �v�����v�g) �ł́A
���͂��s�����Ƃ��ł��܂���B

���ɁAWindows 95/98/Me �Ȃǂ� MS-DOS �v�����v�g�ł́A
�u����Win�v�œ��͂��悤�Ƃ���ƁA
�R���s���[�^�����΂炭���͂��󂯂��Ȃ��Ȃ邱�Ƃ�����܂��B
((*((*MS-DOS �v�����v�g���g�p���鎞�́A
�K���u����Win�v�� OFF �� ���Ă��������B*))*))
MS-DOS �v�����v�g�ł́A
�u����Win�v�̃g�O���L�[ (((%Ctrl%))+((%\%))) ���g���܂���̂ŁA
�u����Win�v�̃E�B���h�E���N���b�N���� OFF �ɂ��Ă��������B

=== �g�p����

���̃\�t�g��((*����*))�A((*���ۏ�*))�ł��B

�u����Win�v�o�[�W���� 1.27 �̌��^�ł���A
�I���W�i���ł́u����Win�v�o�[�W���� 1.26
(((<�����G��|URL:http://t.pos.to/tc/>)) ����� web �y�[�W������\�� 
kanwin126.zip) �̎g�p�����́A
���p�b�P�[�W�Ɋ܂܂��h�L�������g kanchoku.txt �ɂ��ƁA
�ȉ��̂悤�Ȃ��̂ł��B

kanchoku.txt
  ���\�t�g�̎g�p����
    ���̃\�t�g�͎g�p���z�z�����R�ł����A���̃\�t�g���g�p�������Ƃɂ����
  ������肪�������Ă��A��҂��֌W�҂��Ȃ��ӔC�𕉂��܂���B���ȐӔC��
  �g�p���Ă��������B

����A�u����Win�v�o�[�W���� 1.27 �̕��񍇐��ϊ��̃R�[�h 
(bushu_dic.c) �́A
((<"tserv-0.2"|URL:http://www.tcp-ip.or.jp/~tagawa/archive/>)) �� comp.c 
�Ɋ�Â����̂ł���A
����ɂ��� comp.c �́A
((<"GNU GPL"|URL:http://www.gnu.org/licenses/gpl.html>))
���C�Z���X�� tc.el �����^�Ƃ��Ă���Ƃ���܂��B

bushu_dic.c
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

�ȏ�̂��Ƃ���A���ʂƂ��āA�u����Win�v1.27 �̗��p�́A
((<"GNU GPL"|URL:http://www.gnu.org/licenses/gpl.html>)) ��
�]���ׂ����̂ƍl�����܂��B

=end
