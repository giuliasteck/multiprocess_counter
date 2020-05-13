/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
int isPrime (int num){
	if (num == 1 || num == 0)
		return 0;
	for (int i=2, i<num, i++){
		if (num%c == 0)
			return 0;
	}

	return 1;
}



int main() {

  int x, y;

  scanf("%d %d\n", &x, &y);
  printf("%d\n", x + 200);
  return 0;
}
