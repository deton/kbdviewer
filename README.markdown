# kbdviewer: 打鍵表示ツール

物理キーボードで打ったキーを、スクリーンキーボードで表示するツールです。

以下のように、アプリの操作例をアニメーションGIFで作成する際に、
どのキーを操作しているかを表示するために使うのが目的です。

![使用例](tsftutcode-userbushudic-ivs.gif)

* tsf-tutcodeの使用例に使いたかったので、KeyCastOWのように文字を表示するよりも、キーボード上の位置を表示したくて作成。
* [漢直Win](https://github.com/kanchoku/kw)を少しだけ変更したものです。
* 少し検索した限りでは、同様のツールを見つけられなかったので作成。
 + その後、[まじかるキーボード](http://www.pluto.dti.ne.jp/araki/soft/old.html)を見つけました
 + ([姫踊子草](http://www.vector.co.jp/magazine/softnews/110415/n1104151.html)の、補助鍵盤画像で、「キー操作を表示する」と同様のことができるかも。)

## 使い方・動作
1. 起動して`Ctrl+\`や右クリックでオンに切り替えてください。
2. その後、物理キーボードでキーを打つと、打ったキーの背景色を100ms間変えて表示します。

オンにすると各キーに対してRegisterHotKey()をします。
キーが打たれた時に送られてくるWM_HOTKEYをもとに表示を行うとともに、
keybd_event()を発行してIMEやアプリにキーを送ります。

### 設定
* テンキーを表示する: kanchoku.ini で numpad=1 を設定。
![テンキー表示例](numpad.gif)
* 文字サイズを変更する: kwstyle.exe を起動してFontサイズを変更。(kanchoku.iniのstyle_fontsizeに反映される)

## 制約、既知の問題
* AltキーやPageUp/PageDown/Home/End/Delキー等は未対応
* ShiftキーやCtrlキーとの組み合わせは、Shift+文字キーやCtrl+文字キーのみ対応。Shift+TAB、Ctrl+←等やShift+Ctrl+文字等には未対応
* 他プログラムでRegisterHotKey()されているキーはうまく動作しない場合あり
* kbdviewerウィンドウ移動後に、キー送り付けがうまく動かなくなる場合あり。一度kbdviewerを終了してみてください

もっとましな形で作るなら、WH_KEYBOARD_LLを使う形にしたり、
[Carnac](https://github.com/Code52/carnac)を改造したり、
[pyHook](https://sourceforge.net/projects/pyhook/)を使うのが良いかもしれません。

## 参考
* [キー入力を表示しながらスクリーンショットGifを撮る](http://rcmdnk.github.io/blog/2014/08/01/computer-mac-windows/#windows)
 * Macのキーボードビューアには押したキーを表示する機能があるようですが、WindowsのスクリーンキーボードはShiftキー等しか表示してくれない模様
* [まじかるキーボード](http://www.pluto.dti.ne.jp/araki/soft/old.html)、[はっとけキーボード](http://www.pluto.dti.ne.jp/araki/soft/hattoke.html)
* [NohBoard](https://sourceforge.net/projects/nohboard/)、[NohBoard ReWrite](https://github.com/ThoNohT/NohBoard)
* [StreamKB](http://sourceforge.net/projects/streamkb)、[OnScreenKeyboardDisplay](http://sourceforge.net/projects/oskd)
* その他KeyboardTestツール等
