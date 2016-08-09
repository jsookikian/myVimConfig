#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

/* utility function to print working directory */
void pwd() {
   int status;
   pid_t pid = fork();
   if (!pid) {
      printf("current working directory: ");
      fflush(stdout);
      execl("/bin/pwd", "pwd", NULL);
      perror("exec failed");
      exit(EXIT_FAILURE);
   }
   else {
      waitpid(pid, &status, 0);
   }
}


int main() {
   char cwd[1024];
   
   getcwd(cwd, sizeof(cwd));
   
   // Get the path for the vim configuration file
   char *configPath;
   asprintf(&configPath, "%s/deepsea.vim", cwd);
   
   //CD to the home directory
   chdir(getenv("HOME"));
   pwd();
   //Check if .vim folder exists
   // If it doesnt, then make itt.
   if (access("./.vim", F_OK)) {
      printf(".vim folder does not exist\n");
      printf("making .vim folder...\n");
      mkdir(".vim", S_IRWXU);
   }
   // cd to the .vim folder
   chdir("./.vim");
   pwd();

   if (access("./plugin", F_OK)) {
      printf("plugin folder does not exist\n");
      printf("making plugin folder...\n");
      mkdir("plugin", S_IRWXU);
   }
   chdir("./plugin");
   pwd();

   if (access("./deepsea.vim", F_OK)) {
      pid_t pid = fork();
      int status;
      if (!pid) {
         execl("/bin/cp", "/bin/cp", configPath, ".", (char *) 0);
      }
      else {
         waitpid(pid, &status, 0);
         printf("vim configuration succesfully installed\n");
         exit(EXIT_SUCCESS);
      }
   }
   else {
      printf("deepsea.vim configuration is already setup\n");
      printf("Exiting.\n");
   }

   return 0;
}
