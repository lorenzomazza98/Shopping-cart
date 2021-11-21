#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h> /*Ecco le librerie che verranno utilizzate nel progetto*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>


// uso delle define per evitare numeri, i numeri uguali possono significare cose diverse
#define PROD_LEN 20 //lunghezza prodotti
#define NAME_LEN 20//lunghezza nome
#define DESC_LEN 100//lunghezza descrizione

//struttura dei prodotti, questa struct contiene tutte le informazioni dei prodotti
typedef struct
{
    int codice;
    char nome[NAME_LEN];
    char descrizione[DESC_LEN];
    float prezzo;
    float sconto;
    int quantita;
} Prodotto;

//struct del carrello che contiene  prodotti e il numero dei prodotti del carrello
typedef struct
{
    Prodotto prodotti[PROD_LEN];//inserito nel main
    int num_prodotti;
} Carrello;



//PROTOTIPI

// Passo i  dati alle funzioni piuttosto che usare variabili globali per evitare , nel caso di più carrelli, o più insieme di prodotti di scrivere le funzioni
// più volte
// In caso del passaggio di  array, è necessario passare anche la dimensione
void benvenuto(); //Void perchè stampa solo con le printf
int menu();//int perchè torna la scelta
//Prende in input la lista e la dimensione
void Inserimento_Prodotto(Carrello *c, Prodotto prodotti[], int num_prodotti);
//prende in input il puntatore al carrello
void Stampa_Carrello(Carrello *list);
//prendono in input la lista dei prodotti e la dimensione,poi stampa
void Stampa_Prodotti(Prodotto prodotti[], int num_prodotti);
void Ordina_Prodotti(Prodotto prodotti[], int num_prodotti);
//prende in input il nome e poi la lista restituisce un puntatore al prodotto che puo' essere null
//se non trova nulla o punta al prodotto
Prodotto *Cerca_Prodotto(char *nome, Prodotto prodotti[], int num_prodotti);
//prende il input il puntatore al carrello
void Elimina_Prodotto(Carrello *list);



#endif // HEADER_H_INCLUDED
