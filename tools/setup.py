import setup_venv
import setup_addon_main
import os
import subprocess
def excute():
    # toolsフォルダーのパスを取得
    script_path_abs = os.path.abspath(__file__)
    tools_folder_path = os.path.dirname(script_path_abs)
    root_path = os.path.dirname(tools_folder_path)
    os.chdir(root_path)

    # 各スクリプトのパスを取得
    setup_addon_main = os.path.join(tools_folder_path, "setup_addon_main.py")
    setup_project_cfg = os.path.join(tools_folder_path, "setup_project_cfg.py")

    # 各セットアップスクリプトを実行
    # 仮想環境のセットアップ後、仮想環境内で各セットアップを実行
    venv_py = setup_venv.excute()
    subprocess.check_call([venv_py,setup_project_cfg])
    subprocess.check_call([venv_py,setup_addon_main])

if __name__ == "__main__":
    excute()