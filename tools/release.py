import os
import shutil
import argparse
import sys

ignore_dir = (".git", "build", ".vscode", "output")

build_dir = "/home/sorz/code_repository/qmsd_8ms_demo/example/get-start/build"
src_path = "/home/sorz/code_repository/qmsd_8ms_demo"
dst_path = "/home/sorz/code_repository/qmsd_8ms_demo/release"
static_link_libraries_path = build_dir + '/esp-idf'

def get_files(components_path, filter, exclude_dirs=None):
    if not exclude_dirs:
        exclude_dirs = []
    files = []
    for path, dir, file in os.walk(components_path):
        mark_skip = False
        for i in exclude_dirs:
            if path.startswith(f"{components_path}/{i}"):
                mark_skip = True
                break
        if not mark_skip:
            files += [f"{path}/{i}" for i in file]
    files = [i for i in files if filter in i]
    return files

def get_release_components(src_path):
    components = {}
    cmake_release_file = get_files(src_path, "CMakeLists.release")
    for file in cmake_release_file:
        component_name = file.split("/")[-2]
        components[component_name] = "/".join(file.split("/")[:-1])
    return components

def rm_files(path, filter):
    files = get_files(path, filter)
    for i in files:
        os.remove(i)

def generate_release(src, dst, static_link_path, ignore_dir=None):
    shutil.rmtree(dst, ignore_errors=True)
    shutil.copytree(src, dst, ignore=lambda directory, contents: ignore_dir if ignore_dir else set())

    release_components = get_release_components(dst)
    for name, path in release_components.items():
        rm_files(path, '.c')
        shutil.copy(f'{static_link_path}/{name}/lib{name}.a', f'{path}/lib{name}.a')
        shutil.move(f'{path}/CMakeLists.release', f'{path}/CMakeLists.txt')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='QMSD release sdk')
    parser.add_argument('-p', '--src_path')
    parser.add_argument('-o', '--dst_path')
    parser.add_argument('-l', '--link_path')
    args = parser.parse_args()
    if not args.src_path or not args.dst_path or not args.link_path:
        sys.exit(1)

    src_path = args.src_path
    dst_path = args.dst_path
    link_path = args.link_path
    generate_release(src_path, dst_path, f'{link_path}/esp-idf', ignore_dir)
