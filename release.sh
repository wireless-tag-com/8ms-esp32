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

workdir=$(cd $(dirname $0); pwd)

for((i=0;i<${#board_name[@]};i++))
do

echo $[i+1] | bash load.sh

if [ $? -ne 0 ]
then
    exit
fi

idf.py build
if [ $? -ne 0 ]
then
    exit
fi

echo $[i+1] | bash save.sh

if [ $? -ne 0 ]
then
    exit
fi

echo "saved----"${board_name[i]}
done

for((i=0;i<${#component_name[@]};i++))
do
cp $workdir"/config/CMAKE/CMakeLists-"${component_name[i]}".txt" $workdir"/components/"${component_name[i]}"/CMakeLists.txt"
done
echo "--------cmake replaced"

cp config/CMAKE/load.sh ./

for((i=0;i<${#component_name[@]};i++))
do
find $workdir"/components/"${component_name[i]} -name "*.c" | xargs rm -f
done

echo "1" | bash load.sh