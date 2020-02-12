#!/bin/bash
begin_time=$(date +%s)

rawdata=$(face_recognition --tolerance 0.406 --cpus 4 ini-base/ store-raw-cam/|egrep "[0-9]{10}$"|cut -f 2 -d ',')
	mkdir tmp
	cat > tmp/rawdata.txt <<-EOF
	$rawdata
EOF
	data=$(sort tmp/rawdata.txt|uniq)
	cat > tmp/data.txt <<-EOF
	$data
EOF
	num=$(grep -c "" tmp/data.txt)
#	rm -rf tmp

echo "${data}"
echo "a total of ${num} people"
# bottom
end_time=$(date +%s)
run_time=$((end_time-begin_time))
echo "run time: ${run_time}s"
