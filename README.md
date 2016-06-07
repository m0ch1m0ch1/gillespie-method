# Gillespie_Method
## 1. はじめに

    このプログラムは、Gillespie法と呼ばれる手法を用いて確率微分方程式の
    数値解法を行なうプログラムである。

    事前導入ソフトを以下に示す。
      ・Intel Compiler Version 16.0.2 (gcc version 4.9.0 compatibility)
      ・Gnuplot Version 5.0 patchlevel 1      

    各ファイルの内容は以下の通りである。

    ./
      README.md           このファイル

    ./src/
      Makefile            Makefile
      main.c              メイン部分
      Graph.c             グラフ描写部分
      Initial_Para_conc.c 個数の初期値設定
      Initial_para_rapi.c 確率定数の設定
      Stocahtic.c         計算部分
      mt19937ar.c         乱数生成
      table.c             表形式での出力

    ./inc/
      main.h              main.c のヘッダファイル
      mt19937ar.h         乱数用ヘッダファイル

    ./bin/
      Gillespie          実行ファイル

## 2. おわりに

    バグや改良点などありましたらお知らせ下さい。
