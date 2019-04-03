**NOTE: This software is no longer maintained**.<br>
F2Filter had been published on geocities ([http://www.geocities.jp/opiopan/Products/F2Filter/](www.geocities.jp/opiopan/Products/F2Filter/)) over 15 years. Unfortunately, this web service was terminated at end of March, 2019.<br>
All resource ragerding F2Filter has been moved to this GitHub repository with this opportunity. Howerver, I have no intention to maintain this software any more since I have no Windows PC at this time.<br>
This README is also just transrated from original HTML page contents to mark down file.

**注意: このソフトウェアはもう保守されていません**<br>
F2Filterはジオシティーズ([http://www.geocities.jp/opiopan/Products/F2Filter/](www.geocities.jp/opiopan/Products/F2Filter/))で１５年にわたり公開されてきました。しかし残念ながら、2019年3月を持ってこのWebサービスは終了してしまいました。<br>
そこで、F2Filterに関連したリソース全てをGitHubのリポジトリに移動することにしました。しかしこれ以上このソフトウェアの保守するつもりはありません。実は随分前からWindows PCを持たなくなってしまったので。<br>
このREADMEもジオシティーズで公開していたHTMLを単純にMark Downに置き換えただけのものです。

F2Filter
===
最終更新日： 2003年12月21日 <br>
最新バージョン(0.91d)のダウンロードは [こちら](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91d.zip)

## F2Filterとは
F2Filterは、フライトシミュレータFalcon4.0のフォースフィードバックのバグを回避するために作成したソフトです。ゲームコントローラのデバイスドライバとDirectXとの間で動作し、ドライバへの要求をすりかえることで、バグを回避したりフィードバックの動作を変更します。

現在のF2Filterは次のことが実現できます。　
　
- Falcon4.0のフォースフィードバックサポートのバグ（地上でスタートするとスティックの弾性が０になってしまう。）を回避する。
　
- フォースフィードバックに対応したゲームの効果を無効にする。<br>
（フォースフィードバックでないジョイスティックと同等にする。）　

上記の2番目の項目は、Falcon4.0以外のゲームを動かすときに利用することもできます。

## ダウンロード
最新版は次のリンクからダウンロードできます。

[F2Filter Ver0.91d](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91d.zip)

## 使用方法
ダウンロードししたファイルを展開した後、付属のReadme.txtに従ってインストールと設定をしてください。

## ソースコード、ライセンス
MITライセンスのもと公開します。<br>
コンパイルにはVisual C++ 6.0 + Platform SDK最近のもの + DirectX SDK 8.0以降が必要です。

## 履歴

 日付      |バージョン |説明 
----------|---------|------------------------------------------
2002-08-26|[Ver0.91](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91.zip)|アルファ版公開
2002-08-28|[Ver0.91a](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91a.zip)|Falcon 4.0専用モード」がSidewinder FFB2に依存していた部分を修正
2002-08-30|[Ver0.91b](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91b.zip)|ログに採取する情報の追加<br>「Falcon 4.0専用モード」でもログ採取可能に修正
2003-12-20|[Ver0.91c](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91c.zip)|英語リソース追加（日本語OS以外に対応）<br>一応BMSのことを考慮
2003-12-21|[Ver0.91d](https://raw.githubusercontent.com/wiki/opiopan/f2filter/archives/F2F0_91d.zip)|モード選択のドロップダウンリストがWindows XP以外で表示されないバグの修正


