import os
import sys
import subprocess
def excute():
    # スクリプトの場所から、プロジェクトルートのパスを取得
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    # 仮想環境のパス（プロジェクトルート直下の .venv フォルダ）
    venv_dir = os.path.join(base_dir, '.venv')

    # 仮想環境が存在しなければ作成
    if not os.path.exists(venv_dir):
        print(f"Creating virtual environment at: {venv_dir}")
        subprocess.check_call([sys.executable, "-m", "venv", venv_dir])
        print(".venv created successfully!")
    else:
        print(".venv already exists.")

    # 仮想環境内のPython実行ファイルのパスを取得
    if os.name == 'nt':
        venv_python = os.path.join(venv_dir, 'Scripts', 'python.exe')
    else:
        venv_python = os.path.join(venv_dir, 'bin', 'python')

    # requirements.txtが存在すれば、仮想環境のPythonでpipを実行してパッケージをインストール
    requirements_file = os.path.join(base_dir, 'requirements.txt')
    if os.path.exists(requirements_file):
        print(f"Installing packages from {requirements_file} using virtual environment...")
        subprocess.check_call([venv_python, '-m', 'pip', 'install', '-r', requirements_file])
        print("Packages installed successfully!")
    else:
        print("requirements.txt not found.")
    return venv_python




if __name__ == "__main__":
    excute()