# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
       . /etc/bashrc
fi

# User specific aliases and functions
export PS1='[chenhuidong@\u \w]\$ '
export SVN_EDITOR=vi

#WORKPATH
export PWORKPATH=/mnt/home2/51linux_LxomB0aQ
export PLOGPATH=$PWORKPATH/Log
export PLIBPATH=$PWORKPATH/usr/lib

export DBWORKPATH=/mnt/home2/51linux_e6MF016s
export DBLOGPATH=$DBWORKPATH/Log
export DBLIBPATH=$DBWORKPATH/usr/lib

export WEBWORKPATH=/mnt/home2/51linux_ASGNYtrL
export WEBLOGPATH=$WEBWORKPATH/Log
export WEBLIBPATH=$WEBWORKPATH/usr/lib

#tinyxml
export TINYXML_ROOT=/mnt/home2/51linux_LxomB0aQ/usr/lib/tinyxml

#library
export LD_LIBRARY_PATH=$WEBLIBPATH/php/lib:$WEBLIBPATH/libxml2/lib:$WEBLIBPATH/python/lib:$WEBLIBPATH/pcre/lib:$PLIBPATH/libtool/lib:$PLIBPATH/poco/lib:$PLIBPATH/openssl/lib:$PLIBPATH/libevent/lib:$PLIBPATH/glog/lib:$PLIBPATH/tinyxml:$PLIBPATH/stlport/lib:$PLIBPATH/boost/lib:$PLIBPATH/expat/lib:$PLIBPATH/dbus/lib:$DBLIBPATH/mysql/lib/mysql:$DBLIBPATH/unixODBC/lib:$DBLIBPATH/sqlite/lib:$DBLIBPATH/myodbc/lib:$DBLIBPATH/sqliteodbc:$LD_LIBRARY_PATH

export LIBRARY_PATH=$WEBLIBPATH/php/lib:$WEBLIBPATH/libxml2/lib:$WEBLIBPATH/python/lib:$WEBLIBPATH/pcre/lib:$PLIBPATH/libtool/lib:$PLIBPATH/poco/lib:$PLIBPATH/openssl/lib:$PLIBPATH/libevent/lib:$PLIBPATH/glog/lib:$PLIBPATH/tinyxml:$PLIBPATH/stlport/lib:$PLIBPATH/boost/lib:$PLIBPATH/expat/lib:$PLIBPATH/dbus/lib:$DBLIBPATH/mysql/lib/mysql:$DBLIBPATH/unixODBC/lib:$DBLIBPATH/sqlite/lib:$DBLIBPATH/myodbc/lib:$DBLIBPATH/sqliteodbc:$LIBRARY_PATH

export CPLUS_INCLUDE_PATH=$WEBLIBPATH/php/include:$WEBLIBPATH/libxml2/include:$WEBLIBPATH/python/include:$WEBLIBPATH/pcre/include:$PLIBPATH/libtool/include:$PLIBPATH/poco/include:$PLIBPATH/openssl/include:$PLIBPATH/libevent/include:$PLIBPATH/glog/include:$PLIBPATH/tinyxml:$PLIBPATH/stlport/include:$PLIBPATH/boost/include:$PLIBPATH/expat/include:$PLIBPATH/dbus/include/dbus-1.0:$DBLIBPATH/mysql/include/mysql:$DBLIBPATH/unixODBC/include:$DBLIBPATH/sqlite/include:$CPLUS_INCLUDE_PATH

export PATH=$WEBLIBPATH/nginx/sbin:$WEBLIBPATH/php/bin:$WEBLIBPATH/libxml2/bin:$WEBLIBPATH/python/bin:$WEBLIBPATH/pcre/bin:$PLIBPATH/libtool/bin:$PLIBPATH/poco/bin:$PLIBPATH/openssl/bin:$PLIBPATH/dbus/bin:$DBLIBPATH/mysql/bin:$DBLIBPATH/unixODBC/bin:$DBLIBPATH/sqlite/bin:$DBLIBPATH/myodbc/bin:$PATH

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
alias mr="mysql -h'121.42.27.147' -uroot -pChenhd@123 -P54321 -Dmysql"
alias mp="mysql -h'121.42.27.147' -upublic -p123456 -P54321 -Dpublic"

#connect
alias ssh1="ssh 51linux_LxomB0aQ@121.42.27.147"
alias sftp1="sftp 51linux_LxomB0aQ@121.42.27.147"
alias ssh2="ssh 51linux_e6MF016s@121.42.27.147"
alias sftp2="sftp 51linux_e6MF016s@121.42.27.147"
alias ssh3="ssh 51linux_ASGNYtrL@121.42.27.147"
alias sftp3="sftp 51linux_ASGNYtrL@121.42.27.147"

