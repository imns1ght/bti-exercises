#!/bin/bash

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
		charset="$(file -bi "$file.c" | awk -F "=" '{print $2}')"
		if [ "$charset" != utf-8 ]; then
			iconv -f "$charset" -t utf8 "$file.c" -o tmp.c
			mv tmp.c "$file.c"
		fi
		if [ ! -f exec$file ]; then
			if ! gcc $file.c -o exec$file -lm  2> /dev/null; then
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

avaliar 'q1' '..***.*..* 0' '0'
avaliar 'q1' '..***.*..* 1' '1'
avaliar 'q1' '..***.*..* 5' '2'
avaliar 'q1' '..***.*..* 4' 'bum!'
avaliar 'q1' '..***.*..* 9' 'bum!'
avaliar 'q1' '..***.*..* 8' '1'
avaliar 'q1' '* 0' 'bum!'
avaliar 'q1' '. 0' '0'
avaliar 'q1' '.* 1' 'bum!'
avaliar 'q1' '*. 1' '1'
avaliar 'q1' '.* 0' '1'
avaliar 'q1' '.. 1' '0'

avaliar 'q2' 'tres pratos de trigo para tres tigres tristes' 'b c f h j k l m n q u v w x y z'
avaliar 'q2' 'mais vale um passaro na mao do que dois voando' 'b c f g h j k t w x y z'
avaliar 'q2' 'The quick brown fox jumps over the lazy dog' ''
avaliar 'q2' 'Gazeta publica hoje breve nota de faxina na quermesse' 'g k w y'
avaliar 'q2' 'gazeta publica hoje breve nota de faxina na quermesse' 'k w y'

avaliar 'q3' '35-0' 'sim'
avaliar 'q3' '35-2' 'nao'
avaliar 'q3' '35-7' 'nao'
avaliar 'q3' '35-5' 'nao'
avaliar 'q3' '35-1' 'nao'
avaliar 'q3' '35-00' 'nao'
avaliar 'q3' '35-' 'nao'
avaliar 'q3' '08-3' 'sim'
avaliar 'q3' '74-5' 'sim'
avaliar 'q3' '41-4' 'sim'
avaliar 'q3' '33-1' 'sim'
avaliar 'q3' '00-0' 'sim'
avaliar 'q3' '65-6' 'sim'
avaliar 'q3' '17-2' 'sim'
avaliar 'q3' '08-5' 'nao'
avaliar 'q3' '74-4' 'nao'
avaliar 'q3' '41-1' 'nao'
avaliar 'q3' '33-0' 'nao'
avaliar 'q3' '00-4' 'nao'
avaliar 'q3' '65-2' 'nao'
avaliar 'q3' '08-3!' 'nao'
avaliar 'q3' '74-55' 'nao'
avaliar 'q3' '412-4' 'nao'
avaliar 'q3' '331-1' 'nao'
avaliar 'q3' '0--0' 'nao'
avaliar 'q3' '6544' 'nao'
avaliar 'q3' '654-' 'nao'
avaliar 'q3' '08-308-3' 'nao'
avaliar 'q3' '08-3a' 'nao'

avaliar 'q4' 'O seguro morreu de velho' 'ohlev ed uerrom oruges O'
avaliar 'q4' 'ohlev ed uerrom oruges O' 'O seguro morreu de velho'
avaliar 'q4' 'The quick brown fox jumps over the lazy dog' 'god yzal eht revo spmuj xof nworb kciuq ehT'
avaliar 'q4' 'foi sem querer querendo' 'odnereuq rereuq mes iof'
avaliar 'q4' 'favor resolver as pendencias nos profiles' 'seliforp son saicnednep sa revloser rovaf'

avaliar 'q5' 'Ando devagar porque ja tive pressa' 'A: 1\na: 4\nd: 2\ne: 4\ng: 1\ni: 1\nj: 1\nn: 1\no: 2\np: 2\nq: 1\nr: 3\ns: 2\nt: 1\nu: 1\nv: 2\n'
avaliar 'q5' 'Sentou para descansar como se fosse sabado' 'S: 1\na: 6\nb: 1\nc: 2\nd: 2\ne: 4\nf: 1\nm: 1\nn: 2\no: 5\np: 1\nr: 2\ns: 6\nt: 1\nu: 1\n'
avaliar 'q5' 'Cuide bem do seu amor seja quem for' 'C: 1\na: 2\nb: 1\nd: 2\ne: 5\nf: 1\ni: 1\nj: 1\nm: 3\no: 3\nq: 1\nr: 2\ns: 2\nu: 3\n'
avaliar 'q5' 'aAbBcC' 'A: 1\nB: 1\nC: 1\na: 1\nb: 1\nc: 1\n'
avaliar 'q5' 'AAAAAAAAAAAAAAAAAABBBBBBBBCCCCDD' 'A: 18\nB: 8\nC: 4\nD: 2\n'

avaliar 'q6' 'Quantas palavras ha nessa frase?' '5'
avaliar 'q6' 'Este eh um ponto .' '5'
avaliar 'q6' 'ITP' '1'
avaliar 'q6' 'Melhor disciplina' '2'

avaliar 'q7' 'Esta eh uma string' 'E574 3h um4 57r1ng'

avaliar 'q8' 'anotaram a data da maratona' 'sim'
avaliar 'q8' 'arara' 'sim'
avaliar 'q8' 'osso' 'sim'
avaliar 'q8' 'H4CK TH3 W0RLD' 'nao'

