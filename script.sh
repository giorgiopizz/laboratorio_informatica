for i in {2..8}
do
	echo "Creo la cartella esercitazione_$i"
	mkdir "esercitazione_$i"
	mv "esercitazione $i"/* esercitazione_$i 
	echo "ho mosso tutti i contenuti"
	rm -r "esercitazione $i"
done
