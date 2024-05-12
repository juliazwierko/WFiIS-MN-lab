set term png # ustawienie typu terminala, np. m.in. x11 (ekran), postscript, pdf, png, table (kolumny współrzędnych). 
#####################################################################

do for[i=0:1] {
	set o sprintf("fun_g - n=%d", i==0 ? 11 : 101)
	set title "g(x)"
	set xl "x" # tytuł osi x
	p "funckja_g.txt" index i u 1:2 with l title "g(x)", "aproksymacja_funckji_G.txt" index i u 1:2 with l t sprintf("G(x), N=%d", i==0 ? 11 : 101)
}
do for[i=0:1] {
	set o sprintf("fun_g2 - n=%d", i==0 ? 11 : 51)
	set title "g_{2}(x)=g(x)*(1+{/Symbol d}(x))"
	set xl "x" # tytuł osi x
	p "funckja_g2.txt" index i u 1:2 w p pointtype 7 title sprintf("g_{2}(x), N=%d", i==0 ? 11 : 51), "aproksymacja_funckji_G.txt" index i u 1:2 w l t sprintf("G(x), N=%d", i==0 ? 11 : 51)
}
