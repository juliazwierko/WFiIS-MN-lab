set term png # ustawienie typu terminala, np. m.in. x11 (ekran), postscript, pdf, png, table (kolumny współrzędnych).
#####################################################################

########################################
#set out "sygnal_zaszumiony"
#set title "k=10, sygnal zaszumiony"
#set xl "i" # tytuł osi x
#plot "file1.txt" u 1:2 w l notitle
########################################
#set out "trans_Fou_all"
#set title "k=10, transformata Fouriera"
#set xl "{/Symbol w}" # tytuł osi x
#plot "file2.txt" u 1:2 w l notitle
########################################
#set out "trans_Fou_part"
#set title "k=10, transformata Fouriera"
#set xl "{/Symbol w}" # tytuł osi x
#plot "file3.txt" u 1:2 w l notitle
########################################
do for[i=0:2] {
    set output sprintf("odszumiony_k_%d.png", 10-2*i)
    set title sprintf("k = %d", 10-2*i)
    set xl "i" # tytuł osi x
    p "zadanie4.txt" index i u 1:2 w l title "sygnal odszumiony", "" index i u 1:3 w l title "sygnal niezaszumiony"
}