avaliar 'q9' 'AAA-0000' 'sim'
avaliar 'q9' 'DWC-5727' 'sim'
avaliar 'q9' 'AAA-00200' 'não'
avaliar 'q9' 'RAWX-2392' 'não'
avaliar 'q9' 'DAX--9384' 'não'
avaliar 'q9' 'CWX-4999' 'sim'
avaliar 'q9' 'ZE-8938' 'não'
avaliar 'q9' 'FDX-0002' 'sim'
avaliar 'q9' 'AWH-1230' 'sim'
avaliar 'q9' 'RWX-881' 'não'
avaliar 'q9' 'ZZZ-9999' 'sim'
avaliar 'q9' 'CWX4999' 'não'
avaliar 'q9' '3929-FDX' 'não'
avaliar 'q9' 'G3F9X-32' 'não'
avaliar 'q9' 'aaa-0000' 'não'
avaliar 'q9' 'zzz-9999' 'não'
avaliar 'q9' 'ZQE-8938' 'sim'
avaliar 'q9' 'AZA-0909' 'sim'
avaliar 'q9' '-AFS3292' 'não'
avaliar 'q9' '--------' 'não'
avaliar 'q9' 'A-3' 'não'
avaliar 'q9' '\n' 'não'
avaliar 'q9' 'GRE-0000' 'sim'
avaliar 'q9' '-ASE3213' 'não'
avaliar 'q9' '238-2321' 'não'
avaliar 'q9' 'RWX-8381' 'sim'
avaliar 'q9' 'SD2-D232' 'não'
avaliar 'q9' 'RWX-2392' 'sim'
avaliar 'q9' 'DAX-9384' 'sim'
avaliar 'q9' '1D2-D2F2' 'não'
avaliar 'q9' 'AAA-0000AAA-0000' 'não'

avaliar 'q10' '03/05' 'sim'
avaliar 'q10' '00/00' 'nao'
avaliar 'q10' '00/0:' 'nao'
avaliar 'q10' '0:/01' 'nao'
avaliar 'q10' '01/01' 'sim'
avaliar 'q10' '01/02' 'sim'
avaliar 'q10' '01/03' 'sim'
avaliar 'q10' '01/04' 'sim'
avaliar 'q10' '01/05' 'sim'
avaliar 'q10' '01/06' 'sim'
avaliar 'q10' '01/07' 'sim'
avaliar 'q10' '01/08' 'sim'
avaliar 'q10' '01/09' 'sim'
avaliar 'q10' '01/10' 'sim'
avaliar 'q10' '01/11' 'sim'
avaliar 'q10' '01/12' 'sim'
avaliar 'q10' '31/01' 'sim'
avaliar 'q10' '32/01' 'nao'
avaliar 'q10' '28/02' 'sim'
avaliar 'q10' '29/02' 'nao'
avaliar 'q10' '31/03' 'sim'
avaliar 'q10' '33/03' 'nao'
avaliar 'q10' '30/04' 'sim'
avaliar 'q10' '31/04' 'nao'
avaliar 'q10' '31/05' 'sim'
avaliar 'q10' '35/05' 'nao'
avaliar 'q10' '30/06' 'sim'
avaliar 'q10' '31/06' 'nao'
avaliar 'q10' '31/07' 'sim'
avaliar 'q10' '31/08' 'sim'
avaliar 'q10' '30/09' 'sim'
avaliar 'q10' '31/09' 'nao'
avaliar 'q10' '31/10' 'sim'
avaliar 'q10' '30/11' 'sim'
avaliar 'q10' '31/11' 'nao'
avaliar 'q10' '31/12' 'sim'
avaliar 'q10' '19/01' 'sim'
avaliar 'q10' '23/02' 'sim'
avaliar 'q10' '04/03' 'sim'
avaliar 'q10' '03/04' 'sim'
avaliar 'q10' '22/05' 'sim'
avaliar 'q10' '13/06' 'sim'
avaliar 'q10' '11/07' 'sim'
avaliar 'q10' '25/08' 'sim'
avaliar 'q10' '04/09' 'sim'
avaliar 'q10' '15/10' 'sim'
avaliar 'q10' '19/11' 'sim'
avaliar 'q10' '18/12' 'sim'
avaliar 'q10' '00/12' 'nao'
avaliar 'q10' '30/041' 'nao'
avaliar 'q10' '31/052' 'nao'
avaliar 'q10' '135/05' 'nao'
avaliar 'q10' '/3006' 'nao'
avaliar 'q10' '0107/' 'nao'
avaliar 'q10' '010/8' 'nao'
avaliar 'q10' '0/109' 'nao'
avaliar 'q10' '31/aa' 'nao'
avaliar 'q10' '3x/08' 'nao'
avaliar 'q10' 'p0/09' 'nao'
avaliar 'q10' '01-09' 'nao'
avaliar 'q10' '01/13' 'nao'
avaliar 'q10' '01/00' 'nao'
avaliar 'q10' 'testeteste' 'nao'
avaliar 'q10' '0' 'nao'
avaliar 'q10' '01' 'nao'
avaliar 'q10' '01/' 'nao'
avaliar 'q10' '01/0' 'nao'
avaliar 'q10' '01/0a' 'nao'

avaliar 'q11' '3491' '3491'
avaliar 'q11' '0001k-jt3' '13'
avaliar 'q11' '-gm12' '-12'

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

rm gabarito input output exec*

