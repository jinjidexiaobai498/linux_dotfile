#!/bin/bash
#Author:LvXudong
#Time:2023 年 10月 13日 09时02分21秒
#Name:backupSetting.sh
#Version:V1.0
#Description:This is a production script.

# 设置备份目录和文件名
backup_dir="/path/to/backup"
backup_file="vim_neovim_configs_$(date +%Y%m%d).zip"

# 创建备份目录（如果不存在）
mkdir -p "$backup_dir"

# 备份vim配置文件
cp ~/.vimrc "$backup_dir/$backup_file"

# 备份neovim配置文件
cp ~/.config/nvim/init.vim "$backup_dir/$backup_file"

# 压缩备份文件
zip -r "$backup_dir/$backup_file" "$backup_dir/$backup_file"

# 输出备份完成信息
echo "Backup completed: $backup_file"

