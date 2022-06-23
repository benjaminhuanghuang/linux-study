首先使用命令，列出当前服务
```      
service –status-all
```

查询服务是否开机启动
```
systemctl is-enabled servicename.service 
```  

systemctl is-enabled bluetooth.service
如果是enable开机自启动
如果是disable不开机启动


systemctl enable *.service #开机运行服务

systemctl disable *.service #取消开机运行


sudo systemctl disable  bluetooth.service#关闭蓝牙服务

systemctl start *.service #启动服务

systemctl stop *.service #停止服务

systemctl restart *.service #重启服务

systemctl reload *.service #重新加载服务配置文件

systemctl status *.service #查询服务运行状态
  


