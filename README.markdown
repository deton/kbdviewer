# kbdviewer: 打鍵表示ツール

物理キーボードで打ったキーを、スクリーンキーボードで表示するツールです。

以下のように、アプリの操作例をアニメーションGIFで作成する際に、
どのキーを操作しているかを表示するために使うのが目的です。

![使用例](tsftutcode-userbushudic-ivs.gif)

* tsf-tutcodeの使用例に使いたかったので、KeyCastOWのように文字を表示するよりも、キーボード上の位置を表示したくて作成。
* [漢直Win](https://github.com/kanchoku/kw)を少しだけ変更したものです。
* 少し検索した限りでは、同様のツールを見つけられなかったので作成。
  ([姫踊子草](http://www.vector.co.jp/magazine/softnews/110415/n1104151.html)の、補助鍵盤画像で、「キー操作を表示する」と同様のことができるかも。)

## 使い方・動作
起動後、`Ctrl+\`でオンに切り替えると、打ったキーを表示します。

オンにすると各キーに対してRegisterHotKey()をします。
キーが打たれた時に送られてくるWM_HOTKEYをもとに表示を行うとともに、
keybd_event()を発行してIMEやアプリにキーを送ります。

## 制約、既知の問題
* Ctrlキー等は未対応

もっとましな形で作るなら、[Carnac](https://github.com/Code52/carnac)を改造したり、[pyHook](https://sourceforge.net/projects/pyhook/)を使うのが良いかもしれません。

## 参考
* [キー入力を表示しながらスクリーンショットGifを撮る](http://rcmdnk.github.io/blog/2014/08/01/computer-mac-windows/#windows)
 * Macのキーボードビューアには押したキーを表示する機能があるようですが、WindowsのスクリーンキーボードはShiftキー等しか表示してくれない模様
* On-Screen Keyboardの中には同様の機能を持つツールがありそうな気はしますが未調査
* その他KeyboardTestツール等
