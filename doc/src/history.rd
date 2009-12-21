=begin

== 変更履歴

:ver 1.27g (2009-10-18〜)
  * シフト打鍵を用いる入力方式に対応:
  * テーブルファイルの書式を拡張:
  * 外字入力補助機能:
  * 強制練習モード:
  * シフト打鍵によるストロークロック機能:
  * 漢直WinをOFFにしたときに各種モードを初期状態にリセットする: (({offResetModes=((|nnn...|))})) オプション
    (木原さん [offResetModes])
  * (({offHide=2})) の状態から一時的にウィンドウを表示する機能: (({@w})) 特殊定義
    (木原さん [tmpshowwin])
  * ((%BackSpace%)) でストローク単位の消去: (({weakBS=1})) オプション
  * 今打鍵したキーを入力する: (({@w})) 特殊定義
  * 仮想鍵盤の配色・フォントのカスタマイズ機能: kwstyle.exe
  * (({useCtrlKey=1})) の場合や XKeymacs との同時使用時の問題を修正:
  * C-h 等を XKeymacs と同様の方法で処理する隠しオプション: (({useCtrlKey=2})) オプション
    ([漢直スレ4:253])
  * ((%BackSpace%)) 等や @v のキー送出に keybd_event() を用いる: (({outputVKeyMethod=1})) オプション
  * 文字送出方法に WM_UNICHAR を追加:
  * Unicode 文字への対応のテストコード(直接入力のみ、U+0080〜U+3FFF限定): (({outputUnicode=1})) オプション
  * 熟語ガイドに「園、死、ム」などからはじまる熟語を登録しても
    いっさい表示されないバグをfix: ([漢直スレ4:132])
  * 熟語ガイドを有効にしないと defguide（phoenix 配列の配字案内等）が
    表示されない問題を修正:
  * (({@v})) や ((%Tab%)) を使って"h"を入力したときに内部バッファが
    間違って一文字削除されてしまう問題を修正:
  * Visual Studio 2008 でコンパイルが通るように修正:

:ver 1.27f-20060325 (2006-03-25)
  * Word の図表番号挿入ダイアログで文字化けするバグの修正:
    (木原さん [tcode-ml:2665])

:ver 1.27f (2006-03-03)
  * 部首合成変換の改良アルゴリズム:
    (({bushuAlgo=YAMANOBE})) オプション
    (山辺さん [tcode-ml:2652,2662])
  * 活用形の交ぜ書き変換:
    (({conjugationalMaze=2})) オプション
    (山辺さん [tcode-ml:2644--2645])
  * フックと ImmSetCompositionString の組み合わせによる文字送出、および
    ウィンドウクラスごとに異なる文字の送出方法のサポート:
    (木原さん、および山辺さん [tcode-ml:2625--2634])
  * オプション名変更: (({useWMIMECHAR})) → (({outputMethod}))
  * Firefox 1.5 で BackSpace で 2 文字消去されてしまう問題の対処:
    (木原さん [tcode-ml:2625])
  * 半角かな変換: (({enableHankakuKana=1})) オプション
  * 入力の統計: 
    (({record=((|file|))})), (({stat=((|file|))})) オプション

