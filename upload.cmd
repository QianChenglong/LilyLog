@ECHO OFF

SETLOCAL

SET SSH=E:\Soft\rsync\bin\cwRsync_5.4.1_x86_Free\ssh.exe
SET SSH_KEY=/cygdrive/E/pan/Soft/rsync/bin/cwRsync_5.4.1_x86_Free/id_rsa
SET SSH_OPTION=-i %SSH_KEY% -o StrictHostKeyChecking=no

SET RSYNC=E:\Soft\rsync\bin\cwRsync_5.4.1_x86_Free\rsync.exe
SET RSYNC_OP=-avzP -e "%SSH% %SSH_OPTION%" --delete --exclude={build,.git,doc,test,.swp}

SET RHOST=120.25.250.237
SET RUSER=wallace
SET RPATH=%RUSER%@%RHOST%:/home/wallace/

SET LPATH=/cygdrive/E/Programming/SourceCode/LilyLog

%RSYNC% %RSYNC_OP% %LPATH% %RPATH%
