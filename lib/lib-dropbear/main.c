#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern int custom_dropbear_main(int argc, char ** argv);
extern int dropbearkey_main(int argc, char ** argv);

int main(int argc, char *argv[]) {
	char *keytypes[] = {"dss", "rsa", "ecdsa", "ed25519"};

	// This assumes bare rootfs
	if (mkdir("/etc", 0777) != 0) {
		perror("Error creating etc");
		return 1;
	}
	if (mkdir("/etc/dropbear", 0777) != 0) {
		perror("Error creating dropbear");
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		printf("Generating %s...\n", keytypes[i]);
		char keypath[50];
		sprintf(keypath, "/etc/dropbear/dropbear_%s_host_key", keytypes[i]);
		char *arguments[5];
		arguments[0] = "dummy";
		arguments[1] = "-t";
		arguments[2] = keytypes[i];
		arguments[3] = "-f";
		arguments[4] = keypath;
		dropbearkey_main(5, arguments);
	}

	char *dropbear_arguments[] = {"dummy", "-F"};
	return custom_dropbear_main(2, dropbear_arguments);
}
