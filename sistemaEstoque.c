#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{

    char nome[50];
    int cod;
    int quant;
    float preco; 
    struct produto* ante;
    struct produto* prox;

} produto;

produto* inserirProduto(produto** head_ref, char* nome, int cod, int quant, float preco){

    produto* temp = *head_ref;

            while(temp != NULL){
                
                    if(temp->cod == cod){

                        printf(" Codigo %d já existe!\n", cod);
                        
                    return NULL;
                    }
                    
            temp = temp->prox;
            
            }

    produto* novoProduto = (struct produto*)malloc(sizeof(struct produto));

            if(novoProduto == NULL){

                printf(" Erro ao alocar memoria");
            
            return NULL;
            }

    strncpy(novoProduto->nome, nome, sizeof(novoProduto->nome) - 1);
    novoProduto->nome[sizeof(novoProduto->nome) - 1] = '\0';
    novoProduto->cod = cod;
    novoProduto->quant = quant;
    novoProduto->preco = preco;
    novoProduto->prox = NULL;
    novoProduto->ante = NULL;

            if(*head_ref == NULL || strcasecmp((*head_ref)->nome, nome) > 0){
               
            novoProduto->prox = *head_ref;

                    if(*head_ref != NULL){

                    (*head_ref)->ante = novoProduto;
                    
                    }

            *head_ref = novoProduto;
           
            return novoProduto;
            }

    produto* atual = *head_ref;

            while(atual->prox != NULL && strcasecmp(atual->prox->nome, nome) < 0){

            atual = atual->prox;
            
            }

    novoProduto->prox = atual->prox;

            if(atual->prox != NULL){

            atual->prox->ante = novoProduto;

            }

    atual->prox = novoProduto;
    novoProduto->ante = atual;

    return novoProduto;
}


produto* removerProduto(produto** head_ref, int cod){

    produto* temp = *head_ref;

            while(temp != NULL && temp->cod != cod){

            temp = temp->prox;

            }

            if(temp == NULL){

                printf(" Produto cod: %d, nao foi encontrado. \n",cod);

            return NULL;
            }

            if(*head_ref == temp){

            *head_ref = temp->prox;

            }

            if(temp->prox != NULL){

            temp->prox->ante = temp->ante;

            }

            if(temp->ante != NULL){

            temp->ante->prox = temp->prox;     

            }

    free(temp);

    printf(" Produto cod: %d removido com sucesso.\n", cod);
    
    return NULL;
}

produto* buscarProduto(produto* head, int cod){

    produto* temp = head;

            while(temp != NULL){

                    if(temp->cod == cod){

                    return temp;
                    }

            temp = temp->prox;

            }

return NULL;
}

void imprimirListaProdutos(produto* head){

    int count = 0;
        
    produto* temp = head;

            while(temp != NULL){
                
            count++;
            temp = temp->prox;
        
            }

            if(count == 0){
                
                printf(" Nenhum produto na lista.\n");
            
            return;
            }

    produto** produtosArray = (produto**)malloc(count * sizeof(produto*));

    temp = head;

            for(int i = 0; i < count; i++){
               
            produtosArray[i] = temp;
            temp = temp->prox;
            
            }

            for(int i = 0; i < count - 1; i++){

                        for (int j = 0; j < count - i - 1; j++){

                                if (produtosArray[j]->cod > produtosArray[j + 1]->cod) {

                                produto* tempProd = produtosArray[j];
                                produtosArray[j] = produtosArray[j + 1];
                                produtosArray[j + 1] = tempProd;
                                
                                }
                        }
            }

        printf(" Lista de produtos (ordenada pelo codigo):\n");

            for(int i = 0; i < count; i++){
               
                printf("\n Codigo: %d - Nome: %s - Quantidade: %d - Preco: %.2f \n",produtosArray[i]->cod, produtosArray[i]->nome, produtosArray[i]->quant, produtosArray[i]->preco);
            
            }

    free(produtosArray);
}





int main(){

produto* listaProdutos = NULL;
    int escolha, cod, quant;
    float preco;
    char nome[50];

            do {
                
                printf("\n 1. Inserir produto \n 2. Remover produto \n 3. Buscar produto\n 4. Imprimir lista de produtos \n 5. Sair \n");
                printf(" Escolha uma opcao: ");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:

                        printf(" Nome do produto: ");
                        scanf (" %[^\n]%*c", nome); 
                        printf(" Codigo do produto: ");
                        scanf ("%d", &cod);
                        printf(" Quantidade: ");
                        scanf ("%d", &quant);
                        printf(" Preco: ");
                        scanf ("%f", &preco);

                    inserirProduto(&listaProdutos, nome, cod, quant, preco);
                
                    break;

                    case 2:

                        printf(" Codigo do produto a ser removido: ");
                        scanf ("%d", &cod);

                    removerProduto(&listaProdutos, cod);
                    
                    break;

                    case 3:

                        printf(" Codigo do produto a ser buscado: ");
                        scanf ("%d", &cod);

                    produto* encontrado = buscarProduto(listaProdutos, cod);
                    
                            if(encontrado != NULL){
                                
                                printf(" Produto encontrado: Nome: %s - Codigo: %d - Quantidade: %d - Preco: %.2f \n", encontrado->nome, encontrado->cod, encontrado->quant, encontrado->preco);
                            
                                } else{

                                    printf(" Produto nao encontrado!\n");
                                
                                }

                    break;

                    case 4:

                    imprimirListaProdutos(listaProdutos);
                    
                    break;

                    case 5:

                        printf(" Programa encerrado.\n");
                
                    break;

                    default:

                        printf(" Opcao invalida!\n");
                }

            } while (escolha != 5);

return 0;
}