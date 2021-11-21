#include "header.h"

//FUNZIONI
/*mostra il benvenuto a schermo*/
void benvenuto(void){
 time_t t;//variabile dell orario attuale
 time(&t);//lettura dell orario dal sistema
 printf("                                                                                                         \n");
 printf("---------------------------------------------------------------------------------------------------------\n");
 printf("\t\t\t\t\t%s",ctime(&t));//stampa la data
 printf("---------------------------------------------------------------------------------------------------------\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t         BENVENUTO DA \t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t      LORENZO'S MAGIC SHOP \t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t================================\t\t|\n");
 printf("|\t\t\t\t                          \t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
 system("PAUSE");
}

/*mostra il menu a schermo, è un int perchè ritorna la scelta effettuata dall utente*/
int menu()
{
    int scelta;
    printf("\n==============================SHOPPING TIME ================================");
    printf("\n\t\tPremi <1> Se vuoi visualizzare i nostri prodotti.");
    printf("\n\t\tPremi <2> Se vuoi acquistare un prodotto.");
    printf("\n\t\tPremi <3> Se vuoi visualizzare i prodotti per nome.");
    printf("\n\t\tPremi <4> Se vuoi visualizzare il tuo carrello.");
    printf("\n\t\tPremi <5> Se vuoi eliminare un prodotto dal carrello.");
    printf("\n\t\tPremi <6> Se vuoi uscire da nostro negozio.");
    printf("\n\n\t\tFai la tua scelta[1-6]");
    scanf("%d", &scelta);
    while (scelta < 0 || scelta > 6)
    { //fa ripetere la scelta
        printf("Scelta non valida!\n");
        printf("Scelta:  %d", scelta);
        scanf("%d", &scelta);
        return scelta;
    }
    return scelta;
    system("PAUSE");
}

//permette di inserire nel carrello i prodotti,cercando il prodotto per nome
//ATTENZIONE , il nome deve essere preciso ,comprensivo di spazi e differenza tro maiuscole e minuscole
void Inserimento_Prodotto(Carrello *list, Prodotto prodotti[], int num_prodotti)
{
    int i;
    int prodotti_da_acquistare;
    printf("Quanti prodotti vuoi acquistare: ");
    scanf("%d", &prodotti_da_acquistare);
    getc(stdin); // consuma ultimo \n
    for (i = 0; i < prodotti_da_acquistare; i++)
    {
        char nome[NAME_LEN];
        // chiedi nome

        printf("INSERISCI NOME PRODOTTO %d: ", i + 1);
        gets(nome);
        // cerca prodotto
        Prodotto *prodotto_trovato = Cerca_Prodotto(nome, prodotti, num_prodotti);
        if (!prodotto_trovato)
        {
            printf("\nProdotto non trovato!!\n");

            // riporta l'indice indietro per rieseguire il tentativo
            --i;
            continue;
        }
        int quantita;
        printf("INSERISCI QUANTITA': ");
        scanf("%d", &quantita);
        getc(stdin); // consuma ultimo \n

        // inserisci prodotto nel carrello
        list->prodotti[list->num_prodotti] = *prodotto_trovato;
        list->prodotti[list->num_prodotti].quantita = quantita;
        list->num_prodotti++; //incrementa il numero di prodotti nel carrello
    }
}
//stampa il carrello , il passaggio deve avvenire tramite puntatore alla lis
void Stampa_Carrello(Carrello *list)
{
    int i;
    printf("                                                ***** CARRELLO *****                                       \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("|  N  |  CODICE  |     NOME      | PZ. | PREZZO | SCONTO | SUBTOTALE \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    float totale = 0.0;
    for (i = 0; i < list->num_prodotti; i++)
    {
        printf(
            " %5d %11d %-15s %6d %6.2f %6.2f %6.2f\n",
            i + 1,
            list->prodotti[i].codice,
            list->prodotti[i].nome,
            list->prodotti[i].quantita,
            list->prodotti[i].prezzo * list->prodotti[i].quantita,
            list->prodotti[i].sconto,
            (1 - (list->prodotti[i].sconto / 100)) * list->prodotti[i].prezzo * list->prodotti[i].quantita
        );
        totale += (1 - (list->prodotti[i].sconto / 100)) * list->prodotti[i].prezzo * list->prodotti[i].quantita;//formula dello sconto
    }
    printf("Totale carrello: %.2f", totale);
}
//stampa tutti i prodotti passando un array e la sua dimensione, che in questo caso è sempre 20
void Stampa_Prodotti(Prodotto prodotti[], int num_prodotti)
{
    int i;
    printf("                                                    *****  INVENTARIO *****                                       \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("|  CODICE  |     NOME       |         DESCRIZIONE                                   |  PREZZO   |   SCONTO  | PZ.     \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < num_prodotti; i++)
    {
        printf("  %-8d %-16s %-56s %18.2f %8.2f %% %9d\n", prodotti[i].codice, prodotti[i].nome, prodotti[i].descrizione, prodotti[i].prezzo, prodotti[i].sconto, prodotti[i].quantita);
    }
}
// funzione che permette di ordinare i prodotti per nome  con l'algoritmo di ordinamento per inserimento,passando l'array e la sua dimensione
// ho eliminato gli  spazi all'inizio dei nomi, per non avere problemi con l ordinamento
void Ordina_Prodotti(Prodotto prodotti[], int num_prodotti)
{
    int i = 0, j;
    Prodotto el_da_ins;
    for (i = 1; i < num_prodotti; i++)
    {
        el_da_ins = prodotti[i];
        j = i - 1;
        while (j >= 0 && strncmp(el_da_ins.nome, prodotti[j].nome, 20) < 0)
        {
            prodotti[j + 1] = prodotti[j];
            j = j - 1;
        }
        prodotti[j + 1] = el_da_ins;
    }
}
//function per cercare il prodotto dato in input il nome, array prodotti e la dimensione
Prodotto *Cerca_Prodotto(char *nome, Prodotto prodotti[], int num_prodotti)
{
    for (int i = 0; i < num_prodotti; ++i) //scorre i prodotti
    {
        if (strncmp(nome, prodotti[i].nome, NAME_LEN) == 0)//verifica se il nome è presente
        {
            return &prodotti[i]; //allora ritorna il prodotto
        }
    }
    return NULL;
}
void Elimina_Prodotto(Carrello *list)
{
    if (list->num_prodotti == 0) {//verifica che c'è almeno un prodotto nel carrello
        printf("Nessun prodotto nel carrello");
        return;
    }
    int i;
    int prodotti_da_eliminare;
    printf("Quanti prodotti vuoi eliminare: ");
    scanf("%d", &prodotti_da_eliminare);
    if (prodotti_da_eliminare > list->num_prodotti) //se si chiede di eliminare più prodotti di quelli presenti  , permette di eliminare solo quelli presenti
        prodotti_da_eliminare = list->num_prodotti;
    getc(stdin); // consuma ultimo \n
    for (i = 0; i < prodotti_da_eliminare; i++)
    {
        char nome[NAME_LEN];
        // chiedi nome

        printf("INSERISCI NOME PRODOTTO %d: ", i + 1);
        gets(nome);
        // cerca prodotto
        Prodotto *prodotto_trovato = Cerca_Prodotto(nome, list->prodotti, list->num_prodotti);
        if (!prodotto_trovato)
        {
            printf("\nProdotto non trovato!!\n");

            // riporta l'indice indietro per rieseguire il tentativo
            --i;
            continue;
        }
        // elimina prodotto nel carrello
        // prima avanziamo nel carrello fino al prodotto trovato
        int j;
        for(j = 0; &list->prodotti[j] != prodotto_trovato; ++j)
        {

        }

        // ricopiamo i prodotti una posizione indietro, quindi ci fermiamo quando
        // siamo al penultimo e ricopiamo l'ultimo
        for( ; j < list->num_prodotti - 1; ++j) {
            list->prodotti[j] = list->prodotti[j + 1];
        }
        list->num_prodotti--;
    }
}
