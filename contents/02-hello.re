= Hello, Yew!

== 最も簡単なWebアプリ

新しい技術の最初の一歩を踏み出すときには、"Hello, World!"を実行することが慣例です。ここでは、「Hello, Yew!」の文字列を表示するだけのWebアプリを作成し、Github Pagesで公開するための基本を学びます。このWebアプリのサンプルは、以下のURLで公開されています。

//blankline
[外部リンク] Hello, Yew!

@<href>{https://j-impact.github.io/hello-yew/}
//blankline

文字を表示するだけでも立派なWebアプリです。このWebアプリを作るためのコード一式は、以下のリポジトリにまとめています。

//blankline
[外部リンク] J-IMPACT/hello-yew

@<href>{https://github.com/J-IMPACT/hello-yew}
//blankline

== 作業の進め方

以降の章では、このリポジトリに含まれるファイルの内容を１つずつ解説することで、Github PagesでWebアプリを公開するための最小構成を学習します。実際に作業を行いながら本書を読み進める場合には、以下の2通りの方法を推奨します。

//caution{
ただし、どの方法を選択する場合あっても、Githubアカウントが作成済みであり、自身のPCで@<code>{git}コマンドが使用可能になっていることを前提とします。
@<code>{git}コマンドが使用できない場合には、Gitの公式サイト@<href>{https://git-scm.com/}を参照してインストールしてください。
//}

=== 空のプロジェクトを作って、必要なファイルを再現する

Rustで空のプロジェクトを作成し、その中に@<code>{J-IMPACT/hello-yew}内のファイルを作成しながらリポジトリを再現します。コードの写経を通して理解度を高めたい読者におすすめの方法です。コードを写し間違えるとWebアプリが動作しなくなることがあるため注意が必要ですが、動作に不具合がある場合のバグ修正も含めて、非常に実践的な経験を積むことができると思います。

この方法で作業を進める場合には、シェルやコマンドプロンプトでRustプロジェクトを作成したいディレクトリ（フォルダ）に移動し、@<list>{cargo_new}のコマンドで、@<code>{hello-yew}という名前の空のRustプロジェクトを作成します。

//list[cargo_new][Rustプロジェクトの新規作成: shell]{
> cargo new hello-yew
//}

すると@<code>{hello-yew}ディレクトリが作成され、その中にRustで開発を行うための必要最小限のファイルが生成されます。この@<code>{hello-yew}ディレクトリをVS Codeなどのエディタで開き、各ファイルの内容が@<code>{J-IMPACT/hello-yew}と同じになるようにコードを修正してください。

//blankline
[外部リンク] Visual Studio Code（参考）

@<href>{https://code.visualstudio.com/}

//info{
いくつかのファイルは新規に作成する必要があります。

ただし、@<code>{Cargo.lock}ファイルは無視し、@<b>{複製も削除もしないでください}。このファイルはRustのビルド時に、そのときのクレートの状況に合わせて自動で生成されますが、Webアプリ全体の動作に影響を与えません。
//}

//caution{
また、@<code>{J-IMPACT/hello-yew}に含まれていないからといって、@<list>{cargo_new}の実行直後から存在する@<code>{.git}ディレクトリは@<b>{絶対に削除しないでください}。このディレクトリはGitならびにGithubでのプロジェクト管理に極めて重要です。

なお、@<code>{.git}ディレクトリは隠しフォルダに設定されているため、PCの設定によっては見えない場合があります。
//}

この方法を採用した場合には、新規作成した@<code>{hello-yew}ディレクトリと、読者のGithubリポジトリを結びつける作業が必要です。（作業内容は後ほど解説します）

=== リポジトリをフォークする

コードを写経することに意味を感じない、またはサッと一通り本書を読み終えてしまいたい読者にはこちらの方法をおすすめします。

Githubにおけるリポジトリの「@<b>{フォーク}」とは、他のユーザが作成したリポジトリを自分のアカウントにコピーすることを意味します。コピー元のリポジトリを「本家」とし、自身のアカウントの管理下に「分家」を作成するイメージです。具体的には、本章の「Hello, Yew!」リポジトリは「J-IMPACT」のアカウントで作成したため@<code>{J-IMPACT/hello-yew}という名前になっていますが、これをフォークすることで@<code>{[your-user-name]/hello-yew}が作成されます。

フォークの方法は非常に簡単で、Githubにログインした状態で@<img>{fork_button}に示した「Fork」ボタンをクリックするだけです（なお、Fork」ボタンをクリックする前に、その右横にある「Star」ボタンも押していただけると著者が泣いて喜びます）。

//image[fork_button][「Fork」ボタンの位置]

すると@<img>{create_fork}のような画面が表示されるので、「Create fork」ボタンをクリックするとフォークが完了し、読者のアカウントの管理下に置かれた@<code>{[your-user-name]/hello-yew}リポジトリのページに遷移します。

//image[create_fork][「Create fork」ボタンの位置]

//info{
@<code>{J-IMPACT/hello-yew}と@<code>{[your-user-name]/hello-yew}の内容は独立しています。よって、分家である読者の@<code>{hello-yew}の内容を変更しても、本家のリポジトリの内容には影響を与えません。
//}

この@<code>{[your-user-name]/hello-yew}を使って作業を行うため、リポジトリの内容を自身のPCにコピーしておきます。シェルやコマンドプロンプトでリポジトリのコピーを作成したいディレクトリ（フォルダ）に移動し、@<list>{git_clone}のコマンドでリポジトリを@<b>{クローン}してください（@<code>{[your-user-name]}は、読者のアカウント名で置き換えてください。カッコ@<code>{[]}は削除してください。つまり、この部分は読者のリポジトリのURLに相当します）。

//list[git_clone][リポジトリのクローン: shell]{
> git clone https://github.com/[your-user-name]/hello-yew
//}

== Webアプリを実装するためのファイルの解説

ここからは、各ファイルの役割と内容を解説します。

=== @<code>{Cargo.toml}

@<code>{Cargo.toml}はRustプロジェクトに関する様々な設定を記述するファイルです。設定の中でも特に重要なのが、使用するクレートを宣言する@<code>{[dependencies]}の項目です。@<list>{dependencies}にこの部分を表示します。

//list[dependencies][dependenciesの内容: Cargo.toml]{
[dependencies]
yew = { version = "0.21.0", features = ["csr"] }
//}

ここでは@<code>{yew}クレートのみを使用することを宣言しています。@<code>{version = "0.21.0"}は、これまで数多くリリースされた@<code>{yew}クレートの中でも、バージョン0.21.0を使用することを指定しています。異なるバージョンのクレートを使用するとビルドに失敗する場合があるため、指定するバージョンを吟味することは非常に重要です。

@<code>{features}では、@<code>{yew}クレートを使用する際のモード（feature）を指定しています。featureは配列として複数指定することができるため、feature"s"となっています。featureの指定を切り替えることによって、クレートが提供する関数や構造体の内容を変化させることができます。

ここで指定している@<code>{csr}は、@<b>{Client Side Rendering}を意味しています。これと対になるのが@<b>{Server Side Rendering}（SSR）です。レンダリング（Rendering）とは、コンピュータがデータを処理し、HTML等による描画を行う処理のことです。つまり、「画面に何をどう表示するか」を決定する処理です。

以下、「幅がX、高さがYの平行四辺形の面積を計算するWebアプリ」を例に、SSRとCSRの動作の違いを説明します。

==== Server Side Rendering (SSR)

Webアプリにアクセスし、これを利用するユーザのことを@<b>{クライアント}といいます。対して、Webアプリの提供元を@<b>{サーバ}といいます。

SSRは、レンダリングをサーバ側で行う方式です。たとえばクライアントがWebアプリのフォームに「X=3, Y=4」と入力して「計算」ボタンを押したとします。SSRではこの入力内容が@<b>{リクエスト}としてサーバに送られ、サーバでは「3×4=12」という計算を実行します。

そして計算結果「12」を含むHTMLが生成され、それが@<b>{レスポンス}としてクライアントに返送されます。その結果、クライアントのブラウザに「面積は12です」と表示されます。

つまりSSRでは、計算と描画を@<b>{サーバ側で実行}し、結果だけをクライアントに送る構造になっています。そのため、処理速度はサーバの性能に依存します。

==== Client Side Rendering (CSR)

CSRは、レンダリングをクライアント側、つまりブラウザの中で行う方式です。この場合、クライアントがWebアプリにアクセスした時点で、サーバからHTMLやCSS、WASMなどの@<b>{アプリケーションのロジック}を含むファイル一式が送られます。この中には、

「幅がX、高さがYの平行四辺形の面積を求めたかったら、X×Yを計算してね」

という指示がすでに組み込まれています。

CSRでは、クライアントがフォームに「X=3, Y=4」と入力した情報はサーバには送信されません。その代わりにクライアント側のブラウザ内で、すでに送られてきている指示に従って「3×4=12」という計算を実行し、結果の「12」という文字を画面に表示します。

つまりCSRでは、計算と描画を@<b>{クライアント側で実行}します。そのため、処理速度はユーザの端末性能に依存しますが、一度ファイルを読み込めばページ遷移や操作が高速に行えるという利点もあります。

==== 本書における基本戦略

実装したいWebアプリの機能によって、SSR・CSRそれぞれに向き・不向きがあると考えられます。そのため、可能であればこれらを組み合わせて使用したいところです。しかし、静的ホスティングサーバであるGithub Pagesでは、サーバでの処理を実行できないためSSRは採用できません。よって、Github Pagesは以下のようなWebアプリを提供する用途には適していないことがわかります。

 1. サーバの高性能な計算機能を提供するWebアプリ（物理シミュレータなど）
 2. レンダリング時に、クライアントに秘匿すべき情報が必要となるWebアプリ（ログイン処理など）

これら以外のWebアプリの機能は、CSRでも十分に実装することができます。また、1.のように「高機能なサーバ処理」を提供することはできませんが、「高速なバイナリ（WASM）」や「高機能なアルゴリズム」を提供して、有用な物理シミュレータを作ることは可能です（ログイン処理に関しては、Webアプリへのアクセス時に全ユーザ名とパスワードをクライアントに送信してしまえば原理上は実装可能ですが、セキュリティの観点から現実的ではありません）。

本書では、CSRで実装可能な機能を数多く紹介し、それらを組み合わせて有意義なWebアプリをGithub Pages上で公開することを基本戦略とします。

=== @<code>{src/main.rs}

@<code>{src}ディレクトリにはRustのソースコードが格納されます。
その中で、@<code>{main.rs}がWebアプリの動作を定義する核となっています。

ここでは、@<code>{main.rs}の内容を解説しながらRustならびにYewの使い方を解説します。

==== クレート使用の宣言

//list[use_yew][yewクレートの使用を宣言: src/main.rs]{
use yew::prelude::*;
//}

@<list>{use_yew}では@<code>{yew}クレートを使用することを宣言しています。
@<code>{prelude}は、@<code>{yew}クレートの中でも頻繁に利用される機能の一覧です。
つまり@<list>{use_yew}の1行は、「@<code>{yew}クレートの頻繁に利用される機能（@<code>{prelude}）のすべて（@<code>{*}）を使用する」ことを宣言しています。

==== コンポーネントの定義

Yewを使う主な目的は、描画する@<b>{コンポーネント}を定義することです。
コンポーネントとは、複数のHTML要素・CSS・JavaScriptをまとめた@<b>{再利用可能な単位}です。
@<list>{def_app}では、@<code>{App}という非常に簡単なコンポーネントを定義しています。

//list[def_app][Appコンポーネントの定義: src/main.rs]{
#[function_component(App)]
fn app() -> Html {
    html! {
        <h1>{ "Hello, Yew!" }</h1>
    }
}
//}

コンポーネントは、@<code>{function_component}の記法を使用すると、@<code>{Html}構造体を返す関数として定義することができます。
@<code>{Html}構造体は@<code>{html!}マクロを使用して記述することができます。
ここでは@<code>{App}を、@<code>{<h1>Hello, Yew!</h1>}というHTMLを表示するコンポーネントとして定義しています。
コンポーネントは再利用可能な単位なので、これを@<code>{<App />}としてHTMLに挿入すると、その箇所では@<code>{<h1>Hello, Yew!</h1>}として表示されます。

なお、関数名の@<code>{app}には特に意味はありません。関数の返り値が@<code>{Html}であり、他の関数と被りがなければ関数名は何でも良いのですが、コードの可読性を高めるため、コンポーネントと同様の名前をつけておきましょう。

@<code>{html!}マクロの記法について補足しておきます。
@<code>{<h1>Hello, Yew!</h1>}を表示したい場合に、@<list>{html_error}のように書くのは正しくありません。

//list[html_error][間違ったhtml!マクロの書き方]{
html! {
    <h1>Hello, Yew!</h1>
}
//}

@<code>{html!}マクロの内部には、HTMLタグ、コンポーネント、@<code>{{}}で囲んだRustの式や変数を書くことができます。
よって、HTMLタグである@<code>{<h1>}や@<code>{</h1>}を書くことは正しいのですが、その間にある@<code>{Hello, Yew!}はHTMLタグやコンポーネントではなく、@<code>{{}}にも囲まれていないので正しく認識できません。
そのため@<list>{def_app}では「Hello, Yew!」をRustの文字列@<code>{"Hello, Yew!"}として捉え、それを@<code>{{}}で囲んでh1タグの内部に挿入しています。
また、以下のように変数に代入してから@<code>{html!}マクロに挿入することもできます。

//list[def_app_var][変数を使用したAppコンポーネントの定義]{
#[function_component(App)]
fn app() -> Html {
    let message = "Hello, Yew!";
    html! {
        <h1>{ message }</h1>
    }
}
//}

また、@<code>{html!}マクロ内には@<code>{if}分岐や@<code>{for}ループを含めることもできます。
これらの記法については本書の後の章で解説します。

==== Webアプリのレンダリング

Webアプリ全体を記述したコンポーネントを使用して、Webアプリのレンダリングを行うことができます。

//list[yew_renderer][Webアプリのレンダリング: src/main.rs]{
fn main() {
    yew::Renderer::<App>::new().render();
}
//}

@<code>{main}関数内で@<code>{yew::Renderer::<App>::new()}と書くことで、Webアプリの全体像となるコンポーネントが@<code>{App}であることを指定して@<code>{Renderer}を定義できます。
その後、@<code>{render}メソッドを使用して描画を実行します。

=== index.html

Yewを使用して記述したRustコードは、Trunkを使用してWebアプリへとビルドします。
その際、@<code>{index.html}というHTMLテンプレートを用意する必要があります。
@<list>{index_html}にその全体像を示します。

//list[index_html][HTMLテンプレートの内容: index.html]{
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Hello, Yew!</title>
</head>
<body>
    
</body>
</html>
//}

@<code>{<head>}内では、@<code>{<meta>}タグや@<code>{<title>}タグを使ってWebアプリの設定をすることができます。
一方、@<code>{<body>}内は空白になっています。

Trunkを使用してWebアプリをビルドすると、RustからWASMバイナリが作られ、この@<code>{<body>}の内部にはそのバイナリを読み込むための記述が挿入されます。
@<code>{hello-yew}のディレクトリ内で@<list>{trunk_build}のコマンドを使用して、実際にWebアプリをビルドしてみましょう。
（1から写経している読者も、現時点で@<code>{Cargo.toml}, @<code>{src/main.rs}, @<code>{index.html}があればビルドは成功するはずです）

//list[trunk_build][TrunkでWebアプリをビルド: shell]{
> trunk build --release
//}

すると@<code>{dist}というディレクトリが作成され、その中に以下のファイルが生成されます。

 * hello-yew-xxxxxxxxxxxxxxxx_bg.wasm
 * hello-yew-xxxxxxxxxxxxxxxx.js
 * index.html

ビルド時に@<code>{WARN no rust project found}などの警告を発して、上記のファイルが生成されなかった場合は、@<chapref>{91-trunk_error}を参照してください。

ファイル名の「xxxxxxxxxxxxxxxx」の部分はビルドごとに割り振られるハッシュ値で、ビルドしたファイルの内容によって変化します。そのため、ファイル内容の更新を把握しやすくなっています。

@<code>{.wasm}ファイルはRustコードから生成したWASMのバイナリです。この中にWebアプリの計算・描画処理が含まれていますが、スクリプト（コード）ではなくバイナリなので、これをエディタで開いても人間が読めるようにはなっていません。また、@<code>{.js}ファイルは@<code>{.wasm}ファイルを読み込むためのスクリプトです。

@<code>{dist}ディレクトリに生成された@<code>{index.html}の内容を示します。

//list[dist_index_html][WASM読み込みが追加されたHTML: dist/index.html]{
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Hello, Yew!</title>
<link rel="modulepreload" href="/hello-yew/hello-yew-xxxxxxxxxxxxxxxx.js" crossorigin="anonymous" integrity="sha384-PU1JuRrzwvT5mHB5G7NMxTXDiE/8R/qaDNB3QCJjXmg7WXgbnP9kAh5UjFQ7PIM2"><link rel="preload" href="/hello-yew/hello-yew-xxxxxxxxxxxxxxxx_bg.wasm" crossorigin="anonymous" integrity="sha384-pUY38i2Dst7ZceBh+URSvtB0J+noiPpJ8Q+GyaIsEnz7V6+5X5vcQfG6WaUFZczW" as="fetch" type="application/wasm"></head>
<body>
    

<script type="module">
import init, * as bindings from '/hello-yew/hello-yew-xxxxxxxxxxxxxxxx.js';
const wasm = await init({ module_or_path: '/hello-yew/hello-yew-xxxxxxxxxxxxxxxx_bg.wasm' });


window.wasmBindings = bindings;


dispatchEvent(new CustomEvent("TrunkApplicationStarted", {detail: {wasm}}));

</script></body>
</html>
//}

@<code>{hello-yew}ディレクトリの直下に用意した@<code>{index.html}に、@<code>{.wasm}・@<code>{.js}ファイルを通してWASMを使用するための記述が機械的に挿入されています。具体的には、@<code>{<head>}内に@<code>{<link>}、@<code>{<body>}内に@<code>{<script>}が追加された形です。これらの記述によってWebアプリ内でのWASMの使用が可能になりますが、今回は@<code>{<h1>Hello, Yew!</h1>}を表示するだけなので、アプリの見た目は@<list>{h1_only}と同じになります。

//list[h1_only][hello-yewアプリと等価なHTML]{
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Hello, Yew!</title>
</head>
<body>
    <h1>Hello, Yew!</h1>
</body>
</html>
//}

また@<list>{index_html}と@<list>{dist_index_html}を比較すると、挿入された@<code>{<link>}の部分を除いて@<code>{<head>}内の記述が保たれていることがわかります。このように、WASMに依存しない@<code>{<title>}, @<code>{<meta>}などの情報は、事前に@<code>{index.html}の@<code>{<head>}内に記述しておくことができます。

== ローカル環境でのWebアプリの実行

@<list>{trunk_build}で確認したとおり、ここまでのファイルが正しく記述されていればWebアプリをビルドすることができます。手元の環境（ローカル）でWebアプリの動作を確認するには、@<list>{trunk_serve}のコマンドを実行します。

//list[trunk_serve][localhostでWebアプリを実行: shell]{
> trunk serve --release --open
//}

するとブラウザが立ち上がり、@<img>{hello_yew}のように「Hello, Yew!」が表示されます。

//image[hello_yew][Hello, Yew!アプリの実行]

Webアプリの実行を停止するには、@<list>{trunk_serve}のコマンドを実行したコマンドプロンプト（シェル）で@<code>{Ctrl+C}を入力してください。

== Github Pageのためのファイル解説

ここからは、作ったWebアプリをGithub Pagesで公開するために必要なファイルを解説します。

=== Trunk.toml

@<code>{Trunk.toml}は、Trunkでのビルドに関する設定を記述するファイルです。@<code>{hello-yew}の中では、@<list>{trunk_toml}の内容のみ記述しています。

//list[trunk_toml][WebアプリのURLの指定: Trunk.toml]{
[build]
public_url = "/hello-yew/"
//}

@<code>{public_url}を指定することにより、WebアプリのURLを変更できます。これを指定しない場合、デフォルトのURLは@<code>{"/"}です。

この機能を簡単に実験してみましょう。まず、@<code>{Trunk.toml}に@<list>{trunk_toml}の記述がある状態で、ローカル環境でWebアプリを起動します（@<list>{trunk_serve_re}）。

//list[trunk_serve_re][localhostでWebアプリを実行（再掲）: shell]{
> trunk serve --release --open
//}

すると@<img>{url_hello_yew}のように、ブラウザのURL欄には@<code>{.../hello-yew/}と表示されます。

//image[url_hello_yew][public_url = "/hello-yew/"の場合のURL]

URLの確認ができたら@<code>{Ctrl+C}でWebアプリを停止します。
次に、@<code>{Trunk.toml}を削除するか、内容を@<list>{trunk_toml_none}のように書き換えた状態で、@<list>{trunk_serve_re}のコマンドを実行してください。

//list[trunk_toml_none][WebアプリのURLをデフォルトに設定: Trunk.toml]{
[build]
public_url = "/"
//}

すると@<img>{url_none}のように、今度はURLから@<code>{/hello-yew/}の表示が消えます。

//image[url_none][public_url = "/"の場合のURL]

ここで、@<code>{J-IMPACT/hello-yew}リポジトリのURLと、公開されている「Hello, Yew!」アプリのURLの対応関係を見てみます。

//blankline
[外部リンク] J-IMPACT/hello-yew

@<href>{https://github.com/J-IMPACT/hello-yew}

//blankline

[外部リンク] Hello, Yew!（再掲）

@<href>{https://j-impact.github.io/hello-yew/}
//blankline

アカウント名の大文字が小文字になっているという違いもありますが、@<code>{[user-name]/[repository-name]}というリポジトリで管理されているWebアプリのURLは、@<code>{https://[user-name].github.io/[repository-name]/}になります。

このとき、Webアプリが公開されるURLはドメイン@<code>{[user-name].github.io}の直下ではなく、その下の@<code>{/[repository-name]/}になります。TrunkでビルドされたWebアプリは、デフォルトではドメイン直下で動作するように設定されています。このズレを解消するため、@<code>{Trunk.toml}に@<list>{trunk_toml}のような記述をする必要があります。

=== .github/workflows/deploy.yaml

==== Githubの活用方法

これまでに紹介したファイルがあれば、Github PagesでWebアプリを公開することができます。
本書では、Githubを①コードの管理と②Webアプリの公開のために使用します。そのために、@<code>{master}と@<code>{gh-pages}の2つの@<b>{ブランチ}を設定します。

ブランチはコードを管理するための「枝」です。これを活用すると、同一のリポジトリ内で、ブランチごとに独立したファイルや履歴を管理することができます。そこで本書では@<code>{master}ブランチでWebアプリ実装のためのコードを管理し、Trunkでビルドした完成物は@<code>{gh-pages}ブランチに置いておくことにします。Github Pagesは@<code>{gh-pages}ブランチにあるファイルを使用し、Webアプリとして公開します。

以上より、Webアプリを実装した後、それを公開するための手順は以下のようになります。

 1. リポジトリ内で変更したファイルの情報を@<code>{master}ブランチに送信
 2. TrunkでWebアプリをビルド
 3. @<code>{dist}ディレクトリに生成されたファイルを@<code>{gh-pages}ブランチに送信
 4. @<code>{gh-pages}ブランチに@<code>{.nojekyll}ファイルを追加（のちほど解説）

コードの内容を変更するたびに、1から4の手順をすべて実行するのは面倒です。そこで、@<code>{deploy.yaml}ファイルを作成して、1を実行するだけで2,3,4の手順も自動実行されるように設定します。

==== @<code>{deploy.yaml}の設置場所

@<code>{deploy.yaml}は、設置する位置を間違えやすいので注意してください。

 1. まず、リポジトリ直下（@<code>{Cargo.toml}と同じ場所）に@<code>{.github}というディレクトリを作成します。
 2. 次に、@<code>{.github}の中に@<code>{workflows}ディレクトリを作成します。
 3. 最後に、@<code>{workflows}ディレクトリの中に@<code>{deploy.yaml}ファイルを作成します。

よって、リポジトリ直下から見た@<code>{deploy.yaml}の位置（パス）は、@<code>{.github/workflows/deploy.yaml}になります。GithubやVS Codeでは@<code>{.github/workflows}のように、2つのディレクトリ名が結合されて1つのディレクトリのように表示される場合がありますが、これらは入れ子になった別のディレクトリであることに注意してください。

==== Github Actions

Githubは、Github Actionsというビルド・デプロイ（公開）処理自動化のためのCI/CD環境機能を提供しています。CI/CDは、Continuous Integration/Continuous Delivery (Deployment)、つまり「継続的インテグレーション/継続的デリバリ（デプロイ）」の略です。

Githubはリポジトリ内容に変更があった場合、リポジトリ内の@<code>{.github/workflows/deploy.yaml}を自動で検出します。そして、そのファイルに書かれたビルド・デプロイなどの手順をGithub Actionsで実行します。

==== @<code>{deploy.yaml}の内容

以下、@<code>{deploy.yaml}の内容を部分ごとに解説します。

//list[name_trigger][名前とトリガーの定義: .github/workflows/deploy.yaml]{
name: Deploy to GitHub Pages

on:
  push:
    branches:
      - master
//}

@<list>{name_trigger}の@<code>{name}では、Github ActionsのUIに表示される名前を指定しています。その下の@<code>{on}→@<code>{push}→@<code>{branches}→@<code>{master}では、「@<code>{master}ブランチに更新情報が送信（push）されたとき」をトリガーとして、以降の処理を行うことを宣言しています。

//list[permissions][権限の設定: .github/workflows/deploy.yaml]{
permissions:
  contents: write
//}

@<list>{permissions}では、@<code>{permissions}を使用して、ワークフローがリポジトリ内容への書き込みを行うことへの許可を与えています。この権限は、後の処理でファイルの作成や追加を実行するために必要です。

//list[run_steps][実行環境とステップの定義: .github/workflows/deploy.yaml]{
jobs:
  deploy:
    runs-on: ubuntu-latest

    steps:
//}

@<list>{run_steps}の@<code>{jobs}以下で具体的な処理内容を定義しています。@<code>{runs-on: ubuntu-latest}では、Githubが用意した最新のUbuntu OS環境で以降の処理を行うことを指定しています。

処理の内容はステップに分けて@<code>{steps}以下に記述します。実行したい処理の内容は、@<code>{master}ブランチにあるコードをTrunkでビルドし、生成されたファイルを@<code>{gh-pages}ブランチに保存することです。ここからは、各ステップの内容を見ていきます。

//list[checkout][ソースコードの読み込み: .github/workflows/deploy.yaml]{
- name: Checkout repository
  uses: actions/checkout@v3
//}

@<list>{checkout}は「Checkout repository」と名付けられた処理です。@<list>{run_steps}で指定したUbuntu環境は空の状態で起動されるため、ここに現在トリガーされたブランチ（@<code>{master}）のファイルをコピーします。この処理を@<b>{チェックアウト}といいます。

@<code>{uses: actions/checkout@v3}では、@<code>{actions/checkout@v3}という既存の@<b>{アクション}を実行することを指定しています。チェックアウトのような頻繁に実行される処理は、こうしたアクションとして既に定義され、利用可能になっています。

以上をまとめると、このステップは@<code>{actions/checkout@v3}で定義された処理を「Checkout repository」の名前で実行する、という意味になります。

//list[install_rust][実行環境にRustをインストール: .github/workflows/deploy.yaml]{
- name: Install Rust
  uses: actions-rs/toolchain@v1
  with:
    toolchain: stable
    target: wasm32-unknown-unknown
    override: true
//}

起動されたUbuntuは空なので、当然Rustもインストールされていません。ここでは@<code>{actions-rs/toolchain@v1}アクションを使用してRustをインストールしています。その際、@<code>{with}以下に条件を設定することができます。ここでの指定内容は以下のとおりです。

 * @<code>{toolchain: stable}: Rustの安定版（stable）をインストール
 * @<code>{target: wasm32-unknown-unknown}: RustのターゲットにWASM用の@<code>{wasm32-unknown-unknown}を追加
 * @<code>{override: true}: このワークフロー内では、このステップでインストールしたRustを常に使用する

//list[install_trunk][実行環境にTrunkをインストール: .github/workflows/deploy.yaml]{
- name: Install Trunk
  run: cargo install trunk
//}

続けてTrunkをインストールします。この処理は既存のアクションに存在しませんが、インストールは@<code>{cargo install trunk}の1行で完了するので@<run>として処理を記述します。

//list[trunk_build_ubuntu][TrunkでWebアプリをビルド: .github/workflows/deploy.yaml]{
- name: Build
  run: trunk build --release
//}

インストールしたTrunkを使用して、実行環境（Ubuntu）内にコピーした@<code>{master}ブランチのコードからWebアプリをビルドします。ビルド結果のファイルは、実行環境（Ubuntu）の@<code>{dist}ディレクトリに生成されます。

//list[add_nojekyll][: .github/workflows/deploy.yaml]{
- name: Add .nojekyll
  run: touch dist/.nojekyll
//}

@<list>{add_nojekyll}では、実行環境（Ubuntu）に生成された@<code>{dist}ディレクトリの中に@<code>{.nojekyll}という空のファイルを作成しています。このファイルがあると、Github Pagesでデフォルトで実行する@<b>{Jekyll}の処理を無効にすることができます。

JekyllはMarkdownファイルやHTMLテンプレートからHTMLファイルを生成するツールです。
Github Pagesではこれがデフォルトで採用されているため、@<code>{README.md}などのファイルを設置するだけで、それらをHTMLに自動変換したWebページを公開することができます。

しかし、Rust+Yew+Trunkで構築したWebアプリを公開するのにJekyllは不要です。
また、このツールが動作することによって、Jekyllの仕様に合わない形式のファイルをGithub Pagesが無視してしまう場合があるため、明示的に停止させる必要があります。

Jekyllを無効にするためには名前が@<code>{.nojekyll}のファイルがあればよく、中身は空白で構いません。

//list[deploy_gh_pages][Github PagesにWebアプリをデプロイ: .github/workflows/deploy.yaml]{
- name: Deploy to GitHub Pages
  uses: peaceiris/actions-gh-pages@v3
  with:
    github_token: ${{ secrets.GITHUB_TOKEN }}
    publish_dir: ./dist
//}

最後に、実行環境（Ubuntu）に生成された@<code>{dist}ディレクトリの中身を@<code>{gh_pages}ブランチに送信（push）します。
処理には既存の@<code>{peaceiris/actions-gh-pages@v3}アクションを使用し、コピー元の@<code>{dist}ディレクトリは@<code>{publish_dir}によって指定します。

また、@<code>{github_token}で指定しているのはGitHub Actions専用の自動発行トークンです。push時には別途SSHキーなどが要求される場合がありますが、このトークンを使用するとそれを回避することができます。

== その他のファイル

前節までで主要なファイルの解説は完了しましたが、残りのファイルについても簡単に触れておきます。

=== .gitignore

このファイル内に記述したファイルやディレクトリは、GitやGithubでのバージョン管理の対象外になります。つまり、それらの内容に変更があっても履歴が記録されず、Githubにもアップロードされません。

//list[gitignore][バージョン管理から除外するファイル: .gitignore]{
/target
/dist
//}

@<list>{gitignore}に示した通り、ここでは2つのディレクトリ（@<code>{target}と@<code>{dist}）を除外しています。@<code>{master}ブランチで管理したいのはコードのみであるため、ビルドの成果物が入るこれらのディレクトリの変更履歴を記録する必要はありません。