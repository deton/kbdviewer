#!/usr/local/bin/ruby -Ks

# From: [211] 99 <sage>
# Date: 03/09/28 02:33
# 
# ���Ȃ݂Ɏ����̃t�H�[�}�b�g���g�����܂����B
# 
# �����쐬�X�N���v�g�̎g����
# �E1�P�ꂲ�Ƃɉ��s���Ă���t�@�C�������B
# �ikwmaze.dic����Ȃ�s���̃L�[����������"/"�����s�ɒu������Ƃ��j
# �E����2�̃t�@�C����gg1.rb�Agg2.rb�Ƃ��ĕۑ��B
# �E���
# ruby -Ks gg1.rb ���t�@�C�� | sort | uniq | ruby -Ks gg2.rb > �����t�@�C��
# 
# �c�cperl����Ȃ��Ă��߂�Ȃ����B
# 
# From: [212] 99 <sage>
# Date: 03/09/28 02:33
# 
# gg2.rb
# --------

key = ""
while gets
  chop!
  if key.length > 0 && key.length+2 == $_.length && key == $_[0,key.length]
    print $_[-2..-1]
  else
    if key.length > 0
      print "\r\n"
    end
    key = $_.chop
    key.chop!
    print key
    print $_[-2..-1]
  end
end
print "\r\n"

# --------
