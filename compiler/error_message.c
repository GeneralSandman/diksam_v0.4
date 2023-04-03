#include <string.h>
#include "diksamc.h"

ErrorDefinition dkc_error_message_format[] = {
    {"dummy"},
    {"文法エラー($(token)付近)"},
    {"不正な文字($(bad_char))"},
    {"関数名が重複しています($(name))"},
    {"不正なマルチバイト文字です。"},
    {"想定外のワイド文字列です。"},
    {"配列の要素をfinalにはできません。"},
    {"複合代入演算子をfinalに対しては適用できません。"},
    {"関数の引数名$(name)が重複しています。"},
    {"変数名$(name)が重複しています。"},
    {"変数または関数$(name)が見付かりません。"},
    {"$(name)は関数名ですが、関数呼び出しの()がありません。"},
    {"派生型へのキャスト、および派生型へのキャストはできません。"},
    {"$(src)から$(dest)へはキャストできません。"},
    {"算術演算子のオペランドの型が不正です。"},
    {"比較演算子のオペランドの型が不正です。"},
    {"論理and/or演算子のオペランドの型が不正です。"},
    {"マイナス演算子のオペランドの型が不正です。"},
    {"論理否定演算子のオペランドの型が不正です。"},
    {"インクリメント/デクリメント演算子のオペランドの型が不正です。"},
    {"関数呼び出し演算子のオペランドが関数名ではありません。"},
    {"関数$(name)が見付かりません。"},
    {"関数の引数の数が合いません。"},
    {"代入演算子の左辺が左辺値ではありません。"},
    {"ラベル$(label)が存在しません。"},
    {"配列リテラルには最低ひとつの要素が必要です。"},
    {"添字演算子[]の左辺が配列ではありません。"},
    {"配列の添字がintではありません。"},
    {"配列のサイズがintではありません。"},
    {"整数値をゼロで除算しています。"},
    {"package名が長過ぎます(いくらなんでも)"},
    {"requireされたファイルが見付かりません($(file))"},
    {"requireでエラーが発生しました($(status))。"},
    {"ひとつのソースから同一のパッケージを複数回"
     "requireしています($(package_name))。"},
    {"renameで改名される名前にはpackage指定が必要です。"},
    {"abstractが複数回指定されています。"},
    {"アクセス修飾子が複数回指定されています。"},
    {"overrideが複数回指定されています。"},
    {"virtualが複数回指定されています。"},
    {"その型にはメンバ演算子は適用できません。"},
    {"$(class_name)に$(member_name)というメンバはありません。"},
    {"メンバ$(member_name)はprivateのためアクセスできません。"},
    {"abstractなメソッドは実装を持てません。"},
    {"abstractでないメソッドには実装がなければなりません。"},
    {"複数のクラスを継承しています($(name)が2個目のクラス)。"},
    {"Disamでは、abstractクラス以外は継承できません"
     "(クラス$(name)はabstractではありません)。"},
    {"abstractクラス($(name))をnewしています。"},
    {"void型の関数が値を返しています。"},
    {"クラス$(name)が見付かりません。"},
    {"コンストラクタとして指定されているメンバ$(member_name)は"
     "メソッドではありません。"},
    {"newで指定されているメソッド$(member_name)がコンストラクタでは"
     "ありません。"},
    {"現状でフィールド($(member_name))は呼び出せません。"},
    {"メソッド$(member_name)に代入しようとしています。"},
    {"virtualでないメソッド($(name))はオーバーライドできません。"},
    {"メソッドをオーバーライドする際はoverrideの指定が必要です($(name))。"},
    {"abstractでないクラスに、abstractメソッド$(method_name)が存在します。"},
    {"スーパークラスがいないクラスでsuperを使っています。"},
    {"superはメソッドを呼ぶ以外使用できません。"},
    {"superのフィールドは参照できません。"},
    {"$(name)はフィールドです。オーバーライドできません。"},
    {"フィールド名$(name)が重複しています。"},
    {"配列に$(name)というメソッドはありません。"},
    {"文字列に$(name)というメソッドはありません。"},
    {"instanceofのオペランドは参照型でなければなりません。"},
    {"instanceofの右辺の型は参照型でなければなりません。"},
    {"instanceofの対象はクラスでなければなりません。"},
    {"このinstanceofは常に真です。"},
    {"このinstanceofは常に偽です。"},
    {"Diksamのインターフェイスには親子関係はないので、"
     "このinstanceofは常に偽です。"},
    {"ダウンキャストの対象となるのはクラスだけです。"},
    {"ダウンキャストの変換先となるのはクラスだけです。"},
    {"このダウンキャストは不要です。"},
    {"スーパークラスにダウンキャストしようとしています。"},
    {"継承関係のないクラスにダウンキャストしようとしています。"},
    {"Diksamのインターフェイスには親子関係はないので、"
     "ダウンキャストできません。"},
    {"クラス以外の型をcatchしています。"},
    {"catchしているクラス$(class_name)はExceptionの"
     "サブクラスではありません。"},
    {"クラス以外の型をthrowしています。"},
    {"throwしているクラス$(class_name)はExceptionの"
     "サブクラスではありません。"},
    {"オペランドのないthrowがcatchの外にあります。"},
    {"$(statement_name)文はfinally節には書けません。"},
    {"throwsに指定されている$(name)が見付かりません。"},
    {"throwsに指定されている$(name)はExceptionのサブクラスではありません。"},
    {"例外$(name)はthrows節に指定されるか、"
     "内部でcatchされなければなりません。"},
    {"自分自身をrequireしています。"},
    {"if文の条件式がboolean型ではありません。"},
    {"while文の条件式がboolean型ではありません。"},
    {"for文の条件式がboolean型ではありません。"},
    {"do while文の条件式がboolean型ではありません。"},
    {"case節の式の型が不一致です。"},
    {"変数$(name)はfinalです。代入できません。"},
    {"フィールド$(name)はfinalです。代入できません。"},
    {"finalな変数$(name)に初期化子がありません。"},
    {"オーバーライドしているメソッド$(name)のアクセス修飾子が、"
     "スーパークラスに比べ狭くなっています。"},
    {"メソッドまたは関数$(name)の引数の数が間違っています。"},
    {"メソッドまたは関数$(func_name)の$(index)番目の引数"
     "$(param_name)の型が間違っています。"},
    {"メソッドまたは関数$(name)の戻り値の型が不正です。"},
    {"メソッドまたは関数$(func_name)が、適合しない例外"
     "$(exception_name)をthrowsに記述しています。"},
    {"コンストラクタを直接呼び出すことはできません。"},
    {"型名$(name)が見付かりません。"},
    {"列挙型$(type_name)に$(enumerator_name)はありません。"},
    {"Diksamではインターフェイスは継承できません(今のところ)。"},
    {"メンバ$(member_name)はパッケージ外ではアクセスできません。"},
    {"クラス$(class_name)はパッケージ外ではアクセスできません。"},
    {"クラスの外でthisが使われています。"},
    {"クラスの外でsuperが使われています。"},
    {"~演算子のオペランドはintでなければなりません。"},
    {"二項ビット演算子のオペランドはintかbooleanでなければなりません。"},
    {"Cスタイルのコメントの途中でファイルが終了しました。"},
    {"文字列リテラルの途中でファイルが終了しました。"},
    {"文字リテラルが2文字以上あります。"},
    {"dummy"}
};
