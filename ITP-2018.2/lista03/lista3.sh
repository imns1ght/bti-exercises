#!/bin/bash

criarSumario=false
declare -A sumarioAcertos
declare -A sumarioTotal
declare -A sumarioStatus
vermelho='\033[0;31m'
verde='\033[0;32m'
normal='\033[0m'
azul='\033[0;36m'
amarelo='\033[46m'

args=("$@")
avaliar () {
	file=$1
	if [ ! -z ${args[0]} ] && [ ! ${args[0]} == $1 ]; then
		return 1
	fi
	if ! [ -n "${sumarioTotal[$1]}" ]; then
		echo -e "${amarelo}              problema $1            ${normal}"
	fi
	sumarioTotal[$1]=$((sumarioTotal[$1]+1))
	if ! [ -n "${sumarioAcertos[$1]}" ]; then
		sumarioAcertos[$1]=0
	fi
	if [ -f $file.c ]; then
		if [ ! -f exec$file ]; then
			charset="$(file -bi "$file.c" | awk -F "=" '{print $2}')"
			arq=$file.c
			if [ "$charset" != utf-8 ]; then
				iconv -f "$charset" -t utf8 "$file.c" -o tmp.c
				arq=tmp.c
			fi
			if ! gcc $arq -o exec$file -lm  2> /dev/null; then
				sumarioStatus[$1]='código '$file.c' não compila'
			fi
		fi
		echo -e "$2" > input
		echo -e "$3" > gabarito
		if [ -f exec$file ]; then
			timeout 2 ./exec$file < input > output
			printf 'Teste %d: ' ${sumarioTotal[$1]}
			if ! diff -wB output gabarito > /dev/null; then
				echo -e "${vermelho} [x]${normal}"
				if [ ! -z ${args[1]} ] && [ ${args[1]} == "1" ]; then
					echo -e '\tEntrada:' "${azul} $2 ${normal}"
				fi
				echo -e '\tSaída do seu programa:' "${azul} $(cat output) ${normal}"
				echo -e '\tSaída esperada:' "${azul} $3 ${normal}"
			else
				echo -e "${verde} [ok] ${normal}"
				sumarioAcertos[$1]=$((sumarioAcertos[$1]+1))
			fi
		fi
	else
		sumarioStatus[$1]='código '$file.c' não existe'
	fi
}


avaliar 'q1' '8 5' '8, 8, 8, 8, 8'
avaliar 'q1' '1 5' '1, 1, 1, 1, 1'
avaliar 'q1' '3 0' ''
avaliar 'q1' '3 1' '3'
avaliar 'q2' '5 12' '5 6 7 8 9 10 11 12'
avaliar 'q2' '12 5' '12 11 10 9 8 7 6 5'
avaliar 'q3' '9' '45'
avaliar 'q3' '20' '210'
avaliar 'q3' '235' '27730'
avaliar 'q7' '5 0 0 0 0 0' '0'
avaliar 'q7' '4 -2 -3 -4 -5' '-2'
avaliar 'q7' '4 -1 -1 -1 -1' '-1'
avaliar 'q7' '4 1 8 10 23' '23'
avaliar 'q7' '4 -5 3 17 2' '17'
avaliar 'q7' '7 2 4 4 4 5 2 -1' '5'
avaliar 'q8' '13 18' '234 468 702 936'
avaliar 'q8' '21 27' '189 378 567 756 945'
avaliar 'q8' '105 3' '105 210 315 420 525 630 735 840 945'
avaliar 'q9' '6' 'Perfeito'
avaliar 'q9' '33550336' 'Perfeito'
avaliar 'q9' '8128' 'Perfeito'
avaliar 'q9' '17' 'Não perfeito'
avaliar 'q9' '904' 'Não perfeito'
avaliar 'q10' '16 2' 'sim'
avaliar 'q10' '81 3' 'sim'
avaliar 'q10' '1024 2' 'sim'
avaliar 'q10' '1025 2' 'não'
avaliar 'q10' '531441 3' 'sim'
avaliar 'q10' '531443 3' 'não'
avaliar 'q11' '1' '1'
avaliar 'q11' '7' '13'
avaliar 'q11' '12' '144'
avaliar 'q16' '284 220' 'sim'
avaliar 'q16' '6232 6368' 'sim'
avaliar 'q16' '76084 63020' 'sim'
avaliar 'q16' '620 182' 'não'
avaliar 'q16' '1902 63' 'não'
avaliar 'q16' '502 82' 'não'
avaliar 'q17' '84 18' '6'
avaliar 'q17' '54030 76380' '30'
avaliar 'q17' '236640 320943' '1479'
avaliar 'q19' '10 1 4 2 0 0 0 2 0 0 1' '3'
avaliar 'q19' '10 0 2 5 0 0 0 0 0 0 0' '7'
avaliar 'q19' '10 0 0 0 0 0 0 0 0 0 0' '10'
avaliar 'q20' '30 20 8' '3'
avaliar 'q20' '60.0 40.0 11' '4'
avaliar 'q20' '100.0 95.0 7.0' '7'
avaliar 'q20' '10 10 10' '1'
avaliar 'q20' '10 10 15' '0'

totalQuestoes=0
notaTotal=0
sumario=$(basename "$PWD")
echo ''
echo -e "${amarelo}              sumário $1            ${normal}"
echo '----------------------'
echo -e 'problema\tacertos / número de testes'
for i in ${!sumarioTotal[@]}; do
	if ! [ -n "${sumarioStatus[$i]}" ]; then
		echo -e $i '\t' ${sumarioAcertos[$i]} / ${sumarioTotal[$i]}
		acertos=${sumarioAcertos[$i]}
		total=${sumarioTotal[$i]}
		sumario=$sumario,$acertos
		notaQuestao=$(echo "$acertos/$total" | bc -l)
		notaTotal=$(echo "$notaTotal+$notaQuestao" | bc -l)
	else
		sumario=$sumario,0
		echo -e $i '\t' 'Erro:' ${sumarioStatus[$i]}
	fi
	totalQuestoes=$((totalQuestoes+1))
done
if [ $totalQuestoes -ne 0 ]; then
	echo '----------------------'
	echo 'Nota: ' $(echo "2*$notaTotal/$totalQuestoes" | bc -l)
fi

#cria um arquivo csv no diretorio superior (interessante para montar uma planilha)
if [ "$criarSumario" = true ]; then
	echo $sumario >> ../sumario.csv
fi

rm gabarito input output exec*
