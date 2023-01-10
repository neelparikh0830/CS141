REM
REM UIC 2.0 program to input N integers and output the average.
REM
REM Author: Prof. Hummel, U. of Illinois Chicago, Fall 2020
REM

out_s	"# of integers? "
in_i
store_i	M0    REM store N
load_i	0
store_i	M1    REM store i
store_i	M2    REM store sum

load_i	M1    REM i < N?
cmp_i 	M0
jge	+8

out_s	"integer? "
in_i	      REM cin >> x
add_i	M2    REM sum = sum + x
store_i	M2
load_i	M1    REM i++
add_i    1
store_i  M1
jump	-9

out_s	"Avg: "
load_i	M2
div_i	M0
out_i
out_s	"\n"

end
