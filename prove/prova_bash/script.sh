for i in {1..3}
do
	echo "Creo la cartella ciao_$i"
	mkdir "ciao_$i"
	mv "ciao $i"/* ciao_$i 
	echo "ho mosso tutti i contenuti"
	rm -r "ciao $i"
done
