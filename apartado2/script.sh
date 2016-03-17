L=(256  768  49152  73728  196608  393216  786432)
D=(5  29  53  77  95)

rm puntos.txt

for i in "${L[@]}"; do
	for j in "${D[@]}"; do
        echo -e "\n\n*** Prueba con $j, $i ***"
		./test $j $i
    done
done
