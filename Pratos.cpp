#include <iostream>
#include <map>
using namespace std;
/* Cria a estrutura da lista */

struct Restaurante{
 string descprato;
 string ingredprato;
};
int main(){
 int i = 0, chave, opcao;
 char descricao[15], ingr[50];
 /* Cria o Mapa com Lista */
 map<int, Restaurante> MapaPratos;
 Restaurante pratos;
 do {
 system("cls");
 printf("Selecione uma opcao:\n");
 printf("1 - Adicionar um Prato\n");
 printf("2 - Remover um Prato\n");
 printf("3 - Listar todos os Pratos\n");
 printf("4 - Sair\n");
 scanf("%d", &opcao);
 switch (opcao){
 case 1:
 system("cls");
 printf("Adicionar nova disciplina\n");
 printf("Informe o nome do prato: ");
 scanf("%s", &descricao);
 pratos.descprato = descricao;
 fflush(stdin);

 printf("\nInforme os ingredientes do prato: ");
 /* A função gets recebe o texto todo da variável ingr,
incluindo espaço */
 gets(ingr);
 pratos.ingredprato = ingr;
 MapaPratos[(MapaPratos.size()+1)] = pratos;
 cout << "\nPrato adicionado com sucesso!" << endl;
 cout << "\nPrato: " + MapaPratos[MapaPratos.size()].
descprato + "\nIngredientes: " + MapaPratos[MapaPratos.size()].
ingredprato + "\n" << endl;
fflush(stdin);
 system("pause");
 opcao = 0;
 break;
 case 2:
 system("cls");
 printf("Informe o numero do prato para remover: ");
 scanf("%d", &chave);
 /* Verifica se o número do prato existe */
 if(MapaPratos.find(chave) == MapaPratos.end()){
 cout << "Prato nao existente!\n" << endl;
 } else {
 MapaPratos.erase(MapaPratos.find(chave));
 }
 system("pause");
 opcao = 0;
 break;

 case 3:
 system("cls");
 printf("*** Listagem dos pratos! ***\n");
 for (i = 1; i <= MapaPratos.size(); i++) {
 printf("Prato %d: ", i);
 /* Se o prato pesquisado existir, escreve a posição
e os dados da chave */
 if(MapaPratos.find(i) == MapaPratos.end())
 cout << "Prato nao encontrada!\n" << endl;
 else
 /* Caso exista o prato, retorna as informações
na lista associada à chave */
 cout << "\nNome: " + MapaPratos[i].descprato
+ "\nIngrediente: " + MapaPratos[i].ingredprato + "\n" << endl;
 }
 system("pause");
 opcao = 0;
 break;
 default:
 break;
 }
 }while (opcao != 4);
 return 0;
}
