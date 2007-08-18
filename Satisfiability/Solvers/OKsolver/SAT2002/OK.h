                       /* OKsolver; 5.3.1998 */

/* Autor: Oliver Kullmann, Universitaet Frankfurt am Main, Germany */
/* ab Februar 1999: University of Toronto, Computer Science Department */

/* Definitionsdatei */

/* 22.8.1998: Aenderung im Filter: Ersetzen von "ErfK" durch "NeuK" */
/* 20.9.1998: Neue Variable: aktN */
/* 13.11.1998: Resolutions-Baum-Verwaltung */
/* 3.4.1999: Ausgabe einer erfuellenden Belegung */
/* 4.5.1999: Erweiterung der r_2-Reduktion auf r_2^+-Reduktion (optional) */
/* 11.5.1999: Erweiterte Zeitmessung (optional) unter SUN */
/* 31.3.2000: Reduktion1() belegt zusaetzlich die globale Variable rHBel, die relative */
/* Haeufigkeit einer Belegung (falls DYNAMISCH gesetzt wurde). */
/* 27.4.2000: Aus OK.h wurden alle Variablendefinitionen herausgenommen, und durch */
/* Extern-Deklarationen ersetzt --- jene befinden sich nun in OKVar.h, was nur von */
/* OK.c eingelesen wird. Auf diese Weise wird jede Ambiguitaet bzgl. des Definitionsortes */
/* einer Variablen vermieden. */
/* 30.4.2000: BAUMRES wird automatisch definiert, ausser wenn NBAUMRES */
/* definiert ist. */
/* 24.7.2000: Neuer Typ "VarNr" */

/* 19.1.2001: Einfuehrung des 2-dimensionalen Feldes "Meldungen" von Zeichenketten */
/* zur mehrsprachigen Ausgabe, sowie der Funktion "Konstantenfehler" zur Reaktion */
/* im Falle von fehlerhaft definierten Konstanten. Neues Modul "Ausgaben". */
/* 19.1.2001: Neues Modul "Einlesen" mit der Prozedur "Einlesen". */
/* 21.1.2001: Zugrif auf "Meldungen" wird durch die Funktion "Meldung" abgekapselt. */
/* 21.1.2001: Die Baum-Beschneidung so organisiert, da\ss{} nur die Funktionen */
/* nach aussen sichtbar sind, waehrend die Datenstrukturen abgekapselt wurden. */

/* 30.1.2001: Der Modus ADAPTIV ist nun implementiert, wobei die Konstanten */
/* MAXP, MAXN, MAXK, MAXL nur noch zum Einlesen benutzt werden. */

/* 31.1.2001: Der Vergleich zur Bestimmung der optimalen Verzweigungsvariablen */
/* wurde verbessert, so dass nun ">" heisst, dass ein bestimmter Mindest- */
/* abstand bestehen muss. So kann nun wieder auf die Uebersetzer-Option */
/* "ffloat-store" verzichtet werden. */

/* 31.1.2001: Hilfsfunktionen zum Kopieren und Loeschen von Speicherbereichen */
/* wurden eingefuehrt. */

/* 31.1.2001: Das Feld "PosVar" in BaumRes wurde eliminiert, und im adaptiven */
/* Fall konsequent (und direkt) Zeiger eingesetzt. */

/* 1.2.2001: Nun ganz auf die adaptive Version uebergegangen. Die Konstanten */
/* MAXN, MAXP, MAXN, MAXL, MAXLV gibt es nur noch fuer das Einlesen. */
/* (D.h., die Option "ADAPTIV" wurde permanent gemacht.) */

/* 1.2.2001: Aufruf mit Argument "-v" gibt Versionsnummer und Uebersetzungsdatum */
/* aus. */

/* 2.2.2001: Klauselnummern sind nun Zahlen von 1, ... K */

/* 4.2.2001: "Klauselmengen" und "Variablen, Literale" nun als abstrakte */
/* Datentypen. */
/* 4.2.2001: Eine Datei "Gesamt.c", die die einzelnen Uebersetzungseinheiten */
/* alle einliest --- dies ist wohl besser fuer die Optimierung, denn das */
/* Aufloesen von Funktionen funktioniert nur (ohne die umstaendliche */
/* "extern __inline__"-Form) innerhalb einer Uebersetzungseinheit. */

/* 5.2.2001: Zusammenfassung der 6 Vektoren nLv, lLv, nLK, lLK, Lit, Kln */
/* in eine Struktur, und Realisierung eines Literalvorkommens als einen */
/* Zeiger auf eine solche Struktur. */

/* 6.2.2001: Falls Projektionswerte im wesentlichen gleich sind, so wird */
/* ein zweiter Vergleich mittels DeltaN durchgefuehrt. */

/* 8.2.2001: "Klauselnnummern" sind nun auch Zeiger (auf eine Klausel- */
/* informations-Struktur) */

