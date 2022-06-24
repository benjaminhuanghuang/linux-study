1. 显示磁盘占用
```
  df -h：

  du -hd 1 /home 
  -d, --max-depth=N：目录的层数, 只查看/home下一层目录深度，并以人类可读的方式输出
```

2. apt-get autoclean：清理旧版本缓存

3. apt-get clean：清理所有缓存

4. apt-get autoremove：移除孤立软件（可以清理出500M+的空间）

5. rm -rf /var/log/*：删除所有log（删了后last命令提示找不到一个/var/log下的文件。。。）

6. find / -size +100M：列出所有大于100M的文件
