import os

def prep_update(addon_folder_path):
    fnc_fldr = os.path.join(addon_folder_path,"functions")
    XEH_PREP_hpp_file = os.path.join(addon_folder_path,"XEH_PREP.hpp")
    prep_text_lines = [
        "PREP({});\n".format(os.path.splitext(f)[0].replace("fnc_", ""))
        for f in os.listdir(fnc_fldr)
        if os.path.isfile(os.path.join(fnc_fldr, f)) and os.path.splitext(f)[1] == ".sqf"
    ]
    with open(XEH_PREP_hpp_file,"w") as f:
        f.writelines(prep_text_lines)

def get_addons_folder_path():
    tools_dir = os.path.dirname(__file__)
    root_dir = os.path.dirname(tools_dir)
    addonsDir = os.path.join(root_dir,"addons")
    return addonsDir
def get_addons():
    addon_dir = get_addons_folder_path()
    dirs = [f for f in os.listdir(addon_dir) if os.path.isdir(os.path.join(addon_dir, f)) & (f != "main")]
    dirs_abs = [os.path.join(addon_dir,f) for f in dirs]
    return dirs_abs

def prep_update_all():
    for addon in get_addons():
        prep_update(addon)
    return
prep_update_all()