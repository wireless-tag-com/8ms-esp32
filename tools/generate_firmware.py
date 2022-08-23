from ast import arg
import os
import re
import argparse
import sys

src_path = ""

def cover_to_firmware(cover_list, dst_path=None):
    cur_offset = cover_list[0][0]
    if dst_path:
        dst_file = f'{dst_path}/firmware_{hex(cur_offset)}.bin'
    else:
        dst_file = f'firmware_{hex(cur_offset)}.bin'

    with open(dst_file, 'wb') as fout:
        for offset, file_in in cover_list:
            assert offset >= cur_offset
            fout.write(b'\xff' * (offset - cur_offset))
            cur_offset = offset
            with open(file_in, 'rb') as fin:
                data = fin.read()
                fout.write(data)
                cur_offset += len(data)
    return dst_file

def generate(build_path, dst_path=None):
    with open(f"{build_path}/flash_args") as fin:
        firmware_info = fin.read()

    firmware_info = re.findall(r'0x\d+ .*.bin', firmware_info)
    bin_file = []
    for i in firmware_info:
        data = i.split(" ")
        data[0] = int(data[0][2:], base=16)
        data[1] = f'{build_path}/{data[1]}'
        bin_file.append(data)
    bin_file.sort(key = lambda x: x[0])

    return cover_to_firmware(bin_file, dst_path)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='QMSD generate firmware')
    parser.add_argument('-p', '--build_path')
    parser.add_argument('-o', '--output_path', default=None)
    args = parser.parse_args()
    if not args.build_path:
        sys.exit(1)
    file_name = generate(args.build_path, args.output_path)
    print(f"Generate {file_name} success")
    addr = file_name.split("0x")[-1][:-4]
    print(f"esptool.py -p /dev/ttyACM0 write_flash 0x{addr} {file_name}")
