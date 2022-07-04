#!/bin/bash
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
    ZX2D10ECS_cESCP01)
component_name=(bus lvgl qmsd_init screen touch_panel qmsd_mod)
echo "Select the preset to be updated"
for((i=0;i<${#board_name[@]};i++))
do
echo $[i+1]"): "${board_name[i]}
done

read board

workdir=$(cd $(dirname $0); pwd)
#configdir=$workdir"/config"
configdir=$workdir"/config/"
product=$product${board_name[board-1]}

if [ $board -le ${#board_name[@]} ] && [ $board -gt 0 ]
then
echo "Try save into "$configdir$product
cd $configdir
rm -rf ${board_name[board-1]}
mkdir ${board_name[board-1]}
for((i=0;i<${#component_name[@]};i++))
do
cp $workdir"/build/esp-idf/"${component_name[i]}"/lib"${component_name[i]}".a" $configdir$product
done

cp $workdir"/sdkconfig" $configdir$product"/sdkconfig"
echo "Done"
else
echo 'Unknown board type'
fi
