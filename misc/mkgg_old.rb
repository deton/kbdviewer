#!/usr/local/bin/ruby -Ks
#
# mkgg.rb - �n��K�C�h���� (���`��) ���쐬
#
# usage: ruby mkgg.rb kwmaze.dic > gg.dic
#        ruby mkgg.rb general_text_file > gg.dic
#
# �����Ӂ�
#
# ����́A���`���̏n��K�C�h�����A���Ȃ킿�A
#   �w�y�����zT-Code/TUT-Code�X�� Lesson2�y�A�K�z�x
#   <http://pc.2ch.net/test/read.cgi/unix/1061936143/>
# �� 102-106 ���̃R�[�h�̏n��K�C�h�@�\�p�̎������쐬����X�N���v�g�ł��B
#
# �����ǂ����̘A�Ȃ�A�񕶎��A���݂̂��A�����ΏۂƂ��Ă��܂��B
# ���Ȃ�u�Y�X�Z�v�ȊO�̋L���ނ͖�������܂��B
#
# �V�ł̏n��K�C�h�@�\ (��L�X���� 208-212 ���̃R�[�h) �ł�
# ���`���̎����𗘗p���邱�Ƃ́A�\�Ȃ悤�ł����A���Ԃ�񐄏��ł��B
#
# 2003-09-28
#	* first ver.

KanjiPat = /[�Y�X�Z��-�r��-�]/

$gghash = Hash::new

# --------------------------------------------------------------------
# methods

def add2gg(leader, trailer)
  if $gghash[leader].nil? then
    $gghash[leader] = Hash::new
  end
  if ($gghash[leader])[trailer].nil? then
    ($gghash[leader])[trailer] = 0
  end
  ($gghash[leader])[trailer] += 1
end

def outputgg
  $gghash.sort.each do |leader, trailers|
    t = trailers.to_a.sort { |va, vb|
      va[1] <=> vb[1]
    } .reverse.collect { |v|
      v[0]
    }
    puts "#{leader}#{t.join}"
  end
end

# --------------------------------------------------------------------
# main

while line = gets
  line.chomp!

  ary = line.split(//)
  while 2 <= ary.length
    if KanjiPat =~ ary[0] && KanjiPat =~ ary[1] then
      add2gg(ary[0], ary[1])
    end
    ary.shift
  end
end

outputgg
