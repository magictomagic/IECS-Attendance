#!/bin/bash
function generate(){
sudo -S ffmpeg -f video4linux2 -i /dev/video2 -vframes 1 store-raw-cam/$1.jpg <<EOF
hhy
EOF
#cat > signals/$1.txt <<-EOF
#       cnmccp
#EOF
}
function deletes(){
rm -y store-raw-cam/$1.jpg
rm signals/$1.txt
}

r=0
#rm -r signals
rm -rf store-raw-cam/*
#mkdir signals

while(( r < 4 ))
do
	generate p$r
	let r=r+1
done