:ver 1.27e (2004-12-12)
  * phoenix 配列の配字案内 (山辺さん [tcode-ml:2580,2583]):
    「(({defg="..."}))」オプション新設。
  * 熟語ガイド辞書の書式拡張 (山辺さん [tcode-ml:2580,2583]):
    一行でマッチ対象パターンを複数指定可。
  * 起動時 (オフ状態) にウィンドウを隠す (木原さん [tcode-ml:2579]):
    ショートカットのプロパティの「実行時の大きさ」で
    最小化を指定し、「(({offHide=1}))」オプションを指定。
  * phoenix.tbl: 英数字・記号と配字案内設定を含む。GPL 適用可。
  * tt.tbl: prefix 指定を含む。GPL 適用可。
  * テーブルファイルの書式拡張 (暫定):
    「(({#define {table-name,prefix,defguide} ((|arg|))}))」
  * 半角/全角 の連想テーブルの誤りを修正

:ver 1.27d (2004-08-10)
  * 岡俊行さんによる以下の変更 [tcode-ml:2572]
    * VC6 のプロジェクトファイル (kanchoku.dsw, kanchoku.dsp)
    * VC6 でコンパイルが通る (no error, no warning)
    * ON/OFF のホットキーとして、CTRLなどの修飾キーなしも使える
      (「(({unmodifiedHotKey=((|xx|))}))」オプション新設)
    * ヒストリ関係の未初期化など、いくつかのバグフィックス
  * マニュアル更新

:ver 1.27c (2003-12-28)
  * 前置型変換中の後置型変換 (「連習スレ2」99氏 [590-591])
  * 各種バグフィックス (「連習スレ2」99 氏)
    * キーリピート時の動作の改善 ([517])
    * 256 色環境での表示の改善 ([522,537-538])
    * IE の 1 行入力フォームの中で - とか \ とかの直接入力 ([616])
  * 「(({offHide=2}))」オプション:
    モード ON 時も仮想鍵盤を非表示
    (※暫定機能、news.txt やマニュアルには未記載)。
    (「連習スレ2」[614,619])

:ver 1.27b (2003-12-09)
  * tut.tbl: 「(({als})) (({@B}))」の定義の脱落の修正 
    (木原英人さん [tcode-ml:2450])
  * src/moji.c (tblHandaku): 半濁音定義の「う/ヴ」「か/ヵ」「け/ヶ」の
    脱落を修正。
  * phoenix.tbl: 
    萩谷洋治さんの 
    ((<phoenix 配列|URL:http://www.h5.dion.ne.jp/~y_hagiya/hairetsu.html>))
    のテーブルファイル追加。
  * 使用コンパイラ: Borland C++ 5.5 -> 5.5.1

:ver 1.27a (2003-10-04)
  * 熟語ガイド機能追加 (「連習スレ2」99 氏 [102-106,208-209,211-212,240-241])
  * 新設オプション「(({outputSleep=((|n|))}))」
    (「連習スレ2」[99?])
  * 「(({shiftKana=1}))」時のシフト打鍵の扱いの改善
    (木原英人さん [tcode-ml:2438])
  * 部首合成辞書 kwbushu.rev の半角/全角文字の等価定義の誤りの修正
  * マュニアル微更新

:ver 1.27 (2003-08-28)
  * 1.26eb 版をもとに拡張 ([tcode-ml:2437])
    * 再帰的な前置型変換
    * ヒストリ入力機能
    * 活用語の交ぜ書き変換
    * シフト打鍵によるかたかな入力
    * キャレット追従機能 (「連習スレ」816 氏)
    * 送出メッセージとして WM_CHAR をデフォルトに
    * デザイン変更
    * 「漢索板」のクローンソフト「漢索窓」を付属
    * 新しい機能に対応したマニュアル

:(ver 1.26eb) (2002-05-05) (北嶋暁 [tcode-ml:2207])
  * ((<kw126eb-20020505.zip|URL:http://openlab.jp/tcode/soft.html>)) として
    パッケージ化

:ver 1.26eb (2002-04-25) (木原英人 [tcode-ml:2151])
  * 部首合成変換機能 (前置型・後置型) の追加
  * 後置変換に関するバグの修正

:ver 1.26e (2002-01-15) (ゆせよしひろ [tcode-ml:2054])
  * キー入力・マウス操作の変更
  * 後置型交ぜ書き変換機能 (文字数指定) の追加
  * 文字ヘルプ機能の追加

:ver 1.26 (2000-06-10) (徳岡宏樹)
  * ((<"「漢直Win」のオリジナル版"|URL:http://t.pos.to/tc/kanchoku.html>))
  * (バージョン 1.26 以前の履歴は、オリジナル版のドキュメント
    kanchoku.txt を参照)

=end
