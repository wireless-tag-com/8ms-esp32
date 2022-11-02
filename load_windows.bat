
@echo off &setlocal

setlocal enabledelayedexpansion

set boards[0]=WT32_SC01
set boards[1]=WT154_C3SI1
set boards[2]=WT154_S2MI1
set boards[3]=WT_86_32_3ZW1
set boards[4]=WT280_S2MX1
set boards[5]=WT240_C3SI1
set boards[6]=WT_0_S2_240MW1
set boards[7]=ZX3D50CE02S_USRC_4832
set boards[8]=ZX3D95CE01S_AR_4848
set boards[9]=ZX3D95CE01S_UR_4848
set boards[10]=ZX4D30NE01S_UR_4827
set boards[11]=ZX4D60_AR_4896
set boards[12]=ZX2D10GE01R_V_4848
set boards[13]=ZX7D00CE01S_UR_8048

set components[0]=bus
set components[1]=lvgl
set components[2]=qmsd_init
set components[3]=screen
set components[4]=touch_panel
set components[5]=qmsd_mod

echo "please select board(input 0-13)"
:input
set x=0

:SymLoop

if defined boards[%x%] ( 
    call echo "%x%): %%boards[%x%]%%"
    set /a "x+=1"
    GOTO :SymLoop
)

set /p board=

if not defined boards[%board%] (
    echo "please input right board index(0-13)"
    GOTO :input
)

call echo "use %%boards[%board%]%%"

set "f_name=%cd%\config\!!boards[%board%]!!
echo "%f_name%"
copy %f_name%\libqmsd_init.a %cd%\components\qmsd_init\
copy %f_name%\libbus.a %cd%\components\bus\
copy %f_name%\libqmsd_mod.a %cd%\components\qmsd_mod
copy %f_name%\libscreen.a %cd%\components\screen
copy %f_name%\libtouch_panel.a %cd%\components\touch_panel
copy %f_name%\liblvgl.a %cd%\components\lvgl
copy %f_name%\sdkconfig %cd%

del /f /s /q %cd%\build\*.*
rd /s /q %cd%\build
echo "copy lib ok"

pause