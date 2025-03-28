import os
import re
import networkx as nx
from pathlib import Path

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

def addon_folder():
    tools_dir = os.path.dirname(__file__)
    root_dir = os.path.dirname(tools_dir)
    addonsDir = os.path.join(root_dir,"addons")
    return addonsDir
def sub_addon_folders():
    addon_dir = addon_folder()
    dirs = [f for f in os.listdir(addon_dir) if os.path.isdir(os.path.join(addon_dir, f)) & (f != "main")]
    dirs_abs = [os.path.join(addon_dir,f) for f in dirs]
    return dirs_abs

def prep_update_all():
    for addon in sub_addon_folders():
        prep_update(addon)
    return

def auto_class_include():
    #SubAddonFolder→ClassFolder→hppFile
    sub_folder_list = sub_addon_folders()
    class_folder_list = [Path(path, "class") for path in sub_folder_list if Path(path, "class").is_dir()]
    hpp_file_lst = [sorted(fldr.rglob("*.hpp")) for fldr in class_folder_list]
    hpp_file_sorted_lst = sort_by_inheritance_relationship(hpp_file_lst)
    hpp_file_relative_lst = [
        [hpp.relative_to(*hpp.parts[:hpp.parts.index("class")]) for hpp in lst_in_lst] 
        for lst_in_lst in hpp_file_sorted_lst
    ]

    #SubAddon/$PBOPREFIX$ file
    prefix_file_lst = [path.with_name('$PBOPREFIX$') for path in class_folder_list]
    prefix = [Path(file.read_text(encoding="utf-8")) for file in prefix_file_lst]
    
    #Make path_pair_list $PBOPREFIX$ & hppFile
    path_pair = list(zip(prefix, hpp_file_relative_lst))

    #Create #include text
    include_line_text_lst = [
        [f'#include "\{prefix / hpp}"' for hpp in hpp_file_lst] 
        for prefix, hpp_file_lst in path_pair
    ]
    include_text = ["\n".join(lines) for lines in include_line_text_lst]

    # 出力先ファイルを設定
    output_path_lst = [path.with_name('script_class.hpp') for path in class_folder_list]
    
    # 書き込み処理
    for out_path, text in zip(output_path_lst, include_text):
        out_path.write_text(text)


def test():
    sub_folder_list = sub_addon_folders()
    class_folder_list = [Path(path, "class") for path in sub_folder_list if Path(path, "class").is_dir()]
    hpp_file_lst = [sorted(fldr.rglob("*.hpp")) for fldr in class_folder_list]
    print(hpp_file_lst)
    print("------------------")
    print(sort_by_inheritance_relationship(hpp_file_lst))

def sort_by_inheritance_relationship(hpp_file_list :list[list[Path]]):
    final_rslt = []
    for path_list in hpp_file_list:
        first = Path(*path_list[0] .parts[:path_list[0].parts.index("class") +1])
        content_list = [(path.read_text(encoding="utf-8")) for path in path_list]
        hpp_relative_list = [ Path(*path.parts[path.parts.index("class") + 1:]) for path in path_list]
        base_list = [find_base_class(content) for content in content_list]
        base_path_list = []
        for base in base_list:
            rslt = list(filter(lambda path: path.stem == base,hpp_relative_list))
            if(len(rslt) == 0):
                base_path_list.append(None)
                continue
            base_path_list.append(rslt[0])
        path_pair_list = zip(base_path_list,hpp_relative_list)
        
        no_base_class_list  = []
        base_class_list = []
        for pair in path_pair_list:
            if(pair[0] is None):
                no_base_class_list.append(pair[1])
                continue
            base_class_list.append(pair)

        G = nx.DiGraph()
        G.add_nodes_from(no_base_class_list)
        G.add_edges_from(base_class_list)
        second_path_list = list(nx.topological_sort(G))
        sorted_final = [first / second for second in second_path_list]
        final_rslt.append(sorted_final)
    return final_rslt
        
def find_base_class(text : str):
    match = re.search(r'\[\s*"#base"\s*,\s*([^\]]+)\s*\]',text)
    if match:
        parsed = re.search(r'GCLASS\((\w+)\)',match.group(1))
        return parsed.group(1)
    else:
        return None

auto_class_include()
prep_update_all()
