/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>

#define MAX_PROCESSES 3

int isPrime (int num){
	if (num == 1 || num == 0)
		return 0;
	for (int i=2; i<num; i++){
		if (num%i == 0)
			return 0;
	}

	return 1;
}


int main() {

	pid_t pid[MAX_PROCESSES]; //criar processos filhos a partir do pai
	int *shared_mem;
	int num_children = 0;
	int *pos_mem;
	int *resultado;
	char c;

	shared_mem = (int*)mmap(NULL, sizeof(int)*1000, PROT_READ | PROT_WRITE, MAP_SHARED|MAP_ANON, 0, 0);

	resultado = &(shared_mem[0]);
	pos_mem = &(shared_mem[1]);
	(*pos_mem) = 2;
	
	do{
		scanf("%d",&(shared_mem[(*pos_mem)++]));
	}
	while((c = getchar()) != '\n');

	for (num_children; num_children<MAX_PROCESSES; num_children++){
		fflush(stdout);
		pid[num_children] = fork();
		if (pid[num_children] == 0)
			break;
	}

	while((*pos_mem)>= 2){		
		(*pos_mem)--;
		(*resultado) += isPrime(shared_mem[*pos_mem]); 
	}

	for(int i = 0; i<MAX_PROCESSES; i++)
		waitpid(pid[i], NULL,0);

	printf("%d\n", *resultado);

	munmap(shared_mem, sizeof(int)*1000);


	return 0;
}

	




