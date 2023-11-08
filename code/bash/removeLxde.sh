#!/bin/bash
#Author:LvXudong
#Time:2023 年 10月 07日 11时06分12秒
#Name:removeLxde.sh
#Version:V1.0
#Description:This is a production script.

#deepinList=$(apt list --installed | grep lxde)
deepinList=$(apt list | grep lxde)
IFS=$'\n'
for i in $deepinList; do
	apt purge ${i%%"/"*}
done
