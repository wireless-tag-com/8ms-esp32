#!/bin/bash
workdir=$(cd $(dirname $0); pwd)
configdir=$workdir"/config/"

board_name=(
    WT32_SC01
    WT154_C3SI1 
    WT154_S2MI1
    WT_86_32_3ZW1
    WT280_S2MX1
    WT240_C3SI1
    WT_0_S2_240MW1
    ZX350-S3MI1
    ZX430-S3RI1
    ZX430-S3RI2
    ZX480-S3ZW1)
component_name=(bus lvgl qmsd_init screen touch_panel)
for((i=0;i<${#board_name[@]};i++))
do
echo $[i+1]"): "${board_name[i]}
done

read board
product=$product${board_name[board-1]}

if [ $board -le ${#board_name[@]} ] && [ $board -gt 0 ]
then
echo 'Set to '$board'-'${board_name[board-1]}

for((i=0;i<${#component_name[@]};i++))
do
cp $configdir$product"/lib"${component_name[i]}".a" $workdir"/components/"${component_name[i]}
echo '--- '${component_name[i]}' done'
done

cp $configdir${board_name[board-1]}/sdkconfig sdkconfig
echo '--- sdkconfig done'
echo
echo "Done"
rm -rf build
else
echo 'Unknown board type'
fi

