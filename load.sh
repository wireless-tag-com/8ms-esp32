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
    ZX3D50CE02S_USRC_4832
    ZX3D95CE01S_AR_4848
    ZX3D95CE01S_UR_4848
    ZX4D30NE01S_UR_4827
    ZX4D60_AR_4896
    ZX2D10GE01R_V_4848
    ZX7D00CE01S_UR_8048
    ZX7D00CE01S_V12_8048
    ZX3D95CE01S_TR_4848
    )
component_name=(lvgl qmsd_init screen touch_panel)
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

