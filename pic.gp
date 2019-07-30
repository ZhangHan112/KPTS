reset
set term png enhanced font 'Verdana,10'
set output "runtime1.png"
set xlabel "Iteration"
set ylabel "Best"
set title "KPTS"
plot [0:10000][0:300]'output1.dat' using 1:2  with line lw 1.5 title "" ,\
'output2.dat' using 1:2 with line lw 1.5 title "" , \
'output3.dat' using 1:2 with line lw 1.5 title "" , \
'output4.dat' using 1:2 with line lw 1.5 title "" ,


set output "runtime2.png"
plot [0:10000][0:3000]'output5.dat' using 1:2 with line lw 1.5 title "" , \
'output6.dat' using 1:2 with line lw 1.5 title "" , \
'output7.dat' using 1:2 with line lw 1.5 title "" 

set output "runtime3.png"
plot [0:10000][13000000:13800000]'output8.dat' using 1:2 with line lw 1.5 title "" 