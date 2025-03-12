import tomllib
import tomli_w
import os

def execute():
    # ユーザーからの入力を取得
    name = input("Enter the name (e.g. 'Arma Addon Template'): ")
    author = input("Enter the author (e.g. 'FooBar Team'): ")
    prefix = input("Enter the prefix (e.g. 'aam'): ")
    mainprefix = input("Enter the main prefix (e.g. 'z'): ")

    # git_hashは固定値0
    git_hash = 0

    # このスクリプトのディレクトリから2階層上をプロジェクトルートとする
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    file_path = os.path.join(base_dir, ".hemtt", "project.toml")

    # 書き込み先のディレクトリを作成（存在しない場合）
    os.makedirs(os.path.dirname(file_path), exist_ok=True)

    # 既存のTOMLデータを読み込み
    toml_data = {}
    if os.path.exists(file_path):
        with open(file_path, "rb") as f:
            toml_data = tomllib.load(f)

    # 入力値を反映
    toml_data.update({
        "name": name,
        "author": author,
        "prefix": prefix,
        "mainprefix": mainprefix,
        "git_hash": git_hash
    })

    # 書き込み
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(tomli_w.dumps(toml_data))  # dump() ではなく dumps() を使う

    print(f"TOMLファイルが作成または更新されました: {file_path}")

if __name__ == "__main__":
    execute()
