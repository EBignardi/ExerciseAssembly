// Esempio di programma organizzato in due file, un file con codice sorgente C ed
// un file con codice sorgente in linguaggio assembly

#define N 6

int data[] = { 1, 4, -8, 2, 5, 3 };

int find_max(int* data, int dim);

main(void)
{
	int dim;
	dim = find_max(data, N);
}