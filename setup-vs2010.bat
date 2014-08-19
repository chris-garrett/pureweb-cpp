call "%VS100COMNTOOLS%\vsvars32.bat"
set QMAKESPEC=win32-msvc2010
qmake -r -tp vc
