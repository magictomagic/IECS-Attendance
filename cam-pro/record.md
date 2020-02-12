# usb camera take photo
## process record

```shell
# install tool to take photo
sudo apt install ffmpeg

# take photo test: change device when use different USB interfaces /dev/video2
ffmpeg -f video4linux2 -i /dev/video2 -vframes 1 test.jpg

```
```shell
# get webcam in VMware (lsusb show)
lsmod | grep video
sudo rmmod uvcvideo 

# disable webcam in host (1-3.2 is my host, see next shell to get directory name)
sudo gedit /etc/modprobe.d/blacklist.conf
## add
blacklist uvcvideo
## at the bottom
sudo -i
echo 0 > /sys/bus/usb/devices/1-3.2/bConfigurationValue
reboot


# find webcam avaiable in guest
sudo ffmpeg -f video4linux2 -i /dev/video2 -vframes 1 t1.jpg
```
```shell
# get ID like 05a9:2640
lsusb

# find directory
grep 05a9 */idVendor
grep 2640 */idProduct
```

## run requirements
you should add photos in "ini-base" directory 
