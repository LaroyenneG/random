#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static int  (int low, int high)
{
	unsigned long seed_time=0;
	unsigned long seed_count=0;
	FILE *f = NULL;
	f = fopen ("rnd.tmp", "r");
	if (f != NULL) {
		fscanf (f, "%ld", &seed_time);
		fscanf (f, "%ld", &seed_count);
		fclose (f);
	} else {
	   seed_time=(unsigned long) time(NULL);
	   seed_count=0;
	}
	++seed_count;
	f = fopen ("rnd.tmp", "w");
	if (f != NULL) {
		fprintf (f, "%ld\n", seed_time);
		fprintf (f, "%ld\n", seed_count);
		fclose (f);
	}

	srand(seed_time);
	while (--seed_count > 0) rand();
	double v = (double) rand();
	v *= (double) (high-low+1);
	v /= (double) RAND_MAX;
	v += (double) low;
	return (int) v;
}

int main (int argc, char *argv[])
{
	int low=0, high=1;
	switch (--argc) {
	case 1  :
		high = atol (*++argv);
		break;
	case 2  :
		low = atol (*++argv);
		high = atol (*++argv);
		break;
	default :
		break;
	}
	cout << random (low, high) << endl;
	return 0;
}
