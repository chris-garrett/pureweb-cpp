@REM Usage: CopyPrereqs.bat $(SolutionDir) $(TargetDir) #{variant} #{debug_flag}

xcopy /YDFI "%PUREWEB_LIBS%\C++\VS2010\lib\CSI*%3%4.dll" "%2"
xcopy /YDFI "%PUREWEB_LIBS%\C++\VS2010\lib\CSI*%3%4.pdb" "%2"
xcopy /YDFI "%PUREWEB_LIBS%\C++\VS2010\lib\libjpeg%3%4.dll" "%2"
xcopy /YDFI "%PUREWEB_LIBS%\C++\VS2010\lib\icu*%3.dll" "%2"
xcopy /YDFI "%PUREWEB_LIBS%\C++\VS2010\lib\libx264*.dll" "%2"

if "%4" == "d" (
    xcopy /YDFI "%QTDIR%\bin\Qt5Guid.dll" "%2"
    xcopy /YDFI "%QTDIR%\bin\Qt5Cored.dll" "%2" 
    xcopy /YDFI "%QTDIR%\bin\Qt5Widgetsd.dll" "%2"  
    xcopy /YDFI "%QTDIR%\lib\Qt5Guid.pdb" "%2"
    xcopy /YDFI "%QTDIR%\lib\Qt5Cored.pdb" "%2" 
    xcopy /YDFI "%QTDIR%\lib\Qt5Widgetsd.pdb" "%2"  
) else (
 	xcopy /YDFI "%QTDIR%\bin\Qt5Gui.dll" "%2"
 	xcopy /YDFI "%QTDIR%\bin\Qt5Core.dll" "%2"	
 	xcopy /YDFI "%QTDIR%\bin\Qt5Widgets.dll" "%2"
)
