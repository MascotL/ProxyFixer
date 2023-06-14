# ProxyFixer
解决电脑重启后在之前未取消代理的情况下电脑无法正常上网   
适用于clash重启后的无法上网的bug  
需要将程序添加到开机自启动文件夹里

### 设置开机自启动:
在 Windows 系统中，您可以将可执行文件或快捷方式放置在以下文件夹中的任何一个：  
```
%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup
%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp
```
在 Unix-like 系统（如Linux、Mac等）中，您可以将可执行文件或脚本放置在以下文件夹中的任何一个：  
```
/etc/init.d/ （全局）  
/etc/rc.d/ （全局）  
~/.config/autostart/ （用户级别）  
```
请注意，在 Unix-like 系统中，您可能还需要设置文件的执行权限。  
