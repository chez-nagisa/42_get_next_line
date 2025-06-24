# get_next_line  
`get_next_line` is a project from the 42 curriculum that focuses on reading a file or input stream **line by line**.  
The goal is to implement a function that returns the next line from a given file descriptor each time it is called.  
This requires careful memory handling, persistent state management, and edge case handling — all done in C, without using standard high-level functions.

# 🧠 What I Learned
- Dynamic memory allocation and buffer management
- Maintaining state between function calls using static variables
- Handling edge cases such as newline characters, EOF, and memory leaks

# 🧪 How to Use
1. Clone this repository
2. Run make to compile get_next_line.a

# get_next_line（日本語）
`get_next_line` は、42のカリキュラムに含まれるプロジェクトで、ファイルや標準入力から**1行ずつ読み込む関数**をCで実装します。  
この関数は、呼び出されるたびにファイルディスクリプタから次の1行を返すように設計されており、バッファ処理やメモリ管理、状態の保持などをすべて自前で行う必要があります。

## 🧠 学んだこと
- 動的メモリ確保とバッファの管理
- `static` 変数を用いた関数間の状態保持
- 改行やEOF、メモリリークなどの例外処理

## 🧪 使い方
1. このリポジトリをクローンします
2. make を実行して get_next_line.a をビルドします
