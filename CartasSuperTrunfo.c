#include <stdio.h>

struct CartasSuperTrunfo
{
	unsigned long int populacao;
	float area;
	float pib;
	int pontos_turisticos;
	int densidade_populacional;
	int pib_per_capita;
	float super_poder;
};

void cadastrar_cartas(struct CartasSuperTrunfo cartas[], int quantidade_cartas)
{
	for (int i = 0; i < quantidade_cartas; i++)
	{
		printf("\nCarta %d\n", i + 1);
		printf("Digite a população da cidade: ");
		scanf("%d", &cartas[i].populacao);
		printf("Digite a área da cidade: ");
		scanf("%f", &cartas[i].area);
		printf("Digite o PIB da cidade: ");
		scanf("%f", &cartas[i].pib);
		printf("Digite a quantidade de pontos turísticos da cidade: ");
		scanf("%d", &cartas[i].pontos_turisticos);
		cartas[i].densidade_populacional = cartas[i].populacao / cartas[i].area;
		cartas[i].pib_per_capita = cartas[i].pib / cartas[i].populacao;
		cartas[i].super_poder = cartas[i].populacao + cartas[i].area + cartas[i].pib + cartas[i].pontos_turisticos + (1 / cartas[i].densidade_populacional) + cartas[i].pib_per_capita;
	};
};

void comparar_cartas(struct CartasSuperTrunfo cartas[], int quantidade_cartas)
{
	int carta1, carta2;
	printf("\nEscolha as duas cartas que deseja comparar: ");
	printf("\nCarta 1: ");
	scanf("%d", &carta1);
	printf("Carta 2: ");
	scanf("%d", &carta2);
	printf("\nA carta mais poderosa é a: %d\n", cartas[carta1 - 1].super_poder > cartas[carta2 - 1].super_poder ? carta1 : carta2);
};

void exibir_cartas(struct CartasSuperTrunfo cartas[], int quantidade_cartas)
{
	for (int i = 0; i < quantidade_cartas; i++)
	{
		printf("\nCarta %d\n", i + 1);
		printf("População: %lu\n", cartas[i].populacao);
		printf("Área: %.2f\n", cartas[i].area);
		printf("PIB: %.2f\n", cartas[i].pib);
		printf("Pontos Turísticos: %d\n", cartas[i].pontos_turisticos);
		printf("Densidade Populacional: %.2f\n", cartas[i].densidade_populacional);
		printf("PIB per Capita: %.2f\n", cartas[i].pib_per_capita);
		printf("Super Poder: %.2f\n", cartas[i].super_poder);
	};
};

int main()
{
	int quantidade_cartas;

	printf("Digite a quantidade de cartas que deseja cadastrar: ");
	scanf("%d", &quantidade_cartas);
	struct CartasSuperTrunfo cartas[quantidade_cartas];

	cadastrar_cartas(cartas, quantidade_cartas);
	exibir_cartas(cartas, quantidade_cartas);
	comparar_cartas(cartas, quantidade_cartas);

	return 0;
};
