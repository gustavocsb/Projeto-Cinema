/* Nome: Gustavo Caldas Silveira Borges; Matrícula: UC21100557; Curso: Engenharia de Software 1º Semestre, 2021;

Um cinema de Brasília está interessado em descobrir o perfil das pessoas que frequentam suas sessões de filmes 
e para isso, necessita realizar algumas verificações nas informações prestadas. Devem ser solicitados a quantidade
de sessões que serão realizadas, o nome do filme, a quantidade de pessoas que assistiram o filme, assim como o sexo e a idade.

Capítulo 2: Código Limpo, pág 18: 
"o nome de uma variável, função ou classe deve responder a todas as grandes questões. Ele deve lhe dizer porque
existe, o que faz e como é usado. Se um nome requer um comentário então ele não revela seu propósito." */

#include<stdio.h> //biblioteca printf e scanf
#include<string.h> //biblioteca para strlen e strcmp
#include<ctype.h> //biblioteca para o uso do toupper e tolower
#include<locale.h> //biblioteca para o uso de acentos
#include<stdlib.h> //biblioteca para system

int main(){    //estrutura padrão para o começo do código
    setlocale(LC_ALL, "Portuguese"); //definindo a lingua Portuguesa para acentos <locale.h>

//declarando as variáveis
    int sessoes, quantiaPessoas[2]={0,0}, idade[2]={0,0}, crianca[2]={0,0}, adolescente[2]={0,0}, adulto[2]={0,0}, idoso[2]={0,0}, homem[2]={0,0}, mulher[2]={0,0},
	maiorIdadeHomem[2]={0,0}, maiorIdadeMulher[2]={0,0};
	char nomeFilme[2][75], sexo;
	
	printf("------ BEM-VINDO A CENTRAL DE PERFILAMENTO DE CLIENTES DO CINEPOP - BRASÍLIA ------\n\n");
	do { //quantia de sessões, sendo validado para aceitar exatamente 2 sessões
		printf("Informe a quantidade de sessões a serem analisadas [2]: "); //solicitando a quantia de sessões
		scanf("%d", &sessoes); //recebendo a quantia de sessões
		fflush(stdin); //limpando o buffer 
		if (sessoes != 2) //validando a quantia de sessões [2]
		    printf("Quantia inválida, número de sessões deve ser 2\n"); //se for diferente de 2 apresenta a invalidez
	}while (sessoes != 2); //repetição quando houver invalidez
	system("cls"); //limpando o prompt de comando
	
	for (int x = 0; x < 2; x++){ //for para repetir o perfilamento 2x [2 sessões]
		printf("------ PERFILAMENTO DE CLIENTES DO CINEPOP POR SESSÃO - BRASÍLIA ------\n\n");
	
	do { //nome do filme, sendo validado para não aceitar o nome 'vazio' (null)
		printf("Informe o nome do filme da sessão %d: ", x+1); //solicitando o nome do filme
		fgets(nomeFilme[x], 75, stdin); //recebendo a string (nome do Filme)
		fflush(stdin); //limpando o buffer
		if (strlen(nomeFilme[x]) <= 1) //validando se o nome não é null
		    printf("Nome vazio! informe um nome\n"); //se for vazio apresenta a invalidez
	}while (strlen(nomeFilme[x]) <= 1); //repetição quando houver invalidez
	
	do { //quantia de pessoas, sendo validado para no mínimo 10 pessoas
		printf("Informe a quantia de pessoas na sessão %d: ", x+1); //solicitando a quantia de pessoas
		scanf("%d", &quantiaPessoas[x]); //recebendo a quantia de pessoas
		fflush(stdin); //limpando o buffer
		if (quantiaPessoas[x] < 10) //validando a quantia mínima [10]
		    printf("Quantia inválida, número mínimo permitido: 10\n"); //se for menor que 10 apresenta a invalidez
	}while (quantiaPessoas[x] < 10); //repetição quando houver invalidez
	
	for(int i = 0; i < quantiaPessoas[x]; i++){ //coleta de dados(sexo e idade) de acordo com a quantia de pessoas escolhidas
		do { //idade das pessoas, sendo validado para uma idade entre 3 e 100 anos
		    printf("Informe a idade da pessoa %d: ", i+1); //solicitando a idade da pessoa x
		    scanf("%d", &idade[x]); //recebendo a idade da pessoa x
		    fflush(stdin); //limpando o buffer
		    if (idade[x] < 3 || idade[x] > 100) //validando a quantia mínima [3] e máxima [100]
		        printf("Insira uma idade entre 3 a 100 anos\n"); //se for menor que 3 ou maior que 100 apresenta a invalidez
		}while (idade[x] < 3 || idade[x] > 100); //repetição enquanto houver invalidez
		
		do { //sexo das pessoas, sendo validado para M ou F
			printf("Informe o sexo da pessoa %d [M|F]: ", i+1); //solicitando o sexo da pessoa x
			scanf("%c", &sexo); //recebendo o sexo da pessoa x
			fflush(stdin); //limpando o buffer
			sexo = toupper(sexo); //colocando a variável sexo em caixa alta, facilitando o if
			if (sexo != 'M' && sexo != 'F') //validando o sexo [M|F]
			    printf("Sexo inválido! Digite novamente.\n"); //se não for [M|F] apresenta a invalidez
		}while (sexo != 'M' && sexo != 'F'); //repetição enquanto houver invalidez
         
        if (idade[x]>=3 && idade[x]<=13) //aumentar a quantia de crianças [3 à 13 anos]
            crianca[x]+=1; 
        else if (idade[x]>=14 && idade[x]<=17) //aumentar a quantia de adolescentes [14 à 17 anos]
            adolescente[x]+=1;
        else if (idade[x]>=18 && idade[x]<=64) //aumentar a quantia de adultos [18 à 64 anos]
            adulto[x]+=1;
        else if (idade[x]>=65 && idade[x]<=100) //aumentar a quantia de idosos [65 à 100 anos]
            idoso[x]+=1;
            
        if (idade[x]>=18 && sexo=='M') //aumentar a quantia de homens maiores de idade [18+]
            maiorIdadeHomem[x]+=1;
        if (idade[x]>=18 && sexo=='F') //aumentar a quantia de mulheres maiores de idade [18+]
            maiorIdadeMulher[x]+=1;
            
        if (sexo == 'F') //aumentar a quantia de mulheres [sexo = F]
            mulher[x]+=1;
        if (sexo == 'M') //aumentar a quantia de homens [sexo = M]
            homem[x]+=1;
		
	}
	
	system("cls"); //limpando o prompt de comando
	printf("-------- DADOS DA SESSÃO %d --------\n\n", x+1); 
	printf("\tFilme: %s", nomeFilme[x]); //informa o nome do filme
	printf("\tPessoas do sexo feminino: %d\n", mulher[x]); //informa a quantia de pessoas do sexo feminino
	printf("\tPessoas do sexo masculino: %d\n", homem[x]); //informa a quantia de pessoas do sexo masculino
	printf("\tCrianças: %d\n", crianca[x]); //informa a quantia de crianças
	printf("\tAdolescentes: %d\n", adolescente[x]); //informa a quantia de adolescentes
	printf("\tAdultos: %d\n", adulto[x]); //informa a quantia de adultos
	printf("\tIdosos: %d\n", idoso[x]); //informa a quantia de idosos
	system("pause"); //system pause para solicitar o pressionamento de uma tecla para continuar os comandos
	system("cls"); //limpando o prompt de comando
	printf("-------- PESSOAS COM MAIORIDADE NA SESSÃO %d [18+] --------\n\n", x+1); 
	printf("\tHomens: %d\n", maiorIdadeHomem[x]); //informa a quantia de homens maiores de idade
	printf("\tMulheres: %d\n", maiorIdadeMulher[x]); //informa a quantia de mulheres maiores de idade
	system("pause"); //system pause para solicitar o pressionamento de uma tecla para continuar os comandos
	system("cls"); //limpando o prompt de comando
	}
	printf("------- COMPARAÇÃO ENTRE SESSÕES -------\n\n");
	//Informa todos os dados da sessão 1 e 2
	printf("Filme sessão 1: %s", nomeFilme[0]);
	printf("Filme sessão 2: %s", nomeFilme[1]);
	printf("Quantia de pessoas:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", quantiaPessoas[0], quantiaPessoas[1]);
	printf("Crianças:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", crianca[0], crianca[1]);
	printf("Adolescentes:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", adolescente[0], adolescente[1]);
	printf("Adultos:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", adulto[0],adulto[1]);
	printf("Idosos:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", idoso[0], idoso[1]);
	printf("Homens:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", homem[0], homem[1]);
	printf("Mulheres:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", mulher[0], mulher[1]);
	printf("Homens 18+:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", maiorIdadeHomem[0], maiorIdadeHomem[1]);
	printf("Mulheres 18+:\n");
	printf("Sessão 1: %d                      Sessão 2: %d\n", maiorIdadeMulher[0], maiorIdadeMulher[1]);
    
	return 0;  
}
