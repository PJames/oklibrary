                       /* OKsolver; 5.3.1998 */

/* Autor: Oliver Kullmann, Universitaet Frankfurt am Main, Germany */
/* ab Februar 1999: University of Toronto, Computer Science Department */

/* Angelegt: 23.2.2001 */

/* Einheit: "Abstand_aK.c" */

/* "Alle Klauseln mit Gewichten" */


/* Die Gewichte werden aus Abstand_nK uebernommen. */


#include <stdlib.h>
#include <math.h>

#include "OK.h"
#include "Filter.h"
#include "Abstand.h"


float d0, d1;
unsigned int d0S, d1S;


#define G3 0.2
#define G4 0.05
#define G5 0.01
#define G6 0.003

#define ALPHA 20.4514
#define BETA 0.218673

static float *Gewicht;


/* -------------------------------------------------------------------------- */

size_t BedarfAbstandsV( void )
{
  return P * sizeof(float);
}

void *AbstandsV(void *Z)
{
  unsigned int p;

  Gewicht = (float *) Z; Z = (void *) (Gewicht + P);

  for (p = 2; p < P; p++)
    switch (p)
      {
      case 2 : Gewicht[2] = 1; break;
      case 3 : Gewicht[3] = G3; break;
      case 4 : Gewicht[4] = G4; break;
      case 5 : Gewicht[5] = G5; break;
      case 6 : Gewicht[6] = G6; break;
      default : Gewicht[p] = ALPHA * pow(BETA, p);
      }
  
  return Z;
}


char InitAbstand ( void )
{
  return 0;
}

/* -------------------------------------------------------------------------- */


__inline__ void Abstand ( void )

/* d = \sum_{i=2}^{+\infty} Gewicht[i] * LaAnzK[i] */

/* LaAnzK[i] = Anzahl Klauseln der Laenge i (= 0 fuer i >= aktP) */

/* Zweigauswahl: Minimiere \sum_{C \in F} 2^{-|C|}  */

{
  unsigned int i, gZ;
  int s;
  float gd;

  for (i = aktP - 1, gZ = 2, d0 = d1 = 0,
	 s = (DeltaK[Pos][Schalter])[aktP] - (DeltaK[Neg][Schalter])[aktP];
       i > 1; i--, gZ *= 2)
    {
      d0 += (gd = Gewicht[i]) * (LaAnzK[Pos][Schalter])[i];
      d1 += gd * (LaAnzK[Neg][Schalter])[i];
      
      s += gZ * ((DeltaK[Pos][Schalter])[i] - (DeltaK[Neg][Schalter])[i]);
    }

/*   d0 = d0 / (aktN - DeltaN[Pos][Schalter]); */
/*   d1 = d1 / (aktN - DeltaN[Neg][Schalter]); */
  
  
  if (s >= 0)
    Zweig = Pos;
  else
    Zweig = Neg;

  d0S = DeltaN[Pos][Schalter];
  d1S = DeltaN[Neg][Schalter];
}