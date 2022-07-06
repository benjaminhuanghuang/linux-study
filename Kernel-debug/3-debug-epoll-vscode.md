https://www.bilibili.com/video/BV1Sq4y1q7Gv/

在 VScode 中 使用 remote-ssh 插件, ssh 到 Ubuntu VM, 打开 linux 代码所在的 folder

然后再安装插件 ms-vscode.cpp-tools

然后 在 vscode 中生成配置文件
.vscode\launch.json

```
{
  "version": "0.2.0",
  "configurations": [
    {
        "name": "kernel-debug",
        "type": "cppdbg",
        "request": "launch",
        "miDebuggerServerAddress": "127.0.0.1:2222",
        "program": "${workspaceFolder}/vmlinux",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": false,
        "logging": {
            "engineLogging": false
        },
        "MIMode": "gdb",
    }
  ]
}
```
