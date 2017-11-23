/*
source code hp_rechner_5.c
author: Pius Senn
date: 05.10.2017
description:
Aufgabe HP-Rechner 5, Beispiellösung
- Addition, Subtraktion, Multiplikation und Division von Fliesskommazahlen,
Datentyp foat
- Eingabe-Reihenfolge: Variable 1, Variable 2, Operator
- Divison durch Null wird abgefangen
- Weiterrechnen mit dem Resultat ist möglich (Kettenrechnung)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	float var1; // Variable 1
	float var2; // Variable 2
	float resultat; // Resultat
	unsigned char operation; // Operator
	int abfrage = 1; // Programmwiederholung
	int fehler; // Flag, Fehler = 1, kein Fehler = 0
				// Titel
	printf("HP-Rechner 5\n");
	printf("------------\n\n");
	// solange Programm-Wiederholung gewünscht
	do
	{
		// kein Fehler zu Beginn der Berechnung
		fehler = 0;
		if (abfrage == 2)
		{
			// mit dem Resultat weiterrechnen
			var1 = resultat;
		}
		else
		{
			// neue Rechnung
			// Einlesen der ersten Variablen
			printf("1. Variable eingeben: ");
			scanf("%f", &var1);
			getchar(); // Tastaturbuffer leeren
		}
		// Einlesen der zweiten Variablen
		printf("2. Variable eingeben: ");

		scanf("%f", &var2);
		getchar(); // Tastaturbuffer leeren
				   // Einlesen des Operators
		printf("Operator eingeben: ");
		scanf("%c", &operation);
		getchar(); // Tastaturbuffer leeren
				   // Berechnung
		switch (operation)
		{
		case '+':
			resultat = var1 + var2;
			break;
		case '-':
			resultat = var1 - var2;
			break;
		case '*':
			resultat = var1 * var2;
			break;
		case '/':
			// Test auf Division durch Null
			while (var2 == 0)
			{
				// Division durch Null, Fehlermeldung
				printf("\n Division durch Null unzulaessig, geben Sie einen neuen Divisor ein!\n");
					scanf("%f", &var2);
				getchar(); // Tastaturbuffer leeren
			}
			resultat = var1 / var2;
			break;
		default:
			printf("\n***** Operator ungueltig!!\n\n");
			fehler = 1;
		}
		// Ausgabe des Resultats
		if (fehler == 0)
		{
			printf("\n%.2f %c %.2f = %.2f\n\n", var1, operation, var2, resultat);
		}
		// Noch eine Berechung?
		printf("Wollen Sie noch eine Berechnung durchfuehren?\n");
		printf("1 - ja, neue Rechnung\n");
		printf("2 - ja, mit dem Resultat weiterrechnen\n");
		printf("0 - nein, Programm verlassen\n");
		scanf("%d", &abfrage);
		getchar(); // Tastaturbuffer leeren
		printf("\n");
	} while (abfrage > 0);
	return 0;
}