#!/bin/bash
#Author:LvXudong
#Time:2023 年 11月 07日 22时58分21秒
#Name:backup.sh
#Version:V1.0
#Description:This is a production script.

BACKUPDIR=${1:-"${HOME}/Backup"}
LOCALBACKUPDIR=${2:-"${HOME}/backup"}

VIMRC=$HOME/.vimrc
VIM_RUNTIME_DIR=$HOME/.vim_runtime
NVIM_CONFIG=$HOME/.config/nvim
VSCODE_CONFIG=$HOME/.config/Code/User/settings.json
MYBASH=/usr/local/mybash

function backup_dir(){
	PREFIX=${2:-$HOME}

	if [[ -d $PREFIX/${1} ]];then
		cp $PREFIX/$1 $BACKUPDIR/$1 -rf

		if [[ $?==0 ]]; then
			echo "$1 config file backup successfully!"
		fi
	fi

}
backup_file(){
	PREFIX=${2:-$HOME}

	if [[ -f $PREFIX/${1} ]];then
		cp $PREFIX/$1 $BACKUPDIR/$1 -f

		if [[ $?==0 ]]; then
			echo "$1 config file backup successfully!"
		fi
	fi


}
rm $BACKUPDIR -rf
#mkdir -p $BACKUPDIR
if [[ -d $LOCALBACKUPDIR ]]; then
	cp $LOCALBACKUPDIR $BACKUPDIR -rf
else
	mkdir -p $BACKUPDIR
fi

NVIDIA_DRIVE_VERSION=$(nvidia-detector 2>/dev/null)
if ! [[ -z $NVIDIA_DRIVE_VERSION ]]; then
	echo $NVIDIA_DRIVE_VERSION >$BACKUPDIR/.nvidia_driver_version
	echo "nvdia driver version is backup successfully"
else
	echo "there is not nvidia driver"
fi


if [[ -f $VIMRC ]]; then
	cp $VIMRC $BACKUPDIR/.vimrc -f
	if [[ -d $VIM_RUNTIME_DIR ]]; then
		#mkdir $BACKUPDIR/.vim_runtime
		dir=$BACKUPDIR/.vim_runtime/temp_dirs

		ls $VIM_RUNTIME_DIR/temp_dirs | xargs -I + mkdir -p $dir/+

		ls $VIM_RUNTIME_DIR | grep -v temp_dirs | xargs -I + cp $VIM_RUNTIME_DIR/+ $BACKUPDIR/.vim_runtime/+ -rf
	fi

	if [[ $?==0 ]]; then
		echo "VIMRC backup finish successfully!"
	fi
fi

if [[ -f $NVIM_CONFIG/init.lua ]] || [[ -f $NVIM_CONFIG/init.vim ]]; then
	mkdir -p $BACKUPDIR/.config/nvim
	cp $NVIM_CONFIG $BACKUPDIR/.config/nvim -rf
	if [[ $?==0 ]]; then
		echo "NVIM Config File backup successfully!"
	fi
fi

if [[ -f $VSCODE_CONFIG ]]; then
	mkdir -p $BACKUPDIR/.config/Code/User
	cp $VSCODE_CONFIG $BACKUPDIR/.config/Code/User/settings.json
	if [[ $?==0 ]]; then
		echo "VSCODE Config File backup successfully!"
	fi
fi

if [[ -d $MYBASH ]]; then
	cp $MYBASH $BACKUPDIR/mybash -rf

	if [[ $?==0 ]]; then
		echo "Mybash dir backup successfully!"
	fi
fi

backup_dir .ssh

backup_dir .lxd_ls

backup_file .wezterm.lua

backup_dir .leetcode

backup_dir code

