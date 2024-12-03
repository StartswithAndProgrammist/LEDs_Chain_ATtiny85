// ******* needs library **************
#include <avr/io.h> // standard library for avr microcontrollers
#include <util/delay.h> // for _delay_ms()
#include <string.h> // for strlen()
// ************************************


// *********** constants **************  
#define DELAYTIME 1
#define CHARBREAK 2100
// ************************************

// ******** change name ports *********
#define LED1 PB0
#define LED2 PB1
#define LED3 PB2
#define LED4 PB3
#define LED5 PB4 
// ************************************


// ******** all needs array for led char *******
int a[] = {1, 6, 26, 6, 1};
int b[] = {31, 21, 21, 10, 0};
int c2[] = {14, 17, 17, 10, 0};
int d[] = {31, 17, 17, 14, 0};
int e[] = {31, 21, 21, 17, 0};
int f[] = {31, 20, 20, 16, 0};
int g[] = {14, 17, 19, 10, 0};
int h[] = {31, 4, 4, 4, 31};
int i[] = {0, 17, 31, 17, 0};
int j[] = {0, 17, 30, 16, 0};
int k[] = {31, 4, 10, 17, 0};
int l[] = {31, 1, 1, 1, 0};
int m[] = {31, 12, 3, 12, 31};
int n[] = {31, 12, 3, 31, 0};
int o[] = {14, 17, 17, 14, 0};
int p[] = {31, 20, 20, 8, 0};
int q[] = {14, 17, 19, 14, 2};
int r[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};
int t[] = {16, 16, 31, 16, 16};
int u[] = {30, 1, 1, 30, 0};
int v[] = {24, 6, 1, 6, 24};
int w[] = {28, 3, 12, 3, 28};
int x[] = {17, 10, 4, 10, 17};
int y[] = {17, 10, 4, 8, 16};
int z[] = {19, 21, 21, 25, 0};
	
int eos[] = {0, 1, 0, 0, 0}; // .
int excl[] = {0, 29, 0, 0, 0}; // !
int ques[] = {8, 19, 20, 8, 0}; // ?
// *****************************************

	

void displayLine(int line) {
	 int myline = line;
	 
	 if (myline >= 16) { PORTB |= (1 << LED1); myline -= 16; } else { PORTB &= ~(1 << LED1); }
	 if (myline >= 8) { PORTB |= (1 << LED2); myline -= 8; } else { PORTB &= ~(1 << LED2); } 
	 if (myline >= 4) { PORTB |= (1 << LED3); myline -= 4; } else { PORTB &= ~(1 << LED3); }
	 if (myline >= 2) { PORTB |= (1 << LED4); myline -= 2; } else { PORTB &= ~(1 << LED4); }
	 if (myline >= 1) { PORTB |= (1 << LED5); myline -= 1; } else { PORTB &= ~(1 << LED5); } 
		 
}

// ************ function turns all leds on which be in our line ***********************************
 void displayChar(char c) {
	if (c == 'a'){ for (int i = 0; i < 5; i++){ displayLine(a[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'b'){ for (int i = 0; i < 5; i++){ displayLine(b[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'c'){ for (int i = 0; i < 5; i++){ displayLine(c2[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'd'){ for (int i = 0; i < 5; i++){ displayLine(d[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'e'){ for (int i = 0; i < 5; i++){ displayLine(e[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'f'){ for (int i = 0; i < 5; i++){ displayLine(f[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'g'){ for (int i = 0; i < 5; i++){ displayLine(g[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'h'){ for (int i = 0; i < 5; i++){ displayLine(h[i]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'i'){ for (int it = 0; it < 5; it++){ displayLine(i[it]); _delay_ms(DELAYTIME); } displayLine(0); }
	if (c == 'j'){for (int i = 0; i <5; i++){ displayLine(j[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'k'){for (int i = 0; i <5; i++){ displayLine(k[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'l'){for (int i = 0; i <5; i++){ displayLine(l[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'm'){for (int i = 0; i <5; i++){ displayLine(m[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'n'){for (int i = 0; i <5; i++){ displayLine(n[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'o'){for (int i = 0; i <5; i++){ displayLine(o[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'p'){for (int i = 0; i <5; i++){ displayLine(p[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'q'){for (int i = 0; i <5; i++){ displayLine(q[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'r'){for (int i = 0; i <5; i++){ displayLine(r[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 's'){for (int i = 0; i <5; i++){ displayLine(s[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 't'){for (int i = 0; i <5; i++){ displayLine(t[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'u'){for (int i = 0; i <5; i++){ displayLine(u[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'v'){for (int i = 0; i <5; i++){ displayLine(v[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'w'){for (int i = 0; i <5; i++){ displayLine(w[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'x'){for (int i = 0; i <5; i++){ displayLine(x[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'y'){for (int i = 0; i <5; i++){ displayLine(y[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == 'z'){for (int i = 0; i <5; i++){ displayLine(z[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == '!'){for (int i = 0; i <5; i++){ displayLine(excl[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == '?'){for (int i = 0; i <5; i++){ displayLine(ques[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	if (c == '.'){for (int i = 0; i <5; i++){ displayLine(eos[i]); _delay_ms(DELAYTIME); } displayLine(0);}
	_delay_ms(CHARBREAK);
}
// ************************************************************************************************

// ****************** function for print line on POV ****************
void displayString(char* s)
{
	for (int i = 0; i<=strlen(s); i++)
	{
		displayChar(s[i]);
	}
}
// ******************************************************************


// **************** main function where we print line ***************
int main(void){
	
	DDRB |= (1 << LED1) | (1 << LED2) | (1 << LED3) | (1 << LED4) | (1 << LED5); // change ports on OUT
	
	displayString("Kolomin Max");
	
	while(1){
		
	}
		
	return 0;
}
// *******************************************************************
