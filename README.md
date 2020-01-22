# IECS-Attendance
## 大创项目：上课考勤系统
#### 环境搭建
```shell
# 新建虚拟机后调整分辨率
apt-get autoremove open-vm-tools
apt-get install open-vm-tools-desktop

# 装依赖的工具
sudo apt install python3
sudo apt install gcc	
sudo apt install cmake
sudo apt install python3-pip

# 装 face_recognition 项目
pip3 --default-timeout=6000 install face_recognition -i https://pypi.doubanio.com/simple/
```

解决共享文件夹启用后，重启失效（显示启用，但hgfs下没有共享文件夹）问题：
  禁用共享后进入 /mnt
```shell
sudo rm -rf hgfs
```
  再开启共享
