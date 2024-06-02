; Inno Setup Script
[Setup]
AppName=Vardenis-Pavardenis
AppVersion=3.0
DefaultDirName={pf64}\VU\Vardenis-Pavardenis
DefaultGroupName=VU\Vardenis-Pavardenis
OutputBaseFilename=Setup
OutputDir=C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector
PrivilegesRequired=admin
ArchitecturesInstallIn64BitMode=x64

[Files]
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\test_executable.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O1.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O2.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O3.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\studentai10000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\studentai100000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\test_executable.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O1.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O2.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Gytis\Desktop\v3.0\Obj.-programavimas-3uzd\vector\run_O3.bat"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Vardenis-Pavardenis Test"; Filename: "{app}\test_executable.bat"
Name: "{group}\Vardenis-Pavardenis Opt1"; Filename: "{app}\run_O1.bat"
Name: "{group}\Vardenis-Pavardenis Opt2"; Filename: "{app}\run_O2.bat"
Name: "{group}\Vardenis-Pavardenis Opt3"; Filename: "{app}\run_O3.bat"
Name: "{commondesktop}\Vardenis-Pavardenis Test"; Filename: "{app}\test_executable.bat"
Name: "{commondesktop}\Vardenis-Pavardenis Opt1"; Filename: "{app}\run_O1.bat"
Name: "{commondesktop}\Vardenis-Pavardenis Opt2"; Filename: "{app}\run_O2.bat"
Name: "{commondesktop}\Vardenis-Pavardenis Opt3"; Filename: "{app}\run_O3.bat"

[Run]
Filename: "{app}\test_executable.bat"; Description: "{cm:LaunchProgram,Vardenis-Pavardenis Test}"; Flags: shellexec runascurrentuser
Filename: "{app}\run_O1.bat"; Description: "{cm:LaunchProgram,Vardenis-Pavardenis Opt1}"; Flags: shellexec runascurrentuser
Filename: "{app}\run_O2.bat"; Description: "{cm:LaunchProgram,Vardenis-Pavardenis Opt2}"; Flags: shellexec runascurrentuser
Filename: "{app}\run_O3.bat"; Description: "{cm:LaunchProgram,Vardenis-Pavardenis Opt3}"; Flags: shellexec runascurrentuser

[UninstallDelete]
Type: filesandordirs; Name: "{app}"
