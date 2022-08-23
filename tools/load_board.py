import os
import argparse
import sys
import subprocess
import time

BOARD_RELATIVE_PATH = "components/qmsd_board/board"

def get_qmsd_sdk_path():
    dirname, filename = os.path.split(os.path.abspath(__file__))
    return '/'.join(dirname.split('/')[:-1])

def scan_board(path):
    chip_type =  os.listdir(path)
    board = {}
    for chip in chip_type:
        boards = os.listdir(f'{path}/{chip}')
        for i in boards:
            board[i] = f'{path}/{chip}/{i}'
    return board

def run():
    parser = argparse.ArgumentParser(description='QMSD auto select board')
    parser.add_argument('-p', '--project_path')
    parser.add_argument('-b', '--board_name', default=None)
    args = parser.parse_args()
    if not args.project_path:
        sys.exit(1)
    project_path = args.project_path

    print(f"Current project path: {project_path}")
    print("--- Please select board to load sdkconfig ---")
    board_dict = scan_board(get_qmsd_sdk_path() + '/' + BOARD_RELATIVE_PATH)
    boards = list(board_dict.keys())
    boards.sort()
    if args.board_name:
        select = args.board_name
    else:
        while True:
            for num, i in enumerate(boards):
                print(f'{num}): {i}')
            print(f'x): exit')
            select = input(f"Select board [0 ~ {len(boards) - 1}]: ").strip()
            if select == 'x':
                sys.exit(0)
            try:
                select = int(select)
                if select < 0 or select > len(boards) - 1:
                    raise ValueError
                break
            except ValueError:
                print("Select input error, pls retry")
    print(f"Select board: {boards[select]}")
    src_path = f'{board_dict[boards[select]]}/sdkconfig'
    dst_path = f'{project_path}/sdkconfig'
    if not os.path.exists(src_path):
        print(f"Not found sdkconfig: {src_path}")
        sys.exit(1)

    with open(dst_path, 'w+') as fout:
        with open(src_path, "r") as fin:
            fout.write(fin.read())

    os.chdir(project_path)
    subprocess.run(["idf.py", "fullclean"])
    time.sleep(0.5)
    subprocess.run(["idf.py", "reconfigure"])
    
    print("Finish ~_~")

if __name__ == "__main__":
    run()
