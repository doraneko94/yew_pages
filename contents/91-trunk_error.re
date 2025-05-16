= Trunk実行時のエラーについて

@<code>{trunk build}, @<code>{trunk serve}などのコマンド実行時に、@<list>{trunk_warn}のような警告を発してビルドが不十分に終わることがあるかもしれません。

//list[trunk_warn][trunk build実行時の警告: shell]{
> trunk build --release
20XX-XX-XXTXX:XX:XX.XXXXXXZ  INFO  starting build
20XX-XX-XXTXX:XX:XX.XXXXXXZ  INFO spawning asset pipelines
20XX-XX-XXTXX:XX:XX.XXXXXXZ  WARN no rust project found ←←←← 警告
20XX-XX-XXTXX:XX:XX.XXXXXXZ  INFO applying new distribution
20XX-XX-XXTXX:XX:XX.XXXXXXZ  INFO  success
//}

この場合、生成された@<code>{dist}ディレクトリには@<code>{index.html}しか存在せず、その中身にはWASMに関する記述が追加されません。

@<list>{trunk_warn}が生じる主要な原因の1つは、コマンドを実行するディレクトリの位置が間違っていることです。事前に@<code>{cd}コマンドを使って@<code>{Cargo.toml}ファイルが存在するディレクトリに移動してから@<code>{trunk build}, @<code>{trunk serve}などのコマンドを実行してください。

//list[build_hello_yew][trunk buildの実行（hello-yewプロジェクトの場合）: shell]{
.../hello-yew> trunk build --release
//}

コマンドを実行したディレクトリに@<code>{Cargo.toml}が存在するにも関わらず、@<list>{trunk_warn}の警告（「Rustプロジェクトが見つかりません」）が表示される場合もあります。この多くはTrunkのバージョンが古いケースで生じます。

従来のTrunkでは、たとえば@<list>{lib_cdylib}のような記述を@<code>{Cargo.toml}に含める必要がありました。

//list[lib_cdylib][Trunk v0.20.0以前のlibの記述: Cargo.toml]{
[lib]
crate-type = ["cdylib"]
//}

この記述は「Rustを他の言語のライブラリとして使用する」ことを宣言しています。他の言語とは、たとえばWASMのことです。

しかし、Trunk v0.21.0からはこの記述を省略することができるようになりました。そのため、本書ではすべての@<code>{Cargo.toml}で@<code>{[lib]}の記述を省いています。

このようにTrunkのバージョンが異なるとビルドに失敗することがあるため、@<list>{trunk_update}のコマンドでTrunkのアップデートを実行してください。

//list[trunk_update][Trunkのアップデート: shell]{
> cargo install trunk --locked --force
//}

その際、Rust自体のアップデートを要求された場合は@<list>{rust_update}のコマンドを実行してください。

//list[rust_update][Rustのアップデート: shell]{
rustup update stable
rustup default stable
//}

本書の刊行時のサンプルコードは、Trunk v0.21.14でビルドできることを確認しています。将来的にv0.22, v0.23, ...がリリースされ、仕様変更によりサンプルコードのビルドができなくなった場合、@<list>{trunk_v021}のコマンドを実行してTrunkのバージョンをv0.21.14に戻すことを検討してください。

//list[trunk_v021][Trunkのバージョンをv0.21.14に指定してインストール: shell]{
cargo install trunk --version 0.21.14 --force
//}