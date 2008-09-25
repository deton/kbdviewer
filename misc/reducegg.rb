#!/usr/local/bin/ruby -Ks
#
# reducegg.rb - �o�����������A�n��K�C�h��������폜
#
# usage: ruby reducegg.rb CERTAIN kwgg.dic > mygg.dic
#
# 2003-09-29
#	* �n��K�C�h�����̐V�t�H�[�}�b�g (�w�A�K�X�� 2�x208-212) �ɑΉ�
#	* ���ɁA��₪��ɂȂ����G���g���͍폜
# 2003-09-28
# 	* fisrt ver.

# �o���������̃��X�g
$certains = Array::new;

if ARGV.length <= 0 then
  $stderr.puts "usage: #{$0} CERTAIN [gg_dictionary]"
  exit 2
end

# CERTAIN ��ǂ݂���
open(ARGV.shift) do |f|
  while line = f.gets do
    line.strip.split(//).each do |k|
      $certains.push(k) if /\s/ !~ k
    end
  end
end
$certains = $certains.sort.uniq

# �n��K�C�h������ǂݍ��݁A���H���Ȃ���A�o�͂���
while line = gets do
  line.chomp!
  case line
  when /^([^ \/]+) \/(.*)$/
    # new format GG-dic
    leader, trailers = $1, $2.split(//)
    trailers.delete_if do |k|
      $certains.include?(k)
    end
    puts(leader + " /" + trailers.join("")) if 0 < trailers.length

  when /^(.)(.*)$/
    # old format GG-dic
    leader, trailers = $1, $2.split(//)
    trailers.delete_if do |k|
      $certains.include?(k)
    end
    puts(leader + trailers.join("")) if 0 < trailers.length

  else
    # invalid line
    $stderr.puts " skipped: #{line}"
  end # case line
end