/* 12.2.2001: Die Ausgabe der Rechenzeit enthaelt nun auch die Einlese-Zeit. */
/* 12.2.2001: Die leere Klauselmenge ist nun als Eingabe erlaubt. */
/* 12.2.2001: Falls DYNAMISCH gesetzt ist, wird nach Beendigung der */
/* Reduktion in "Sat" die Prozedur InitAbstand2() aufgerufen */
/* (sonst geschieht nichts). */

/* 18.2.2001: Verallgemeinertes Eingabeformat (erstmal nur 4 Standards) */
/* 18.2.2001: Eine Liste von Argumenten (einschliesslich der Optionen */
/* wird verarbeitet. */

/* 20.2.2001: Differenzierung zwischen P0, N0, K0, L0 (die tatsaechlichen */
/* Dimensionen der Eingabe als Multi-Klauselmenge (ohne jede Reduktion)), */
/* und P, N, K, L, die Dimensionen nach Vorreduktion. */
/* N ist nun auch die tatsaechliche Anzahl (d.h., ohne Vorkommen in */
/* tautologischen Klauseln zu beruecksichtigen). */

/* 24.2.2001: Zaehlung von Fast-Autarkien (genau eine neue Klausel) */

/* 28.2.2001: 1-Klauseln-Reduktion in der Eingabe */
/* 28.2.2001: Bearbeitung von Signalen SIGUSR1, SIGUSR2 */

/* 3.3.2001: Elimination von REDPLUS */

/* 4.3.2001: Lokal neue 2-Klauseln mit "LOKALLERNEN" */
/* (LOKALLERNEN ist notwendige Voraussetzung fuer FASTAUTARKIEN, */
/* aber nicht hinreichend; moechte man nur FASTAUTARKIEN haben, */
/* so setze man LOKALLERNEN, FASTAUTARKIEN und NL2RED.) */

/* 14.8.2001: Konservative Transformation nach C++ */

/* 18.8.2001: Neue Option KEININLINE zur Uebersetzung getrennten */
/* Uebersetzung der Einheiten. */


/* --------------------------------------------------------- */

#ifndef GELESENOK

#include <stdbool.h>

#define VERSIONSNUMMER1 "1"
#define VERSIONSNUMMER2 "23"
/* Version = VERSIONSNUMMER1 "." VERSIONSNUMMER2 */

#define DATUM "27.8.2004"

extern const bool internal;

/* Allgemeine Optionen */

/* Ist DYNAMISCH definiert, so wird vor jedem Bewertungsdurchlauf fuer
   die Variablen */
/* InitAbstand2() aufgerufen. */

#ifdef KEININLINE
#  define __inline__ 
#else
#  define __inline__ inline
#endif
/* falls KEININLINE definiert ist, so wird das Schluesselwort __inline__ */
/* ueberall geloescht */

/* Ist SYSTIME definiert, wird anstelle der (Standard-)Zeitmessung durch clock() */
/* die (nur) unter SUN verfuegbare Zeitmessung mittels times(Zeiger) verwendet. */
/* Die Konstante CLOCKS_PER_SEC = 1000000 wird so durch CLK_TCK = 100 ersetzt, */
/* was erheblich laengere Zeitmessung zulaesst. Informationen unter Sun zu */
/* times erhaelt man mittels "man 2 times". */
/* Achtung: Es kann nicht mehr die Kompiler-Option "Xc" fuer maximale ANSI-Konformanz */
/* benutzt werden, sondern nur noch "Xa". */
/* Und unter gcc darf nicht "-ansi" verwendet werden (denn bei Verwendung von "-ansi" */
/* gibt es kein CLK_TCK). */

/* Algorithmische Optionen */

/* Ist BAUMRES definiert, so wird der Suchbaum nur so weit aufgebaut, wie */
/* es fuer den zugehoerigen Resolutionsbaum noetig ist. */
/* (Dies kann den Suchbaum drastisch verkleinern, bringt aber auch zusaetzliche */
/*  Arbeit mit sich.) */

#ifndef NBAUMRES
#define BAUMRES
#endif

/* Ist LITTAB definiert, so wird die Baumbeschneidung platzeffizienter */
/* mittels einer Literaltabelle implementiert (kostet ca. 5 - 10 % */
/* mehr Zeit. */

#ifdef BAUMRES
#  ifndef NLITTAB
#  define LITTAB
#  endif
#endif

/* Ist LOKALLERNEN definiert, so werden 2-Klauseln lokal gelernt. */

/* Ist NL2RED definiert, so werden beim lokalen Lernen keine 2-Reduktionen */
/* gelernt (ist nicht FASTAUTARKIE definiert, so neutralisiert dies */
/* die Option LOKALLERNEN). */

/* Ist FASTAUTARKIE definiert, so werden 2-Klauseln gelernt, die sich durch */
/* 1-Autarkien ergeben. */


/* Nun wird OPTIONENZEICHENKETTE definiert als */

/*  [ D ] [ I ] [ S ] [ [ T | TT ] | [ L [2C] [1A] ] ] */

