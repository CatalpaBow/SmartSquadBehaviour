import os
import sys
import shutil
import tomllib

def excute(addon_name):
    ##ルートディレクトリを調整
    root_dir = ".."
    if os.path.exists("addons"):
        root_dir = "."
    os.chdir(root_dir)

    folder_path = create_addon_folder_from_template(addon_name)
    print("以下のパスにアドオンフォルダを作成しました:",folder_path)
    rewrite_files_based_on_project_cfg(addon_name,folder_path)
    print("アドオンフォルダの作成が完了しました")


def create_addon_folder_from_template(addon_name):
    if(addon_name == 'main'):
        template_path = './tools/addonTemplate/main'
    else:
        template_path = './tools/addonTemplate/blank'
    new_addon_path = './addons/{}'.format(addon_name) 
    
    shutil.copytree(template_path, new_addon_path)
    return new_addon_path

def rewrite_files_based_on_project_cfg(addon_name,addon_path):
    cfg = load_project_cfg()
    rewrite_table = create_rewrite_table(addon_name,cfg)
    excute_rewrite(os.path.abspath(addon_path),rewrite_table)
    return


def create_rewrite_table(addon_name,config):
    return  {
         'replacement_MAINPREFIX'  : config['mainprefix'],
         'replacement_PREFIX'      : config['prefix'], 
         'replacement_upper_PREFIX': config['prefix'].upper(),
         'replacement_MODNAME'     : config['name'],
         'replacement_AUTHOR'      : config['author'],
         'blank'                   : addon_name, 
         'Blank'                   : addon_name.capitalize(),
         'BLANK'                   : addon_name.upper()
        }
def load_project_cfg():
    with open(".hemtt/project.toml", 'rb') as fin:
        config = tomllib.load(fin)
    print("パス .hemtt/project.toml からconfigを読み込みました.")
    show_project_cfg_info(config)
    return config

def excute_rewrite(path,replacement_map):
    for path in getAllFilePath(path):
        with open(path, 'r', encoding="utf-8") as f:
            lines = f.readlines()
            updated_lines = [replace_line(line, replacement_map) for line in lines]
        
        with open(path, 'w', encoding="utf-8") as f:
            f.writelines(updated_lines)
            f.close()

def show_project_cfg_info(config):
    print('--構成内容--')
    print('name:',config['name'])
    print('author:',config['author'])
    print('prefix:' ,config['prefix'])
    print('mainprefix:',config['mainprefix'])

def getAllFilePath(path) :
    for root, _, files in os.walk(path):
        for filename in files:
            yield os.path.join(root, filename)

def replace_line(line, replacements):
    global updated
    for pattern, replacement in replacements.items():
        if( pattern in line):
            line = line.replace(pattern, replacement)
            updated = True    
    return line
    
if __name__ == "__main__":
    addon_name = input("Enter the addon name:")
    excute(addon_name)
    sys.exit()