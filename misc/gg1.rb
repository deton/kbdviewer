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
# gg1.rb
# --------

while gets
  chop!
  while $_ =~ /^..+$/
    if $_ =~ /[^��-��]$/ && $_ !~ /^[��-��].$/
      print $_.gsub(/.$/, ' /\&')
      print "\r\n"
    end
    chop!
    chop!
  end
end

# --------