/* wobei "[]" fuer "optional" steht, und "|" fuer "oder". */

#ifdef BAUMRES
#ifdef LITTAB
#define OPTIONENKENNUNG1 "TT"
#else
#define OPTIONENKENNUNG1 "T"
#endif
#else
#define OPTIONENKENNUNG1 ""
#endif

#ifdef LOKALLERNEN
#define OPTIONENKENNUNG2 "L"
#ifndef NL2RED
#define OPTIONENKENNUNG3 "2C"
#else
#define OPTIONENKENNUNG3 ""
#endif
#ifdef FASTAUTARKIE
#define OPTIONENKENNUNG4 "1A"
#else
#define OPTIONENKENNUNG4 ""
#endif
#else
#define OPTIONENKENNUNG2 ""
#define OPTIONENKENNUNG3 ""
#define OPTIONENKENNUNG4 ""
#endif

#ifdef DYNAMISCH
#define OPTIONENKENNUNG5 "D"
#else
#define OPTIONENKENNUNG5 ""
#endif

#ifndef KEININLINE
#define OPTIONENKENNUNG6 "I"
#else
#define OPTIONENKENNUNG6 ""
#endif

#ifdef SYSTIME
#define OPTIONENKENNUNG7 "S"
#else
#define OPTIONENKENNUNG7 ""
#endif




/* -------------------------------------------------------------------------- */

/* Datentypen */


/* Vorzeichen */
typedef enum { Pos = 0, Neg = 1 } VZ;

/* Klausellaengen */
typedef unsigned int KLL;


/* -------------------------------------------------------------------------- */


#define ANZSPRACHEN 2
#ifndef SPRACHE
#define SPRACHE 1
#endif
/* SPRACHE = 0: Deutsch */
/* SPRACHE = 1: Englisch */
extern unsigned int Sprache;


#define ANZSTANDARDS 4
#ifndef STANDARD
#define STANDARD 1
#endif
extern unsigned int Standard;

extern bool Belegung;

#ifdef TABLEOUTPUT
#else
#  ifdef XMLOUTPUT
#    define XMLAUS
#  else
#    define DIMACSAUS
#  endif
#endif

#ifdef ASSIGNMENT
#  define BELEGUNG
#endif


/* -------------------------------------------------------------------------- */


/* Darstellung der Eingabe bzw. der aktuellen Klauselmenge */

/* Maximale Klauselnlaenge, Variablenanzahl, Anzahl von Literalvorkommen */
/* und Klauselnanzahl in der Eingabe und nach Vorreduktion */

extern unsigned int P0, P;
extern unsigned int N0, N;
extern unsigned int L0, L;
extern unsigned int K0, K;


extern unsigned int aktN;
/* aktN <= N ist die aktuelle Zahl von unbelegten Variablen */

extern unsigned int aktP;
/* aktP <= P ist die aktuelle maximale Klauselnlaenge */

/* Die folgenden Variablen sind nur aktiviert, wenn der Schalter */
/* Schranken gesetzt worden ist: */

extern unsigned int MAXN;
extern unsigned int MAXL;
extern unsigned int MAXK;

enum Ausgabeformat {Dimacs_Format, XML_Format, Tabellen_Format};


/* ---------------------------------------------------------------------------- */


/* Statistik */


extern long unsigned int Knoten, SingleKnoten, VerSingleKnoten, QuasiSingleKnoten, PureL, Autarkien, V1KlRed, FastAutarkien, InitEinerRed, neue2Klauseln, maxneue2K;

extern unsigned int Suchbaumtiefe, Ueberschreitung2, init2Klauseln;


/* Knoten            = Anzahl der Aufrufe von "SAT" */

/* SingleKnoten      = Anzahl der Aufrufe von "SAT" ohne binaere Verzweigung */

/* VerSingleKnoten   = Verpasste Single-Knoten (wg. falscher Reihenfolge der Zweige */

/* QuasiSingleKnoten = Anzahl der Aufrufe von "SAT" mit nur "scheinbarer" binaerer */
/*                     Verzweigung (z.B. ein Zweig ergab 2-CNF) */


/* Anzahl der ("wirklichen") Blaetter: */

/*      ((Knoten - SingleKnoten) + 1) / 2  - QuasiSingleKnoten */


/* Die Variablen "Knoten, SingleKnoten, QuasiSingleKnoten" werden in SAT berechnet. */



/* Reduktionen: */

/* PureL             = Anzahl der Reduktionen purer Literale */

/* Autarkien         = Anzahl der Reduktionen mittels (echter) Autarkien */

/* V1KlRed           = Anzahl der Reduktionen mittels verallgemeinerter 1-Kl.-Elim. */
/*                     (oder "r_2-Reduktionen") */

/* Redplus           = Anzahl der (echten) r_2^+-Reduktionen */


/* "PureL" wird in Reduktion2, "V1KlRed" und "Redplus" in Reduktion1, und "Autarkien" in Filter */
/* berechnet. */


#endif

#define GELESENOK 1
