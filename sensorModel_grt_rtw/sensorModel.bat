set MATLAB=D:\Programs\MATLAB\R2018b

cd .

if "%1"=="" ("D:\Programs\MATLAB\R2018b\bin\win64\gmake"  -f sensorModel.mk all) else ("D:\Programs\MATLAB\R2018b\bin\win64\gmake"  -f sensorModel.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
