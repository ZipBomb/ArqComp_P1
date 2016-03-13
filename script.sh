L=(256  768  256  384  1024  2048  4096)
D=(2  12  26  64  92)

rm puntos.txt

for i in "${L[@]}"; do
	for j in "${D[@]}"; do
        echo -e "\n\n*** Prueba con $j, $i ***"
		./test $j $i
    done
done
