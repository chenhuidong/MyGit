# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions
export PS1='[chenhuidong@51linux \w]\$ '
export SVN_EDITOR=vi
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/usr/lib/libevent/lib:~/usr/lib/glog/lib:~/usr/lib/tinyxml:~/usr/lib/stlport/lib:~/usr/lib/sqlite/lib
export LIBRARY_PATH=$LIBRARY_PATH:~/usr/lib/libevent/lib:~/usr/lib/glog/lib:~/usr/lib/tinyxml:~/usr/lib/stlport/lib:~/usr/lib/sqlite/lib
export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:~/usr/lib/libevent/include:~/usr/lib/glog/include:~/usr/lib/tinyxml:~/usr/lib/stlport/include:~/usr/lib/sqlite/include
export WORKPATH=/home/51linux_LxomB0aQ
export LOGPATH=/home/51linux_LxomB0aQ/Log

#tinyxml
export TINYXML_ROOT=~/usr/lib/tinyxml

#cmd
alias l="ls -ltrF"
alias la="ls -altrF"

#dir
alias cdgit="cd ~/MyProgram/MyGit"
alias cdcpp="cd ~/MyProgram/MyGit/Cpp"

#svn
alias sp="svn up"

#git
alias gc="git commit -a"
alias gs="git status"
alias gh="git push"
alias gl="git pull"

