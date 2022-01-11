#!/bin/bash
workdir=$(cd $(dirname $0); pwd)
configdir=$workdir"/config/"

board_name=(WT32_SC01_LANDSCAPE WT32_SC01_PORTRAIT WT154-S2MI1-PERFORMANCE WT154-S2MI1-WIFI WT154_C3SI1 WT-86-32-3ZW0-PERFORMANCE WT-86-32-3ZW0-WIFI WT-86-32-3ZW1-PERFORMANCE WT-86-32-3ZW1-WIFI WT280-S2MT1 WT280-S2MI1)
component_name=(qmsd_init lvgl blockly lvgl_esp32_drivers bus qmsd_ui)
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

mv -f components/qmsd_ui/libqmsd_ui.a components/qmsd_ui/lib/libqmsd_ui.a

cp $configdir${board_name[board-1]}/sdkconfig_${board_name[board-1]} sdkconfig
echo '--- sdkconfig done'
echo
echo "Done"
rm -rf build
else
echo 'Unknown board type'
fi

