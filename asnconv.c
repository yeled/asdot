/*  convert BGP ASNs
*  ./asnconv 4262723631
*  ./asnconv 65036.12
*  ./asnconv 65412
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  //char *asn = malloc(strlen(argv[1]) );
  char asn[strlen(argv[1])] ;
  strcpy(asn, argv[1]);
  char dot = '.';
  char *asdot = strchr(asn, dot); // search for a '.' in the string
  unsigned int asn_int = atoi(asn); // convert string -> int

  if(asdot != NULL ) { // if '.' is found, then we have asdot

    printf("ASDOT: ");
    /* wtaf http://stackoverflow.com/a/19724503 */
    *asdot = '\0'; // overwrite the test, creating two strings (XXX)
    unsigned int asn_low = asn_int;
    unsigned int asn_high = atoi(asdot+1); // +1 is magic to find next string
    printf("%u\n", (asn_low<<16)+asn_high); // multiply by 65536
    //printf("(%d*65535+%d)\n", asn_low, asn_high);
    //printf("low: %d\nhigh: %d\n", asn_low, asn_high);

  } else if(asn_int <= 65535 ) { // normal low asn

    printf("2 Byte ASPLAIN: ");
    printf("%u\n", asn_int);
    //printf("(%u)\n", asn);

  } else if(asn_int >= 65536) { // otherwise, asplain

    printf("4 Byte ASPLAIN: ");
    printf("%u.%u\n", asn_int/65536, asn_int%65536);
    //printf("(%u)\n", asn_int);
  }

    return (0);
}
