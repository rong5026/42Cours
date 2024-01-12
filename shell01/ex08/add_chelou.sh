echo $FT_NBR1+$FT_NBR2 | tr "\'\\\?\!mrdoc" 013401234 | tr "\"" 2 | xargs echo "obase=13;ibase=5;" | bc| tr 0123456789ABCD "gtaio luSnemf"
