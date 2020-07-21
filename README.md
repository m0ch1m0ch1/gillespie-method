# gillespie-method
## 1. はじめに

    このプログラムはGillespie法と呼ばれる確率微分方程式の
    数値計算を実施するプログラムである．

    事前に導入が必要なソフト
      ・gcc version 4.9.0 ~
      ・Gnuplot Version 5.0 patchlevel 1 ~

    各ファイルの内容は以下の通りである。

    ./
      README.md           このファイル

    ./src/
      Makefile            Makefile
      main.c              メイン部分
      Graph.c             グラフ描写部分
      Initial_Para.c      個数の初期値・確率定数の設定
      Stocahtic.c         計算部分
      mt19937ar.c         乱数生成
      table.c             表形式での出力

    ./inc/
      main.h              main.c のヘッダファイル
      mt19937ar.h         乱数用ヘッダファイル

    ./bin/
      gillespie          実行ファイル

## 2. おわりに

    バグや改良点などありましたらお知らせ下さい。
