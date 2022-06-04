#!/bin/sh

# sudo mkdir /mnt/ram8mbdisk
# sudo mount -t tmpfs -o rw,size=8M tmpfs /mnt/ram8mbdisk 
# sudo chmod XXX /mnt/ram8mbdisk

run_test() {
	test_name="$1"
	cmd="$2"
	times=$3
	result="$4"

	tmp_file="/mnt/ram8mbdisk/tmp$test_name"

	echo "Test $test_name:
		cmd: $cmd
		times: $times
		result: $result"
	i=0
	while [ "$i" -lt "$times" ]; do
		$cmd > $tmp_file$i &
		i=$(($i+1))
	done
	wait
	cat $tmp_file* >> $result
	rm $tmp_file*
	echo "Test $test_name: done"
}

gcc -Wall -Wextra -Werror measure_time.c -o measure_time

name1="original"
name2="optimized"

cmd1="./measure_time original"
cmd2="./measure_time optimized"

times2run=1000

result1="time_result1.txt"
result2="time_result2.txt"

rm -f $result1 $result2

echo $name1 > $result1
echo $name2 > $result2

run_test "$name1" "$cmd1" "$times2run" "$result1" &
run_test "$name2" "$cmd2" "$times2run" "$result2" &

wait
echo "Done"

