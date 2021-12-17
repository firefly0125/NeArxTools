@echo off

if exist %LocalAppData%\Microsoft\MSBuild\v4.0\NeArxTest.Doc.Core.props del /Q %LocalAppData%\Microsoft\MSBuild\v4.0\NeArxTest.Doc.Core.props
copy %~dp0\props\NeArxTest.Doc.Core.props %LocalAppData%\Microsoft\MSBuild\v4.0
