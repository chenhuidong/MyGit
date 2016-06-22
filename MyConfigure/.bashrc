# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions

export PS1='[chenhuidong@\u \w]\$ '
export SVN_EDITOR=vi

#cmd
alias l="ls -ltrF"
alias la="ls -altrF"

#dir
alias cdgit="cd /home/chenhuidong/MyProgram/MyGit"
alias cdcpp="cd /home/chenhuidong/MyProgram/MyGit/Cpp"
alias cdweb="cd /usr/local/nginx/html"
alias cdphp="cd /home/chenhuidong/MyProgram/MyPHP"
alias cdlog="cd /home/chenhuidong/Log"
alias cdlua="cd /home/chenhuidong/MyProgram/MyGit/Lua"

#svn
alias sp="svn up"

#mysql
#alias my="mysql -h'121.42.27.147' -umysql -P54321 -pAdmin_123 -Dpublic"
#alias init="/home/chenhuidong/MyTools/init.sh"

export PATH=/usr/local/bin:/usr/bin/openssl:$PATH
export C_INCLUDE_PATH=/usr/local/include/hiredis:/home/chenhuidong/MyTools/MyInclude:/usr/local/include/glib-2.0:/usr/local/include/gio-unix-2.0:/usr/local/lib/glib-2.0/include:/usr/include/dbus-1.0:/usr/include:/usr/local/include:/usr/include/openssl:/home/chenhuidong/MyProgram/MyGit/Cpp/Linux/apue.2e/include:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=/usr/local/include/hiredis:/home/chenhuidong/MyTools/MyInclude:/usr/local/include/glib-2.0:/usr/local/include/gio-unix-2.0:/usr/local/lib/glib-2.0/include:/usr/include/dbus-1.0:/usr/include:/usr/local/include:/usr/include/openssl:/home/chenhuidong/MyProgram/MyGit/Cpp/Linux/apue.2e/include:$CPLUS_INCLUDE_PATH
export LD_LIBRARY_PATH=/home/chenhuidong/MyTools/MyLib:/usr/local/lib64:/usr/lib:/usr/local/lib:/usr/lib64/openssl:/home/chenhuidong/MyProgram/MyGit/Cpp/Linux/apue.2e/lib:$LD_LIBRARY_PATH
export LIBRARY_PATH=/home/chenhuidong/MyTools/MyLib:/usr/local/lib64:/usr/lib:/usr/local/lib:/usr/lib64/openssl:/home/chenhuidong/MyProgram/MyGit/Cpp/Linux/apue.2e/lib:$LIBRARY_PATH
export POCO_BASE=/home/chenhuidong/MyProgram/MyGit/Cpp/poco-1.6.1-all
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

#dbus
DBUS_SESSION_BUS_ADDRESS='unix:abstract=/tmp/dbus-J7PNkyKqOv,guid=4e6d607ad66d8cf0921899365727971c';
export DBUS_SESSION_BUS_ADDRESS;
DBUS_SESSION_BUS_PID=15778;

#glog
export LOG_PATH=/home/chenhuidong/Log

#workpath
export WORK_PATH=/home/chenhuidong/MyProgram/MyGit/Cpp/Boost/MyBoost
