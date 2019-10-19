for i in {1..3}
do	
	echo "Elimino le cartelle ciao_$i"
	rm -r "ciao_$i"
	echo "Creo le cartelle"
	mkdir "ciao $i"
	touch "ciao $i/file$i.txt"
	
done

	
