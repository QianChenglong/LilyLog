@ECHO OFF

SETLOCAL

SET SSH=E:\Soft\rsync\bin\cwRsync_5.4.1_x86_Free\ssh.exe
SET SSH_KEY=/cygdrive/E/Soft/rsync/bin/cwRsync_5.4.1_x86_Free/id_rsa
SET SSH_OPTION=-i %SSH_KEY% -o StrictHostKeyChecking=no

SET RSYNC=E:\Soft\rsync\bin\cwRsync_5.4.1_x86_Free\rsync.exe
SET RSYNC_OP=-rvzP -e "%SSH% %SSH_OPTION%" --delete --exclude={build,.git,doc,test,.swp}

rem SET RHOST=app.gupiaoxianji.com
SET RHOST=debug.gupiaoxianji.com
SET RUSER=root
SET RPATH=%RUSER%@%RHOST%:/opt/lilylog

SET LPATH=/cygdrive/E/Programming/SourceCode/LilyLog/

%RSYNC% %RSYNC_OP% %LPATH% %RPATH%
