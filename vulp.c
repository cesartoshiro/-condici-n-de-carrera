#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char *fn = "/tmp/XYZ";
	char buffer[60];
	FILE* fp;

	uid_t realUID = getuid();
	uid_t effUID = getuid();

	scanf("%50s", buffer);

	seteuid(realUID);

	if(!access(fn, W_OK)) {
		sleep(10)
		fp = fopen(fn, "a+");
		fwrite("\n", sizeof(char), 1, fp);
		fwrite(buffer, sizeof(char), strlen(buffer), fp);
		fclose(fp);
	}
	else {
		printf("No permission\n");
		seteuid(effUID);
	}
	return 0;
}