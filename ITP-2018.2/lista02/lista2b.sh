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
				echo -e '\tEntrada:' "${azul} $2 ${normal}"
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

avaliar 'q1' '1 3 -1' '1 3 2'
avaliar 'q1' '2 -2 3' '2 1 3'
avaliar 'q1' '-3 3 2' '1 3 2'
avaliar 'q1' '2 -1 1' '2 3 1'
avaliar 'q1' '1 3 2' '1 3 2'
avaliar 'q1' '3 2 1' '3 2 1'
avaliar 'q1' '1 -1 -1' '1 ? ?'
avaliar 'q1' '-2 2 -2' '? 2 ?'
avaliar 'q1' '-3 -3 3' '? ? 3'
avaliar 'q1' '1 -1 -2' '1 2 3'
avaliar 'q1' '1 -3 -1' '1 2 3'
avaliar 'q1' '-2 -3 3' '1 2 3'
avaliar 'q1' '2 -2 -3' '2 3 1'
avaliar 'q1' '1 -2 -3' '1 3 2'
avaliar 'q1' '-2 -1 3' '1 2 3'
avaliar 'q1' '-1 -2 -3' '? ? ?'
avaliar 'q1' '-1 -1 -2' '? ? 1'
avaliar 'q1' '-3 -3 -2' '? ? 3'
avaliar 'q1' '-2 -1 -2' '? 2 ?'
avaliar 'q1' '-3 -1 -2' '? ? ?'
avaliar 'q1' '-2 -3 -3' '3 ? ?'

avaliar 'q2' '3 10' '18'
avaliar 'q2' '4 20' '60'
avaliar 'q2' '5 1572' '247275'
avaliar 'q2' '7 1572' '176400'
avaliar 'q2' '29 1572' '43065'
avaliar 'q2' '29 15982' '4410204'

avaliar 'q3' '4 0' 'Maria'
avaliar 'q3' '5 3' 'João'
avaliar 'q3' '7 2' 'João'
avaliar 'q3' '1 0' 'João'
avaliar 'q3' '0 0' 'Maria'
avaliar 'q3' '10 4' 'Maria'
avaliar 'q3' '4 8' 'Maria'
avaliar 'q3' '1 4' 'João'
avaliar 'q3' '7 3' 'João'
avaliar 'q3' '7 8' 'João'
avaliar 'q3' '8 7' 'João'
avaliar 'q3' '4 10' 'Maria'
avaliar 'q3' '2 2' 'Maria'




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
