# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
       . /etc/bashrc
fi

# User specific aliases and functions
export PS1='[chenhuidong@51linux \w]\$ '
export SVN_EDITOR=vi

export LD_LIBRARY_PATH=/mnt/home2/51linux_LxomB0aQ/usr/lib/libtool/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/poco/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/openssl/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/libevent/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/glog/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/tinyxml:/mnt/home2/51linux_LxomB0aQ/usr/lib/stlport/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/boost/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/expat/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/dbus/lib:/mnt/home2/51linux_e6MF016s/usr/lib/mysql/lib/mysql:/mnt/home2/51linux_e6MF016s/usr/lib/unixODBC/lib:/mnt/home2/51linux_e6MF016s/usr/lib/sqlite/lib:/mnt/home2/51linux_e6MF016s/usr/lib/myodbc/lib:/mnt/home2/51linux_e6MF016s/usr/lib/sqliteodbc:$LD_LIBRARY_PATH

export LIBRARY_PATH=/mnt/home2/51linux_LxomB0aQ/usr/lib/libtool/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/poco/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/openssl/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/libevent/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/glog/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/tinyxml:/mnt/home2/51linux_LxomB0aQ/usr/lib/stlport/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/boost/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/expat/lib:/mnt/home2/51linux_LxomB0aQ/usr/lib/dbus/lib:/mnt/home2/51linux_e6MF016s/usr/lib/mysql/lib/mysql:/mnt/home2/51linux_e6MF016s/usr/lib/unixODBC/lib:/mnt/home2/51linux_e6MF016s/usr/lib/sqlite/lib:/mnt/home2/51linux_e6MF016s/usr/lib/myodbc/lib:/mnt/home2/51linux_e6MF016s/usr/lib/sqliteodbc:$LIBRARY_PATH

export CPLUS_INCLUDE_PATH=/mnt/home2/51linux_LxomB0aQ/usr/lib/libtool/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/poco/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/openssl/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/libevent/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/glog/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/tinyxml:/mnt/home2/51linux_LxomB0aQ/usr/lib/stlport/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/boost/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/expat/include:/mnt/home2/51linux_LxomB0aQ/usr/lib/dbus/include/dbus-1.0:/mnt/home2/51linux_e6MF016s/usr/lib/mysql/include/mysql:/mnt/home2/51linux_e6MF016s/usr/lib/unixODBC/include:/mnt/home2/51linux_e6MF016s/usr/lib/sqlite/include:$CPLUS_INCLUDE_PATH

export PATH=/mnt/home2/51linux_LxomB0aQ/usr/lib/libtool/bin:/mnt/home2/51linux_LxomB0aQ/usr/lib/poco/bin:/mnt/home2/51linux_LxomB0aQ/usr/lib/openssl/bin:/mnt/home2/51linux_LxomB0aQ/usr/lib/dbus/bin:/mnt/home2/51linux_e6MF016s/usr/lib/mysql/bin:/mnt/home2/51linux_e6MF016s/usr/lib/unixODBC/bin:/mnt/home2/51linux_e6MF016s/usr/lib/sqlite/bin:/mnt/home2/51linux_e6MF016s/usr/lib/myodbc/bin:$PATH

export WORKPATH=/mnt/home2/51linux_LxomB0aQ
export LOGPATH=/mnt/home2/51linux_LxomB0aQ/Log
export WORKPATH2=/mnt/home2/51linux_e6MF016s
export LOGPATH2=/mnt/home2/51linux_e6MF016s/Log

#tinyxml
export TINYXML_ROOT=/mnt/home2/51linux_LxomB0aQ/usr/lib/tinyxml

#cmd
alias l="ls -ltrF"
alias la="ls -altrF"

#dir
alias cdgit="cd /mnt/home2/51linux_LxomB0aQ/MyProgram/MyGit"
alias cdcpp="cd /mnt/home2/51linux_LxomB0aQ/MyProgram/MyGit/Cpp"

#svn
alias sp="svn up"

#git
alias gc="git commit -a"
alias gs="git status"
alias gh="git push"
alias gl="git pull"

#mysql
alias mr="mysql -h'121.42.27.147' -uroot -p111111 -P54321 -Dmysql"
alias mp="mysql -h'121.42.27.147' -upublic -p111111 -P54321 -Dpublic"

#connect
alias ssh1="ssh 51linux_LxomB0aQ@121.42.27.147"
alias sftp1="sftp 51linux_LxomB0aQ@121.42.27.147"
alias ssh2="ssh 51linux_e6MF016s@121.42.27.147"
alias sftp2="sftp 51linux_e6MF016s@121.42.27.147"
