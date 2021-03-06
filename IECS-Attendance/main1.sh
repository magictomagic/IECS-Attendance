#!/bin/bash
begin_time=$(date +%s)
function get_recognized_id(){
	rawdata=$(face_recognition --tolerance 0.5 --cpus 4 $1 $2|egrep "[0-9]{10}$"|cut -f 2 -d ',')
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


}

# first parameter: individuals' directory
# second parameter: group photos' directory
get_recognized_id /home/hhy/IECS-Attendance/101individuals/ /home/hhy/IECS-Attendance/101sum1/

echo "${data}"
echo "a total of ${num} people"
# bottom
end_time=$(date +%s)
run_time=$((end_time-begin_time))
echo "run time: ${run_time}s"
